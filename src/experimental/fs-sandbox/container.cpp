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

    std::string Container::makeOverlayOptions() const noexcept {
        return "lowerdir=" + std::string{ mRootfs }
            + ",upperdir=" + std::string{ mUpperDir.path }
        + ",workdir=" + std::string{ mWorkDir.path };
    }

    Container::Container(std::filesystem::path rootfs) noexcept(false)
        : mRootfs{ std::move(rootfs) }
        , mWorkDir{ "/tmp/workdir.XXXXXX" }
        , mUpperDir{ "/tmp/upperdir.XXXXXX" }
        , mMergeDir{ "/tmp/mergedir.XXXXXX" }
        , mOverlay{ "overlay", mMergeDir.path, "overlay", 0, makeOverlayOptions().c_str() }
        , mOldRootfs{ mMergeDir.path / "rootfs.XXXXXX" }
    {
        if (::mount(mMergeDir.path.c_str(), mMergeDir.path.c_str(), NULL, MS_BIND, NULL) == -1)
        {
            throw std::runtime_error("New root is not a mount point");
        }

        if (::syscall(SYS_pivot_root, mMergeDir.path.c_str(), mOldRootfs.path.c_str()) != 0)
        {
            throw std::runtime_error("pivot_root failed: " + std::string{ strerror(errno) });
        }

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

    Container::~Container() noexcept
    {
        mOldRootfs.keep = true;

        mHome.reset();
        mTmp.reset();
        mUsr.reset();
        mBin.reset();
        mLib64.reset();
        mLib.reset();
        mProc.reset();

        auto oldRootfs = fs::path{ "/" } / mOldRootfs.path.filename();
        if (::chroot(oldRootfs.c_str()) != 0)
        {
            std::cerr << "chroot failed: " << std::strerror(errno) << std::endl;
        }
    }
}
