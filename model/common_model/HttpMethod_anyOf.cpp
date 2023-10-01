
#include "HttpMethod_anyOf.h"
#include "Helpers.h"
#include <stdexcept>
#include <sstream>

namespace ngkore::model::common {

HttpMethod_anyOf::HttpMethod_anyOf() {}

void HttpMethod_anyOf::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool HttpMethod_anyOf::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool HttpMethod_anyOf::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "HttpMethod_anyOf" : pathPrefix;

  if (m_value ==
      HttpMethod_anyOf::eHttpMethod_anyOf::INVALID_VALUE_OPENAPI_GENERATED) {
    success = false;
    msg << _pathPrefix << ": has no value;";
  }

  return success;
}

bool HttpMethod_anyOf::operator==(const HttpMethod_anyOf& rhs) const {
  return getValue() == rhs.getValue()

      ;
}

bool HttpMethod_anyOf::operator!=(const HttpMethod_anyOf& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const HttpMethod_anyOf& o) {
  j = nlohmann::json();

  switch (o.getValue()) {
    case HttpMethod_anyOf::eHttpMethod_anyOf::INVALID_VALUE_OPENAPI_GENERATED:
      j = "INVALID_VALUE_OPENAPI_GENERATED";
      break;
    case HttpMethod_anyOf::eHttpMethod_anyOf::GET:
      j = "GET";
      break;
    case HttpMethod_anyOf::eHttpMethod_anyOf::POST:
      j = "POST";
      break;
    case HttpMethod_anyOf::eHttpMethod_anyOf::PUT:
      j = "PUT";
      break;
    case HttpMethod_anyOf::eHttpMethod_anyOf::DELETE:
      j = "DELETE";
      break;
    case HttpMethod_anyOf::eHttpMethod_anyOf::PATCH:
      j = "PATCH";
      break;
    case HttpMethod_anyOf::eHttpMethod_anyOf::OPTIONS:
      j = "OPTIONS";
      break;
    case HttpMethod_anyOf::eHttpMethod_anyOf::HEAD:
      j = "HEAD";
      break;
    case HttpMethod_anyOf::eHttpMethod_anyOf::CONNECT:
      j = "CONNECT";
      break;
    case HttpMethod_anyOf::eHttpMethod_anyOf::TRACE:
      j = "TRACE";
      break;
  }
}

void from_json(const nlohmann::json& j, HttpMethod_anyOf& o) {
  auto s = j.get<std::string>();
  if (s == "GET") {
    o.setValue(HttpMethod_anyOf::eHttpMethod_anyOf::GET);
  } else if (s == "POST") {
    o.setValue(HttpMethod_anyOf::eHttpMethod_anyOf::POST);
  } else if (s == "PUT") {
    o.setValue(HttpMethod_anyOf::eHttpMethod_anyOf::PUT);
  } else if (s == "DELETE") {
    o.setValue(HttpMethod_anyOf::eHttpMethod_anyOf::DELETE);
  } else if (s == "PATCH") {
    o.setValue(HttpMethod_anyOf::eHttpMethod_anyOf::PATCH);
  } else if (s == "OPTIONS") {
    o.setValue(HttpMethod_anyOf::eHttpMethod_anyOf::OPTIONS);
  } else if (s == "HEAD") {
    o.setValue(HttpMethod_anyOf::eHttpMethod_anyOf::HEAD);
  } else if (s == "CONNECT") {
    o.setValue(HttpMethod_anyOf::eHttpMethod_anyOf::CONNECT);
  } else if (s == "TRACE") {
    o.setValue(HttpMethod_anyOf::eHttpMethod_anyOf::TRACE);
  } else {
    std::stringstream ss;
    ss << "Unexpected value " << s << " in json"
       << " cannot be converted to enum of type"
       << " HttpMethod_anyOf::eHttpMethod_anyOf";
    throw std::invalid_argument(ss.str());
  }
}

HttpMethod_anyOf::eHttpMethod_anyOf HttpMethod_anyOf::getValue() const {
  return m_value;
}
void HttpMethod_anyOf::setValue(HttpMethod_anyOf::eHttpMethod_anyOf value) {
  m_value = value;
}

}  // namespace ngkore::model::common
