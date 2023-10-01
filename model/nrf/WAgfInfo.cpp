
#include "WAgfInfo.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::nrf {

WAgfInfo::WAgfInfo() {
  m_Ipv4EndpointAddressesIsSet = false;
  m_Ipv6EndpointAddressesIsSet = false;
  m_EndpointFqdn               = "";
  m_EndpointFqdnIsSet          = false;
}

void WAgfInfo::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool WAgfInfo::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool WAgfInfo::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success                  = true;
  const std::string _pathPrefix = pathPrefix.empty() ? "WAgfInfo" : pathPrefix;

  if (ipv4EndpointAddressesIsSet()) {
    const std::vector<std::string>& value = m_Ipv4EndpointAddresses;
    const std::string currentValuePath = _pathPrefix + ".ipv4EndpointAddresses";

    if (value.size() < 1) {
      success = false;
      msg << currentValuePath << ": must have at least 1 elements;";
    }
    {  // Recursive validation of array elements
      const std::string oldValuePath = currentValuePath;
      int i                          = 0;
      for (const std::string& value : value) {
        const std::string currentValuePath =
            oldValuePath + "[" + std::to_string(i) + "]";

        i++;
      }
    }
  }

  if (ipv6EndpointAddressesIsSet()) {
    const std::vector<ngkore::model::common::Ipv6Addr>& value =
        m_Ipv6EndpointAddresses;
    const std::string currentValuePath = _pathPrefix + ".ipv6EndpointAddresses";

    if (value.size() < 1) {
      success = false;
      msg << currentValuePath << ": must have at least 1 elements;";
    }
    {  // Recursive validation of array elements
      const std::string oldValuePath = currentValuePath;
      int i                          = 0;
      for (const ngkore::model::common::Ipv6Addr& value : value) {
        const std::string currentValuePath =
            oldValuePath + "[" + std::to_string(i) + "]";

        success =
            value.validate(msg, currentValuePath + ".ipv6EndpointAddresses") &&
            success;

        i++;
      }
    }
  }

  return success;
}

bool WAgfInfo::operator==(const WAgfInfo& rhs) const {
  return

      ((!ipv4EndpointAddressesIsSet() && !rhs.ipv4EndpointAddressesIsSet()) ||
       (ipv4EndpointAddressesIsSet() && rhs.ipv4EndpointAddressesIsSet() &&
        getIpv4EndpointAddresses() == rhs.getIpv4EndpointAddresses())) &&

      ((!ipv6EndpointAddressesIsSet() && !rhs.ipv6EndpointAddressesIsSet()) ||
       (ipv6EndpointAddressesIsSet() && rhs.ipv6EndpointAddressesIsSet() &&
        getIpv6EndpointAddresses() == rhs.getIpv6EndpointAddresses())) &&

      ((!endpointFqdnIsSet() && !rhs.endpointFqdnIsSet()) ||
       (endpointFqdnIsSet() && rhs.endpointFqdnIsSet() &&
        getEndpointFqdn() == rhs.getEndpointFqdn()))

          ;
}

bool WAgfInfo::operator!=(const WAgfInfo& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const WAgfInfo& o) {
  j = nlohmann::json();
  if (o.ipv4EndpointAddressesIsSet() || !o.m_Ipv4EndpointAddresses.empty())
    j["ipv4EndpointAddresses"] = o.m_Ipv4EndpointAddresses;
  if (o.ipv6EndpointAddressesIsSet() || !o.m_Ipv6EndpointAddresses.empty())
    j["ipv6EndpointAddresses"] = o.m_Ipv6EndpointAddresses;
  if (o.endpointFqdnIsSet()) j["endpointFqdn"] = o.m_EndpointFqdn;
}

void from_json(const nlohmann::json& j, WAgfInfo& o) {
  if (j.find("ipv4EndpointAddresses") != j.end()) {
    j.at("ipv4EndpointAddresses").get_to(o.m_Ipv4EndpointAddresses);
    o.m_Ipv4EndpointAddressesIsSet = true;
  }
  if (j.find("ipv6EndpointAddresses") != j.end()) {
    j.at("ipv6EndpointAddresses").get_to(o.m_Ipv6EndpointAddresses);
    o.m_Ipv6EndpointAddressesIsSet = true;
  }
  if (j.find("endpointFqdn") != j.end()) {
    j.at("endpointFqdn").get_to(o.m_EndpointFqdn);
    o.m_EndpointFqdnIsSet = true;
  }
}

std::vector<std::string> WAgfInfo::getIpv4EndpointAddresses() const {
  return m_Ipv4EndpointAddresses;
}
void WAgfInfo::setIpv4EndpointAddresses(std::vector<std::string> const& value) {
  m_Ipv4EndpointAddresses      = value;
  m_Ipv4EndpointAddressesIsSet = true;
}
bool WAgfInfo::ipv4EndpointAddressesIsSet() const {
  return m_Ipv4EndpointAddressesIsSet;
}
void WAgfInfo::unsetIpv4EndpointAddresses() {
  m_Ipv4EndpointAddressesIsSet = false;
}
std::vector<ngkore::model::common::Ipv6Addr> WAgfInfo::getIpv6EndpointAddresses()
    const {
  return m_Ipv6EndpointAddresses;
}
void WAgfInfo::setIpv6EndpointAddresses(
    std::vector<ngkore::model::common::Ipv6Addr> const& value) {
  m_Ipv6EndpointAddresses      = value;
  m_Ipv6EndpointAddressesIsSet = true;
}
bool WAgfInfo::ipv6EndpointAddressesIsSet() const {
  return m_Ipv6EndpointAddressesIsSet;
}
void WAgfInfo::unsetIpv6EndpointAddresses() {
  m_Ipv6EndpointAddressesIsSet = false;
}
std::string WAgfInfo::getEndpointFqdn() const {
  return m_EndpointFqdn;
}
void WAgfInfo::setEndpointFqdn(std::string const& value) {
  m_EndpointFqdn      = value;
  m_EndpointFqdnIsSet = true;
}
bool WAgfInfo::endpointFqdnIsSet() const {
  return m_EndpointFqdnIsSet;
}
void WAgfInfo::unsetEndpointFqdn() {
  m_EndpointFqdnIsSet = false;
}

}  // namespace ngkore::model::nrf
