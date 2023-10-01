
#include "ScheduledCommunicationType.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

ScheduledCommunicationType::ScheduledCommunicationType() {}

void ScheduledCommunicationType::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool ScheduledCommunicationType::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool ScheduledCommunicationType::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "ScheduledCommunicationType" : pathPrefix;

  if (!m_value.validate(msg)) {
    success = false;
  }
  return success;
}

bool ScheduledCommunicationType::operator==(
    const ScheduledCommunicationType& rhs) const {
  return

      getValue() == rhs.getValue();
}

bool ScheduledCommunicationType::operator!=(
    const ScheduledCommunicationType& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const ScheduledCommunicationType& o) {
  j = nlohmann::json();
  to_json(j, o.m_value);
}

void from_json(const nlohmann::json& j, ScheduledCommunicationType& o) {
  from_json(j, o.m_value);
}

ScheduledCommunicationType_anyOf ScheduledCommunicationType::getValue() const {
  return m_value;
}

void ScheduledCommunicationType::setValue(
    ScheduledCommunicationType_anyOf value) {
  m_value = value;
}

ScheduledCommunicationType_anyOf::eScheduledCommunicationType_anyOf
ScheduledCommunicationType::getEnumValue() const {
  return m_value.getValue();
}

void ScheduledCommunicationType::setEnumValue(
    ScheduledCommunicationType_anyOf::eScheduledCommunicationType_anyOf value) {
  m_value.setValue(value);
}

}  // namespace ngkore::model::common
