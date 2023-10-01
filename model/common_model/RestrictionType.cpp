
#include "RestrictionType.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

RestrictionType::RestrictionType() {}

void RestrictionType::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool RestrictionType::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool RestrictionType::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "RestrictionType" : pathPrefix;

  if (!m_value.validate(msg)) {
    success = false;
  }
  return success;
}

bool RestrictionType::operator==(const RestrictionType& rhs) const {
  return

      getValue() == rhs.getValue();
}

bool RestrictionType::operator!=(const RestrictionType& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const RestrictionType& o) {
  j = nlohmann::json();
  to_json(j, o.m_value);
}

void from_json(const nlohmann::json& j, RestrictionType& o) {
  from_json(j, o.m_value);
}

RestrictionType_anyOf RestrictionType::getValue() const {
  return m_value;
}

void RestrictionType::setValue(RestrictionType_anyOf value) {
  m_value = value;
}

RestrictionType_anyOf::eRestrictionType_anyOf RestrictionType::getEnumValue()
    const {
  return m_value.getValue();
}

void RestrictionType::setEnumValue(
    RestrictionType_anyOf::eRestrictionType_anyOf value) {
  m_value.setValue(value);
}

}  // namespace ngkore::model::common
