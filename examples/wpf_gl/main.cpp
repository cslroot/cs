#include <iostream>

#include <cs/base.h>
#include <cs/core.h>
#include <cs/render.h>
#include <cs/modeler.h>
#include <cs/app.h>

int main(int argc, char** argv)
{
    auto pmyapp = std::make_unique<cs::app::CSApp>(argc, argv);
    auto& app = *pmyapp;

    auto& doc = app.Documents().OpenNewDocument(typeid(cs::app::CSDocument3d).name());
    doc.SaveAs("save.txt");

    std::cout << "document saved" << std::endl;

    size_t i = app.Documents().Size();
    std::cout << i << std::endl;

    cs::base::CSString str;
    str += u8"hoge";
    str += u8"fuga";
    std::cout << str << std::endl;

    cs::base::CSVec3d v3d;
    cs::base::CSVec3d v3d2(1, 2, 3);
    cs::base::CSVec3d v3d3(1, 2, 3);
    v3d += v3d2;
    v3d += v3d3;
    std::cout << v3d.x << std::endl;
    std::cout << v3d.y << std::endl;
    std::cout << v3d.z << std::endl;

    auto& modeler = doc.Modeler();
    auto& box = modeler.CreateBox({ 0,0,0 }, { 1,1,1 });
    auto mat = CS_NEW cs::render::BasicMaterial({ 1.0, 0.0, 0.0 });

    auto scene = CS_NEW cs::render::Scene();
    auto camera = CS_NEW cs::render::PerspectiveCamera();
    auto renderer = CS_NEW cs::render::GLRenderer();

    auto cube = CS_NEW cs::render::Mesh(box, *mat);
    scene->Add(cube);

    bool stop = false;
    while (stop)
    {
        renderer->Render(*scene, *camera);
        stop = true;
    }

    std::cout << str.c_str() << std::endl;
}
