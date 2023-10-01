
#include "UpConfidentiality.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

UpConfidentiality::UpConfidentiality() {}

void UpConfidentiality::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool UpConfidentiality::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool UpConfidentiality::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "UpConfidentiality" : pathPrefix;

  if (!m_value.validate(msg)) {
    success = false;
  }
  return success;
}

bool UpConfidentiality::operator==(const UpConfidentiality& rhs) const {
  return

      getValue() == rhs.getValue();
}

bool UpConfidentiality::operator!=(const UpConfidentiality& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const UpConfidentiality& o) {
  j = nlohmann::json();
  to_json(j, o.m_value);
}

void from_json(const nlohmann::json& j, UpConfidentiality& o) {
  from_json(j, o.m_value);
}

UpIntegrity_anyOf UpConfidentiality::getValue() const {
  return m_value;
}

void UpConfidentiality::setValue(UpIntegrity_anyOf value) {
  m_value = value;
}

UpIntegrity_anyOf::eUpIntegrity_anyOf UpConfidentiality::getEnumValue() const {
  return m_value.getValue();
}

void UpConfidentiality::setEnumValue(
    UpIntegrity_anyOf::eUpIntegrity_anyOf value) {
  m_value.setValue(value);
}

}  // namespace ngkore::model::common
