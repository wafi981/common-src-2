
#include "CollectionPeriodRmmLteMdt.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

CollectionPeriodRmmLteMdt::CollectionPeriodRmmLteMdt() {}

void CollectionPeriodRmmLteMdt::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool CollectionPeriodRmmLteMdt::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool CollectionPeriodRmmLteMdt::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "CollectionPeriodRmmLteMdt" : pathPrefix;

  if (!m_value.validate(msg)) {
    success = false;
  }
  return success;
}

bool CollectionPeriodRmmLteMdt::operator==(
    const CollectionPeriodRmmLteMdt& rhs) const {
  return

      getValue() == rhs.getValue();
}

bool CollectionPeriodRmmLteMdt::operator!=(
    const CollectionPeriodRmmLteMdt& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const CollectionPeriodRmmLteMdt& o) {
  j = nlohmann::json();
  to_json(j, o.m_value);
}

void from_json(const nlohmann::json& j, CollectionPeriodRmmLteMdt& o) {
  from_json(j, o.m_value);
}

CollectionPeriodRmmLteMdt_anyOf CollectionPeriodRmmLteMdt::getValue() const {
  return m_value;
}

void CollectionPeriodRmmLteMdt::setValue(
    CollectionPeriodRmmLteMdt_anyOf value) {
  m_value = value;
}

CollectionPeriodRmmLteMdt_anyOf::eCollectionPeriodRmmLteMdt_anyOf
CollectionPeriodRmmLteMdt::getEnumValue() const {
  return m_value.getValue();
}

void CollectionPeriodRmmLteMdt::setEnumValue(
    CollectionPeriodRmmLteMdt_anyOf::eCollectionPeriodRmmLteMdt_anyOf value) {
  m_value.setValue(value);
}

}  // namespace ngkore::model::common
