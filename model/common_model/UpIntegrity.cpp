
#include "UpIntegrity.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

UpIntegrity::UpIntegrity() {}

void UpIntegrity::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool UpIntegrity::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool UpIntegrity::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "UpIntegrity" : pathPrefix;

  if (!m_value.validate(msg)) {
    success = false;
  }
  return success;
}

bool UpIntegrity::operator==(const UpIntegrity& rhs) const {
  return

      getValue() == rhs.getValue();
}

bool UpIntegrity::operator!=(const UpIntegrity& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const UpIntegrity& o) {
  j = nlohmann::json();
  to_json(j, o.m_value);
}

void from_json(const nlohmann::json& j, UpIntegrity& o) {
  from_json(j, o.m_value);
}

UpIntegrity_anyOf UpIntegrity::getValue() const {
  return m_value;
}

void UpIntegrity::setValue(UpIntegrity_anyOf value) {
  m_value = value;
}

UpIntegrity_anyOf::eUpIntegrity_anyOf UpIntegrity::getEnumValue() const {
  return m_value.getValue();
}

void UpIntegrity::setEnumValue(UpIntegrity_anyOf::eUpIntegrity_anyOf value) {
  m_value.setValue(value);
}

}  // namespace ngkore::model::common
