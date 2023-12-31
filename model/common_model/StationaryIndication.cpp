
#include "StationaryIndication.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

StationaryIndication::StationaryIndication() {}

void StationaryIndication::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool StationaryIndication::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool StationaryIndication::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "StationaryIndication" : pathPrefix;

  if (!m_value.validate(msg)) {
    success = false;
  }
  return success;
}

bool StationaryIndication::operator==(const StationaryIndication& rhs) const {
  return

      getValue() == rhs.getValue();
}

bool StationaryIndication::operator!=(const StationaryIndication& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const StationaryIndication& o) {
  j = nlohmann::json();
  to_json(j, o.m_value);
}

void from_json(const nlohmann::json& j, StationaryIndication& o) {
  from_json(j, o.m_value);
}

StationaryIndication_anyOf StationaryIndication::getValue() const {
  return m_value;
}

void StationaryIndication::setValue(StationaryIndication_anyOf value) {
  m_value = value;
}

StationaryIndication_anyOf::eStationaryIndication_anyOf
StationaryIndication::getEnumValue() const {
  return m_value.getValue();
}

void StationaryIndication::setEnumValue(
    StationaryIndication_anyOf::eStationaryIndication_anyOf value) {
  m_value.setValue(value);
}

}  // namespace ngkore::model::common
