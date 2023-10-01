
#include "MeasurementLteForMdt.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

MeasurementLteForMdt::MeasurementLteForMdt() {}

void MeasurementLteForMdt::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool MeasurementLteForMdt::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool MeasurementLteForMdt::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "MeasurementLteForMdt" : pathPrefix;

  if (!m_value.validate(msg)) {
    success = false;
  }
  return success;
}

bool MeasurementLteForMdt::operator==(const MeasurementLteForMdt& rhs) const {
  return

      getValue() == rhs.getValue();
}

bool MeasurementLteForMdt::operator!=(const MeasurementLteForMdt& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const MeasurementLteForMdt& o) {
  j = nlohmann::json();
  to_json(j, o.m_value);
}

void from_json(const nlohmann::json& j, MeasurementLteForMdt& o) {
  from_json(j, o.m_value);
}

MeasurementLteForMdt_anyOf MeasurementLteForMdt::getValue() const {
  return m_value;
}

void MeasurementLteForMdt::setValue(MeasurementLteForMdt_anyOf value) {
  m_value = value;
}

MeasurementLteForMdt_anyOf::eMeasurementLteForMdt_anyOf
MeasurementLteForMdt::getEnumValue() const {
  return m_value.getValue();
}

void MeasurementLteForMdt::setEnumValue(
    MeasurementLteForMdt_anyOf::eMeasurementLteForMdt_anyOf value) {
  m_value.setValue(value);
}

}  // namespace ngkore::model::common
