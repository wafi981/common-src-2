
#include "Ipv6Addr.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

Ipv6Addr::Ipv6Addr() {}

void Ipv6Addr::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool Ipv6Addr::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool Ipv6Addr::validate(
  return success;
}

bool Ipv6Addr::operator==(const Ipv6Addr& rhs) const {
  return getIpv6Addr() == rhs.getIpv6Addr();
}

bool Ipv6Addr::operator!=(const Ipv6Addr& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const Ipv6Addr& o) {
  j = nlohmann::json();
  j = o.getIpv6Addr();
}

void from_json(const nlohmann::json& j, Ipv6Addr& o) {
  o.setIpv6Addr(j);
}

std::string Ipv6Addr::getIpv6Addr() const {
  return m_Ipv6Addr;
}
void Ipv6Addr::setIpv6Addr(std::string const& value) {
  m_Ipv6Addr = value;
}

}  // namespace ngkore::model::common
