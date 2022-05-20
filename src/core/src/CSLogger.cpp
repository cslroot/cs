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

namespace {}

#pragma region static
// std::unique_ptr<CSLogger>
// CSLogger::Create()
// {
//   auto pLogger = std::make_unique<CSLogger>();
//   return pLogger;
// }
#pragma endregion static

struct CSLogger::Impl
{
  Poco::Logger* _logger;

  Impl(const Impl&) = delete;
  const Impl& operator=(const Impl&) = delete;
  Impl()
  {
    // init poco logger
    auto* pSChannel = new Poco::SplitterChannel();
    pSChannel->addChannel(new Poco::FileChannel("cs.logger.log"));
    pSChannel->addChannel(new Poco::ConsoleChannel);

    auto* pFChannel = new Poco::FormattingChannel(
      new Poco::PatternFormatter("%Y-%m-%d %H:%M:%S.%c %N[%P]:%s:%q: %t"));

    pFChannel->setChannel(pSChannel);

    auto& log = Poco::Logger::create(
      Poco::Logger::ROOT, pFChannel, Poco::Message::PRIO_INFORMATION);
    log.information("logger initialized");
    _logger = &log;
  }

  ~Impl()
  {
    _logger->information("logger terminated.");
    _logger->close();
  }
};

#pragma region public

CSLogger::CSLogger()
  : _impl(std::make_unique<Impl>())
{}

CSLogger::~CSLogger() = default;

void
CSLogger::SetLevel(const cs::base::CSString& level)
{
  _impl->_logger->setLevel(level.c_str());
}
void
CSLogger::SetLevel(const Priority& level)
{
  _impl->_logger->setLevel(static_cast<int>(level));
}

void
CSLogger::Fatal(const cs::base::CSString& message)
{
  _impl->_logger->fatal(message.c_str());
}
void
CSLogger::Critical(const cs::base::CSString& message)
{
  _impl->_logger->critical(message.c_str());
}
void
CSLogger::Error(const cs::base::CSString& message)
{
  _impl->_logger->error(message.c_str());
}
void
CSLogger::Warning(const cs::base::CSString& message)
{
  _impl->_logger->warning(message.c_str());
}
void
CSLogger::Notice(const cs::base::CSString& message)
{
  _impl->_logger->notice(message.c_str());
}
void
CSLogger::Information(const cs::base::CSString& message)
{
  _impl->_logger->information(message.c_str());
}
void
CSLogger::Debug(const cs::base::CSString& message)
{
  _impl->_logger->debug(message.c_str());
}
void
CSLogger::Trace(const cs::base::CSString& message)
{
  _impl->_logger->trace(message.c_str());
}

void
CSLogger::Write(Priority priority, const cs::base::CSString& message)
{
  auto prio = static_cast<Poco::Message::Priority>((int)priority + 1);
  auto msg = Poco::Message(std::string(""), message.c_str(), prio);
  _impl->_logger->log(msg);
}

#pragma endregion
