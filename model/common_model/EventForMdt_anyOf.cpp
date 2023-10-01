
#include "EventForMdt_anyOf.h"
#include "Helpers.h"
#include <stdexcept>
#include <sstream>

namespace ngkore::model::common {

EventForMdt_anyOf::EventForMdt_anyOf() {}

void EventForMdt_anyOf::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool EventForMdt_anyOf::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool EventForMdt_anyOf::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "EventForMdt_anyOf" : pathPrefix;

  if (m_value ==
      EventForMdt_anyOf::eEventForMdt_anyOf::INVALID_VALUE_OPENAPI_GENERATED) {
    success = false;
    msg << _pathPrefix << ": has no value;";
  }

  return success;
}

bool EventForMdt_anyOf::operator==(const EventForMdt_anyOf& rhs) const {
  return getValue() == rhs.getValue()

      ;
}

bool EventForMdt_anyOf::operator!=(const EventForMdt_anyOf& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const EventForMdt_anyOf& o) {
  j = nlohmann::json();

  switch (o.getValue()) {
    case EventForMdt_anyOf::eEventForMdt_anyOf::INVALID_VALUE_OPENAPI_GENERATED:
      j = "INVALID_VALUE_OPENAPI_GENERATED";
      break;
    case EventForMdt_anyOf::eEventForMdt_anyOf::OUT_OF_COVERAG:
      j = "OUT_OF_COVERAG";
      break;
    case EventForMdt_anyOf::eEventForMdt_anyOf::A2_EVENT:
      j = "A2_EVENT";
      break;
  }
}

void from_json(const nlohmann::json& j, EventForMdt_anyOf& o) {
  auto s = j.get<std::string>();
  if (s == "OUT_OF_COVERAG") {
    o.setValue(EventForMdt_anyOf::eEventForMdt_anyOf::OUT_OF_COVERAG);
  } else if (s == "A2_EVENT") {
    o.setValue(EventForMdt_anyOf::eEventForMdt_anyOf::A2_EVENT);
  } else {
    std::stringstream ss;
    ss << "Unexpected value " << s << " in json"
       << " cannot be converted to enum of type"
       << " EventForMdt_anyOf::eEventForMdt_anyOf";
    throw std::invalid_argument(ss.str());
  }
}

EventForMdt_anyOf::eEventForMdt_anyOf EventForMdt_anyOf::getValue() const {
  return m_value;
}
void EventForMdt_anyOf::setValue(EventForMdt_anyOf::eEventForMdt_anyOf value) {
  m_value = value;
}

}  // namespace ngkore::model::common
