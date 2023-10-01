
#include "UriScheme.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

UriScheme::UriScheme() {}

void UriScheme::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool UriScheme::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool UriScheme::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success                  = true;
  const std::string _pathPrefix = pathPrefix.empty() ? "UriScheme" : pathPrefix;

  if (!m_value.validate(msg)) {
    success = false;
  }
  return success;
}

bool UriScheme::operator==(const UriScheme& rhs) const {
  return

      getValue() == rhs.getValue();
}

bool UriScheme::operator!=(const UriScheme& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const UriScheme& o) {
  j = nlohmann::json();
  to_json(j, o.m_value);
}

void from_json(const nlohmann::json& j, UriScheme& o) {
  from_json(j, o.m_value);
}

UriScheme_anyOf UriScheme::getValue() const {
  return m_value;
}

void UriScheme::setValue(UriScheme_anyOf value) {
  m_value = value;
}

UriScheme_anyOf::eUriScheme_anyOf UriScheme::getEnumValue() const {
  return m_value.getValue();
}

void UriScheme::setEnumValue(UriScheme_anyOf::eUriScheme_anyOf value) {
  m_value.setValue(value);
}

std::string UriScheme::getEnumString() const {
  return helpers::enumToString(m_value);
}

}  // namespace ngkore::model::common
