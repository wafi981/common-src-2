
#include "SensorMeasurement_anyOf.h"
#include "Helpers.h"
#include <stdexcept>
#include <sstream>

namespace ngkore::model::common {

SensorMeasurement_anyOf::SensorMeasurement_anyOf() {}

void SensorMeasurement_anyOf::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool SensorMeasurement_anyOf::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool SensorMeasurement_anyOf::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "SensorMeasurement_anyOf" : pathPrefix;

  if (m_value == SensorMeasurement_anyOf::eSensorMeasurement_anyOf::
                     INVALID_VALUE_OPENAPI_GENERATED) {
    success = false;
    msg << _pathPrefix << ": has no value;";
  }

  return success;
}

bool SensorMeasurement_anyOf::operator==(
    const SensorMeasurement_anyOf& rhs) const {
  return getValue() == rhs.getValue()

      ;
}

bool SensorMeasurement_anyOf::operator!=(
    const SensorMeasurement_anyOf& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const SensorMeasurement_anyOf& o) {
  j = nlohmann::json();

  switch (o.getValue()) {
    case SensorMeasurement_anyOf::eSensorMeasurement_anyOf::
        INVALID_VALUE_OPENAPI_GENERATED:
      j = "INVALID_VALUE_OPENAPI_GENERATED";
      break;
    case SensorMeasurement_anyOf::eSensorMeasurement_anyOf::BAROMETRIC_PRESSURE:
      j = "BAROMETRIC_PRESSURE";
      break;
    case SensorMeasurement_anyOf::eSensorMeasurement_anyOf::UE_SPEED:
      j = "UE_SPEED";
      break;
    case SensorMeasurement_anyOf::eSensorMeasurement_anyOf::UE_ORIENTATION:
      j = "UE_ORIENTATION";
      break;
  }
}

void from_json(const nlohmann::json& j, SensorMeasurement_anyOf& o) {
  auto s = j.get<std::string>();
  if (s == "BAROMETRIC_PRESSURE") {
    o.setValue(
        SensorMeasurement_anyOf::eSensorMeasurement_anyOf::BAROMETRIC_PRESSURE);
  } else if (s == "UE_SPEED") {
    o.setValue(SensorMeasurement_anyOf::eSensorMeasurement_anyOf::UE_SPEED);
  } else if (s == "UE_ORIENTATION") {
    o.setValue(
        SensorMeasurement_anyOf::eSensorMeasurement_anyOf::UE_ORIENTATION);
  } else {
    std::stringstream ss;
    ss << "Unexpected value " << s << " in json"
       << " cannot be converted to enum of type"
       << " SensorMeasurement_anyOf::eSensorMeasurement_anyOf";
    throw std::invalid_argument(ss.str());
  }
}

SensorMeasurement_anyOf::eSensorMeasurement_anyOf
SensorMeasurement_anyOf::getValue() const {
  return m_value;
}
void SensorMeasurement_anyOf::setValue(
    SensorMeasurement_anyOf::eSensorMeasurement_anyOf value) {
  m_value = value;
}

}  // namespace ngkore::model::common
