
#include "InterfaceUpfInfoItem.h"
#include "Helpers.h"
#include "config.hpp"

#include <sstream>

namespace ngkore::model::nrf {

using namespace ngkore::model::common;

InterfaceUpfInfoItem::InterfaceUpfInfoItem() {
  m_Ipv4EndpointAddressesIsSet = false;
  m_Ipv6EndpointAddressesIsSet = false;
  m_EndpointFqdn               = "";
  m_EndpointFqdnIsSet          = false;
  m_NetworkInstance            = "";
  m_NetworkInstanceIsSet       = false;
}

void InterfaceUpfInfoItem::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool InterfaceUpfInfoItem::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool InterfaceUpfInfoItem::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "InterfaceUpfInfoItem" : pathPrefix;

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
    const std::vector<Ipv6Addr>& value = m_Ipv6EndpointAddresses;
    const std::string currentValuePath = _pathPrefix + ".ipv6EndpointAddresses";

    if (value.size() < 1) {
      success = false;
      msg << currentValuePath << ": must have at least 1 elements;";
    }
    {  // Recursive validation of array elements
      const std::string oldValuePath = currentValuePath;
      int i                          = 0;
      for (const ngkore::model::nrf::Ipv6Addr& value : value) {
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

bool InterfaceUpfInfoItem::operator==(const InterfaceUpfInfoItem& rhs) const {
  return

      (getInterfaceType() == rhs.getInterfaceType()) &&

      ((!ipv4EndpointAddressesIsSet() && !rhs.ipv4EndpointAddressesIsSet()) ||
       (ipv4EndpointAddressesIsSet() && rhs.ipv4EndpointAddressesIsSet() &&
        getIpv4EndpointAddresses() == rhs.getIpv4EndpointAddresses())) &&

      ((!ipv6EndpointAddressesIsSet() && !rhs.ipv6EndpointAddressesIsSet()) ||
       (ipv6EndpointAddressesIsSet() && rhs.ipv6EndpointAddressesIsSet() &&
        getIpv6EndpointAddresses() == rhs.getIpv6EndpointAddresses())) &&

      ((!endpointFqdnIsSet() && !rhs.endpointFqdnIsSet()) ||
       (endpointFqdnIsSet() && rhs.endpointFqdnIsSet() &&
        getEndpointFqdn() == rhs.getEndpointFqdn())) &&

      ((!networkInstanceIsSet() && !rhs.networkInstanceIsSet()) ||
       (networkInstanceIsSet() && rhs.networkInstanceIsSet() &&
        getNetworkInstance() == rhs.getNetworkInstance()))

          ;
}

bool InterfaceUpfInfoItem::operator!=(const InterfaceUpfInfoItem& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const InterfaceUpfInfoItem& o) {
  j                  = nlohmann::json();
  j["interfaceType"] = o.m_InterfaceType;
  if (o.ipv4EndpointAddressesIsSet() || !o.m_Ipv4EndpointAddresses.empty())
    j["ipv4EndpointAddresses"] = o.m_Ipv4EndpointAddresses;
  if (o.ipv6EndpointAddressesIsSet() || !o.m_Ipv6EndpointAddresses.empty())
    j["ipv6EndpointAddresses"] = o.m_Ipv6EndpointAddresses;
  if (o.endpointFqdnIsSet()) j["endpointFqdn"] = o.m_EndpointFqdn;
  if (o.networkInstanceIsSet()) j["networkInstance"] = o.m_NetworkInstance;
}

void from_json(const nlohmann::json& j, InterfaceUpfInfoItem& o) {
  j.at("interfaceType").get_to(o.m_InterfaceType);
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
  if (j.find("networkInstance") != j.end()) {
    j.at("networkInstance").get_to(o.m_NetworkInstance);
    o.m_NetworkInstanceIsSet = true;
  }
}

ngkore::model::nrf::UPInterfaceType InterfaceUpfInfoItem::getInterfaceType()
    const {
  return m_InterfaceType;
}
void InterfaceUpfInfoItem::setInterfaceType(
    ngkore::model::nrf::UPInterfaceType const& value) {
  m_InterfaceType = value;
}
std::vector<std::string> InterfaceUpfInfoItem::getIpv4EndpointAddresses()
    const {
  return m_Ipv4EndpointAddresses;
}
void InterfaceUpfInfoItem::setIpv4EndpointAddresses(
    std::vector<std::string> const& value) {
  m_Ipv4EndpointAddresses      = value;
  m_Ipv4EndpointAddressesIsSet = true;
}
bool InterfaceUpfInfoItem::ipv4EndpointAddressesIsSet() const {
  return m_Ipv4EndpointAddressesIsSet;
}
void InterfaceUpfInfoItem::unsetIpv4EndpointAddresses() {
  m_Ipv4EndpointAddressesIsSet = false;
}
std::vector<ngkore::model::nrf::Ipv6Addr>
InterfaceUpfInfoItem::getIpv6EndpointAddresses() const {
  return m_Ipv6EndpointAddresses;
}
void InterfaceUpfInfoItem::setIpv6EndpointAddresses(
    std::vector<Ipv6Addr> const& value) {
  m_Ipv6EndpointAddresses      = value;
  m_Ipv6EndpointAddressesIsSet = true;
}
bool InterfaceUpfInfoItem::ipv6EndpointAddressesIsSet() const {
  return m_Ipv6EndpointAddressesIsSet;
}
void InterfaceUpfInfoItem::unsetIpv6EndpointAddresses() {
  m_Ipv6EndpointAddressesIsSet = false;
}
std::string InterfaceUpfInfoItem::getEndpointFqdn() const {
  return m_EndpointFqdn;
}
void InterfaceUpfInfoItem::setEndpointFqdn(std::string const& value) {
  m_EndpointFqdn      = value;
  m_EndpointFqdnIsSet = true;
}
bool InterfaceUpfInfoItem::endpointFqdnIsSet() const {
  return m_EndpointFqdnIsSet;
}
void InterfaceUpfInfoItem::unsetEndpointFqdn() {
  m_EndpointFqdnIsSet = false;
}
std::string InterfaceUpfInfoItem::getNetworkInstance() const {
  return m_NetworkInstance;
}
void InterfaceUpfInfoItem::setNetworkInstance(std::string const& value) {
  m_NetworkInstance      = value;
  m_NetworkInstanceIsSet = true;
}
bool InterfaceUpfInfoItem::networkInstanceIsSet() const {
  return m_NetworkInstanceIsSet;
}
void InterfaceUpfInfoItem::unsetNetworkInstance() {
  m_NetworkInstanceIsSet = false;
}

std::string InterfaceUpfInfoItem::to_string(int indent_level) const {
  std::string out;
  std::string fmt_title = ngkore::config::get_title_formatter(indent_level);
  std::string fmt_value_inner =
      ngkore::config::get_value_formatter(indent_level + 1);

  out.append(fmt::format(fmt_title, "interface_upf_info_item:"));
  out.append(fmt::format(
      fmt_value_inner, "interface_type", m_InterfaceType.getEnumString()));
  if (m_NetworkInstanceIsSet) {
    out.append(
        fmt::format(fmt_value_inner, "network_instance", m_NetworkInstance));
  }
  // TODO other values
  return out;
}

}  // namespace ngkore::model::nrf
