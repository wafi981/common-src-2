
#include "PatchOperation.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

PatchOperation::PatchOperation() {}

void PatchOperation::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool PatchOperation::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool PatchOperation::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "PatchOperation" : pathPrefix;

  if (!m_value.validate(msg)) {
    success = false;
  }
  return success;
}

bool PatchOperation::operator==(const PatchOperation& rhs) const {
  return

      getValue() == rhs.getValue();
}

bool PatchOperation::operator!=(const PatchOperation& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const PatchOperation& o) {
  j = nlohmann::json();
  to_json(j, o.m_value);
}

void from_json(const nlohmann::json& j, PatchOperation& o) {
  from_json(j, o.m_value);
}

PatchOperation_anyOf PatchOperation::getValue() const {
  return m_value;
}

void PatchOperation::setValue(PatchOperation_anyOf value) {
  m_value = value;
}

PatchOperation_anyOf::ePatchOperation_anyOf PatchOperation::getEnumValue()
    const {
  return m_value.getValue();
}

std::string PatchOperation::getEnumString() const {
  return helpers::enumToString(m_value);
}

void PatchOperation::setEnumValue(
    PatchOperation_anyOf::ePatchOperation_anyOf value) {
  m_value.setValue(value);
}

}  // namespace ngkore::model::common
