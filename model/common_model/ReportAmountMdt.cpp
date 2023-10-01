
#include "ReportAmountMdt.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

ReportAmountMdt::ReportAmountMdt() {}

void ReportAmountMdt::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool ReportAmountMdt::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool ReportAmountMdt::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "ReportAmountMdt" : pathPrefix;

  if (!m_value.validate(msg)) {
    success = false;
  }
  return success;
}

bool ReportAmountMdt::operator==(const ReportAmountMdt& rhs) const {
  return

      getValue() == rhs.getValue();
}

bool ReportAmountMdt::operator!=(const ReportAmountMdt& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const ReportAmountMdt& o) {
  j = nlohmann::json();
  to_json(j, o.m_value);
}

void from_json(const nlohmann::json& j, ReportAmountMdt& o) {
  from_json(j, o.m_value);
}

ReportAmountMdt_anyOf ReportAmountMdt::getValue() const {
  return m_value;
}

void ReportAmountMdt::setValue(ReportAmountMdt_anyOf value) {
  m_value = value;
}

ReportAmountMdt_anyOf::eReportAmountMdt_anyOf ReportAmountMdt::getEnumValue()
    const {
  return m_value.getValue();
}

void ReportAmountMdt::setEnumValue(
    ReportAmountMdt_anyOf::eReportAmountMdt_anyOf value) {
  m_value.setValue(value);
}

}  // namespace ngkore::model::common
