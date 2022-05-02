#include "CSConfig.h"

#include <cs/base.h>

#include <Poco/Path.h>
#include <Poco/Util/AbstractConfiguration.h>
#include <Poco/Util/JSONConfiguration.h>

using namespace cs::core;

struct CSConfig::Impl
{
  Impl()
    : _config(new Poco::Util::JSONConfiguration)
  {}

  Poco::AutoPtr<Poco::Util::JSONConfiguration> _config;
};

CSConfig::CSConfig()
  : _impl(std::make_unique<Impl>())
{
  _impl->_config->setInt("version", 20220201);
  _impl->_config->setString("loglevel", "default");
  _impl->_config->setString("mouse_mode", "default");
}

CSConfig::~CSConfig() {}

void
CSConfig::SetValue(const cs::base::CSString& key, bool bValue)
{
  _impl->_config->setBool(key.c_str(), bValue);
}
void
CSConfig::SetValue(const cs::base::CSString& key, int iValue)
{
  _impl->_config->setInt(key.c_str(), iValue);
}
void
CSConfig::SetValue(const cs::base::CSString& key, double dValue)
{
  _impl->_config->setDouble(key.c_str(), dValue);
}

void
CSConfig::SetValue(const cs::base::CSString& key,
                   const cs::base::CSString& strValue)
{
  _impl->_config->setString(key.c_str(), strValue.c_str());
}

template<typename T>
T
CSConfig::GetValue(const cs::base::CSString& key) const
{}

template<>
bool
CSConfig::GetValue<bool>(const cs::base::CSString& key) const
{
  return _impl->_config->getBool(key.c_str());
}

template<>
int
CSConfig::GetValue<int>(const cs::base::CSString& key) const
{
  return _impl->_config->getInt(key.c_str());
}

template<>
double
CSConfig::GetValue<double>(const cs::base::CSString& key) const
{
  return _impl->_config->getDouble(key.c_str());
}
template<>
cs::base::CSString
CSConfig::GetValue<cs::base::CSString>(const cs::base::CSString& key) const
{
  return _impl->_config->getString(key.c_str());
}

//----- static ----
cs::base::CSString
CSConfig::ConfigHomePath()
{
  return Poco::Path::configHome().c_str();
}
