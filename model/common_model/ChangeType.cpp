
#include "ChangeType.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

ChangeType::ChangeType() {}

void ChangeType::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool ChangeType::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool ChangeType::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "ChangeType" : pathPrefix;

  if (!m_value.validate(msg)) {
    success = false;
  }
  return success;
}

bool ChangeType::operator==(const ChangeType& rhs) const {
  return

      getValue() == rhs.getValue();
}

bool ChangeType::operator!=(const ChangeType& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const ChangeType& o) {
  j = nlohmann::json();
  to_json(j, o.m_value);
}

void from_json(const nlohmann::json& j, ChangeType& o) {
  from_json(j, o.m_value);
}

ChangeType_anyOf ChangeType::getValue() const {
  return m_value;
}

void ChangeType::setValue(ChangeType_anyOf value) {
  m_value = value;
}

ChangeType_anyOf::eChangeType_anyOf ChangeType::getEnumValue() const {
  return m_value.getValue();
}

void ChangeType::setEnumValue(ChangeType_anyOf::eChangeType_anyOf value) {
  m_value.setValue(value);
}

}  // namespace ngkore::model::common
