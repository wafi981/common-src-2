
#include "Ipv6AddrRm.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

Ipv6AddrRm::Ipv6AddrRm() {}

bool Ipv6AddrRm::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "Ipv6AddrRm" : pathPrefix;

  return success;
}

void to_json(nlohmann::json& j, const Ipv6AddrRm& o) {
  j = nlohmann::json();
  if (o.m_Ipv6Addr.empty()) {
    j = nullptr;
  } else {
    j = o.m_Ipv6Addr;
  }
}

void from_json(const nlohmann::json& j, Ipv6AddrRm& o) {
  if (!j.is_null()) {
    o.setIpv6Addr(j);
  }
}

}  // namespace ngkore::model::common
