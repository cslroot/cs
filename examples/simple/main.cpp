// #include <iostream>

#include <cs/app.h>
#include <cs/base.h>
#include <cs/core.h>
#include <cs/kernel.h>
#include <cs/math.h>
#include <cs/modeler.h>
#include <cs/render.h>

#include <fmt/format.h>

#include <cassert>
#include <filesystem>

using namespace cs;

namespace fs = std::filesystem;

int
main(int argc, char** argv)
{
  auto& app = CSApp::Instance().Initialize(argc, argv);
  auto& log = app.Log();

  // test print logger
  auto printLogs = [&]() {
    log.Fatal("fatal message");
    log.Critical("critical message");
    log.Error("error message");
    log.Warning("warning message");
    log.Notice("notice message");
    log.Information("information message");
    log.Debug("debug message");
    log.Trace("trace message");
  };

  printLogs();

  // config
  auto& conf = app.Config();
  auto confPath = CSConfig::ConfigHomePath();
  log.Information(fmt::format("config path: {}", confPath.c_str()).c_str());
  printLogs();

  conf.Save();

  // session id
  auto strSessionID = app.SessionID().ToString();
  log.Information(strSessionID);
  log.Information(app.SessionID().ToString());

  // plugin
  app.PluginManager().LoadAll(argc, argv);
  {
    auto* pPlugin = app.PluginManager().GetPlugin("Unexpected Plugin name");
    if (pPlugin) {
    }
  }

  auto* pPlugin = app.PluginManager().GetPlugin("SimplePlugin");
  if (pPlugin) {
    log.Information(pPlugin->Name());
  } else {
    log.Information("SimplePlugin not found");
  }

  // document
  assert(nullptr == app.Documents().ActiveDocument());

  auto& doc =
    app.Documents().OpenNewDocument(typeid(cs::app::CSDocument2d).name());
  doc.SaveAs("save.txt.db");
  assert(&doc == app.Documents().ActiveDocument());

  auto& doc2 =
    app.Documents().OpenNewDocument(typeid(cs::app::CSDocument3d).name());
  doc2.SetName(u8"2nd document");
  doc2.SaveAs("doc2.txt");
  assert(&doc != app.Documents().ActiveDocument());
  assert(&doc2 == app.Documents().ActiveDocument());

  log.Information("document saved");

  size_t i = app.Documents().Size();
  std::cout << i << std::endl;

  cs::base::CSString str;
  str += u8"message";
  str += u8"-append message";
  std::cout << str << std::endl;

  cs::math::CSVec3d v3d;
  cs::math::CSVec3d v3d2({ 1.0, 2.0, 3.0 });
  cs::math::CSVec3d v3d3({ 1.0, 2.0, 3.0 });
  v3d += v3d2;
  v3d += v3d3;
  std::cout << v3d.x << std::endl;
  std::cout << v3d.y << std::endl;
  std::cout << v3d.z << std::endl;

  auto& modeler = doc.Modeler();
  auto& box = modeler.CreateBox({ { 0.0, 0.0, 0.0 } }, { { 1.0, 1.0, 0.0 } });
  auto* mat = CS_NEW cs::render::BasicMaterial({ 1.0, 0.0, 0.0 });

  auto scene = std::make_unique<cs::render::Scene>();
  auto camera = std::make_unique<cs::render::PerspectiveCamera>();
  auto renderer = std::make_unique<cs::render::EmptyRenderer>();

  auto cube = std::make_unique<cs::render::Mesh>(box, *mat);
  scene->Add(std::move(cube));

  // render only once
  renderer->Render(*scene, *camera);

  return 0;
}
