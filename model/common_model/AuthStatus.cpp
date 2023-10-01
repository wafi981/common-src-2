
#include "AuthStatus.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

AuthStatus::AuthStatus() {}

void AuthStatus::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool AuthStatus::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool AuthStatus::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "AuthStatus" : pathPrefix;

  if (!m_value.validate(msg)) {
    success = false;
  }
  return success;
}

bool AuthStatus::operator==(const AuthStatus& rhs) const {
  return

      getValue() == rhs.getValue();
}

bool AuthStatus::operator!=(const AuthStatus& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const AuthStatus& o) {
  j = nlohmann::json();
  to_json(j, o.m_value);
}

void from_json(const nlohmann::json& j, AuthStatus& o) {
  from_json(j, o.m_value);
}

AuthStatus_anyOf AuthStatus::getValue() const {
  return m_value;
}

void AuthStatus::setValue(AuthStatus_anyOf value) {
  m_value = value;
}

AuthStatus_anyOf::eAuthStatus_anyOf AuthStatus::getEnumValue() const {
  return m_value.getValue();
}

void AuthStatus::setEnumValue(AuthStatus_anyOf::eAuthStatus_anyOf value) {
  m_value.setValue(value);
}

}  // namespace ngkore::model::common
