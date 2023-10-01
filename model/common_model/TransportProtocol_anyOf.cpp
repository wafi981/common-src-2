
#include "TransportProtocol_anyOf.h"
#include "Helpers.h"
#include <stdexcept>
#include <sstream>

namespace ngkore::model::common {

TransportProtocol_anyOf::TransportProtocol_anyOf() {}

void TransportProtocol_anyOf::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool TransportProtocol_anyOf::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool TransportProtocol_anyOf::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "TransportProtocol_anyOf" : pathPrefix;

  if (m_value == TransportProtocol_anyOf::eTransportProtocol_anyOf::
                     INVALID_VALUE_OPENAPI_GENERATED) {
    success = false;
    msg << _pathPrefix << ": has no value;";
  }

  return success;
}

bool TransportProtocol_anyOf::operator==(
    const TransportProtocol_anyOf& rhs) const {
  return getValue() == rhs.getValue()

      ;
}

bool TransportProtocol_anyOf::operator!=(
    const TransportProtocol_anyOf& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const TransportProtocol_anyOf& o) {
  j = nlohmann::json();

  switch (o.getValue()) {
    case TransportProtocol_anyOf::eTransportProtocol_anyOf::
        INVALID_VALUE_OPENAPI_GENERATED:
      j = "INVALID_VALUE_OPENAPI_GENERATED";
      break;
    case TransportProtocol_anyOf::eTransportProtocol_anyOf::UDP:
      j = "UDP";
      break;
    case TransportProtocol_anyOf::eTransportProtocol_anyOf::TCP:
      j = "TCP";
      break;
  }
}

void from_json(const nlohmann::json& j, TransportProtocol_anyOf& o) {
  auto s = j.get<std::string>();
  if (s == "UDP") {
    o.setValue(TransportProtocol_anyOf::eTransportProtocol_anyOf::UDP);
  } else if (s == "TCP") {
    o.setValue(TransportProtocol_anyOf::eTransportProtocol_anyOf::TCP);
  } else {
    std::stringstream ss;
    ss << "Unexpected value " << s << " in json"
       << " cannot be converted to enum of type"
       << " TransportProtocol_anyOf::eTransportProtocol_anyOf";
    throw std::invalid_argument(ss.str());
  }
}

TransportProtocol_anyOf::eTransportProtocol_anyOf
TransportProtocol_anyOf::getValue() const {
  return m_value;
}
void TransportProtocol_anyOf::setValue(
    TransportProtocol_anyOf::eTransportProtocol_anyOf value) {
  m_value = value;
}

}  // namespace ngkore::model::common
