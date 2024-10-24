#include "tempdir.hpp"
#include <cstdlib>
#include <cstring>
#include <stdexcept>
#include <cstdlib>
#include <iostream>
#include <limits.h>

namespace fs = std::filesystem;

TempDir::TempDir() noexcept(false)
    : TempDir(fs::path{ "/tmp/XXXXXX" })
{
}

TempDir::TempDir(std::filesystem::path _template) noexcept(false)
{
    char workdir[PATH_MAX];
    ::strcpy(workdir, _template.c_str());
    if (nullptr == ::mkdtemp(workdir))
    {
        throw std::runtime_error("mkdtemp failed: " + std::string{ strerror(errno) });
    }
    path = workdir;
}

TempDir::~TempDir() noexcept
{
    if (keep)
        return;

    try
    {
        if (fs::exists(path) && fs::is_directory(path))
        {
            for (const auto& entry : fs::directory_iterator(path))
            {
                fs::remove_all(entry.path());
            }
            fs::remove(path);
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "Failed to remove temporary directory " << path << ": " << e.what() << std::endl;
    }
}
