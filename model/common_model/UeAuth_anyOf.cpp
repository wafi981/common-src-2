
#include "UeAuth_anyOf.h"
#include "Helpers.h"
#include <stdexcept>
#include <sstream>

namespace ngkore::model::common {

UeAuth_anyOf::UeAuth_anyOf() {}

void UeAuth_anyOf::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool UeAuth_anyOf::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool UeAuth_anyOf::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "UeAuth_anyOf" : pathPrefix;

  if (m_value == UeAuth_anyOf::eUeAuth_anyOf::INVALID_VALUE_OPENAPI_GENERATED) {
    success = false;
    msg << _pathPrefix << ": has no value;";
  }

  return success;
}

bool UeAuth_anyOf::operator==(const UeAuth_anyOf& rhs) const {
  return getValue() == rhs.getValue()

      ;
}

bool UeAuth_anyOf::operator!=(const UeAuth_anyOf& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const UeAuth_anyOf& o) {
  j = nlohmann::json();

  switch (o.getValue()) {
    case UeAuth_anyOf::eUeAuth_anyOf::INVALID_VALUE_OPENAPI_GENERATED:
      j = "INVALID_VALUE_OPENAPI_GENERATED";
      break;
    case UeAuth_anyOf::eUeAuth_anyOf::AUTHORIZED:
      j = "AUTHORIZED";
      break;
    case UeAuth_anyOf::eUeAuth_anyOf::NOT_AUTHORIZED:
      j = "NOT_AUTHORIZED";
      break;
  }
}

void from_json(const nlohmann::json& j, UeAuth_anyOf& o) {
  auto s = j.get<std::string>();
  if (s == "AUTHORIZED") {
    o.setValue(UeAuth_anyOf::eUeAuth_anyOf::AUTHORIZED);
  } else if (s == "NOT_AUTHORIZED") {
    o.setValue(UeAuth_anyOf::eUeAuth_anyOf::NOT_AUTHORIZED);
  } else {
    std::stringstream ss;
    ss << "Unexpected value " << s << " in json"
       << " cannot be converted to enum of type"
       << " UeAuth_anyOf::eUeAuth_anyOf";
    throw std::invalid_argument(ss.str());
  }
}

UeAuth_anyOf::eUeAuth_anyOf UeAuth_anyOf::getValue() const {
  return m_value;
}
void UeAuth_anyOf::setValue(UeAuth_anyOf::eUeAuth_anyOf value) {
  m_value = value;
}

}  // namespace ngkore::model::common
