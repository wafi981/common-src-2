
#include "ReportTypeMdt_anyOf.h"
#include "Helpers.h"
#include <stdexcept>
#include <sstream>

namespace ngkore::model::common {

ReportTypeMdt_anyOf::ReportTypeMdt_anyOf() {}

void ReportTypeMdt_anyOf::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool ReportTypeMdt_anyOf::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool ReportTypeMdt_anyOf::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "ReportTypeMdt_anyOf" : pathPrefix;

  if (m_value == ReportTypeMdt_anyOf::eReportTypeMdt_anyOf::
                     INVALID_VALUE_OPENAPI_GENERATED) {
    success = false;
    msg << _pathPrefix << ": has no value;";
  }

  return success;
}

bool ReportTypeMdt_anyOf::operator==(const ReportTypeMdt_anyOf& rhs) const {
  return getValue() == rhs.getValue()

      ;
}

bool ReportTypeMdt_anyOf::operator!=(const ReportTypeMdt_anyOf& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const ReportTypeMdt_anyOf& o) {
  j = nlohmann::json();

  switch (o.getValue()) {
    case ReportTypeMdt_anyOf::eReportTypeMdt_anyOf::
        INVALID_VALUE_OPENAPI_GENERATED:
      j = "INVALID_VALUE_OPENAPI_GENERATED";
      break;
    case ReportTypeMdt_anyOf::eReportTypeMdt_anyOf::PERIODICAL:
      j = "PERIODICAL";
      break;
    case ReportTypeMdt_anyOf::eReportTypeMdt_anyOf::EVENT_TRIGGED:
      j = "EVENT_TRIGGED";
      break;
  }
}

void from_json(const nlohmann::json& j, ReportTypeMdt_anyOf& o) {
  auto s = j.get<std::string>();
  if (s == "PERIODICAL") {
    o.setValue(ReportTypeMdt_anyOf::eReportTypeMdt_anyOf::PERIODICAL);
  } else if (s == "EVENT_TRIGGED") {
    o.setValue(ReportTypeMdt_anyOf::eReportTypeMdt_anyOf::EVENT_TRIGGED);
  } else {
    std::stringstream ss;
    ss << "Unexpected value " << s << " in json"
       << " cannot be converted to enum of type"
       << " ReportTypeMdt_anyOf::eReportTypeMdt_anyOf";
    throw std::invalid_argument(ss.str());
  }
}

ReportTypeMdt_anyOf::eReportTypeMdt_anyOf ReportTypeMdt_anyOf::getValue()
    const {
  return m_value;
}
void ReportTypeMdt_anyOf::setValue(
    ReportTypeMdt_anyOf::eReportTypeMdt_anyOf value) {
  m_value = value;
}

}  // namespace ngkore::model::common
