// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#include <rapidjson/writer.h>
#include <string>

#include <CommonUtils.h>
#include <Logging.h>
#include <Mmi.h>

#define TPM_LOGFILE "/var/log/osconfig_tpm.log"
#define TPM_ROLLEDLOGFILE "/var/log/osconfig_tpm.bak"

#define TPM "Tpm"
#define TPM_STATUS "TpmStatus"
#define TPM_VERSION "TpmVersion"
#define TPM_MANUFACTURER "TpmManufacturer"

class TpmLog
{
    public:
        static OSCONFIG_LOG_HANDLE Get()
        {
            return m_logTpm;
        }

        static void OpenLog()
        {
            m_logTpm = ::OpenLog(TPM_LOGFILE, TPM_ROLLEDLOGFILE);
        }

        static void CloseLog()
        {
            ::CloseLog(&m_logTpm);
        }

    private:
        static OSCONFIG_LOG_HANDLE m_logTpm;
};

class Tpm
{
    public:
        enum Status { Unknown, TpmDetected, TpmNotDetected };

        Tpm(int maxPayloadSizeBytes);
        virtual ~Tpm();
        virtual std::string RunCommand(const char* command);

        void Trim(std::string& s);
        unsigned char Decode(char c);
        void HexToText(std::string& s);

        int Get(const char* objectName, MMI_JSON_STRING* payload, int* payloadSizeBytes);
        void GetStatus(std::string& status);
        void GetVersion(std::string& version);
        void GetManufacturer(std::string& manufacturer);

        int m_maxPayloadSizeBytes;
};