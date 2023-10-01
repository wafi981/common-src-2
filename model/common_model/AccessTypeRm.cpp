
#include "AccessTypeRm.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

AccessTypeRm::AccessTypeRm() {}

bool AccessTypeRm::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "AccessTypeRm" : pathPrefix;

  return success;
}

void to_json(nlohmann::json& j, const AccessTypeRm& o) {
  j = nlohmann::json();

  switch (o.getValue()) {
    case AccessType::eAccessType::INVALID_VALUE_OPENAPI_GENERATED:
      j = nullptr;
      break;
    case AccessType::eAccessType::_3GPP_ACCESS:
      j = "3GPP_ACCESS";
      break;
    case AccessType::eAccessType::NON_3GPP_ACCESS:
      j = "NON_3GPP_ACCESS";
      break;
  }
}

void from_json(const nlohmann::json& j, AccessTypeRm& o) {
  if (!j) {
    o.setValue(AccessType::eAccessType::INVALID_VALUE_OPENAPI_GENERATED);
    return;
  }

  auto s = j.get<std::string>();
  if (s == "3GPP_ACCESS") {
    o.setValue(AccessType::eAccessType::_3GPP_ACCESS);
  } else if (s == "NON_3GPP_ACCESS") {
    o.setValue(AccessType::eAccessType::NON_3GPP_ACCESS);
  } else {
    std::stringstream ss;
    ss << "Unexpected value " << s << " in json"
       << " cannot be converted to enum of type"
       << " AccessType::eAccessType";
    throw std::invalid_argument(ss.str());
  }
}

}  // namespace ngkore::model::common
