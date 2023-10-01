
#include "ReportTypeMdt.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

ReportTypeMdt::ReportTypeMdt() {}

void ReportTypeMdt::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool ReportTypeMdt::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool ReportTypeMdt::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "ReportTypeMdt" : pathPrefix;

  if (!m_value.validate(msg)) {
    success = false;
  }
  return success;
}

bool ReportTypeMdt::operator==(const ReportTypeMdt& rhs) const {
  return

      getValue() == rhs.getValue();
}

bool ReportTypeMdt::operator!=(const ReportTypeMdt& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const ReportTypeMdt& o) {
  j = nlohmann::json();
  to_json(j, o.m_value);
}

void from_json(const nlohmann::json& j, ReportTypeMdt& o) {
  from_json(j, o.m_value);
}

ReportTypeMdt_anyOf ReportTypeMdt::getValue() const {
  return m_value;
}

void ReportTypeMdt::setValue(ReportTypeMdt_anyOf value) {
  m_value = value;
}

ReportTypeMdt_anyOf::eReportTypeMdt_anyOf ReportTypeMdt::getEnumValue() const {
  return m_value.getValue();
}

void ReportTypeMdt::setEnumValue(
    ReportTypeMdt_anyOf::eReportTypeMdt_anyOf value) {
  m_value.setValue(value);
}

}  // namespace ngkore::model::common
