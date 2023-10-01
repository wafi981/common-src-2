
#include "Ipv6PrefixRm.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

Ipv6PrefixRm::Ipv6PrefixRm() {}

bool Ipv6PrefixRm::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "Ipv6PrefixRm" : pathPrefix;

  return success;
}

void to_json(nlohmann::json& j, const Ipv6PrefixRm& o) {
  j = nlohmann::json();
  if (o.m_Ipv6Prefix.empty()) {
    j = nullptr;
  } else {
    j = o.m_Ipv6Prefix;
  }
}

void from_json(const nlohmann::json& j, Ipv6PrefixRm& o) {
  if (!j.is_null()) {
    o.setIpv6Prefix(j);
  }
}

}  // namespace ngkore::model::common
