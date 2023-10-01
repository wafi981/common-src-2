
#include "ScheduledCommunicationType_anyOf.h"
#include "Helpers.h"
#include <stdexcept>
#include <sstream>

namespace ngkore::model::common {

ScheduledCommunicationType_anyOf::ScheduledCommunicationType_anyOf() {}

void ScheduledCommunicationType_anyOf::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool ScheduledCommunicationType_anyOf::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool ScheduledCommunicationType_anyOf::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "ScheduledCommunicationType_anyOf" : pathPrefix;

  if (m_value ==
      ScheduledCommunicationType_anyOf::eScheduledCommunicationType_anyOf::
          INVALID_VALUE_OPENAPI_GENERATED) {
    success = false;
    msg << _pathPrefix << ": has no value;";
  }

  return success;
}

bool ScheduledCommunicationType_anyOf::operator==(
    const ScheduledCommunicationType_anyOf& rhs) const {
  return getValue() == rhs.getValue()

      ;
}

bool ScheduledCommunicationType_anyOf::operator!=(
    const ScheduledCommunicationType_anyOf& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const ScheduledCommunicationType_anyOf& o) {
  j = nlohmann::json();

  switch (o.getValue()) {
    case ScheduledCommunicationType_anyOf::eScheduledCommunicationType_anyOf::
        INVALID_VALUE_OPENAPI_GENERATED:
      j = "INVALID_VALUE_OPENAPI_GENERATED";
      break;
    case ScheduledCommunicationType_anyOf::eScheduledCommunicationType_anyOf::
        DOWNLINK_ONLY:
      j = "DOWNLINK_ONLY";
      break;
    case ScheduledCommunicationType_anyOf::eScheduledCommunicationType_anyOf::
        UPLINK_ONLY:
      j = "UPLINK_ONLY";
      break;
    case ScheduledCommunicationType_anyOf::eScheduledCommunicationType_anyOf::
        BIDIRECTIONAL:
      j = "BIDIRECTIONAL";
      break;
  }
}

void from_json(const nlohmann::json& j, ScheduledCommunicationType_anyOf& o) {
  auto s = j.get<std::string>();
  if (s == "DOWNLINK_ONLY") {
    o.setValue(ScheduledCommunicationType_anyOf::
                   eScheduledCommunicationType_anyOf::DOWNLINK_ONLY);
  } else if (s == "UPLINK_ONLY") {
    o.setValue(ScheduledCommunicationType_anyOf::
                   eScheduledCommunicationType_anyOf::UPLINK_ONLY);
  } else if (s == "BIDIRECTIONAL") {
    o.setValue(ScheduledCommunicationType_anyOf::
                   eScheduledCommunicationType_anyOf::BIDIRECTIONAL);
  } else {
    std::stringstream ss;
    ss << "Unexpected value " << s << " in json"
       << " cannot be converted to enum of type"
       << " ScheduledCommunicationType_anyOf::eScheduledCommunicationType_"
          "anyOf";
    throw std::invalid_argument(ss.str());
  }
}

ScheduledCommunicationType_anyOf::eScheduledCommunicationType_anyOf
ScheduledCommunicationType_anyOf::getValue() const {
  return m_value;
}
void ScheduledCommunicationType_anyOf::setValue(
    ScheduledCommunicationType_anyOf::eScheduledCommunicationType_anyOf value) {
  m_value = value;
}

}  // namespace ngkore::model::common
