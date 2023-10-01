
#include "LoggingDurationMdt.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

LoggingDurationMdt::LoggingDurationMdt() {}

void LoggingDurationMdt::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool LoggingDurationMdt::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool LoggingDurationMdt::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "LoggingDurationMdt" : pathPrefix;

  if (!m_value.validate(msg)) {
    success = false;
  }
  return success;
}

bool LoggingDurationMdt::operator==(const LoggingDurationMdt& rhs) const {
  return

      getValue() == rhs.getValue();
}

bool LoggingDurationMdt::operator!=(const LoggingDurationMdt& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const LoggingDurationMdt& o) {
  j = nlohmann::json();
  to_json(j, o.m_value);
}

void from_json(const nlohmann::json& j, LoggingDurationMdt& o) {
  from_json(j, o.m_value);
}

LoggingDurationMdt_anyOf LoggingDurationMdt::getValue() const {
  return m_value;
}

void LoggingDurationMdt::setValue(LoggingDurationMdt_anyOf value) {
  m_value = value;
}

LoggingDurationMdt_anyOf::eLoggingDurationMdt_anyOf
LoggingDurationMdt::getEnumValue() const {
  return m_value.getValue();
}

void LoggingDurationMdt::setEnumValue(
    LoggingDurationMdt_anyOf::eLoggingDurationMdt_anyOf value) {
  m_value.setValue(value);
}

}  // namespace ngkore::model::common
