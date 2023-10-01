
#include "LoggingIntervalNrMdt_anyOf.h"
#include "Helpers.h"
#include <stdexcept>
#include <sstream>

namespace ngkore::model::common {

LoggingIntervalNrMdt_anyOf::LoggingIntervalNrMdt_anyOf() {}

void LoggingIntervalNrMdt_anyOf::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool LoggingIntervalNrMdt_anyOf::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool LoggingIntervalNrMdt_anyOf::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "LoggingIntervalNrMdt_anyOf" : pathPrefix;

  if (m_value == LoggingIntervalNrMdt_anyOf::eLoggingIntervalNrMdt_anyOf::
                     INVALID_VALUE_OPENAPI_GENERATED) {
    success = false;
    msg << _pathPrefix << ": has no value;";
  }

  return success;
}

bool LoggingIntervalNrMdt_anyOf::operator==(
    const LoggingIntervalNrMdt_anyOf& rhs) const {
  return getValue() == rhs.getValue()

      ;
}

bool LoggingIntervalNrMdt_anyOf::operator!=(
    const LoggingIntervalNrMdt_anyOf& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const LoggingIntervalNrMdt_anyOf& o) {
  j = nlohmann::json();

  switch (o.getValue()) {
    case LoggingIntervalNrMdt_anyOf::eLoggingIntervalNrMdt_anyOf::
        INVALID_VALUE_OPENAPI_GENERATED:
      j = "INVALID_VALUE_OPENAPI_GENERATED";
      break;
    case LoggingIntervalNrMdt_anyOf::eLoggingIntervalNrMdt_anyOf::_128:
      j = "128";
      break;
    case LoggingIntervalNrMdt_anyOf::eLoggingIntervalNrMdt_anyOf::_256:
      j = "256";
      break;
    case LoggingIntervalNrMdt_anyOf::eLoggingIntervalNrMdt_anyOf::_512:
      j = "512";
      break;
    case LoggingIntervalNrMdt_anyOf::eLoggingIntervalNrMdt_anyOf::_1024:
      j = "1024";
      break;
    case LoggingIntervalNrMdt_anyOf::eLoggingIntervalNrMdt_anyOf::_2048:
      j = "2048";
      break;
    case LoggingIntervalNrMdt_anyOf::eLoggingIntervalNrMdt_anyOf::_3072:
      j = "3072";
      break;
    case LoggingIntervalNrMdt_anyOf::eLoggingIntervalNrMdt_anyOf::_4096:
      j = "4096";
      break;
    case LoggingIntervalNrMdt_anyOf::eLoggingIntervalNrMdt_anyOf::_6144:
      j = "6144";
      break;
    case LoggingIntervalNrMdt_anyOf::eLoggingIntervalNrMdt_anyOf::_320:
      j = "320";
      break;
    case LoggingIntervalNrMdt_anyOf::eLoggingIntervalNrMdt_anyOf::_640:
      j = "640";
      break;
    case LoggingIntervalNrMdt_anyOf::eLoggingIntervalNrMdt_anyOf::INFINITY:
      j = "infinity";
      break;
  }
}

void from_json(const nlohmann::json& j, LoggingIntervalNrMdt_anyOf& o) {
  auto s = j.get<std::string>();
  if (s == "128") {
    o.setValue(LoggingIntervalNrMdt_anyOf::eLoggingIntervalNrMdt_anyOf::_128);
  } else if (s == "256") {
    o.setValue(LoggingIntervalNrMdt_anyOf::eLoggingIntervalNrMdt_anyOf::_256);
  } else if (s == "512") {
    o.setValue(LoggingIntervalNrMdt_anyOf::eLoggingIntervalNrMdt_anyOf::_512);
  } else if (s == "1024") {
    o.setValue(LoggingIntervalNrMdt_anyOf::eLoggingIntervalNrMdt_anyOf::_1024);
  } else if (s == "2048") {
    o.setValue(LoggingIntervalNrMdt_anyOf::eLoggingIntervalNrMdt_anyOf::_2048);
  } else if (s == "3072") {
    o.setValue(LoggingIntervalNrMdt_anyOf::eLoggingIntervalNrMdt_anyOf::_3072);
  } else if (s == "4096") {
    o.setValue(LoggingIntervalNrMdt_anyOf::eLoggingIntervalNrMdt_anyOf::_4096);
  } else if (s == "6144") {
    o.setValue(LoggingIntervalNrMdt_anyOf::eLoggingIntervalNrMdt_anyOf::_6144);
  } else if (s == "320") {
    o.setValue(LoggingIntervalNrMdt_anyOf::eLoggingIntervalNrMdt_anyOf::_320);
  } else if (s == "640") {
    o.setValue(LoggingIntervalNrMdt_anyOf::eLoggingIntervalNrMdt_anyOf::_640);
  } else if (s == "infinity") {
    o.setValue(
        LoggingIntervalNrMdt_anyOf::eLoggingIntervalNrMdt_anyOf::INFINITY);
  } else {
    std::stringstream ss;
    ss << "Unexpected value " << s << " in json"
       << " cannot be converted to enum of type"
       << " LoggingIntervalNrMdt_anyOf::eLoggingIntervalNrMdt_anyOf";
    throw std::invalid_argument(ss.str());
  }
}

LoggingIntervalNrMdt_anyOf::eLoggingIntervalNrMdt_anyOf
LoggingIntervalNrMdt_anyOf::getValue() const {
  return m_value;
}
void LoggingIntervalNrMdt_anyOf::setValue(
    LoggingIntervalNrMdt_anyOf::eLoggingIntervalNrMdt_anyOf value) {
  m_value = value;
}

}  // namespace ngkore::model::common
