
#include "TransportProtocol.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

TransportProtocol::TransportProtocol() {}

void TransportProtocol::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool TransportProtocol::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool TransportProtocol::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "TransportProtocol" : pathPrefix;

  if (!m_value.validate(msg)) {
    success = false;
  }
  return success;
}

bool TransportProtocol::operator==(const TransportProtocol& rhs) const {
  return

      getValue() == rhs.getValue();
}

bool TransportProtocol::operator!=(const TransportProtocol& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const TransportProtocol& o) {
  j = nlohmann::json();
  to_json(j, o.m_value);
}

void from_json(const nlohmann::json& j, TransportProtocol& o) {
  from_json(j, o.m_value);
}

TransportProtocol_anyOf TransportProtocol::getValue() const {
  return m_value;
}

void TransportProtocol::setValue(TransportProtocol_anyOf value) {
  m_value = value;
}

TransportProtocol_anyOf::eTransportProtocol_anyOf
TransportProtocol::getEnumValue() const {
  return m_value.getValue();
}

void TransportProtocol::setEnumValue(
    TransportProtocol_anyOf::eTransportProtocol_anyOf value) {
  m_value.setValue(value);
}

}  // namespace ngkore::model::common
