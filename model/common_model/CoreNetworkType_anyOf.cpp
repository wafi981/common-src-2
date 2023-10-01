
#include "CoreNetworkType_anyOf.h"
#include "Helpers.h"
#include <stdexcept>
#include <sstream>

namespace ngkore::model::common {

CoreNetworkType_anyOf::CoreNetworkType_anyOf() {}

void CoreNetworkType_anyOf::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool CoreNetworkType_anyOf::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool CoreNetworkType_anyOf::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "CoreNetworkType_anyOf" : pathPrefix;

  if (m_value == CoreNetworkType_anyOf::eCoreNetworkType_anyOf::
                     INVALID_VALUE_OPENAPI_GENERATED) {
    success = false;
    msg << _pathPrefix << ": has no value;";
  }

  return success;
}

bool CoreNetworkType_anyOf::operator==(const CoreNetworkType_anyOf& rhs) const {
  return getValue() == rhs.getValue()

      ;
}

bool CoreNetworkType_anyOf::operator!=(const CoreNetworkType_anyOf& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const CoreNetworkType_anyOf& o) {
  j = nlohmann::json();

  switch (o.getValue()) {
    case CoreNetworkType_anyOf::eCoreNetworkType_anyOf::
        INVALID_VALUE_OPENAPI_GENERATED:
      j = "INVALID_VALUE_OPENAPI_GENERATED";
      break;
    case CoreNetworkType_anyOf::eCoreNetworkType_anyOf::_5GC:
      j = "5GC";
      break;
    case CoreNetworkType_anyOf::eCoreNetworkType_anyOf::EPC:
      j = "EPC";
      break;
  }
}

void from_json(const nlohmann::json& j, CoreNetworkType_anyOf& o) {
  auto s = j.get<std::string>();
  if (s == "5GC") {
    o.setValue(CoreNetworkType_anyOf::eCoreNetworkType_anyOf::_5GC);
  } else if (s == "EPC") {
    o.setValue(CoreNetworkType_anyOf::eCoreNetworkType_anyOf::EPC);
  } else {
    std::stringstream ss;
    ss << "Unexpected value " << s << " in json"
       << " cannot be converted to enum of type"
       << " CoreNetworkType_anyOf::eCoreNetworkType_anyOf";
    throw std::invalid_argument(ss.str());
  }
}

CoreNetworkType_anyOf::eCoreNetworkType_anyOf CoreNetworkType_anyOf::getValue()
    const {
  return m_value;
}
void CoreNetworkType_anyOf::setValue(
    CoreNetworkType_anyOf::eCoreNetworkType_anyOf value) {
  m_value = value;
}

}  // namespace ngkore::model::common
