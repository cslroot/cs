#include <iostream>

#include <cs/app.h>
#include <cs/base.h>
#include <cs/core.h>
#include <cs/kernel.h>
#include <cs/math.h>
#include <cs/modeler.h>
#include <cs/render.h>

#include <fmt/format.h>

#include <cassert>

using namespace cs::app;
using namespace cs::base;
using namespace cs::core;

int
main(int argc, char** argv)
{

  auto pmyapp = std::make_unique<cs::app::CSApp>(argc, argv);
  auto& app = *pmyapp;
  auto& log = app.Log();

  // test print logger
  log.Fatal("fatal message");
  log.Critical("critial message");
  log.Error("error message");
  log.Warning("warning message");
  log.Notice("notice message");
  log.Information("information message");
  log.Debug("debug message");
  log.Trace("trace message");

  // config
  auto confPath = app.Config().ConfigHomePath();
  log.Information(fmt::format("config path: {}", confPath.c_str()).c_str());

  // session id
  auto strSessionID = app.SessionID().ToString();
  log.Information(strSessionID);
  log.Information(app.SessionID().ToString());

  assert(nullptr == app.Documents().ActiveDocument());

  auto& doc =
    app.Documents().OpenNewDocument(typeid(cs::app::CSDocument3d).name());
  doc.SaveAs("save.txt.db");
  assert(&doc == app.Documents().ActiveDocument());

  auto& doc2 =
    app.Documents().OpenNewDocument(typeid(cs::app::CSDocument3d).name());
  doc2.SetName(u8"2nd document");
  doc2.SaveAs("doc2.txt");
  assert(&doc != app.Documents().ActiveDocument());
  assert(&doc2 == app.Documents().ActiveDocument());

  std::cout << "document saved" << std::endl;

  size_t i = app.Documents().Size();
  std::cout << i << std::endl;

  cs::base::CSString str;
  str += u8"hoge";
  str += u8"fuga";
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
  auto mat = CS_NEW cs::render::BasicMaterial({ 1.0, 0.0, 0.0 });

  auto scene = CS_NEW cs::render::Scene();
  auto camera = CS_NEW cs::render::PerspectiveCamera();
  auto renderer = CS_NEW cs::render::EmptyRenderer();

  auto cube = new cs::render::Mesh(box, *mat);
  scene->Add(cube);

  bool stop = false;
  while (stop) {
    renderer->Render(*scene, *camera);
    stop = true;
  }

  std::cout << str.c_str() << std::endl;
}
