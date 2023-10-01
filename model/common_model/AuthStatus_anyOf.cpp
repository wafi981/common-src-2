
#include "AuthStatus_anyOf.h"
#include "Helpers.h"
#include <stdexcept>
#include <sstream>

namespace ngkore::model::common {

AuthStatus_anyOf::AuthStatus_anyOf() {}

void AuthStatus_anyOf::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool AuthStatus_anyOf::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool AuthStatus_anyOf::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "AuthStatus_anyOf" : pathPrefix;

  if (m_value ==
      AuthStatus_anyOf::eAuthStatus_anyOf::INVALID_VALUE_OPENAPI_GENERATED) {
    success = false;
    msg << _pathPrefix << ": has no value;";
  }

  return success;
}

bool AuthStatus_anyOf::operator==(const AuthStatus_anyOf& rhs) const {
  return getValue() == rhs.getValue()

      ;
}

bool AuthStatus_anyOf::operator!=(const AuthStatus_anyOf& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const AuthStatus_anyOf& o) {
  j = nlohmann::json();

  switch (o.getValue()) {
    case AuthStatus_anyOf::eAuthStatus_anyOf::INVALID_VALUE_OPENAPI_GENERATED:
      j = "INVALID_VALUE_OPENAPI_GENERATED";
      break;
    case AuthStatus_anyOf::eAuthStatus_anyOf::EAP_SUCCESS:
      j = "EAP_SUCCESS";
      break;
    case AuthStatus_anyOf::eAuthStatus_anyOf::EAP_FAILURE:
      j = "EAP_FAILURE";
      break;
    case AuthStatus_anyOf::eAuthStatus_anyOf::PENDING:
      j = "PENDING";
      break;
  }
}

void from_json(const nlohmann::json& j, AuthStatus_anyOf& o) {
  auto s = j.get<std::string>();
  if (s == "EAP_SUCCESS") {
    o.setValue(AuthStatus_anyOf::eAuthStatus_anyOf::EAP_SUCCESS);
  } else if (s == "EAP_FAILURE") {
    o.setValue(AuthStatus_anyOf::eAuthStatus_anyOf::EAP_FAILURE);
  } else if (s == "PENDING") {
    o.setValue(AuthStatus_anyOf::eAuthStatus_anyOf::PENDING);
  } else {
    std::stringstream ss;
    ss << "Unexpected value " << s << " in json"
       << " cannot be converted to enum of type"
       << " AuthStatus_anyOf::eAuthStatus_anyOf";
    throw std::invalid_argument(ss.str());
  }
}

AuthStatus_anyOf::eAuthStatus_anyOf AuthStatus_anyOf::getValue() const {
  return m_value;
}
void AuthStatus_anyOf::setValue(AuthStatus_anyOf::eAuthStatus_anyOf value) {
  m_value = value;
}

}  // namespace ngkore::model::common
