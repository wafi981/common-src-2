
#include "RgWirelineCharacteristicsRm.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

RgWirelineCharacteristicsRm::RgWirelineCharacteristicsRm() {}

void RgWirelineCharacteristicsRm::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool RgWirelineCharacteristicsRm::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool RgWirelineCharacteristicsRm::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "RgWirelineCharacteristicsRm" : pathPrefix;

  if (!m_value.validate(msg)) {
    success = false;
  }
  return success;
}

bool RgWirelineCharacteristicsRm::operator==(
    const RgWirelineCharacteristicsRm& rhs) const {
  return

      getValue() == rhs.getValue();
}

bool RgWirelineCharacteristicsRm::operator!=(
    const RgWirelineCharacteristicsRm& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const RgWirelineCharacteristicsRm& o) {
  j = nlohmann::json();
  to_json(j, o.m_value);
}

void from_json(const nlohmann::json& j, RgWirelineCharacteristicsRm& o) {
  from_json(j, o.m_value);
}

NullValue RgWirelineCharacteristicsRm::getValue() const {
  return m_value;
}

void RgWirelineCharacteristicsRm::setValue(NullValue value) {
  m_value = value;
}

NullValue::eNullValue RgWirelineCharacteristicsRm::getEnumValue() const {
  return m_value.getValue();
}

void RgWirelineCharacteristicsRm::setEnumValue(NullValue::eNullValue value) {
  m_value.setValue(value);
}

}  // namespace ngkore::model::common
