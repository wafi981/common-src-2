
#include "JobType.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

JobType::JobType() {}

void JobType::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool JobType::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool JobType::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success                  = true;
  const std::string _pathPrefix = pathPrefix.empty() ? "JobType" : pathPrefix;

  if (!m_value.validate(msg)) {
    success = false;
  }
  return success;
}

bool JobType::operator==(const JobType& rhs) const {
  return

      getValue() == rhs.getValue();
}

bool JobType::operator!=(const JobType& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const JobType& o) {
  j = nlohmann::json();
  to_json(j, o.m_value);
}

void from_json(const nlohmann::json& j, JobType& o) {
  from_json(j, o.m_value);
}

JobType_anyOf JobType::getValue() const {
  return m_value;
}

void JobType::setValue(JobType_anyOf value) {
  m_value = value;
}

JobType_anyOf::eJobType_anyOf JobType::getEnumValue() const {
  return m_value.getValue();
}

void JobType::setEnumValue(JobType_anyOf::eJobType_anyOf value) {
  m_value.setValue(value);
}

}  // namespace ngkore::model::common
