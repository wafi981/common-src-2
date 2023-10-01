
#include "StationaryIndication_anyOf.h"
#include "Helpers.h"
#include <stdexcept>
#include <sstream>

namespace ngkore::model::common {

StationaryIndication_anyOf::StationaryIndication_anyOf() {}

void StationaryIndication_anyOf::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool StationaryIndication_anyOf::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool StationaryIndication_anyOf::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "StationaryIndication_anyOf" : pathPrefix;

  if (m_value == StationaryIndication_anyOf::eStationaryIndication_anyOf::
                     INVALID_VALUE_OPENAPI_GENERATED) {
    success = false;
    msg << _pathPrefix << ": has no value;";
  }

  return success;
}

bool StationaryIndication_anyOf::operator==(
    const StationaryIndication_anyOf& rhs) const {
  return getValue() == rhs.getValue()

      ;
}

bool StationaryIndication_anyOf::operator!=(
    const StationaryIndication_anyOf& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const StationaryIndication_anyOf& o) {
  j = nlohmann::json();

  switch (o.getValue()) {
    case StationaryIndication_anyOf::eStationaryIndication_anyOf::
        INVALID_VALUE_OPENAPI_GENERATED:
      j = "INVALID_VALUE_OPENAPI_GENERATED";
      break;
    case StationaryIndication_anyOf::eStationaryIndication_anyOf::STATIONARY:
      j = "STATIONARY";
      break;
    case StationaryIndication_anyOf::eStationaryIndication_anyOf::MOBILE:
      j = "MOBILE";
      break;
  }
}

void from_json(const nlohmann::json& j, StationaryIndication_anyOf& o) {
  auto s = j.get<std::string>();
  if (s == "STATIONARY") {
    o.setValue(
        StationaryIndication_anyOf::eStationaryIndication_anyOf::STATIONARY);
  } else if (s == "MOBILE") {
    o.setValue(StationaryIndication_anyOf::eStationaryIndication_anyOf::MOBILE);
  } else {
    std::stringstream ss;
    ss << "Unexpected value " << s << " in json"
       << " cannot be converted to enum of type"
       << " StationaryIndication_anyOf::eStationaryIndication_anyOf";
    throw std::invalid_argument(ss.str());
  }
}

StationaryIndication_anyOf::eStationaryIndication_anyOf
StationaryIndication_anyOf::getValue() const {
  return m_value;
}
void StationaryIndication_anyOf::setValue(
    StationaryIndication_anyOf::eStationaryIndication_anyOf value) {
  m_value = value;
}

}  // namespace ngkore::model::common
