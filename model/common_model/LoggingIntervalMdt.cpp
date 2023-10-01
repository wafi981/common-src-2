
#include "LoggingIntervalMdt.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

LoggingIntervalMdt::LoggingIntervalMdt() {}

void LoggingIntervalMdt::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool LoggingIntervalMdt::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool LoggingIntervalMdt::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "LoggingIntervalMdt" : pathPrefix;

  if (!m_value.validate(msg)) {
    success = false;
  }
  return success;
}

bool LoggingIntervalMdt::operator==(const LoggingIntervalMdt& rhs) const {
  return

      getValue() == rhs.getValue();
}

bool LoggingIntervalMdt::operator!=(const LoggingIntervalMdt& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const LoggingIntervalMdt& o) {
  j = nlohmann::json();
  to_json(j, o.m_value);
}

void from_json(const nlohmann::json& j, LoggingIntervalMdt& o) {
  from_json(j, o.m_value);
}

LoggingIntervalMdt_anyOf LoggingIntervalMdt::getValue() const {
  return m_value;
}

void LoggingIntervalMdt::setValue(LoggingIntervalMdt_anyOf value) {
  m_value = value;
}

LoggingIntervalMdt_anyOf::eLoggingIntervalMdt_anyOf
LoggingIntervalMdt::getEnumValue() const {
  return m_value.getValue();
}

void LoggingIntervalMdt::setEnumValue(
    LoggingIntervalMdt_anyOf::eLoggingIntervalMdt_anyOf value) {
  m_value.setValue(value);
}

}  // namespace ngkore::model::common
