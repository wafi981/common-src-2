
#include "NotificationControl.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

NotificationControl::NotificationControl() {}

void NotificationControl::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool NotificationControl::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool NotificationControl::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "NotificationControl" : pathPrefix;

  if (!m_value.validate(msg)) {
    success = false;
  }
  return success;
}

bool NotificationControl::operator==(const NotificationControl& rhs) const {
  return

      getValue() == rhs.getValue();
}

bool NotificationControl::operator!=(const NotificationControl& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const NotificationControl& o) {
  j = nlohmann::json();
  to_json(j, o.m_value);
}

void from_json(const nlohmann::json& j, NotificationControl& o) {
  from_json(j, o.m_value);
}

NotificationControl_anyOf NotificationControl::getValue() const {
  return m_value;
}

void NotificationControl::setValue(NotificationControl_anyOf value) {
  m_value = value;
}

NotificationControl_anyOf::eNotificationControl_anyOf
NotificationControl::getEnumValue() const {
  return m_value.getValue();
}

void NotificationControl::setEnumValue(
    NotificationControl_anyOf::eNotificationControl_anyOf value) {
  m_value.setValue(value);
}

}  // namespace ngkore::model::common
