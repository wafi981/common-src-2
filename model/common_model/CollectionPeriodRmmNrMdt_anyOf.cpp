
#include "CollectionPeriodRmmNrMdt_anyOf.h"
#include "Helpers.h"
#include <stdexcept>
#include <sstream>

namespace ngkore::model::common {

CollectionPeriodRmmNrMdt_anyOf::CollectionPeriodRmmNrMdt_anyOf() {}

void CollectionPeriodRmmNrMdt_anyOf::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool CollectionPeriodRmmNrMdt_anyOf::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool CollectionPeriodRmmNrMdt_anyOf::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "CollectionPeriodRmmNrMdt_anyOf" : pathPrefix;

  if (m_value ==
      CollectionPeriodRmmNrMdt_anyOf::eCollectionPeriodRmmNrMdt_anyOf::
          INVALID_VALUE_OPENAPI_GENERATED) {
    success = false;
    msg << _pathPrefix << ": has no value;";
  }

  return success;
}

bool CollectionPeriodRmmNrMdt_anyOf::operator==(
    const CollectionPeriodRmmNrMdt_anyOf& rhs) const {
  return getValue() == rhs.getValue()

      ;
}

bool CollectionPeriodRmmNrMdt_anyOf::operator!=(
    const CollectionPeriodRmmNrMdt_anyOf& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const CollectionPeriodRmmNrMdt_anyOf& o) {
  j = nlohmann::json();

  switch (o.getValue()) {
    case CollectionPeriodRmmNrMdt_anyOf::eCollectionPeriodRmmNrMdt_anyOf::
        INVALID_VALUE_OPENAPI_GENERATED:
      j = "INVALID_VALUE_OPENAPI_GENERATED";
      break;
    case CollectionPeriodRmmNrMdt_anyOf::eCollectionPeriodRmmNrMdt_anyOf::_1024:
      j = "1024";
      break;
    case CollectionPeriodRmmNrMdt_anyOf::eCollectionPeriodRmmNrMdt_anyOf::_2048:
      j = "2048";
      break;
    case CollectionPeriodRmmNrMdt_anyOf::eCollectionPeriodRmmNrMdt_anyOf::_5120:
      j = "5120";
      break;
    case CollectionPeriodRmmNrMdt_anyOf::eCollectionPeriodRmmNrMdt_anyOf::
        _10240:
      j = "10240";
      break;
    case CollectionPeriodRmmNrMdt_anyOf::eCollectionPeriodRmmNrMdt_anyOf::
        _60000:
      j = "60000";
      break;
  }
}

void from_json(const nlohmann::json& j, CollectionPeriodRmmNrMdt_anyOf& o) {
  auto s = j.get<std::string>();
  if (s == "1024") {
    o.setValue(
        CollectionPeriodRmmNrMdt_anyOf::eCollectionPeriodRmmNrMdt_anyOf::_1024);
  } else if (s == "2048") {
    o.setValue(
        CollectionPeriodRmmNrMdt_anyOf::eCollectionPeriodRmmNrMdt_anyOf::_2048);
  } else if (s == "5120") {
    o.setValue(
        CollectionPeriodRmmNrMdt_anyOf::eCollectionPeriodRmmNrMdt_anyOf::_5120);
  } else if (s == "10240") {
    o.setValue(CollectionPeriodRmmNrMdt_anyOf::eCollectionPeriodRmmNrMdt_anyOf::
                   _10240);
  } else if (s == "60000") {
    o.setValue(CollectionPeriodRmmNrMdt_anyOf::eCollectionPeriodRmmNrMdt_anyOf::
                   _60000);
  } else {
    std::stringstream ss;
    ss << "Unexpected value " << s << " in json"
       << " cannot be converted to enum of type"
       << " CollectionPeriodRmmNrMdt_anyOf::eCollectionPeriodRmmNrMdt_anyOf";
    throw std::invalid_argument(ss.str());
  }
}

CollectionPeriodRmmNrMdt_anyOf::eCollectionPeriodRmmNrMdt_anyOf
CollectionPeriodRmmNrMdt_anyOf::getValue() const {
  return m_value;
}
void CollectionPeriodRmmNrMdt_anyOf::setValue(
    CollectionPeriodRmmNrMdt_anyOf::eCollectionPeriodRmmNrMdt_anyOf value) {
  m_value = value;
}

}  // namespace ngkore::model::common
