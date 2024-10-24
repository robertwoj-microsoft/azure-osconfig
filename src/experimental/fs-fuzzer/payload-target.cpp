#include <cstdint>
#include <string>
#include "Mmi.h"
#include "SecurityBaseline.h"
#include <iostream>

extern "C" int LLVMFuzzerTestOneInput(const std::uint8_t* Data, std::size_t Size) {
    SecurityBaselineInitialize();
    auto handle = SecurityBaselineMmiOpen("SecurityBaselineTest", 4096);
    if (handle == nullptr)
    {
        SecurityBaselineShutdown();
        return 0;
    }

    char* payload = nullptr;
    int payloadSizeBytes = 0;

    auto input = std::string(reinterpret_cast<const char*>(Data), Size);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", input.c_str(), &payload, &payloadSizeBytes);
    SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiClose(handle);
    SecurityBaselineShutdown();
    return 0;  // Values other than 0 and -1 are reserved for future use.
}