
#include "MeasurementNrForMdt.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

MeasurementNrForMdt::MeasurementNrForMdt() {}

void MeasurementNrForMdt::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool MeasurementNrForMdt::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool MeasurementNrForMdt::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "MeasurementNrForMdt" : pathPrefix;

  if (!m_value.validate(msg)) {
    success = false;
  }
  return success;
}

bool MeasurementNrForMdt::operator==(const MeasurementNrForMdt& rhs) const {
  return

      getValue() == rhs.getValue();
}

bool MeasurementNrForMdt::operator!=(const MeasurementNrForMdt& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const MeasurementNrForMdt& o) {
  j = nlohmann::json();
  to_json(j, o.m_value);
}

void from_json(const nlohmann::json& j, MeasurementNrForMdt& o) {
  from_json(j, o.m_value);
}

MeasurementLteForMdt_anyOf MeasurementNrForMdt::getValue() const {
  return m_value;
}

void MeasurementNrForMdt::setValue(MeasurementLteForMdt_anyOf value) {
  m_value = value;
}

MeasurementLteForMdt_anyOf::eMeasurementLteForMdt_anyOf
MeasurementNrForMdt::getEnumValue() const {
  return m_value.getValue();
}

void MeasurementNrForMdt::setEnumValue(
    MeasurementLteForMdt_anyOf::eMeasurementLteForMdt_anyOf value) {
  m_value.setValue(value);
}

}  // namespace ngkore::model::common
