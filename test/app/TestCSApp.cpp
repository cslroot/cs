#include <array>
#include <cs/app.h>
#include <cs/core.h>
#include <gtest/gtest.h>
#include <stdexcept>

using namespace cs;
using namespace cs::app;

namespace {
int s_argc;
char** s_argv;
}

int
main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  s_argc = argc;
  s_argv = argv;
  return RUN_ALL_TESTS();
}

TEST(TestCSApp, ctorDefault)
{
  // CSApp app;
}

TEST(TestCSApp, ctorWithInstanciate)
{
  auto& app = CSApp::Instance();
  app.Initialize(s_argc, s_argv);
  EXPECT_STRNE(app.Path().c_str(), "");
}
TEST(TestCSApp, Initialize)
{
  auto& app = CSApp::Instance();
  app.Initialize(s_argc, s_argv);
}

TEST(TestCSApp, Documents)
{
  auto& app = CSApp::Instance();
  auto& docs = app.Documents();

  EXPECT_NE(reinterpret_cast<uint64_t>(&docs), 0U);
  EXPECT_EQ(docs.Size(), 0);
}

TEST(TestCSApp, Commands)
{
  auto& app = CSApp::Instance();
  auto& coms = app.Commands();

  EXPECT_NE(reinterpret_cast<uint64_t>(&coms), 0U);
  EXPECT_EQ(coms.Size(), 0);
}

TEST(TestCSApp, Config)
{
  auto& app = CSApp::Instance();
  auto& conf = app.Config();

  EXPECT_NE(reinterpret_cast<uint64_t>(&conf), 0U);
  EXPECT_STRNE(conf.ConfigHomePath().c_str(), "");
}

TEST(TestCSApp, Log)
{
  auto& app = CSApp::Instance();
  auto& log = app.Log();

  EXPECT_NE(reinterpret_cast<uint64_t>(&log), 0U);
}

TEST(TestCSApp, SessionID)
{
  auto& app = CSApp::Instance();
  auto& sid = app.SessionID();

  EXPECT_NE(reinterpret_cast<uint64_t>(&sid), 0U);
  EXPECT_STRNE(sid.ToString().c_str(), "");
}

TEST(TestCSApp, PluginManager)
{
  auto& app = CSApp::Instance();
  auto& plugins = app.PluginManager();

  EXPECT_NE(reinterpret_cast<uint64_t>(&plugins), 0U);
  ASSERT_NO_THROW(plugins.LoadAll(s_argc, s_argv));
}

TEST(TestCSApp, Path)
{
  auto& app = CSApp::Instance();
  app.Initialize(s_argc, s_argv);
  auto apppath = app.Path();

  EXPECT_FALSE(apppath.empty());
}
