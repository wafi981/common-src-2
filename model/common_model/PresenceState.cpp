
#include "PresenceState.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

PresenceState::PresenceState() {}

void PresenceState::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool PresenceState::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool PresenceState::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "PresenceState" : pathPrefix;

  if (!m_value.validate(msg)) {
    success = false;
  }
  return success;
}

bool PresenceState::operator==(const PresenceState& rhs) const {
  return

      getValue() == rhs.getValue();
}

bool PresenceState::operator!=(const PresenceState& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const PresenceState& o) {
  j = nlohmann::json();
  to_json(j, o.m_value);
}

void from_json(const nlohmann::json& j, PresenceState& o) {
  from_json(j, o.m_value);
}

PresenceState_anyOf PresenceState::getValue() const {
  return m_value;
}

void PresenceState::setValue(PresenceState_anyOf value) {
  m_value = value;
}

PresenceState_anyOf::ePresenceState_anyOf PresenceState::getEnumValue() const {
  return m_value.getValue();
}

void PresenceState::setEnumValue(
    PresenceState_anyOf::ePresenceState_anyOf value) {
  m_value.setValue(value);
}

}  // namespace ngkore::model::common
