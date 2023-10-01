
#include "LoggingDurationMdt_anyOf.h"
#include "Helpers.h"
#include <stdexcept>
#include <sstream>

namespace ngkore::model::common {

LoggingDurationMdt_anyOf::LoggingDurationMdt_anyOf() {}

void LoggingDurationMdt_anyOf::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool LoggingDurationMdt_anyOf::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool LoggingDurationMdt_anyOf::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "LoggingDurationMdt_anyOf" : pathPrefix;

  if (m_value == LoggingDurationMdt_anyOf::eLoggingDurationMdt_anyOf::
                     INVALID_VALUE_OPENAPI_GENERATED) {
    success = false;
    msg << _pathPrefix << ": has no value;";
  }

  return success;
}

bool LoggingDurationMdt_anyOf::operator==(
    const LoggingDurationMdt_anyOf& rhs) const {
  return getValue() == rhs.getValue()

      ;
}

bool LoggingDurationMdt_anyOf::operator!=(
    const LoggingDurationMdt_anyOf& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const LoggingDurationMdt_anyOf& o) {
  j = nlohmann::json();

  switch (o.getValue()) {
    case LoggingDurationMdt_anyOf::eLoggingDurationMdt_anyOf::
        INVALID_VALUE_OPENAPI_GENERATED:
      j = "INVALID_VALUE_OPENAPI_GENERATED";
      break;
    case LoggingDurationMdt_anyOf::eLoggingDurationMdt_anyOf::_600:
      j = "600";
      break;
    case LoggingDurationMdt_anyOf::eLoggingDurationMdt_anyOf::_1200:
      j = "1200";
      break;
    case LoggingDurationMdt_anyOf::eLoggingDurationMdt_anyOf::_2400:
      j = "2400";
      break;
    case LoggingDurationMdt_anyOf::eLoggingDurationMdt_anyOf::_3600:
      j = "3600";
      break;
    case LoggingDurationMdt_anyOf::eLoggingDurationMdt_anyOf::_5400:
      j = "5400";
      break;
    case LoggingDurationMdt_anyOf::eLoggingDurationMdt_anyOf::_7200:
      j = "7200";
      break;
  }
}

void from_json(const nlohmann::json& j, LoggingDurationMdt_anyOf& o) {
  auto s = j.get<std::string>();
  if (s == "600") {
    o.setValue(LoggingDurationMdt_anyOf::eLoggingDurationMdt_anyOf::_600);
  } else if (s == "1200") {
    o.setValue(LoggingDurationMdt_anyOf::eLoggingDurationMdt_anyOf::_1200);
  } else if (s == "2400") {
    o.setValue(LoggingDurationMdt_anyOf::eLoggingDurationMdt_anyOf::_2400);
  } else if (s == "3600") {
    o.setValue(LoggingDurationMdt_anyOf::eLoggingDurationMdt_anyOf::_3600);
  } else if (s == "5400") {
    o.setValue(LoggingDurationMdt_anyOf::eLoggingDurationMdt_anyOf::_5400);
  } else if (s == "7200") {
    o.setValue(LoggingDurationMdt_anyOf::eLoggingDurationMdt_anyOf::_7200);
  } else {
    std::stringstream ss;
    ss << "Unexpected value " << s << " in json"
       << " cannot be converted to enum of type"
       << " LoggingDurationMdt_anyOf::eLoggingDurationMdt_anyOf";
    throw std::invalid_argument(ss.str());
  }
}

LoggingDurationMdt_anyOf::eLoggingDurationMdt_anyOf
LoggingDurationMdt_anyOf::getValue() const {
  return m_value;
}
void LoggingDurationMdt_anyOf::setValue(
    LoggingDurationMdt_anyOf::eLoggingDurationMdt_anyOf value) {
  m_value = value;
}

}  // namespace ngkore::model::common