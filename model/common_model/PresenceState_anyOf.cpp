
#include "PresenceState_anyOf.h"
#include "Helpers.h"
#include <stdexcept>
#include <sstream>

namespace ngkore::model::common {

PresenceState_anyOf::PresenceState_anyOf() {}

void PresenceState_anyOf::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool PresenceState_anyOf::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool PresenceState_anyOf::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "PresenceState_anyOf" : pathPrefix;

  if (m_value == PresenceState_anyOf::ePresenceState_anyOf::
                     INVALID_VALUE_OPENAPI_GENERATED) {
    success = false;
    msg << _pathPrefix << ": has no value;";
  }

  return success;
}

bool PresenceState_anyOf::operator==(const PresenceState_anyOf& rhs) const {
  return getValue() == rhs.getValue()

      ;
}

bool PresenceState_anyOf::operator!=(const PresenceState_anyOf& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const PresenceState_anyOf& o) {
  j = nlohmann::json();

  switch (o.getValue()) {
    case PresenceState_anyOf::ePresenceState_anyOf::
        INVALID_VALUE_OPENAPI_GENERATED:
      j = "INVALID_VALUE_OPENAPI_GENERATED";
      break;
    case PresenceState_anyOf::ePresenceState_anyOf::IN_AREA:
      j = "IN_AREA";
      break;
    case PresenceState_anyOf::ePresenceState_anyOf::OUT_OF_AREA:
      j = "OUT_OF_AREA";
      break;
    case PresenceState_anyOf::ePresenceState_anyOf::UNKNOWN:
      j = "UNKNOWN";
      break;
    case PresenceState_anyOf::ePresenceState_anyOf::INACTIVE:
      j = "INACTIVE";
      break;
  }
}

void from_json(const nlohmann::json& j, PresenceState_anyOf& o) {
  auto s = j.get<std::string>();
  if (s == "IN_AREA") {
    o.setValue(PresenceState_anyOf::ePresenceState_anyOf::IN_AREA);
  } else if (s == "OUT_OF_AREA") {
    o.setValue(PresenceState_anyOf::ePresenceState_anyOf::OUT_OF_AREA);
  } else if (s == "UNKNOWN") {
    o.setValue(PresenceState_anyOf::ePresenceState_anyOf::UNKNOWN);
  } else if (s == "INACTIVE") {
    o.setValue(PresenceState_anyOf::ePresenceState_anyOf::INACTIVE);
  } else {
    std::stringstream ss;
    ss << "Unexpected value " << s << " in json"
       << " cannot be converted to enum of type"
       << " PresenceState_anyOf::ePresenceState_anyOf";
    throw std::invalid_argument(ss.str());
  }
}

PresenceState_anyOf::ePresenceState_anyOf PresenceState_anyOf::getValue()
    const {
  return m_value;
}
void PresenceState_anyOf::setValue(
    PresenceState_anyOf::ePresenceState_anyOf value) {
  m_value = value;
}

}  // namespace ngkore::model::common