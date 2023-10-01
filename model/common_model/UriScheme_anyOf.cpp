
#include "UriScheme_anyOf.h"
#include "Helpers.h"
#include <stdexcept>
#include <sstream>

namespace ngkore::model::common {

UriScheme_anyOf::UriScheme_anyOf() {}

void UriScheme_anyOf::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool UriScheme_anyOf::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool UriScheme_anyOf::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "UriScheme_anyOf" : pathPrefix;

  if (m_value ==
      UriScheme_anyOf::eUriScheme_anyOf::INVALID_VALUE_OPENAPI_GENERATED) {
    success = false;
    msg << _pathPrefix << ": has no value;";
  }

  return success;
}

bool UriScheme_anyOf::operator==(const UriScheme_anyOf& rhs) const {
  return getValue() == rhs.getValue()

      ;
}

bool UriScheme_anyOf::operator!=(const UriScheme_anyOf& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const UriScheme_anyOf& o) {
  j = nlohmann::json();

  switch (o.getValue()) {
    case UriScheme_anyOf::eUriScheme_anyOf::INVALID_VALUE_OPENAPI_GENERATED:
      j = "INVALID_VALUE_OPENAPI_GENERATED";
      break;
    case UriScheme_anyOf::eUriScheme_anyOf::HTTP:
      j = "http";
      break;
    case UriScheme_anyOf::eUriScheme_anyOf::HTTPS:
      j = "https";
      break;
  }
}

void from_json(const nlohmann::json& j, UriScheme_anyOf& o) {
  auto s = j.get<std::string>();
  if (s == "http") {
    o.setValue(UriScheme_anyOf::eUriScheme_anyOf::HTTP);
  } else if (s == "https") {
    o.setValue(UriScheme_anyOf::eUriScheme_anyOf::HTTPS);
  } else {
    std::stringstream ss;
    ss << "Unexpected value " << s << " in json"
       << " cannot be converted to enum of type"
       << " UriScheme_anyOf::eUriScheme_anyOf";
    throw std::invalid_argument(ss.str());
  }
}

UriScheme_anyOf::eUriScheme_anyOf UriScheme_anyOf::getValue() const {
  return m_value;
}
void UriScheme_anyOf::setValue(UriScheme_anyOf::eUriScheme_anyOf value) {
  m_value = value;
}

}  // namespace ngkore::model::common
