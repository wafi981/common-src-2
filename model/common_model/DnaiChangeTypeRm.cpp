
#include "DnaiChangeTypeRm.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

DnaiChangeTypeRm::DnaiChangeTypeRm() {}

bool DnaiChangeTypeRm::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "DnaiChangeTypeRm" : pathPrefix;

  return success;
}

void to_json(nlohmann::json& j, const DnaiChangeTypeRm& o) {
  j = nlohmann::json();
  if (o.m_value.getValue() == DnaiChangeType_anyOf::eDnaiChangeType_anyOf::
                                  INVALID_VALUE_OPENAPI_GENERATED) {
    j = nullptr;
  } else {
    to_json(j, o.m_value);
  }
}

void from_json(const nlohmann::json& j, DnaiChangeTypeRm& o) {
  if (j.is_null()) {
    o.m_value.setValue(DnaiChangeType_anyOf::eDnaiChangeType_anyOf::
                           INVALID_VALUE_OPENAPI_GENERATED);
  } else {
    from_json(j, o.m_value);
  }
}

}  // namespace ngkore::model::common
