
#include "HttpMethod.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

HttpMethod::HttpMethod() {}

void HttpMethod::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool HttpMethod::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool HttpMethod::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "HttpMethod" : pathPrefix;

  if (!m_value.validate(msg)) {
    success = false;
  }
  return success;
}

bool HttpMethod::operator==(const HttpMethod& rhs) const {
  return

      getValue() == rhs.getValue();
}

bool HttpMethod::operator!=(const HttpMethod& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const HttpMethod& o) {
  j = nlohmann::json();
  to_json(j, o.m_value);
}

void from_json(const nlohmann::json& j, HttpMethod& o) {
  from_json(j, o.m_value);
}

HttpMethod_anyOf HttpMethod::getValue() const {
  return m_value;
}

void HttpMethod::setValue(HttpMethod_anyOf value) {
  m_value = value;
}

HttpMethod_anyOf::eHttpMethod_anyOf HttpMethod::getEnumValue() const {
  return m_value.getValue();
}

void HttpMethod::setEnumValue(HttpMethod_anyOf::eHttpMethod_anyOf value) {
  m_value.setValue(value);
}

}  // namespace ngkore::model::common
