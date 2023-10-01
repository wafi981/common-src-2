
#include "Ipv6Prefix.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

Ipv6Prefix::Ipv6Prefix() {}

void Ipv6Prefix::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool Ipv6Prefix::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool Ipv6Prefix::validate(
  return success;
}

bool Ipv6Prefix::operator==(const Ipv6Prefix& rhs) const {
  return getIpv6Prefix() == rhs.getIpv6Prefix();
}

bool Ipv6Prefix::operator!=(const Ipv6Prefix& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const Ipv6Prefix& o) {
  j = o.getIpv6Prefix();
}

void from_json(const nlohmann::json& j, Ipv6Prefix& o) {
  o.setIpv6Prefix(j);
}

void Ipv6Prefix::setIpv6Prefix(const std::string& value) {
  m_Ipv6Prefix = value;
}

std::string Ipv6Prefix::getIpv6Prefix() const {
  return m_Ipv6Prefix;
}

}  // namespace ngkore::model::common
