
#include "ReportingTrigger_anyOf.h"
#include "Helpers.h"
#include <stdexcept>
#include <sstream>

namespace ngkore::model::common {

ReportingTrigger_anyOf::ReportingTrigger_anyOf() {}

void ReportingTrigger_anyOf::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool ReportingTrigger_anyOf::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool ReportingTrigger_anyOf::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "ReportingTrigger_anyOf" : pathPrefix;

  if (m_value == ReportingTrigger_anyOf::eReportingTrigger_anyOf::
                     INVALID_VALUE_OPENAPI_GENERATED) {
    success = false;
    msg << _pathPrefix << ": has no value;";
  }

  return success;
}

bool ReportingTrigger_anyOf::operator==(
    const ReportingTrigger_anyOf& rhs) const {
  return getValue() == rhs.getValue()

      ;
}

bool ReportingTrigger_anyOf::operator!=(
    const ReportingTrigger_anyOf& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const ReportingTrigger_anyOf& o) {
  j = nlohmann::json();

  switch (o.getValue()) {
    case ReportingTrigger_anyOf::eReportingTrigger_anyOf::
        INVALID_VALUE_OPENAPI_GENERATED:
      j = "INVALID_VALUE_OPENAPI_GENERATED";
      break;
    case ReportingTrigger_anyOf::eReportingTrigger_anyOf::PERIODICAL:
      j = "PERIODICAL";
      break;
    case ReportingTrigger_anyOf::eReportingTrigger_anyOf::EVENT_A2:
      j = "EVENT_A2";
      break;
    case ReportingTrigger_anyOf::eReportingTrigger_anyOf::EVENT_A2_PERIODIC:
      j = "EVENT_A2_PERIODIC";
      break;
    case ReportingTrigger_anyOf::eReportingTrigger_anyOf::
        ALL_RRM_EVENT_TRIGGERS:
      j = "ALL_RRM_EVENT_TRIGGERS";
      break;
  }
}

void from_json(const nlohmann::json& j, ReportingTrigger_anyOf& o) {
  auto s = j.get<std::string>();
  if (s == "PERIODICAL") {
    o.setValue(ReportingTrigger_anyOf::eReportingTrigger_anyOf::PERIODICAL);
  } else if (s == "EVENT_A2") {
    o.setValue(ReportingTrigger_anyOf::eReportingTrigger_anyOf::EVENT_A2);
  } else if (s == "EVENT_A2_PERIODIC") {
    o.setValue(
        ReportingTrigger_anyOf::eReportingTrigger_anyOf::EVENT_A2_PERIODIC);
  } else if (s == "ALL_RRM_EVENT_TRIGGERS") {
    o.setValue(ReportingTrigger_anyOf::eReportingTrigger_anyOf::
                   ALL_RRM_EVENT_TRIGGERS);
  } else {
    std::stringstream ss;
    ss << "Unexpected value " << s << " in json"
       << " cannot be converted to enum of type"
       << " ReportingTrigger_anyOf::eReportingTrigger_anyOf";
    throw std::invalid_argument(ss.str());
  }
}

ReportingTrigger_anyOf::eReportingTrigger_anyOf
ReportingTrigger_anyOf::getValue() const {
  return m_value;
}
void ReportingTrigger_anyOf::setValue(
    ReportingTrigger_anyOf::eReportingTrigger_anyOf value) {
  m_value = value;
}

}  // namespace ngkore::model::common
