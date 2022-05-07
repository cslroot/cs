#include "CSLogger.h"

#include <cs/base/CSString.h>

#include <Poco/ConsoleChannel.h>
#include <Poco/FileChannel.h>
#include <Poco/FormattingChannel.h>
#include <Poco/Logger.h>
#include <Poco/Message.h>
#include <Poco/PatternFormatter.h>
#include <Poco/SplitterChannel.h>

using namespace cs::core;

namespace {

Poco::Logger&
getLogger()
{
  return Poco::Logger::get(Poco::Logger::ROOT);
}

}

#pragma region static
std::unique_ptr<CSLogger>
CSLogger::Create()
{
  auto pLogger = std::make_unique<CSLogger>();
  return pLogger;
}
#pragma endregion static

struct CSLogger::Impl
{
  Poco::Logger* _logger;

  Impl()
  {
    // init poco logger
    Poco::SplitterChannel* pSChannel = new Poco::SplitterChannel();
    pSChannel->addChannel(new Poco::FileChannel("cs.logger.log"));
    pSChannel->addChannel(new Poco::ConsoleChannel);

    Poco::FormattingChannel* pFChannel = new Poco::FormattingChannel(
      new Poco::PatternFormatter("%Y-%m-%d %H:%M:%S.%c %N[%P]:%s:%q:%t"));

    pFChannel->setChannel(pSChannel);

    auto& log = Poco::Logger::create(
      Poco::Logger::ROOT, pFChannel, Poco::Message::PRIO_INFORMATION);
    log.information("logger initialized");
  }

  ~Impl()
  {
    getLogger().information("logger terminated.");
    getLogger().close();
  }
};

#pragma region public

CSLogger::CSLogger()
  : _impl(std::make_unique<Impl>())
{}

CSLogger::~CSLogger() {}

void
CSLogger::Fatal(const cs::base::CSString& message)
{
  getLogger().fatal(message.c_str());
}
void
CSLogger::Critical(const cs::base::CSString& message)
{
  getLogger().critical(message.c_str());
}
void
CSLogger::Error(const cs::base::CSString& message)
{
  getLogger().error(message.c_str());
}
void
CSLogger::Warning(const cs::base::CSString& message)
{
  getLogger().warning(message.c_str());
}
void
CSLogger::Notice(const cs::base::CSString& message)
{
  getLogger().notice(message.c_str());
}
void
CSLogger::Information(const cs::base::CSString& message)
{
  getLogger().information(message.c_str());
}
void
CSLogger::Debug(const cs::base::CSString& message)
{
  getLogger().debug(message.c_str());
}
void
CSLogger::Trace(const cs::base::CSString& message)
{
  getLogger().trace(message.c_str());
}

void
CSLogger::Write(Priority priority, const cs::base::CSString& message)
{
  Poco::Message::Priority prio = (Poco::Message::Priority)((int)priority + 1);
  auto msg = Poco::Message(std::string(""), message.c_str(), prio);
  getLogger().log(msg);
}

#pragma endregion
