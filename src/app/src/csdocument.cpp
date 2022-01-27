#include "csdocument.h"

#include <cs/base.h>

#include <fstream>

// #include <filesystem>
// using fs = std::filesystem;

using namespace cs::app;
using namespace cs::base;

struct CSDocument::Impl
{
    CSString _name;
    CSString _filepath;
};

CSDocument::CSDocument()
    : _impl(std::make_unique<Impl>())
{}

CSDocument::~CSDocument()
{}

void CSDocument::SaveAs(const cs::base::CSString& filepath)
{
    std::ofstream ofs(filepath.c_str());
    ofs << "hoge" << std::endl;
    ofs.close();

    _impl->_filepath = filepath;
}
