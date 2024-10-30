#include <cstdint>
#include <string>
#include "Mmi.h"
#include "SecurityBaseline.h"
#include <iostream>
#include <csignal>
#include <cstring>
#include <unistd.h>
#include "sandbox.hpp"

extern "C" int LLVMFuzzerRunDriver(int*, char***, int (*)(const uint8_t*, size_t));

static auto g_sandbox = sandbox::Sandbox{};

// extern "C" int LLVMFuzzerTestOneInput(const std::uint8_t* data, std::size_t size)
static int target(const std::uint8_t* data, std::size_t size) noexcept(false)
{
    g_sandbox.reset();
    auto corpusPath = g_sandbox.getOldRootfs() / "corpus";
    if (::chdir(corpusPath.c_str()) == -1)
    {
        return -1;
    }

    SecurityBaselineInitialize();
    auto handle = SecurityBaselineMmiOpen("SecurityBaselineTest", 4096);
    if (handle == nullptr)
    {
        SecurityBaselineShutdown();
        return 0;
    }

    char* payload = nullptr;
    int payloadSizeBytes = 0;

    auto input = std::string(reinterpret_cast<const char*>(data), size);
    int x[5];
    x[5] = 0;
    SecurityBaselineMmiGet(handle, "SecurityBaseline", input.c_str(), &payload, &payloadSizeBytes);
    SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiClose(handle);
    SecurityBaselineShutdown();
    return 0;
}

static void setup_sigint_handler(void (*handler)(int)) {
    struct sigaction sa;
    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if (sigaction(SIGINT, &sa, nullptr) == -1)
    {
        std::cerr << "Failed to set up SIGINT handler: " << strerror(errno) << std::endl;
        std::exit(EXIT_FAILURE);
    }
}

int main(int argc, char** argv)
{
    auto task = [&]() -> int {
        /*
         * Restore default handler, libfuzzer installs its own handlers
         */
        setup_sigint_handler(SIG_DFL);
        return LLVMFuzzerRunDriver(&argc, &argv, target);
    };

    /* Ignore interrupt here, let libfuzzer decide what to do */
    setup_sigint_handler(SIG_IGN);
    return g_sandbox.exec(task);
}
