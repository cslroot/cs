#include "CSDocument.h"

#include <cs/base.h>
#include <cs/core.h>
#include <cs/modeler.h>

#include <fstream>

// #include <filesystem>
// using fs = std::filesystem;

using namespace cs::app;
using namespace cs::base;
using namespace cs::modeler;

struct CSDocument::Impl
{
  CSString _name;
  CSString _filepath;

  cs::modeler::CSModeler _modeler;
};

CSDocument::CSDocument(Key)
  : _impl(std::make_unique<Impl>())
{}

CSDocument::~CSDocument() {}

void
CSDocument::SaveAs(const cs::base::CSString& filepath)
{
  std::ofstream ofs(filepath.c_str());
  ofs << "hoge" << std::endl;
  // ofs << "name: " << Name() << std::endl;
  ofs.close();

  _impl->_filepath = filepath;
}

cs::modeler::CSModeler&
CSDocument::Modeler() const
{
  return _impl->_modeler;
}
