
#include "ReflectiveQoSAttribute.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

ReflectiveQoSAttribute::ReflectiveQoSAttribute() {}

void ReflectiveQoSAttribute::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool ReflectiveQoSAttribute::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool ReflectiveQoSAttribute::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "ReflectiveQoSAttribute" : pathPrefix;

  if (!m_value.validate(msg)) {
    success = false;
  }
  return success;
}

bool ReflectiveQoSAttribute::operator==(
    const ReflectiveQoSAttribute& rhs) const {
  return

      getValue() == rhs.getValue();
}

bool ReflectiveQoSAttribute::operator!=(
    const ReflectiveQoSAttribute& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const ReflectiveQoSAttribute& o) {
  j = nlohmann::json();
  to_json(j, o.m_value);
}

void from_json(const nlohmann::json& j, ReflectiveQoSAttribute& o) {
  from_json(j, o.m_value);
}

ReflectiveQoSAttribute_anyOf ReflectiveQoSAttribute::getValue() const {
  return m_value;
}

void ReflectiveQoSAttribute::setValue(ReflectiveQoSAttribute_anyOf value) {
  m_value = value;
}

ReflectiveQoSAttribute_anyOf::eReflectiveQoSAttribute_anyOf
ReflectiveQoSAttribute::getEnumValue() const {
  return m_value.getValue();
}

void ReflectiveQoSAttribute::setEnumValue(
    ReflectiveQoSAttribute_anyOf::eReflectiveQoSAttribute_anyOf value) {
  m_value.setValue(value);
}

}  // namespace ngkore::model::common
