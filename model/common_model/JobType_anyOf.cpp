
#include "JobType_anyOf.h"
#include "Helpers.h"
#include <stdexcept>
#include <sstream>

namespace ngkore::model::common {

JobType_anyOf::JobType_anyOf() {}

void JobType_anyOf::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool JobType_anyOf::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool JobType_anyOf::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "JobType_anyOf" : pathPrefix;

  if (m_value ==
      JobType_anyOf::eJobType_anyOf::INVALID_VALUE_OPENAPI_GENERATED) {
    success = false;
    msg << _pathPrefix << ": has no value;";
  }

  return success;
}

bool JobType_anyOf::operator==(const JobType_anyOf& rhs) const {
  return getValue() == rhs.getValue()

      ;
}

bool JobType_anyOf::operator!=(const JobType_anyOf& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const JobType_anyOf& o) {
  j = nlohmann::json();

  switch (o.getValue()) {
    case JobType_anyOf::eJobType_anyOf::INVALID_VALUE_OPENAPI_GENERATED:
      j = "INVALID_VALUE_OPENAPI_GENERATED";
      break;
    case JobType_anyOf::eJobType_anyOf::IMMEDIATE_MDT_ONLY:
      j = "IMMEDIATE_MDT_ONLY";
      break;
    case JobType_anyOf::eJobType_anyOf::LOGGED_MDT_ONLY:
      j = "LOGGED_MDT_ONLY";
      break;
    case JobType_anyOf::eJobType_anyOf::TRACE_ONLY:
      j = "TRACE_ONLY";
      break;
    case JobType_anyOf::eJobType_anyOf::IMMEDIATE_MDT_AND_TRACE:
      j = "IMMEDIATE_MDT_AND_TRACE";
      break;
    case JobType_anyOf::eJobType_anyOf::RLF_REPORTS_ONLY:
      j = "RLF_REPORTS_ONLY";
      break;
    case JobType_anyOf::eJobType_anyOf::RCEF_REPORTS_ONLY:
      j = "RCEF_REPORTS_ONLY";
      break;
    case JobType_anyOf::eJobType_anyOf::LOGGED_MBSFN_MDT:
      j = "LOGGED_MBSFN_MDT";
      break;
  }
}

void from_json(const nlohmann::json& j, JobType_anyOf& o) {
  auto s = j.get<std::string>();
  if (s == "IMMEDIATE_MDT_ONLY") {
    o.setValue(JobType_anyOf::eJobType_anyOf::IMMEDIATE_MDT_ONLY);
  } else if (s == "LOGGED_MDT_ONLY") {
    o.setValue(JobType_anyOf::eJobType_anyOf::LOGGED_MDT_ONLY);
  } else if (s == "TRACE_ONLY") {
    o.setValue(JobType_anyOf::eJobType_anyOf::TRACE_ONLY);
  } else if (s == "IMMEDIATE_MDT_AND_TRACE") {
    o.setValue(JobType_anyOf::eJobType_anyOf::IMMEDIATE_MDT_AND_TRACE);
  } else if (s == "RLF_REPORTS_ONLY") {
    o.setValue(JobType_anyOf::eJobType_anyOf::RLF_REPORTS_ONLY);
  } else if (s == "RCEF_REPORTS_ONLY") {
    o.setValue(JobType_anyOf::eJobType_anyOf::RCEF_REPORTS_ONLY);
  } else if (s == "LOGGED_MBSFN_MDT") {
    o.setValue(JobType_anyOf::eJobType_anyOf::LOGGED_MBSFN_MDT);
  } else {
    std::stringstream ss;
    ss << "Unexpected value " << s << " in json"
       << " cannot be converted to enum of type"
       << " JobType_anyOf::eJobType_anyOf";
    throw std::invalid_argument(ss.str());
  }
}

JobType_anyOf::eJobType_anyOf JobType_anyOf::getValue() const {
  return m_value;
}
void JobType_anyOf::setValue(JobType_anyOf::eJobType_anyOf value) {
  m_value = value;
}

}  // namespace ngkore::model::common
