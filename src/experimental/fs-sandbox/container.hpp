#ifndef FS_TESTS_CONTAINER_HPP
#define FS_TESTS_CONTAINER_HPP

#include "tempdir.hpp"
#include "mountpoint.hpp"
#include "task.hpp"
#include <filesystem>

namespace sandbox
{
    /**
     * @brief The container class is responsible for setting up the root filesystem and the required mount points.
     */
    class Container
    {
        TempDir mRootfs;

        /* TODO: Overlay could be optional */
        // TempDir mWorkDir;
        // TempDir mUpperDir;
        // TempDir mMergeDir;
        // MountPoint mOverlay;

        /* Keeps the old root filesystem mountpoint to allow us getting back */
        TempDir mOldRootfs;

        /* These mount points are require different initialization order, pointers make it easier to maintain */
        std::unique_ptr<MountPoint> mProc;
        std::unique_ptr<MountPoint> mLib;
        std::unique_ptr<MountPoint> mBin;
        std::unique_ptr<MountPoint> mUsr;
        std::unique_ptr<MountPoint> mLib64;
        std::unique_ptr<MountPoint> mTmp;
        std::unique_ptr<MountPoint> mHome;
    public:
        explicit Container() noexcept(false);
        Container(const Container&) = delete;
        Container& operator=(const Container&) = delete;
        Container(Container&&) = delete;
        Container& operator=(Container&&) = delete;
        ~Container() noexcept;

        const std::filesystem::path& getRootfs() const noexcept { return mRootfs.path; }
        std::filesystem::path getOldRootfs() const noexcept { return std::filesystem::path("/") / mOldRootfs.path.filename(); }
    private:
        // std::string makeOverlayOptions() const noexcept;
        void cleanupRootfs() noexcept;
    };
} // namespace sandbox

#endif // FS_TESTS_CONTAINER_HPP