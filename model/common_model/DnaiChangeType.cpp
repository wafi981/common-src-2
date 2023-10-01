
#include "DnaiChangeType.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

DnaiChangeType::DnaiChangeType() {}

void DnaiChangeType::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool DnaiChangeType::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool DnaiChangeType::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "DnaiChangeType" : pathPrefix;

  if (!m_value.validate(msg)) {
    success = false;
  }
  return success;
}

bool DnaiChangeType::operator==(const DnaiChangeType& rhs) const {
  return

      getValue() == rhs.getValue();
}

bool DnaiChangeType::operator!=(const DnaiChangeType& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const DnaiChangeType& o) {
  j = nlohmann::json();
  to_json(j, o.m_value);
}

void from_json(const nlohmann::json& j, DnaiChangeType& o) {
  from_json(j, o.m_value);
}

DnaiChangeType_anyOf DnaiChangeType::getValue() const {
  return m_value;
}

void DnaiChangeType::setValue(DnaiChangeType_anyOf value) {
  m_value = value;
}

DnaiChangeType_anyOf::eDnaiChangeType_anyOf DnaiChangeType::getEnumValue()
    const {
  return m_value.getValue();
}

void DnaiChangeType::setEnumValue(
    DnaiChangeType_anyOf::eDnaiChangeType_anyOf value) {
  m_value.setValue(value);
}

}  // namespace ngkore::model::common
