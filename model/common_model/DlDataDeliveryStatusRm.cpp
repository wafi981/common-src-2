
#include "DlDataDeliveryStatusRm.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

DlDataDeliveryStatusRm::DlDataDeliveryStatusRm() {}

bool DlDataDeliveryStatusRm::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "DlDataDeliveryStatusRm" : pathPrefix;

  return success;
}

void to_json(nlohmann::json& j, const DlDataDeliveryStatusRm& o) {
  j = nlohmann::json();
  if (o.m_value.getValue() ==
      DlDataDeliveryStatus_anyOf::eDlDataDeliveryStatus_anyOf::
          INVALID_VALUE_OPENAPI_GENERATED) {
    j = nullptr;
  } else {
    to_json(j, o.m_value);
  }
}

void from_json(const nlohmann::json& j, DlDataDeliveryStatusRm& o) {
  if (j.is_null()) {
    o.m_value.setValue(DlDataDeliveryStatus_anyOf::eDlDataDeliveryStatus_anyOf::
                           INVALID_VALUE_OPENAPI_GENERATED);
  } else {
    from_json(j, o.m_value);
  }
}

}  // namespace ngkore::model::common
