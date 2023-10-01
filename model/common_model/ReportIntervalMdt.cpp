
#include "ReportIntervalMdt.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

ReportIntervalMdt::ReportIntervalMdt() {}

void ReportIntervalMdt::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool ReportIntervalMdt::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool ReportIntervalMdt::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "ReportIntervalMdt" : pathPrefix;

  if (!m_value.validate(msg)) {
    success = false;
  }
  return success;
}

bool ReportIntervalMdt::operator==(const ReportIntervalMdt& rhs) const {
  return

      getValue() == rhs.getValue();
}

bool ReportIntervalMdt::operator!=(const ReportIntervalMdt& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const ReportIntervalMdt& o) {
  j = nlohmann::json();
  to_json(j, o.m_value);
}

void from_json(const nlohmann::json& j, ReportIntervalMdt& o) {
  from_json(j, o.m_value);
}

ReportIntervalMdt_anyOf ReportIntervalMdt::getValue() const {
  return m_value;
}

void ReportIntervalMdt::setValue(ReportIntervalMdt_anyOf value) {
  m_value = value;
}

ReportIntervalMdt_anyOf::eReportIntervalMdt_anyOf
ReportIntervalMdt::getEnumValue() const {
  return m_value.getValue();
}

void ReportIntervalMdt::setEnumValue(
    ReportIntervalMdt_anyOf::eReportIntervalMdt_anyOf value) {
  m_value.setValue(value);
}

}  // namespace ngkore::model::common
