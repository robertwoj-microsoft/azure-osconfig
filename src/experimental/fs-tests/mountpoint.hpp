#ifndef FS_TESTS_MOUNTPOINT_HPP
#define FS_TESTS_MOUNTPOINT_HPP

#include <filesystem>
#include <sys/mount.h> // Propagates mount flags to the caller

namespace sandbox
{
    /**
     * @brief Represents a mount point.
     *
     * This is a scope-exit wrapper around system mount command.
     */
    class MountPoint
    {
    public:
        explicit MountPoint(std::string source, std::filesystem::path target, std::string type, unsigned long flags, const void* data) noexcept(false);
        MountPoint(const MountPoint&) = delete;
        MountPoint& operator=(const MountPoint&) = delete;
        MountPoint(MountPoint&&) = delete;
        MountPoint& operator=(MountPoint&&) = delete;
        ~MountPoint() noexcept;

        void setTarget(std::filesystem::path target) noexcept { mTarget = std::move(target); }
    private:
        std::filesystem::path mTarget;
    };
} // namespace sandbox

#endif // FS_TESTS_MOUNTPOINT_HPP