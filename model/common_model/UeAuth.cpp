
#include "UeAuth.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

UeAuth::UeAuth() {}

void UeAuth::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool UeAuth::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool UeAuth::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success                  = true;
  const std::string _pathPrefix = pathPrefix.empty() ? "UeAuth" : pathPrefix;

  if (!m_value.validate(msg)) {
    success = false;
  }
  return success;
}

bool UeAuth::operator==(const UeAuth& rhs) const {
  return

      getValue() == rhs.getValue();
}

bool UeAuth::operator!=(const UeAuth& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const UeAuth& o) {
  j = nlohmann::json();
  to_json(j, o.m_value);
}

void from_json(const nlohmann::json& j, UeAuth& o) {
  from_json(j, o.m_value);
}

UeAuth_anyOf UeAuth::getValue() const {
  return m_value;
}

void UeAuth::setValue(UeAuth_anyOf value) {
  m_value = value;
}

UeAuth_anyOf::eUeAuth_anyOf UeAuth::getEnumValue() const {
  return m_value.getValue();
}

void UeAuth::setEnumValue(UeAuth_anyOf::eUeAuth_anyOf value) {
  m_value.setValue(value);
}

}  // namespace ngkore::model::common
