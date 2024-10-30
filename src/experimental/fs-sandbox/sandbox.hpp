#ifndef FS_TESTS_SANDBOX_HPP
#define FS_TESTS_SANDBOX_HPP

#include "task.hpp"
#include "container.hpp"
#include <filesystem>
#include <functional>

namespace sandbox
{
    class Sandbox
    {
        static constexpr std::size_t cStackSize = 1024 * 1024;
        char mChildStack[cStackSize];
        std::unique_ptr<Container> mContainer;
    public:
        Sandbox() noexcept(false);
        Sandbox(const Sandbox&) = delete;
        Sandbox& operator=(const Sandbox&) = delete;
        Sandbox(Sandbox&&) = delete;
        Sandbox& operator=(Sandbox&&) = delete;
        ~Sandbox() = default;

        int exec(Task task) noexcept(false);
        void reset() noexcept(false);
        void clear() noexcept(false);
        std::filesystem::path getRootfs() const noexcept { return mContainer ? mContainer->getRootfs() : std::filesystem::path("/"); }
        std::filesystem::path getOldRootfs() const noexcept { return mContainer ? mContainer->getOldRootfs() : std::filesystem::path("/"); }
    private:
        void updateIDMap(std::string mapping, std::filesystem::path path) const noexcept(false);
        void denySetgroups(pid_t childPid) const noexcept(false);
    };
} // namespace sandbox

#endif // FS_TESTS_SANDBOX_HPP