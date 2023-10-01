
#include "NotificationControl_anyOf.h"
#include "Helpers.h"
#include <stdexcept>
#include <sstream>

namespace ngkore::model::common {

NotificationControl_anyOf::NotificationControl_anyOf() {}

void NotificationControl_anyOf::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool NotificationControl_anyOf::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool NotificationControl_anyOf::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "NotificationControl_anyOf" : pathPrefix;

  if (m_value == NotificationControl_anyOf::eNotificationControl_anyOf::
                     INVALID_VALUE_OPENAPI_GENERATED) {
    success = false;
    msg << _pathPrefix << ": has no value;";
  }

  return success;
}

bool NotificationControl_anyOf::operator==(
    const NotificationControl_anyOf& rhs) const {
  return getValue() == rhs.getValue()

      ;
}

bool NotificationControl_anyOf::operator!=(
    const NotificationControl_anyOf& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const NotificationControl_anyOf& o) {
  j = nlohmann::json();

  switch (o.getValue()) {
    case NotificationControl_anyOf::eNotificationControl_anyOf::
        INVALID_VALUE_OPENAPI_GENERATED:
      j = "INVALID_VALUE_OPENAPI_GENERATED";
      break;
    case NotificationControl_anyOf::eNotificationControl_anyOf::REQUESTED:
      j = "REQUESTED";
      break;
    case NotificationControl_anyOf::eNotificationControl_anyOf::NOT_REQUESTED:
      j = "NOT_REQUESTED";
      break;
  }
}

void from_json(const nlohmann::json& j, NotificationControl_anyOf& o) {
  auto s = j.get<std::string>();
  if (s == "REQUESTED") {
    o.setValue(
        NotificationControl_anyOf::eNotificationControl_anyOf::REQUESTED);
  } else if (s == "NOT_REQUESTED") {
    o.setValue(
        NotificationControl_anyOf::eNotificationControl_anyOf::NOT_REQUESTED);
  } else {
    std::stringstream ss;
    ss << "Unexpected value " << s << " in json"
       << " cannot be converted to enum of type"
       << " NotificationControl_anyOf::eNotificationControl_anyOf";
    throw std::invalid_argument(ss.str());
  }
}

NotificationControl_anyOf::eNotificationControl_anyOf
NotificationControl_anyOf::getValue() const {
  return m_value;
}
void NotificationControl_anyOf::setValue(
    NotificationControl_anyOf::eNotificationControl_anyOf value) {
  m_value = value;
}

}  // namespace ngkore::model::common
