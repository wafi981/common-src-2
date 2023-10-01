
#include "UPInterfaceType.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::nrf {

UPInterfaceType::UPInterfaceType() {}

void UPInterfaceType::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool UPInterfaceType::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool UPInterfaceType::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "UPInterfaceType" : pathPrefix;

  if (!m_value.validate(msg)) {
    success = false;
  }
  return success;
}

bool UPInterfaceType::operator==(const UPInterfaceType& rhs) const {
  return

      getValue() == rhs.getValue();
}

bool UPInterfaceType::operator!=(const UPInterfaceType& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const UPInterfaceType& o) {
  j = nlohmann::json();
  to_json(j, o.m_value);
}

void from_json(const nlohmann::json& j, UPInterfaceType& o) {
  from_json(j, o.m_value);
}

UPInterfaceType_anyOf UPInterfaceType::getValue() const {
  return m_value;
}

void UPInterfaceType::setValue(UPInterfaceType_anyOf value) {
  m_value = value;
}

UPInterfaceType_anyOf::eUPInterfaceType_anyOf UPInterfaceType::getEnumValue()
    const {
  return m_value.getValue();
}

void UPInterfaceType::setEnumValue(
    UPInterfaceType_anyOf::eUPInterfaceType_anyOf value) {
  m_value.setValue(value);
}

std::string UPInterfaceType::getEnumString() const {
  return common::helpers::enumToString(m_value);
}

}  // namespace ngkore::model::nrf
