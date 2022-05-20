#include "CSDocument2d.h"

using namespace cs::app;

CSDocument2d::CSDocument2d(const cs::base::CSString& docName) {}

CSDocument2d::~CSDocument2d() = default;

cs::base::CSString
CSDocument2d::TypeName() const
{
  return "CSDocument2d";
}
