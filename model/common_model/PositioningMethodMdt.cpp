
#include "PositioningMethodMdt.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

PositioningMethodMdt::PositioningMethodMdt() {}

void PositioningMethodMdt::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool PositioningMethodMdt::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool PositioningMethodMdt::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "PositioningMethodMdt" : pathPrefix;

  if (!m_value.validate(msg)) {
    success = false;
  }
  return success;
}

bool PositioningMethodMdt::operator==(const PositioningMethodMdt& rhs) const {
  return

      getValue() == rhs.getValue();
}

bool PositioningMethodMdt::operator!=(const PositioningMethodMdt& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const PositioningMethodMdt& o) {
  j = nlohmann::json();
  to_json(j, o.m_value);
}

void from_json(const nlohmann::json& j, PositioningMethodMdt& o) {
  from_json(j, o.m_value);
}

PositioningMethodMdt_anyOf PositioningMethodMdt::getValue() const {
  return m_value;
}

void PositioningMethodMdt::setValue(PositioningMethodMdt_anyOf value) {
  m_value = value;
}

PositioningMethodMdt_anyOf::ePositioningMethodMdt_anyOf
PositioningMethodMdt::getEnumValue() const {
  return m_value.getValue();
}

void PositioningMethodMdt::setEnumValue(
    PositioningMethodMdt_anyOf::ePositioningMethodMdt_anyOf value) {
  m_value.setValue(value);
}

}  // namespace ngkore::model::common
