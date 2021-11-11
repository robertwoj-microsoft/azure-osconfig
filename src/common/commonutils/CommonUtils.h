// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#ifndef COMMON_H
#define COMMON_H

#include <stddef.h>

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

#define UNUSED(x) (void)(x)

// Linefeed (LF) ASCII character
#ifndef EOL
#define EOL 10
#endif

#ifdef __cplusplus
extern "C"
{
#endif

char* LoadStringFromFile(const char* fileName, bool stopAtEol);

bool SavePayloadToFile(const char* fileName, const char* payload, const int payloadSizeBytes);

typedef int(*CommandCallback)(void* context);

int ExecuteCommand(void* context, const char* command, bool replaceEol, bool forJson, unsigned int maxTextResultBytes, unsigned int timeoutSeconds, char** textResult, CommandCallback callback, void* log);

int RestrictFileAccessToCurrentAccountOnly(const char* fileName);

size_t HashString(const char* source);

#ifdef __cplusplus
}
#endif

#endif // COMMON_H