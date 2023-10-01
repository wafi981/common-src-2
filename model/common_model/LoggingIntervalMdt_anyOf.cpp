
#include "LoggingIntervalMdt_anyOf.h"
#include "Helpers.h"
#include <stdexcept>
#include <sstream>

namespace ngkore::model::common {

LoggingIntervalMdt_anyOf::LoggingIntervalMdt_anyOf() {}

void LoggingIntervalMdt_anyOf::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool LoggingIntervalMdt_anyOf::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool LoggingIntervalMdt_anyOf::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "LoggingIntervalMdt_anyOf" : pathPrefix;

  if (m_value == LoggingIntervalMdt_anyOf::eLoggingIntervalMdt_anyOf::
                     INVALID_VALUE_OPENAPI_GENERATED) {
    success = false;
    msg << _pathPrefix << ": has no value;";
  }

  return success;
}

bool LoggingIntervalMdt_anyOf::operator==(
    const LoggingIntervalMdt_anyOf& rhs) const {
  return getValue() == rhs.getValue()

      ;
}

bool LoggingIntervalMdt_anyOf::operator!=(
    const LoggingIntervalMdt_anyOf& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const LoggingIntervalMdt_anyOf& o) {
  j = nlohmann::json();

  switch (o.getValue()) {
    case LoggingIntervalMdt_anyOf::eLoggingIntervalMdt_anyOf::
        INVALID_VALUE_OPENAPI_GENERATED:
      j = "INVALID_VALUE_OPENAPI_GENERATED";
      break;
    case LoggingIntervalMdt_anyOf::eLoggingIntervalMdt_anyOf::_128:
      j = "128";
      break;
    case LoggingIntervalMdt_anyOf::eLoggingIntervalMdt_anyOf::_256:
      j = "256";
      break;
    case LoggingIntervalMdt_anyOf::eLoggingIntervalMdt_anyOf::_512:
      j = "512";
      break;
    case LoggingIntervalMdt_anyOf::eLoggingIntervalMdt_anyOf::_1024:
      j = "1024";
      break;
    case LoggingIntervalMdt_anyOf::eLoggingIntervalMdt_anyOf::_2048:
      j = "2048";
      break;
    case LoggingIntervalMdt_anyOf::eLoggingIntervalMdt_anyOf::_3072:
      j = "3072";
      break;
    case LoggingIntervalMdt_anyOf::eLoggingIntervalMdt_anyOf::_4096:
      j = "4096";
      break;
    case LoggingIntervalMdt_anyOf::eLoggingIntervalMdt_anyOf::_6144:
      j = "6144";
      break;
  }
}

void from_json(const nlohmann::json& j, LoggingIntervalMdt_anyOf& o) {
  auto s = j.get<std::string>();
  if (s == "128") {
    o.setValue(LoggingIntervalMdt_anyOf::eLoggingIntervalMdt_anyOf::_128);
  } else if (s == "256") {
    o.setValue(LoggingIntervalMdt_anyOf::eLoggingIntervalMdt_anyOf::_256);
  } else if (s == "512") {
    o.setValue(LoggingIntervalMdt_anyOf::eLoggingIntervalMdt_anyOf::_512);
  } else if (s == "1024") {
    o.setValue(LoggingIntervalMdt_anyOf::eLoggingIntervalMdt_anyOf::_1024);
  } else if (s == "2048") {
    o.setValue(LoggingIntervalMdt_anyOf::eLoggingIntervalMdt_anyOf::_2048);
  } else if (s == "3072") {
    o.setValue(LoggingIntervalMdt_anyOf::eLoggingIntervalMdt_anyOf::_3072);
  } else if (s == "4096") {
    o.setValue(LoggingIntervalMdt_anyOf::eLoggingIntervalMdt_anyOf::_4096);
  } else if (s == "6144") {
    o.setValue(LoggingIntervalMdt_anyOf::eLoggingIntervalMdt_anyOf::_6144);
  } else {
    std::stringstream ss;
    ss << "Unexpected value " << s << " in json"
       << " cannot be converted to enum of type"
       << " LoggingIntervalMdt_anyOf::eLoggingIntervalMdt_anyOf";
    throw std::invalid_argument(ss.str());
  }
}

LoggingIntervalMdt_anyOf::eLoggingIntervalMdt_anyOf
LoggingIntervalMdt_anyOf::getValue() const {
  return m_value;
}
void LoggingIntervalMdt_anyOf::setValue(
    LoggingIntervalMdt_anyOf::eLoggingIntervalMdt_anyOf value) {
  m_value = value;
}

}  // namespace ngkore::model::common
