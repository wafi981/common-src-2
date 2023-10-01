
#include "PduSessionType.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

PduSessionType::PduSessionType() {}

void PduSessionType::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool PduSessionType::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool PduSessionType::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "PduSessionType" : pathPrefix;

  if (!m_value.validate(msg)) {
    success = false;
  }
  return success;
}

bool PduSessionType::operator==(const PduSessionType& rhs) const {
  return

      getValue() == rhs.getValue();
}

bool PduSessionType::operator!=(const PduSessionType& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const PduSessionType& o) {
  j = nlohmann::json();
  to_json(j, o.m_value);
}

void from_json(const nlohmann::json& j, PduSessionType& o) {
  from_json(j, o.m_value);
}

PduSessionType_anyOf PduSessionType::getValue() const {
  return m_value;
}

void PduSessionType::setValue(PduSessionType_anyOf value) {
  m_value = value;
}

PduSessionType_anyOf::ePduSessionType_anyOf PduSessionType::getEnumValue()
    const {
  return m_value.getValue();
}

void PduSessionType::setEnumValue(
    PduSessionType_anyOf::ePduSessionType_anyOf value) {
  m_value.setValue(value);
}

}  // namespace ngkore::model::common
