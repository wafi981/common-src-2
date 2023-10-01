
#include "SensorMeasurement.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

SensorMeasurement::SensorMeasurement() {}

void SensorMeasurement::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool SensorMeasurement::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool SensorMeasurement::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "SensorMeasurement" : pathPrefix;

  if (!m_value.validate(msg)) {
    success = false;
  }
  return success;
}

bool SensorMeasurement::operator==(const SensorMeasurement& rhs) const {
  return

      getValue() == rhs.getValue();
}

bool SensorMeasurement::operator!=(const SensorMeasurement& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const SensorMeasurement& o) {
  j = nlohmann::json();
  to_json(j, o.m_value);
}

void from_json(const nlohmann::json& j, SensorMeasurement& o) {
  from_json(j, o.m_value);
}

SensorMeasurement_anyOf SensorMeasurement::getValue() const {
  return m_value;
}

void SensorMeasurement::setValue(SensorMeasurement_anyOf value) {
  m_value = value;
}

SensorMeasurement_anyOf::eSensorMeasurement_anyOf
SensorMeasurement::getEnumValue() const {
  return m_value.getValue();
}

void SensorMeasurement::setEnumValue(
    SensorMeasurement_anyOf::eSensorMeasurement_anyOf value) {
  m_value.setValue(value);
}

}  // namespace ngkore::model::common
