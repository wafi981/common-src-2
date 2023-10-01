
#include "LcsServiceAuth_anyOf.h"
#include "Helpers.h"
#include <stdexcept>
#include <sstream>

namespace ngkore::model::common {

LcsServiceAuth_anyOf::LcsServiceAuth_anyOf() {}

void LcsServiceAuth_anyOf::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool LcsServiceAuth_anyOf::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool LcsServiceAuth_anyOf::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "LcsServiceAuth_anyOf" : pathPrefix;

  if (m_value == LcsServiceAuth_anyOf::eLcsServiceAuth_anyOf::
                     INVALID_VALUE_OPENAPI_GENERATED) {
    success = false;
    msg << _pathPrefix << ": has no value;";
  }

  return success;
}

bool LcsServiceAuth_anyOf::operator==(const LcsServiceAuth_anyOf& rhs) const {
  return getValue() == rhs.getValue()

      ;
}

bool LcsServiceAuth_anyOf::operator!=(const LcsServiceAuth_anyOf& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const LcsServiceAuth_anyOf& o) {
  j = nlohmann::json();

  switch (o.getValue()) {
    case LcsServiceAuth_anyOf::eLcsServiceAuth_anyOf::
        INVALID_VALUE_OPENAPI_GENERATED:
      j = "INVALID_VALUE_OPENAPI_GENERATED";
      break;
    case LcsServiceAuth_anyOf::eLcsServiceAuth_anyOf::
        LOCATION_ALLOWED_WITH_NOTIFICATION:
      j = "LOCATION_ALLOWED_WITH_NOTIFICATION";
      break;
    case LcsServiceAuth_anyOf::eLcsServiceAuth_anyOf::
        LOCATION_ALLOWED_WITHOUT_NOTIFICATION:
      j = "LOCATION_ALLOWED_WITHOUT_NOTIFICATION";
      break;
    case LcsServiceAuth_anyOf::eLcsServiceAuth_anyOf::
        LOCATION_ALLOWED_WITHOUT_RESPONSE:
      j = "LOCATION_ALLOWED_WITHOUT_RESPONSE";
      break;
    case LcsServiceAuth_anyOf::eLcsServiceAuth_anyOf::
        LOCATION_RESTRICTED_WITHOUT_RESPONSE:
      j = "LOCATION_RESTRICTED_WITHOUT_RESPONSE";
      break;
    case LcsServiceAuth_anyOf::eLcsServiceAuth_anyOf::NOTIFICATION_ONLY:
      j = "NOTIFICATION_ONLY";
      break;
    case LcsServiceAuth_anyOf::eLcsServiceAuth_anyOf::
        NOTIFICATION_AND_VERIFICATION_ONLY:
      j = "NOTIFICATION_AND_VERIFICATION_ONLY";
      break;
  }
}

void from_json(const nlohmann::json& j, LcsServiceAuth_anyOf& o) {
  auto s = j.get<std::string>();
  if (s == "LOCATION_ALLOWED_WITH_NOTIFICATION") {
    o.setValue(LcsServiceAuth_anyOf::eLcsServiceAuth_anyOf::
                   LOCATION_ALLOWED_WITH_NOTIFICATION);
  } else if (s == "LOCATION_ALLOWED_WITHOUT_NOTIFICATION") {
    o.setValue(LcsServiceAuth_anyOf::eLcsServiceAuth_anyOf::
                   LOCATION_ALLOWED_WITHOUT_NOTIFICATION);
  } else if (s == "LOCATION_ALLOWED_WITHOUT_RESPONSE") {
    o.setValue(LcsServiceAuth_anyOf::eLcsServiceAuth_anyOf::
                   LOCATION_ALLOWED_WITHOUT_RESPONSE);
  } else if (s == "LOCATION_RESTRICTED_WITHOUT_RESPONSE") {
    o.setValue(LcsServiceAuth_anyOf::eLcsServiceAuth_anyOf::
                   LOCATION_RESTRICTED_WITHOUT_RESPONSE);
  } else if (s == "NOTIFICATION_ONLY") {
    o.setValue(LcsServiceAuth_anyOf::eLcsServiceAuth_anyOf::NOTIFICATION_ONLY);
  } else if (s == "NOTIFICATION_AND_VERIFICATION_ONLY") {
    o.setValue(LcsServiceAuth_anyOf::eLcsServiceAuth_anyOf::
                   NOTIFICATION_AND_VERIFICATION_ONLY);
  } else {
    std::stringstream ss;
    ss << "Unexpected value " << s << " in json"
       << " cannot be converted to enum of type"
       << " LcsServiceAuth_anyOf::eLcsServiceAuth_anyOf";
    throw std::invalid_argument(ss.str());
  }
}

LcsServiceAuth_anyOf::eLcsServiceAuth_anyOf LcsServiceAuth_anyOf::getValue()
    const {
  return m_value;
}
void LcsServiceAuth_anyOf::setValue(
    LcsServiceAuth_anyOf::eLcsServiceAuth_anyOf value) {
  m_value = value;
}

}  // namespace ngkore::model::common
