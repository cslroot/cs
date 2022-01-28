#include <iostream>

#include <cs/base.h>
#include <cs/core.h>
#include <cs/app.h>

int main(int argc, char** argv)
{
    auto pmyapp = std::make_unique<cs::app::CSApp>(argc, argv);
    auto& app = *pmyapp;

    auto& doc = app.OpenNewDocument();
    doc.SaveAs("save.doc");

    auto& doc2 = app.OpenNewDocument();

    size_t i = app.Documents().Size();
    std::cout << i << std::endl;

    cs::base::CSString str;
    str += u8"hoge";


    cs::base::CSVec3d v3d;
    cs::base::CSVec3d v3d2(1, 2, 3);
    cs::base::CSVec3d v3d3(1, 2, 3);
    v3d += v3d2;
    v3d += v3d3;
    std::cout << v3d.x << std::endl;
    std::cout << v3d.y << std::endl;
    std::cout << v3d.z << std::endl;

    std::cout << str.c_str() << std::endl;
}
