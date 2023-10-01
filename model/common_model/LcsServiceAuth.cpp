
#include "LcsServiceAuth.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

LcsServiceAuth::LcsServiceAuth() {}

void LcsServiceAuth::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool LcsServiceAuth::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool LcsServiceAuth::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "LcsServiceAuth" : pathPrefix;

  if (!m_value.validate(msg)) {
    success = false;
  }
  return success;
}

bool LcsServiceAuth::operator==(const LcsServiceAuth& rhs) const {
  return

      getValue() == rhs.getValue();
}

bool LcsServiceAuth::operator!=(const LcsServiceAuth& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const LcsServiceAuth& o) {
  j = nlohmann::json();
  to_json(j, o.m_value);
}

void from_json(const nlohmann::json& j, LcsServiceAuth& o) {
  from_json(j, o.m_value);
}

LcsServiceAuth_anyOf LcsServiceAuth::getValue() const {
  return m_value;
}

void LcsServiceAuth::setValue(LcsServiceAuth_anyOf value) {
  m_value = value;
}

LcsServiceAuth_anyOf::eLcsServiceAuth_anyOf LcsServiceAuth::getEnumValue()
    const {
  return m_value.getValue();
}

void LcsServiceAuth::setEnumValue(
    LcsServiceAuth_anyOf::eLcsServiceAuth_anyOf value) {
  m_value.setValue(value);
}

}  // namespace ngkore::model::common
