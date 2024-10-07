#ifndef FS_TESTS_TEMPDIR_HPP
#define FS_TESTS_TEMPDIR_HPP

#include <filesystem>

struct TempDir {
    std::filesystem::path path;

    explicit TempDir() noexcept(false);
    explicit TempDir(std::filesystem::path _template) noexcept(false);
    TempDir(const TempDir&) = delete;
    TempDir& operator=(const TempDir&) = delete;
    TempDir(TempDir&&) = delete;
    TempDir& operator=(TempDir&&) = delete;
    ~TempDir() noexcept;
};

#endif // FS_TESTS_TEMPDIR_HPP