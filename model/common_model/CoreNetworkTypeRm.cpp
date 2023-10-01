
#include "CoreNetworkTypeRm.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

CoreNetworkTypeRm::CoreNetworkTypeRm() {}

bool CoreNetworkTypeRm::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "CoreNetworkTypeRm" : pathPrefix;

  return success;
}

void to_json(nlohmann::json& j, const CoreNetworkTypeRm& o) {
  j = nlohmann::json();
  if (o.m_value.getValue() == CoreNetworkType_anyOf::eCoreNetworkType_anyOf::
                                  INVALID_VALUE_OPENAPI_GENERATED) {
    j = nullptr;
  } else {
    to_json(j, o.m_value);
  }
}

void from_json(const nlohmann::json& j, CoreNetworkTypeRm& o) {
  if (j.is_null()) {
    o.m_value.setValue(CoreNetworkType_anyOf::eCoreNetworkType_anyOf::
                           INVALID_VALUE_OPENAPI_GENERATED);
  } else {
    from_json(j, o.m_value);
  }
}

}  // namespace ngkore::model::common
