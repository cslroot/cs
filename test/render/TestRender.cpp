#include <cs/app.h>
#include <cs/base.h>
#include <cs/core.h>
#include <cs/kernel.h>
#include <cs/math.h>
#include <cs/modeler.h>
#include <cs/render.h>

#include <gtest/gtest.h>

#include <array>
#include <memory>
#include <stdexcept>

using namespace cs;
using namespace cs::render;
using namespace cs::math;

TEST(TestRender, ctorDefault)
{
  auto mat = cs::render::BasicMaterial({ 1.0, 0.0, 0.0 });

  auto scene = std::make_unique<cs::render::Scene>();
  auto camera = std::make_unique<cs::render::PerspectiveCamera>();
  auto renderer = std::make_unique<cs::render::EmptyRenderer>();

  cs::app::CSDocument2d doc("testRender");
  auto& modeler = doc.Modeler();
  auto& box = modeler.CreateBox({ { 0.0, 0.0, 0.0 } }, { { 1.0, 1.0, 0.0 } });
  auto cube = std::make_unique<cs::render::Mesh>(box, mat);
  scene->Add(std::move(cube));

  // render only once
  renderer->Render(*scene, *camera);
}
