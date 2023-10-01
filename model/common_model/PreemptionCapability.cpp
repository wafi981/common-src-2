
#include "PreemptionCapability.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

PreemptionCapability::PreemptionCapability() {}

void PreemptionCapability::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool PreemptionCapability::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool PreemptionCapability::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "PreemptionCapability" : pathPrefix;

  if (!m_value.validate(msg)) {
    success = false;
  }
  return success;
}

bool PreemptionCapability::operator==(const PreemptionCapability& rhs) const {
  return

      getValue() == rhs.getValue();
}

bool PreemptionCapability::operator!=(const PreemptionCapability& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const PreemptionCapability& o) {
  j = nlohmann::json();
  to_json(j, o.m_value);
}

void from_json(const nlohmann::json& j, PreemptionCapability& o) {
  from_json(j, o.m_value);
}

PreemptionCapability_anyOf PreemptionCapability::getValue() const {
  return m_value;
}

void PreemptionCapability::setValue(PreemptionCapability_anyOf value) {
  m_value = value;
}

PreemptionCapability_anyOf::ePreemptionCapability_anyOf
PreemptionCapability::getEnumValue() const {
  return m_value.getValue();
}

void PreemptionCapability::setEnumValue(
    PreemptionCapability_anyOf::ePreemptionCapability_anyOf value) {
  m_value.setValue(value);
}

}  // namespace ngkore::model::common
