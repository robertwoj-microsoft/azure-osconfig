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
            // std::cout << "Creating directory: " << mTarget << std::endl;
            if (!fs::create_directories(mTarget))
            {
                throw std::runtime_error("failed to create target directory");
            }
        }

        // std::cout << "Mounting " << source << " on " << mTarget << " as " << type << std::endl;
        if (::mount(std::move(source).c_str(), mTarget.c_str(), std::move(type).c_str(), flags, data) != 0)
        {
            throw std::runtime_error("mount failed: " + std::string{ strerror(errno) });
        }
    }

    MountPoint::~MountPoint() noexcept
    {
        if(!fs::exists(mTarget))
        {
            return;
        }

        // std::cout << "Unmounting " << mTarget << std::endl;
        if (::umount(mTarget.c_str()) != 0)
        {
            std::cerr << "failed to unmount " << mTarget << ": " << strerror(errno) << std::endl;
        }
    }
} // namespace sandbox
