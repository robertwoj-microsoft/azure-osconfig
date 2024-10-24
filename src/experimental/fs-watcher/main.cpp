#include <iostream>
#include <sys/inotify.h>
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>
#include <filesystem>
#include <cstring>
#include <sys/file.h>
#include <map>


namespace fs = std::filesystem;

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <directory>" << std::endl;
        return 1;
    }

    fs::path directory(argv[1]);
    if (!fs::exists(directory))
    {
        std::cerr << "Directory " << directory << " does not exist" << std::endl;
        return 1;
    }

    int fd = inotify_init();
    if (fd < 0)
    {
        std::cerr << "Failed to initialize inotify" << std::endl;
        return 1;
    }

    int wd = inotify_add_watch(fd, directory.c_str(), IN_CLOSE_WRITE | IN_MOVED_TO | IN_MOVED_FROM | IN_CREATE | IN_CREATE);
    if (wd < 0)
    {
        std::cerr << "Failed to add watch" << std::endl;
        ::close(fd);
        return 1;
    }

    char buffer[sizeof(struct inotify_event) + NAME_MAX + 1];
    std::map<uint32_t, fs::path> move_events;
    std::map<fs::path, int> file_descriptors;
    while (true)
    {
        ssize_t len = ::read(fd, buffer, sizeof(buffer));
        if (len < 0)
        {
            std::cerr << "Failed to read inotify events, len: " << len << std::endl;
            ::close(wd);
            ::close(fd);
            return 1;
        }

        ssize_t offset = 0;
        while (offset < len)
        {
            struct inotify_event* event = reinterpret_cast<struct inotify_event*>(buffer + offset);
            offset += sizeof(struct inotify_event) + event->len;
            if (event->mask & IN_CLOSE_WRITE)
            {
                fprintf(stderr, "[ CLOSE ] %s/%s\n", directory.c_str(), event->name);
                fprintf(stderr, "=============================\n");
                auto it = file_descriptors.find(directory / event->name);
                if (it == file_descriptors.end())
                    continue;
                auto desc = it->second;

                // Read the file
                char buf[1024 * 1024];
                ssize_t n = ::read(desc, buf, sizeof(buf));
                if (n < 0)
                {
                    std::cerr << "Failed to read file " << event->name << ": " << strerror(errno) << std::endl;
                    ::close(desc);
                    continue;
                }

                fputs(buf, stdout);
                fprintf(stderr, "=============================\n");
            }
            else if (event->mask & IN_MOVED_TO)
            {
                auto it = move_events.find(event->cookie);
                if (it == move_events.end())
                    it = move_events.insert({ event->cookie, directory / event->name }).first;
                else
                {
                    fprintf(stderr, "[ MOVE ] %s -> %s/%s\n", it->second.c_str(), directory.c_str(), event->name);
                }
            }
            else if (event->mask & IN_MOVED_FROM)
            {
                auto it = move_events.find(event->cookie);
                if (it == move_events.end())
                    it = move_events.insert({ event->cookie, directory / event->name }).first;
                else
                {
                    fprintf(stderr, "[ MOVE ] %s/%s -> %s\n", directory.c_str(), event->name, it->second.c_str());
                }
            }
            else if (event->mask & IN_CREATE)
            {
                char path[PATH_MAX];
                snprintf(path, sizeof(path), "%s/%s", directory.c_str(), event->name);
                auto desc = ::open(path, O_RDONLY);
                if (desc < 0)
                {
                    fprintf(stderr, "Failed to open file %s: %s\n", path, strerror(errno));
                    continue;
                }
                fprintf(stderr, "[ CREATE ] %s/%s\n", directory.c_str(), event->name);
                file_descriptors[directory / event->name] = desc;
            }
            else
            {
                fprintf(stderr, "Unknown event: %d\n", event->mask);
            }
        }
    }

    ::close(wd);
    ::close(fd);
    return 0;
}