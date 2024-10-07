#include "sandbox.hpp"

#include <filesystem>
#include <iostream>
#include <gtest/gtest.h>
#include <version.h>
#include <Mmi.h>
#include <CommonUtils.h>
#include <SecurityBaseline.h>
#include <fstream>

namespace fs = std::filesystem;

class SecurityBaselineTest : public ::testing::Test
{
public:
    sandbox::Sandbox m_sandbox;
    MMI_HANDLE m_handle = nullptr;

    void SetUp() override
    {
        m_sandbox.reset();
        /* Temporary, for some reason SecurityBaselineInitialize() makes a copy of /etc/fstab at the very beginning */
        createFile("/etc/fstab", "This is a test file\n");
        SecurityBaselineInitialize();

        m_handle = SecurityBaselineMmiOpen("SecurityBaselineTest", 1024);
        ASSERT_NE(nullptr, m_handle);
    }

    void TearDown() override
    {
        SecurityBaselineShutdown();
    }

    void createFile(fs::path path, const std::string& content, fs::perms mode = fs::perms::owner_read | fs::perms::owner_write | fs::perms::group_read | fs::perms::others_read)
    {
        path = m_sandbox.getRootfs() / path;
        if (!fs::exists(path.parent_path()))
            ASSERT_TRUE(fs::create_directories(path.parent_path()));
        std::ofstream file{ path };
        file << content;
        file.close();

        fs::permissions(path, mode, fs::perm_options::replace);
    }
};

TEST_F(SecurityBaselineTest, auditEnsurePermissionsOnEtcIssue_NoEtcIssue)
{
    char* payload = nullptr;
    int payloadSizeBytes = 0;

    EXPECT_EQ(MMI_OK, SecurityBaselineMmiGet(m_handle, "SecurityBaseline", "auditEnsurePermissionsOnEtcIssue", &payload, &payloadSizeBytes));
    ASSERT_NE(nullptr, payload);
    ASSERT_NE(0, payloadSizeBytes);

    EXPECT_EQ(std::string{ payload }, std::string{ "\"PASS\'\\/etc\\/issue\' is not found, nothing to check\"" });

    SecurityBaselineMmiFree(payload);
}

TEST_F(SecurityBaselineTest, auditEnsurePermissionsOnEtcIssue_CompliantEtcIssue)
{
    char* payload = nullptr;
    int payloadSizeBytes = 0;

    createFile("/etc/issue", "This is a test file\n");
    EXPECT_EQ(MMI_OK, SecurityBaselineMmiGet(m_handle, "SecurityBaseline", "auditEnsurePermissionsOnEtcIssue", &payload, &payloadSizeBytes));
    ASSERT_NE(nullptr, payload);
    ASSERT_NE(0, payloadSizeBytes);

    EXPECT_EQ(std::string{ payload }, std::string{ "\"PASS\'\\/etc\\/issue\' has required access (644) and ownership (uid: 0, gid: 0)\"" });

    SecurityBaselineMmiFree(payload);
}

TEST_F(SecurityBaselineTest, auditEnsurePermissionsOnEtcIssue_NonCompliantEtcIssue)
{
    char* payload = nullptr;
    int payloadSizeBytes = 0;

    createFile("/etc/issue", "This is a test file\n", fs::perms::owner_read | fs::perms::owner_write | fs::perms::group_read | fs::perms::group_write | fs::perms::others_read);
    EXPECT_EQ(MMI_OK, SecurityBaselineMmiGet(m_handle, "SecurityBaseline", "auditEnsurePermissionsOnEtcIssue", &payload, &payloadSizeBytes));
    ASSERT_NE(nullptr, payload);
    ASSERT_NE(0, payloadSizeBytes);

    EXPECT_EQ(std::string{ payload }, std::string{ "\"Access to '\\/etc\\/issue' (664) does not match expected (644)\"" });

    SecurityBaselineMmiFree(payload);
}

TEST_F(SecurityBaselineTest, remediateEnsurePermissionsOnEtcIssue_NoEtcIssue)
{
    EXPECT_EQ(MMI_OK, SecurityBaselineMmiSet(m_handle, "SecurityBaseline", "remediateEnsurePermissionsOnEtcIssue", NULL, 0));
    EXPECT_FALSE(fs::exists("/etc/issue"));
}

TEST_F(SecurityBaselineTest, remediateEnsurePermissionsOnEtcIssue_CompliantEtcIssue)
{
    createFile("/etc/issue", "This is a test file\n");
    EXPECT_EQ(MMI_OK, SecurityBaselineMmiSet(m_handle, "SecurityBaseline", "remediateEnsurePermissionsOnEtcIssue", NULL, 0));
    ASSERT_TRUE(fs::exists("/etc/issue"));
    auto status = fs::status("/etc/issue");
    ASSERT_TRUE(status.permissions() == (fs::perms::owner_read | fs::perms::owner_write | fs::perms::group_read | fs::perms::others_read));
}

TEST_F(SecurityBaselineTest, remediateEnsurePermissionsOnEtcIssue_NonCompliantEtcIssue)
{
    createFile("/etc/issue", "This is a test file\n", fs::perms::owner_read | fs::perms::owner_write | fs::perms::group_read | fs::perms::group_write | fs::perms::others_read);
    EXPECT_EQ(MMI_OK, SecurityBaselineMmiSet(m_handle, "SecurityBaseline", "remediateEnsurePermissionsOnEtcIssue", NULL, 0));
    ASSERT_TRUE(fs::exists("/etc/issue"));
    auto status = fs::status("/etc/issue");
    ASSERT_TRUE(status.permissions() == (fs::perms::owner_read | fs::perms::owner_write | fs::perms::group_read | fs::perms::others_read));
}

int main(int argc, char** argv) {
    sandbox::Sandbox sandbox;
    auto task = [&]() -> int
        {
            testing::InitGoogleTest(&argc, argv);
            return RUN_ALL_TESTS();
        };

    return sandbox.exec(std::move(task));
}