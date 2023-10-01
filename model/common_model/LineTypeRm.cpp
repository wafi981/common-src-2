
#include "LineTypeRm.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

LineTypeRm::LineTypeRm() {}

bool LineTypeRm::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "LineTypeRm" : pathPrefix;

  return success;
}

void to_json(nlohmann::json& j, const LineTypeRm& o) {
  j = nlohmann::json();

  if (o.m_value.getValue() ==
      LineType_anyOf::eLineType_anyOf::INVALID_VALUE_OPENAPI_GENERATED) {
    j = nullptr;
  } else {
    to_json(j, o.m_value);
  }
}

void from_json(const nlohmann::json& j, LineTypeRm& o) {
  if (j.is_null()) {
    o.setEnumValue(
        LineType_anyOf::eLineType_anyOf::INVALID_VALUE_OPENAPI_GENERATED);
  } else {
    from_json(j, o.m_value);
  }
}

}  // namespace ngkore::model::common
