#include <iostream>
#include <memory>

#include <cs/app.h>
#include <cs/base.h>
#include <cs/core.h>
#include <cs/kernel.h>
#include <cs/math.h>
#include <cs/modeler.h>
#include <cs/render.h>

using namespace cs::core;
using namespace cs::kernel;

int
main(int argc, char** argv)
{
  std::locale::global(std::locale(
#if _WIN32 && !__MINGW32__ && !__CYGWIN__
    ".UTF-8"
#else
    ""
#endif
    ));

  auto& app = cs::app::CSApp::Create(argc, argv);
  auto& doc = dynamic_cast<cs::app::CSDocument2d&>(
    app.Documents().OpenNewDocument(typeid(cs::app::CSDocument2d).name()));

  auto scene = std::make_unique<cs::render::Scene>();
  auto camera = std::make_unique<cs::render::PerspectiveCamera>();

  cs::math::CSVec2d p1 = { { 0.0, 0.0 } };
  cs::math::CSVec2d p2 = { { 1.0, 1.0 } };

  cs::base::CSColor color = { 1.0, 1.0, 0.0 };
  auto mat = std::make_unique<cs::render::DrawingMaterial>(color);

  // line
  auto line = std::make_unique<cs::kernel::Segment2d>(p1, p2);
  line->Property().SetColor(color);
  auto lineObj =
    std::make_unique<cs::render::CSDisplayableObject2d>(*line, *mat);
  scene->Add(std::move(lineObj));

  // circle
  auto circle = std::make_unique<cs::kernel::Circle2d>(p1, 0.4);
  auto circleObj =
    std::make_unique<cs::render::CSDisplayableObject2d>(*circle, *mat);
  scene->Add(std::move(circleObj));

  auto renderer = std::make_unique<cs::render::GLFWRenderer>();
  renderer->Init();

  while (!renderer->WindowShouldClose()) {
    renderer->Render(*scene, *camera);
  }

  exit(EXIT_SUCCESS);
}
