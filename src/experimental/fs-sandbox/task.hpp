#ifndef FS_TESTS_TASK_HPP
#define FS_TESTS_TASK_HPP

#include <functional>
#include <stdexcept>

namespace sandbox
{
    using Task = std::function<int()>;

    struct TaskException : public std::runtime_error
    {
        TaskException(const std::string& message)
            : std::runtime_error{ message }
        {
        }

        TaskException(const std::exception& e)
            : std::runtime_error{ e.what() }
        {
        }
    };
} // namespace sandbox

#endif // FS_TESTS_TASK_HPP