
#include "PositioningMethodMdt_anyOf.h"
#include "Helpers.h"
#include <stdexcept>
#include <sstream>

namespace ngkore::model::common {

PositioningMethodMdt_anyOf::PositioningMethodMdt_anyOf() {}

void PositioningMethodMdt_anyOf::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool PositioningMethodMdt_anyOf::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool PositioningMethodMdt_anyOf::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "PositioningMethodMdt_anyOf" : pathPrefix;

  if (m_value == PositioningMethodMdt_anyOf::ePositioningMethodMdt_anyOf::
                     INVALID_VALUE_OPENAPI_GENERATED) {
    success = false;
    msg << _pathPrefix << ": has no value;";
  }

  return success;
}

bool PositioningMethodMdt_anyOf::operator==(
    const PositioningMethodMdt_anyOf& rhs) const {
  return getValue() == rhs.getValue()

      ;
}

bool PositioningMethodMdt_anyOf::operator!=(
    const PositioningMethodMdt_anyOf& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const PositioningMethodMdt_anyOf& o) {
  j = nlohmann::json();

  switch (o.getValue()) {
    case PositioningMethodMdt_anyOf::ePositioningMethodMdt_anyOf::
        INVALID_VALUE_OPENAPI_GENERATED:
      j = "INVALID_VALUE_OPENAPI_GENERATED";
      break;
    case PositioningMethodMdt_anyOf::ePositioningMethodMdt_anyOf::GNSS:
      j = "GNSS";
      break;
    case PositioningMethodMdt_anyOf::ePositioningMethodMdt_anyOf::E_CELL_ID:
      j = "E_CELL_ID";
      break;
  }
}

void from_json(const nlohmann::json& j, PositioningMethodMdt_anyOf& o) {
  auto s = j.get<std::string>();
  if (s == "GNSS") {
    o.setValue(PositioningMethodMdt_anyOf::ePositioningMethodMdt_anyOf::GNSS);
  } else if (s == "E_CELL_ID") {
    o.setValue(
        PositioningMethodMdt_anyOf::ePositioningMethodMdt_anyOf::E_CELL_ID);
  } else {
    std::stringstream ss;
    ss << "Unexpected value " << s << " in json"
       << " cannot be converted to enum of type"
       << " PositioningMethodMdt_anyOf::ePositioningMethodMdt_anyOf";
    throw std::invalid_argument(ss.str());
  }
}

PositioningMethodMdt_anyOf::ePositioningMethodMdt_anyOf
PositioningMethodMdt_anyOf::getValue() const {
  return m_value;
}
void PositioningMethodMdt_anyOf::setValue(
    PositioningMethodMdt_anyOf::ePositioningMethodMdt_anyOf value) {
  m_value = value;
}

}  // namespace ngkore::model::common
