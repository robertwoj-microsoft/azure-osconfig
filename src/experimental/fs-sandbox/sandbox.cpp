#include "sandbox.hpp"
#include "container.hpp"
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>
#include <fcntl.h>
#include <cstring>
#include <iostream>
#include <vector>

namespace sandbox
{
    namespace fs = std::filesystem;

    class Sandbox;
    struct ChildArgs
    {
        Sandbox& sandbox;
        Task task;
        int pipe[2];

        explicit ChildArgs(Sandbox& sandbox, Task task)
            : sandbox{ sandbox }
            , task{ std::move(task) }
            , pipe{}
        {
        }
    };

    static int childProcess(void* arg)
    {
        const auto& childArgs = *reinterpret_cast<const ChildArgs*>(arg);

        ::close(childArgs.pipe[1]);
        char ch;
        if (::read(childArgs.pipe[0], &ch, 1) != 0)
        {
            ::close(childArgs.pipe[0]);
            return EXIT_FAILURE;
        }

        ::close(childArgs.pipe[0]);

        try
        {
            /* Disable rootfs mount propagation */
            if (::mount(NULL, "/", NULL, MS_REC | MS_PRIVATE, NULL) == -1)
            {
                throw std::runtime_error("Failed to disable shared propagation on /");
            }

            try
            {
                return std::invoke(childArgs.task);
            }
            catch (const std::exception& e)
            {
                throw TaskException{ e };
            }
        }
        catch (const TaskException& e)
        {
            std::cerr << "Task failed with exception: " << e.what() << std::endl;
            return EXIT_FAILURE;
        }
        catch (const std::exception& e)
        {
            std::cerr << "Exception: " << e.what() << std::endl;
            return EXIT_FAILURE;
        }
    }

    Sandbox::Sandbox() noexcept(false)
    {
    }

    int Sandbox::exec(Task task) noexcept(false)
    {
        auto childArgs = ChildArgs{ *this, std::move(task) };

        if (::pipe(childArgs.pipe) == -1)
        {
            throw std::runtime_error("pipe failed: " + std::string{ strerror(errno) });
        }

        int flags = CLONE_NEWNS | CLONE_NEWUSER | CLONE_NEWPID | SIGCHLD;
        auto child_pid = ::clone(childProcess, reinterpret_cast<void*>(mChildStack + cStackSize), flags, reinterpret_cast<void*>(&childArgs));
        if (child_pid == -1)
        {
            throw std::runtime_error("clone failed: " + std::string{ strerror(errno) });
        }

        auto map_path = fs::path(std::string{ "/proc/" } + std::to_string(child_pid) + "/uid_map");
        auto uid_map = std::string{ "0 " } + std::to_string(getuid()) + " 1";
        updateIDMap(std::move(uid_map), std::move(map_path));

        denySetgroups(child_pid);
        map_path = fs::path(std::string{ "/proc/" } + std::to_string(child_pid) + "/gid_map");
        uid_map = std::string{ "0 " } + std::to_string(getgid()) + " 1";
        updateIDMap(std::move(uid_map), std::move(map_path));

        ::close(childArgs.pipe[1]);    /* Close the write end of the pipe */

        /* Wait for child */
        int wstatus = 0;
        if (::waitpid(child_pid, &wstatus, 0) == -1)
        {
            ::close(childArgs.pipe[0]);
            throw std::runtime_error("waitpid failed: " + std::string{ strerror(errno) });
        }

        ::close(childArgs.pipe[0]);
        if (WIFEXITED(wstatus))
        {
            return WEXITSTATUS(wstatus);
        }

        throw std::runtime_error("child process exited abnormally");
    }

    void Sandbox::reset() noexcept(false)
    {
        mContainer = std::make_unique<Container>();
    }

    void Sandbox::clear() noexcept(false)
    {
        mContainer.reset();
    }

    void Sandbox::updateIDMap(std::string mapping, fs::path path) const noexcept(false)
    {
        auto fd = ::open(path.c_str(), O_RDWR);
        if (fd == -1)
        {
            throw std::runtime_error("open failed: " + std::string{ strerror(errno) });
        }

        if (::write(fd, mapping.c_str(), mapping.size()) != mapping.size())
        {
            ::close(fd);
            throw std::runtime_error("write failed: " + std::string{ strerror(errno) });
        }

        ::close(fd);
    }

    void Sandbox::denySetgroups(pid_t childPid) const noexcept(false)
    {
        auto path = fs::path(std::string{ "/proc/" } + std::to_string(childPid) + "/setgroups");
        auto fd = ::open(path.c_str(), O_RDWR);
        if (fd == -1)
        {
            if (errno != ENOENT)
            {
                throw std::runtime_error("failed to open setgroups file: " + std::string{ strerror(errno) });
            }

            return;
        }

        if (::write(fd, "deny", 4) == -1)
        {
            ::close(fd);
            throw std::runtime_error("failed to write to setgroups file: " + std::string{ strerror(errno) });
        }

        ::close(fd);
    }
} // namespace sandbox