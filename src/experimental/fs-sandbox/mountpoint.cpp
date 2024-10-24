#include "mountpoint.hpp"
#include <sys/mount.h>
#include <cstring>
#include <iostream>

namespace sandbox
{
    namespace fs = std::filesystem;
    using string = std::string;

    MountPoint::MountPoint(string source, fs::path target, string type, unsigned long flags, const void* data) noexcept(false)
        : mTarget{ std::move(target) }
    {
        if (!fs::exists(mTarget))
        {
            if (!fs::create_directories(mTarget))
            {
                throw std::runtime_error("failed to create target directory");
            }
        }

        if (::mount(source.c_str(), mTarget.c_str(), type.c_str(), flags, data) != 0)
        {
            throw std::runtime_error("mount failed: " + std::string{ strerror(errno) });
        }
    }

    MountPoint::~MountPoint() noexcept
    {
        if(!fs::exists(mTarget))
        {
            std::cerr << "Cannot unmount " << mTarget << ", directory does not exist" << std::endl;
            return;
        }

        if (::umount2(mTarget.c_str(), MNT_DETACH) != 0)
        {
            std::cerr << "failed to unmount " << mTarget << ": " << strerror(errno) << std::endl;
            return;
        }
    }
} // namespace sandbox
