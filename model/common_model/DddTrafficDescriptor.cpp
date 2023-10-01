
#include "DddTrafficDescriptor.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

DddTrafficDescriptor::DddTrafficDescriptor() {
  m_Ipv4Addr        = "";
  m_Ipv4AddrIsSet   = false;
  m_Ipv6AddrIsSet   = false;
  m_PortNumber      = 0;
  m_PortNumberIsSet = false;
  m_MacAddr         = "";
  m_MacAddrIsSet    = false;
}

void DddTrafficDescriptor::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool DddTrafficDescriptor::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool DddTrafficDescriptor::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "DddTrafficDescriptor" : pathPrefix;

  if (ipv4AddrIsSet()) {
    const std::string& value           = m_Ipv4Addr;
    const std::string currentValuePath = _pathPrefix + ".ipv4Addr";
  }

  if (portNumberIsSet()) {
    const int32_t& value               = m_PortNumber;
    const std::string currentValuePath = _pathPrefix + ".portNumber";

    if (value < 0) {
      success = false;
      msg << currentValuePath << ": must be greater than or equal to 0;";
    }
  }

  if (macAddrIsSet()) {
    const std::string& value           = m_MacAddr;
    const std::string currentValuePath = _pathPrefix + ".macAddr";
  }

  return success;
}

bool DddTrafficDescriptor::operator==(const DddTrafficDescriptor& rhs) const {
  return

      ((!ipv4AddrIsSet() && !rhs.ipv4AddrIsSet()) ||
       (ipv4AddrIsSet() && rhs.ipv4AddrIsSet() &&
        getIpv4Addr() == rhs.getIpv4Addr())) &&

      ((!ipv6AddrIsSet() && !rhs.ipv6AddrIsSet()) ||
       (ipv6AddrIsSet() && rhs.ipv6AddrIsSet() &&
        getIpv6Addr() == rhs.getIpv6Addr())) &&

      ((!portNumberIsSet() && !rhs.portNumberIsSet()) ||
       (portNumberIsSet() && rhs.portNumberIsSet() &&
        getPortNumber() == rhs.getPortNumber())) &&

      ((!macAddrIsSet() && !rhs.macAddrIsSet()) ||
       (macAddrIsSet() && rhs.macAddrIsSet() &&
        getMacAddr() == rhs.getMacAddr()))

          ;
}

bool DddTrafficDescriptor::operator!=(const DddTrafficDescriptor& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const DddTrafficDescriptor& o) {
  j = nlohmann::json();
  if (o.ipv4AddrIsSet()) j["ipv4Addr"] = o.m_Ipv4Addr;
  if (o.ipv6AddrIsSet()) j["ipv6Addr"] = o.m_Ipv6Addr;
  if (o.portNumberIsSet()) j["portNumber"] = o.m_PortNumber;
  if (o.macAddrIsSet()) j["macAddr"] = o.m_MacAddr;
}

void from_json(const nlohmann::json& j, DddTrafficDescriptor& o) {
  if (j.find("ipv4Addr") != j.end()) {
    j.at("ipv4Addr").get_to(o.m_Ipv4Addr);
    o.m_Ipv4AddrIsSet = true;
  }
  if (j.find("ipv6Addr") != j.end()) {
    j.at("ipv6Addr").get_to(o.m_Ipv6Addr);
    o.m_Ipv6AddrIsSet = true;
  }
  if (j.find("portNumber") != j.end()) {
    j.at("portNumber").get_to(o.m_PortNumber);
    o.m_PortNumberIsSet = true;
  }
  if (j.find("macAddr") != j.end()) {
    j.at("macAddr").get_to(o.m_MacAddr);
    o.m_MacAddrIsSet = true;
  }
}

std::string DddTrafficDescriptor::getIpv4Addr() const {
  return m_Ipv4Addr;
}
void DddTrafficDescriptor::setIpv4Addr(std::string const& value) {
  m_Ipv4Addr      = value;
  m_Ipv4AddrIsSet = true;
}
bool DddTrafficDescriptor::ipv4AddrIsSet() const {
  return m_Ipv4AddrIsSet;
}
void DddTrafficDescriptor::unsetIpv4Addr() {
  m_Ipv4AddrIsSet = false;
}
ngkore::model::common::Ipv6Addr DddTrafficDescriptor::getIpv6Addr() const {
  return m_Ipv6Addr;
}
void DddTrafficDescriptor::setIpv6Addr(
    ngkore::model::common::Ipv6Addr const& value) {
  m_Ipv6Addr      = value;
  m_Ipv6AddrIsSet = true;
}
bool DddTrafficDescriptor::ipv6AddrIsSet() const {
  return m_Ipv6AddrIsSet;
}
void DddTrafficDescriptor::unsetIpv6Addr() {
  m_Ipv6AddrIsSet = false;
}
int32_t DddTrafficDescriptor::getPortNumber() const {
  return m_PortNumber;
}
void DddTrafficDescriptor::setPortNumber(int32_t const value) {
  m_PortNumber      = value;
  m_PortNumberIsSet = true;
}
bool DddTrafficDescriptor::portNumberIsSet() const {
  return m_PortNumberIsSet;
}
void DddTrafficDescriptor::unsetPortNumber() {
  m_PortNumberIsSet = false;
}
std::string DddTrafficDescriptor::getMacAddr() const {
  return m_MacAddr;
}
void DddTrafficDescriptor::setMacAddr(std::string const& value) {
  m_MacAddr      = value;
  m_MacAddrIsSet = true;
}
bool DddTrafficDescriptor::macAddrIsSet() const {
  return m_MacAddrIsSet;
}
void DddTrafficDescriptor::unsetMacAddr() {
  m_MacAddrIsSet = false;
}

}  // namespace ngkore::model::common
