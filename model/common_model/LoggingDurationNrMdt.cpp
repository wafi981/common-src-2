
#include "LoggingDurationNrMdt.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

LoggingDurationNrMdt::LoggingDurationNrMdt() {}

void LoggingDurationNrMdt::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool LoggingDurationNrMdt::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool LoggingDurationNrMdt::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "LoggingDurationNrMdt" : pathPrefix;

  if (!m_value.validate(msg)) {
    success = false;
  }
  return success;
}

bool LoggingDurationNrMdt::operator==(const LoggingDurationNrMdt& rhs) const {
  return

      getValue() == rhs.getValue();
}

bool LoggingDurationNrMdt::operator!=(const LoggingDurationNrMdt& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const LoggingDurationNrMdt& o) {
  j = nlohmann::json();
  to_json(j, o.m_value);
}

void from_json(const nlohmann::json& j, LoggingDurationNrMdt& o) {
  from_json(j, o.m_value);
}

LoggingDurationMdt_anyOf LoggingDurationNrMdt::getValue() const {
  return m_value;
}

void LoggingDurationNrMdt::setValue(LoggingDurationMdt_anyOf value) {
  m_value = value;
}

LoggingDurationMdt_anyOf::eLoggingDurationMdt_anyOf
LoggingDurationNrMdt::getEnumValue() const {
  return m_value.getValue();
}

void LoggingDurationNrMdt::setEnumValue(
    LoggingDurationMdt_anyOf::eLoggingDurationMdt_anyOf value) {
  m_value.setValue(value);
}

}  // namespace ngkore::model::common
