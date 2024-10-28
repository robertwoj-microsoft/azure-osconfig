#include "container.hpp"
#include "mountpoint.hpp"
#include <unistd.h>
#include <cstring>
#include <iostream>
#include <syscall.h>
#include <fstream>
#include <fcntl.h>
#include <limits.h>

namespace sandbox
{
    namespace fs = std::filesystem;

    // std::string Container::makeOverlayOptions() const noexcept {
    //     return "lowerdir=" + std::string{ mRootfs }
    //         + ",upperdir=" + std::string{ mUpperDir.path }
    //     + ",workdir=" + std::string{ mWorkDir.path };
    // }

    Container::Container(std::filesystem::path rootfs) noexcept(false)
        : mRootfs{ std::move(rootfs) }
        // , mWorkDir{ "/tmp/workdir.XXXXXX" }
        // , mUpperDir{ "/tmp/upperdir.XXXXXX" }
        // , mMergeDir{ "/tmp/mergedir.XXXXXX" }
        // , mOverlay{ "overlay", mMergeDir.path, "overlay", 0, makeOverlayOptions().c_str() }
        , mOldRootfs{ mRootfs / "rootfs.XXXXXX" }
    {
        /* The temporary rootfs must be a mount point for the pivot_root syscall to succeed */
        if (::mount(mRootfs.c_str(), mRootfs.c_str(), NULL, MS_BIND, NULL) == -1)
        {
            throw std::runtime_error("New root is not a mount point");
        }

        /* Use the pivot_root function in order to keep the old root filesystem reference */
        if (::syscall(SYS_pivot_root, mRootfs.c_str(), mOldRootfs.path.c_str()) != 0)
        {
            if(::umount2(mRootfs.c_str(), MNT_DETACH) == -1)
            {
                std::cerr << "ERROR: Failed to unmount new rootfs: " << std::strerror(errno) << std::endl;
            }

            throw std::runtime_error("pivot_root failed: " + std::string{ strerror(errno) });
        }

        try
        {
            /* TODO: the cleanup logic should be reviewed and tested here */
            auto oldRootfs = fs::path{ "/" } / mOldRootfs.path.filename();
            mProc = std::make_unique<MountPoint>("proc", "/proc", "proc", 0, nullptr);
            mLib = std::make_unique<MountPoint>(oldRootfs / "lib", "/lib", "", MS_BIND | MS_REC | MS_RDONLY, nullptr);
            mLib64 = std::make_unique<MountPoint>(oldRootfs / "lib64", "/lib64", "", MS_BIND | MS_REC | MS_RDONLY, nullptr);
            mBin = std::make_unique<MountPoint>(oldRootfs / "bin", "/bin", "", MS_BIND | MS_REC | MS_RDONLY, nullptr);
            mUsr = std::make_unique<MountPoint>(oldRootfs / "usr", "/usr", "", MS_BIND | MS_REC | MS_RDONLY, nullptr);
            mTmp = std::make_unique<MountPoint>("tmpfs", "/tmp", "tmpfs", 0, nullptr);
            /* Required for sanitizer and llvm-symbolizer to show useful output */
            mHome = std::make_unique<MountPoint>(oldRootfs / "home", "/home", "", MS_BIND | MS_REC | MS_RDONLY, nullptr);

            if (::chdir("/"))
            {
                throw std::runtime_error("chdir failed: " + std::string{ strerror(errno) });
            }
        }
        catch (const std::exception& e)
        {
            cleanupRootfs();
            throw;
        }
    }

    Container::~Container() noexcept
    {
        cleanupRootfs();
    }

    void Container::cleanupRootfs() noexcept
    {
        mHome.reset();
        mTmp.reset();
        mUsr.reset();
        mBin.reset();
        mLib64.reset();
        mLib.reset();
        mProc.reset();

        auto oldRootfs = fs::path{ "/" } / mOldRootfs.path.filename();
        TempDir tempRootfs{ oldRootfs / "tmp" / "rootfs.XXXXXX" };
        // std::cerr << "Mounting temp rootfs: " << tempRootfs.path << std::endl;
        if (::syscall(SYS_pivot_root, oldRootfs.c_str(), tempRootfs.path.c_str()) != 0)
        {
            std::cerr << "ERROR: Failed to pivot temporary rootfs " << oldRootfs << " to " << tempRootfs.path << ": " << std::strerror(errno) << std::endl;
            return;
        }

        auto tempRootfsPath = fs::path("/tmp") / tempRootfs.path.filename();
        // std::cerr << "Unmounting temp rootfs: " << tempRootfsPath << std::endl;
        if (::umount2(tempRootfsPath.c_str(), MNT_DETACH) == -1)
        {
            std::cerr << "ERROR: Failed to unmount temporary rootfs " << tempRootfsPath << ": " << std::strerror(errno) << std::endl;
            return;
        }

        // std::cerr << "Removing " << tempRootfsPath << std::endl;
        if (!fs::remove_all(tempRootfsPath))
        {
            std::cerr << "ERROR: Failed to remove temp rootfs: " << tempRootfs.path << std::endl;
            return;
        }
    }
}
