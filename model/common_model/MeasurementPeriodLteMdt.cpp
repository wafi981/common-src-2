
#include "MeasurementPeriodLteMdt.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

MeasurementPeriodLteMdt::MeasurementPeriodLteMdt() {}

void MeasurementPeriodLteMdt::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool MeasurementPeriodLteMdt::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool MeasurementPeriodLteMdt::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "MeasurementPeriodLteMdt" : pathPrefix;

  if (!m_value.validate(msg)) {
    success = false;
  }
  return success;
}

bool MeasurementPeriodLteMdt::operator==(
    const MeasurementPeriodLteMdt& rhs) const {
  return

      getValue() == rhs.getValue();
}

bool MeasurementPeriodLteMdt::operator!=(
    const MeasurementPeriodLteMdt& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const MeasurementPeriodLteMdt& o) {
  j = nlohmann::json();
  to_json(j, o.m_value);
}

void from_json(const nlohmann::json& j, MeasurementPeriodLteMdt& o) {
  from_json(j, o.m_value);
}

CollectionPeriodRmmLteMdt_anyOf MeasurementPeriodLteMdt::getValue() const {
  return m_value;
}

void MeasurementPeriodLteMdt::setValue(CollectionPeriodRmmLteMdt_anyOf value) {
  m_value = value;
}

CollectionPeriodRmmLteMdt_anyOf::eCollectionPeriodRmmLteMdt_anyOf
MeasurementPeriodLteMdt::getEnumValue() const {
  return m_value.getValue();
}

void MeasurementPeriodLteMdt::setEnumValue(
    CollectionPeriodRmmLteMdt_anyOf::eCollectionPeriodRmmLteMdt_anyOf value) {
  m_value.setValue(value);
}

}  // namespace ngkore::model::common
