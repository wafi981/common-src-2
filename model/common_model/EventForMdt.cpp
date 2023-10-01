
#include "EventForMdt.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

EventForMdt::EventForMdt() {}

void EventForMdt::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool EventForMdt::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool EventForMdt::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "EventForMdt" : pathPrefix;

  if (!m_value.validate(msg)) {
    success = false;
  }
  return success;
}

bool EventForMdt::operator==(const EventForMdt& rhs) const {
  return

      getValue() == rhs.getValue();
}

bool EventForMdt::operator!=(const EventForMdt& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const EventForMdt& o) {
  j = nlohmann::json();
  to_json(j, o.m_value);
}

void from_json(const nlohmann::json& j, EventForMdt& o) {
  from_json(j, o.m_value);
}

EventForMdt_anyOf EventForMdt::getValue() const {
  return m_value;
}

void EventForMdt::setValue(EventForMdt_anyOf value) {
  m_value = value;
}

EventForMdt_anyOf::eEventForMdt_anyOf EventForMdt::getEnumValue() const {
  return m_value.getValue();
}

void EventForMdt::setEnumValue(EventForMdt_anyOf::eEventForMdt_anyOf value) {
  m_value.setValue(value);
}

}  // namespace ngkore::model::common
