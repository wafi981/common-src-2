
#include "NotificationControlRm.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

NotificationControlRm::NotificationControlRm() {}

bool NotificationControlRm::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "NotificationControlRm" : pathPrefix;

  return success;
}

void to_json(nlohmann::json& j, const NotificationControlRm& o) {
  j = nlohmann::json();
  if (o.m_value.getValue() ==
      NotificationControl_anyOf::eNotificationControl_anyOf::
          INVALID_VALUE_OPENAPI_GENERATED) {
    j = nullptr;
  } else {
    to_json(j, o.m_value);
  }
}

void from_json(const nlohmann::json& j, NotificationControlRm& o) {
  if (j.is_null()) {
    o.setEnumValue(NotificationControl_anyOf::eNotificationControl_anyOf::
                       INVALID_VALUE_OPENAPI_GENERATED);
  } else {
    from_json(j, o.m_value);
  }
}

}  // namespace ngkore::model::common
