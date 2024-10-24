#include <cstdint>
#include <string>
#include "Mmi.h"
#include "SecurityBaseline.h"
#include <iostream>
#include "sandbox.hpp"
#include <unistd.h>
#include <archive.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <limits.h>
#include <set>

namespace fs = std::filesystem;
struct ReportFailure : std::runtime_error
{
    ReportFailure(const std::string& message) : std::runtime_error(message) {}
};

// struct Context
// {
//     MMI_HANDLE handle;
//     sandbox::Sandbox m_sandbox;
// public:
//     Context() {
//         SecurityBaselineInitialize();
//         handle = SecurityBaselineMmiOpen("SecurityBaselineTest", 4096);
//         if(nullptr == handle) {
//             std::cerr << "SecurityBaselineMmiOpen failed" << std::endl;
//             SecurityBaselineShutdown();
//             exit(-1);
//         }
//     }

//     ~Context() {
//         SecurityBaselineMmiClose(handle);
//         SecurityBaselineShutdown();
//     }

//     MMI_HANDLE handle() const {
//         return handle;
//     }

//     sandbox::Sandbox& sandbox() {
//         return m_sandbox;
//     }

//     int exec(sandbox::Task task) {
//         return m_sandbox.exec(task);
//     }
// };

/*
 * Tar file unpacking code is based on libarchive example:
 * https://github.com/libarchive/libarchive/blob/master/examples/untar.c
 */
static int copy_data(archive* reader, archive* writer)
{
    int rc;
    const void* buff;
    size_t size;
    int64_t offset;

    for (;;)
    {
        rc = archive_read_data_block(reader, &buff, &size, &offset);
        if (rc == ARCHIVE_EOF)
            return ARCHIVE_OK;
        if (rc != ARCHIVE_OK)
        {
            // std::cerr << "Failed to read data block: " << archive_error_string(reader) << std::endl;
            return rc;
        }

        rc = archive_write_data_block(writer, buff, size, offset);
        if (rc != ARCHIVE_OK)
        {
            // std::cerr << "Failed to write data block: " << archive_error_string(writer) << std::endl;
            return rc;
        }
    }

    return ARCHIVE_FAILED;
}

static int unpack(const std::uint8_t* data, std::size_t size) noexcept
{
    archive* reader = nullptr, * writer = nullptr;
    int rc = ARCHIVE_FAILED;

    reader = archive_read_new();
    if (reader == nullptr)
    {
        // std::cerr << "Failed to obtain archive reader" << std::endl;
        goto unpack_out;
    }

    writer = archive_write_disk_new();
    if (nullptr == writer)
    {
        // std::cerr << "Failed to obtain archive writer" << std::endl;
        goto unpack_out;
    }

    if ((rc = archive_write_disk_set_options(writer, ARCHIVE_EXTRACT_TIME | ARCHIVE_EXTRACT_PERM | ARCHIVE_EXTRACT_ACL | ARCHIVE_EXTRACT_FFLAGS)) != ARCHIVE_OK)
    {
        // std::cerr << "Failed to set archive write disk options: " << archive_error_string(writer) << std::endl;
        goto unpack_out;
    }

    if ((rc = archive_read_support_format_tar(reader)) != ARCHIVE_OK)
    {
        // std::cerr << "Failed to set archive read support format tar: " << archive_error_string(reader) << std::endl;
        goto unpack_out;
    }

    if ((rc = archive_read_open_memory(reader, data, size)) != ARCHIVE_OK)
    {
        // std::cerr << "Failed to read archive from memory: " << archive_error_string(reader) << std::endl;
        goto unpack_out;
    }

    for (;;)
    {
        archive_entry* entry = nullptr;
        rc = archive_read_next_header(reader, &entry);
        if (rc == ARCHIVE_EOF)
            break;
        if (rc != ARCHIVE_OK)
        {
            // std::cerr << "Failed to read next header: " << archive_error_string(reader) << std::endl;
            goto unpack_out;
        }

        if ((rc = archive_write_header(writer, entry) != ARCHIVE_OK))
        {
            // std::cerr << "Failed to write header: " << archive_error_string(writer) << std::endl;
            goto unpack_out;
        }

        if ((rc = copy_data(reader, writer)) != ARCHIVE_OK)
        {
            // copy_data() prints out message in case of failure
            goto unpack_out;
        }

        if ((rc = archive_write_finish_entry(writer)) != ARCHIVE_OK)
        {
            // std::cerr << "Failed to finish entry: " << archive_error_string(writer) << std::endl;
            goto unpack_out;
        }
    }

    rc = ARCHIVE_OK;
unpack_out:
    archive_read_close(reader);
    archive_read_free(reader);
    archive_write_close(writer);
    archive_write_free(writer);
    return rc;
}


static void test(sandbox::Sandbox& sandbox) {
    SecurityBaselineInitialize();
    auto handle = SecurityBaselineMmiOpen("SecurityBaselineTest", 4096);
    if (nullptr == handle)
    {
        std::cerr << "SecurityBaselineMmiOpen failed" << std::endl;
        SecurityBaselineShutdown();
        return;
    }

    char* payload = nullptr;
    int payloadSizeBytes = 0;

    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsurePermissionsOnEtcIssue", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsurePermissionsOnEtcIssueNet", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsurePermissionsOnEtcHostsAllow", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsurePermissionsOnEtcHostsDeny", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsurePermissionsOnEtcSshSshdConfig", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsurePermissionsOnEtcShadow", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsurePermissionsOnEtcShadowDash", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsurePermissionsOnEtcGShadow", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsurePermissionsOnEtcGShadowDash", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsurePermissionsOnEtcPasswd", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsurePermissionsOnEtcPasswdDash", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsurePermissionsOnEtcGroup", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsurePermissionsOnEtcGroupDash", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsurePermissionsOnEtcAnacronTab", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsurePermissionsOnEtcCronD", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsurePermissionsOnEtcCronDaily", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsurePermissionsOnEtcCronHourly", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsurePermissionsOnEtcCronMonthly", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsurePermissionsOnEtcCronWeekly", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsurePermissionsOnEtcMotd", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureInetdNotInstalled", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureXinetdNotInstalled", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureRshServerNotInstalled", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureNisNotInstalled", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureTftpdNotInstalled", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureReadaheadFedoraNotInstalled", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureBluetoothHiddNotInstalled", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureIsdnUtilsBaseNotInstalled", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureIsdnUtilsKdumpToolsNotInstalled", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureIscDhcpdServerNotInstalled", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureSendmailNotInstalled", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureSldapdNotInstalled", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureBind9NotInstalled", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureDovecotCoreNotInstalled", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureAuditdInstalled", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsurePrelinkIsDisabled", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureTalkClientIsNotInstalled", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureCronServiceIsEnabled", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureAuditdServiceIsRunning", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureKernelSupportForCpuNx", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureAllTelnetdPackagesUninstalled", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureNodevOptionOnHomePartition", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureNodevOptionOnTmpPartition", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureNodevOptionOnVarTmpPartition", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureNosuidOptionOnTmpPartition", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureNosuidOptionOnVarTmpPartition", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureNoexecOptionOnVarTmpPartition", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureNoexecOptionOnDevShmPartition", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureNodevOptionEnabledForAllRemovableMedia", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureNoexecOptionEnabledForAllRemovableMedia", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureNosuidOptionEnabledForAllRemovableMedia", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureNoexecNosuidOptionsEnabledForAllNfsMounts", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureAllEtcPasswdGroupsExistInEtcGroup", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureNoDuplicateUidsExist", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureNoDuplicateGidsExist", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureNoDuplicateUserNamesExist", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureNoDuplicateGroupsExist", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureShadowGroupIsEmpty", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureRootGroupExists", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureAllAccountsHavePasswords", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureNonRootAccountsHaveUniqueUidsGreaterThanZero", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureNoLegacyPlusEntriesInEtcPasswd", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureNoLegacyPlusEntriesInEtcShadow", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureNoLegacyPlusEntriesInEtcGroup", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureDefaultRootAccountGroupIsGidZero", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureRootIsOnlyUidZeroAccount", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureAllUsersHomeDirectoriesExist", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureUsersOwnTheirHomeDirectories", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureRestrictedUserHomeDirectories", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsurePasswordHashingAlgorithm", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureMinDaysBetweenPasswordChanges", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureInactivePasswordLockPeriod", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsurePasswordExpiration", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsurePasswordExpirationWarning", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureSystemAccountsAreNonLogin", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureAuthenticationRequiredForSingleUserMode", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureDotDoesNotAppearInRootsPath", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureRemoteLoginWarningBannerIsConfigured", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureLocalLoginWarningBannerIsConfigured", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureSuRestrictedToRootGroup", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureDefaultUmaskForAllUsers", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureAutomountingDisabled", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureKernelCompiledFromApprovedSources", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureDefaultDenyFirewallPolicyIsSet", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsurePacketRedirectSendingIsDisabled", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureIcmpRedirectsIsDisabled", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    // SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureSourceRoutedPacketsIsDisabled", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    // SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureAcceptingSourceRoutedPacketsIsDisabled", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    // SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureIgnoringBogusIcmpBroadcastResponses", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    // SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureIgnoringIcmpEchoPingsToMulticast", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    // SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureMartianPacketLoggingIsEnabled", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    // SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureReversePathSourceValidationIsEnabled", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    // SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureTcpSynCookiesAreEnabled", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureSystemNotActingAsNetworkSniffer", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureAllWirelessInterfacesAreDisabled", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureIpv6ProtocolIsEnabled", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureDccpIsDisabled", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureSctpIsDisabled", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureDisabledSupportForRds", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureTipcIsDisabled", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureZeroconfNetworkingIsDisabled", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsurePermissionsOnBootloaderConfig", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsurePasswordReuseIsLimited", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureMountingOfUsbStorageDevicesIsDisabled", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureCoreDumpsAreRestricted", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsurePasswordCreationRequirements", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureLockoutForFailedPasswordAttempts", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureDisabledInstallationOfCramfsFileSystem", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureDisabledInstallationOfFreevxfsFileSystem", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureDisabledInstallationOfHfsFileSystem", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureDisabledInstallationOfHfsplusFileSystem", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureDisabledInstallationOfJffs2FileSystem", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureVirtualMemoryRandomizationIsEnabled", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureAllBootloadersHavePasswordProtectionEnabled", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureLoggingIsConfigured", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureSyslogPackageIsInstalled", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureSystemdJournaldServicePersistsLogMessages", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureALoggingServiceIsEnabled", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureFilePermissionsForAllRsyslogLogFiles", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureLoggerConfigurationFilesAreRestricted", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureAllRsyslogLogFilesAreOwnedByAdmGroup", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureAllRsyslogLogFilesAreOwnedBySyslogUser", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureRsyslogNotAcceptingRemoteMessages", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureSyslogRotaterServiceIsEnabled", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureTelnetServiceIsDisabled", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureRcprshServiceIsDisabled", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureTftpServiceisDisabled", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureAtCronIsRestrictedToAuthorizedUsers", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureSshPortIsConfigured", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureSshBestPracticeProtocol", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureSshBestPracticeIgnoreRhosts", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureSshLogLevelIsSet", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureSshMaxAuthTriesIsSet", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureAllowUsersIsConfigured", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureDenyUsersIsConfigured", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureAllowGroupsIsConfigured", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureDenyGroupsConfigured", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureSshHostbasedAuthenticationIsDisabled", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureSshPermitRootLoginIsDisabled", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureSshPermitEmptyPasswordsIsDisabled", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureSshClientIntervalCountMaxIsConfigured", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureSshClientAliveIntervalIsConfigured", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureSshLoginGraceTimeIsSet", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureOnlyApprovedMacAlgorithmsAreUsed", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureSshWarningBannerIsEnabled", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureUsersCannotSetSshEnvironmentOptions", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureAppropriateCiphersForSsh", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureAvahiDaemonServiceIsDisabled", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureCupsServiceisDisabled", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsurePostfixPackageIsUninstalled", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsurePostfixNetworkListeningIsDisabled", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureRpcgssdServiceIsDisabled", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureRpcidmapdServiceIsDisabled", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsurePortmapServiceIsDisabled", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureNetworkFileSystemServiceIsDisabled", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureRpcsvcgssdServiceIsDisabled", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureSnmpServerIsDisabled", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureRsynServiceIsDisabled", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureNisServerIsDisabled", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureRshClientNotInstalled", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureSmbWithSambaIsDisabled", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureUsersDotFilesArentGroupOrWorldWritable", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureNoUsersHaveDotForwardFiles", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureNoUsersHaveDotNetrcFiles", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureNoUsersHaveDotRhostsFiles", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureRloginServiceIsDisabled", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);
    SecurityBaselineMmiGet(handle, "SecurityBaseline", "auditEnsureUnnecessaryAccountsAreRemoved", &payload, &payloadSizeBytes); SecurityBaselineMmiFree(payload);

    SecurityBaselineMmiClose(handle);
    SecurityBaselineShutdown();
}

/**
 * @brief Fuzzing entry point
 */
extern "C" int LLVMFuzzerTestOneInput(const std::uint8_t* input, std::size_t size) {
    static auto sandbox = sandbox::Sandbox{};

    auto task = [input, size]() {
        try
        {
            sandbox.reset();
            if (unpack(input, size) != ARCHIVE_OK)
            {
                sandbox.clear();
                /* In case the archive is invalid, fuzzer won't generate new corpus item if we return -1 */
                return -1;
            }

            /* Isolate child process for graceful cleanup */
            auto pid = fork();
            if (pid == -1)
            {
                std::cerr << "Failed to fork: " << strerror(errno) << std::endl;
                sandbox.clear();
                return -1;
            }

            if (pid == 0)
            {
                std::set<int> descriptors;
                for (const auto& entry : fs::directory_iterator("/proc/self/fd"))
                {
                    descriptors.insert(atoi(entry.path().filename().c_str()));
                }

                /*
                 * Invoke the test
                 */
                test(sandbox);

                for (const auto& entry : fs::directory_iterator("/proc/self/fd"))
                {
                    if (std::find(descriptors.begin(), descriptors.end(), atoi(entry.path().filename().c_str())) != descriptors.end())
                    {
                        continue;
                    }

                    char path[PATH_MAX];
                    memset(path, 0, sizeof(path));
                    if (readlink(entry.path().c_str(), path, sizeof(path)) == -1)
                    {
                        std::cerr << "readlink failed: " << strerror(errno) << std::endl;
                        continue;
                    }

                    std::cerr << "Open at exit: " << path << " (" << entry.path() << ")" << std::endl;
                    return EXIT_FAILURE;
                }

                for(const auto& entry : fs::directory_iterator("/tmp"))
                {
                    auto prefix = entry.path().filename().string().substr(0, ::strlen("~osconfig"));
                    std::transform(prefix.begin(), prefix.end(), prefix.begin(), ::tolower);
                    if(prefix == "~osconfig")
                    {
                        std::cerr << "Leftover file found: " << entry.path() << std::endl;
                        return EXIT_FAILURE;
                    }
                }
                return 0;
            }
            else
            {
                // Parent process
                int wstatus = 0;
                if (::waitpid(pid, &wstatus, 0) == -1)
                {
                    std::cerr << "waitpid failed: " << strerror(errno) << std::endl;
                    sandbox.clear();
                    return -1;
                }

                if (!WIFEXITED(wstatus) || 0 != WEXITSTATUS(wstatus))
                {
                    throw ReportFailure("Child process exited abnormally");
                }
            }
        }
        catch (const ReportFailure& e)
        {
            sandbox.clear();
            return EXIT_FAILURE;
        }
        catch (const std::exception& e)
        {
            std::cerr << "Failed to execute test: " << e.what() << std::endl;
            sandbox.clear();
            return -1;
        }

        sandbox.clear();
        return 0;
    };

    try
    {
        auto result = sandbox.exec(task);
        if (result == EXIT_FAILURE)
        {
            throw ReportFailure("Taks process crashed");
        }

        /* Propagate exit code fron the task callback */
        return result;
    }
    catch (const ReportFailure& e)
    {
        /* Fuzzer reports crash here */
        throw;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Failed to execute task: " << e.what() << std::endl;
        /* Avoid creating new inputs */
        return -1;
    }

    /* Possibly new corpus input will be created now */
    return 0;
}
