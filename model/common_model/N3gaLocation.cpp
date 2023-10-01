
#include "N3gaLocation.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

N3gaLocation::N3gaLocation() {
  m_N3gppTaiIsSet       = false;
  m_N3IwfId             = "";
  m_N3IwfIdIsSet        = false;
  m_UeIpv4Addr          = "";
  m_UeIpv4AddrIsSet     = false;
  m_UeIpv6AddrIsSet     = false;
  m_PortNumber          = 0;
  m_PortNumberIsSet     = false;
  m_TnapIdIsSet         = false;
  m_ProtocolIsSet       = false;
  m_TwapIdIsSet         = false;
  m_HfcNodeIdIsSet      = false;
  m_GliIsSet            = false;
  m_W5gbanLineTypeIsSet = false;
  m_Gci                 = "";
  m_GciIsSet            = false;
}

void N3gaLocation::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool N3gaLocation::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool N3gaLocation::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "N3gaLocation" : pathPrefix;
  if (portNumberIsSet()) {
    const int32_t& value               = m_PortNumber;
    const std::string currentValuePath = _pathPrefix + ".portNumber";

    if (value < 0) {
      success = false;
      msg << currentValuePath << ": must be greater than or equal to 0;";
    }
  }

  return success;
}

bool N3gaLocation::operator==(const N3gaLocation& rhs) const {
  return

      ((!n3gppTaiIsSet() && !rhs.n3gppTaiIsSet()) ||
       (n3gppTaiIsSet() && rhs.n3gppTaiIsSet() &&
        getN3gppTai() == rhs.getN3gppTai())) &&

      ((!n3IwfIdIsSet() && !rhs.n3IwfIdIsSet()) ||
       (n3IwfIdIsSet() && rhs.n3IwfIdIsSet() &&
        getN3IwfId() == rhs.getN3IwfId())) &&

      ((!ueIpv4AddrIsSet() && !rhs.ueIpv4AddrIsSet()) ||
       (ueIpv4AddrIsSet() && rhs.ueIpv4AddrIsSet() &&
        getUeIpv4Addr() == rhs.getUeIpv4Addr())) &&

      ((!ueIpv6AddrIsSet() && !rhs.ueIpv6AddrIsSet()) ||
       (ueIpv6AddrIsSet() && rhs.ueIpv6AddrIsSet() &&
        getUeIpv6Addr() == rhs.getUeIpv6Addr())) &&

      ((!portNumberIsSet() && !rhs.portNumberIsSet()) ||
       (portNumberIsSet() && rhs.portNumberIsSet() &&
        getPortNumber() == rhs.getPortNumber())) &&

      ((!tnapIdIsSet() && !rhs.tnapIdIsSet()) ||
       (tnapIdIsSet() && rhs.tnapIdIsSet() &&
        getTnapId() == rhs.getTnapId())) &&

      ((!protocolIsSet() && !rhs.protocolIsSet()) ||
       (protocolIsSet() && rhs.protocolIsSet() &&
        getProtocol() == rhs.getProtocol())) &&

      ((!twapIdIsSet() && !rhs.twapIdIsSet()) ||
       (twapIdIsSet() && rhs.twapIdIsSet() &&
        getTwapId() == rhs.getTwapId())) &&

      ((!hfcNodeIdIsSet() && !rhs.hfcNodeIdIsSet()) ||
       (hfcNodeIdIsSet() && rhs.hfcNodeIdIsSet() &&
        getHfcNodeId() == rhs.getHfcNodeId())) &&

      ((!gliIsSet() && !rhs.gliIsSet()) ||
       (gliIsSet() && rhs.gliIsSet() && getGli() == rhs.getGli())) &&

      ((!w5gbanLineTypeIsSet() && !rhs.w5gbanLineTypeIsSet()) ||
       (w5gbanLineTypeIsSet() && rhs.w5gbanLineTypeIsSet() &&
        getW5gbanLineType() == rhs.getW5gbanLineType())) &&

      ((!gciIsSet() && !rhs.gciIsSet()) ||
       (gciIsSet() && rhs.gciIsSet() && getGci() == rhs.getGci()))

          ;
}

bool N3gaLocation::operator!=(const N3gaLocation& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const N3gaLocation& o) {
  j = nlohmann::json();
  if (o.n3gppTaiIsSet()) j["n3gppTai"] = o.m_N3gppTai;
  if (o.n3IwfIdIsSet()) j["n3IwfId"] = o.m_N3IwfId;
  if (o.ueIpv4AddrIsSet()) j["ueIpv4Addr"] = o.m_UeIpv4Addr;
  if (o.ueIpv6AddrIsSet()) j["ueIpv6Addr"] = o.m_UeIpv6Addr;
  if (o.portNumberIsSet()) j["portNumber"] = o.m_PortNumber;
  if (o.tnapIdIsSet()) j["tnapId"] = o.m_TnapId;
  if (o.protocolIsSet()) j["protocol"] = o.m_Protocol;
  if (o.twapIdIsSet()) j["twapId"] = o.m_TwapId;
  if (o.hfcNodeIdIsSet()) j["hfcNodeId"] = o.m_HfcNodeId;
  if (o.gliIsSet()) j["gli"] = o.m_Gli;
  if (o.w5gbanLineTypeIsSet()) j["w5gbanLineType"] = o.m_W5gbanLineType;
  if (o.gciIsSet()) j["gci"] = o.m_Gci;
}

void from_json(const nlohmann::json& j, N3gaLocation& o) {
  if (j.find("n3gppTai") != j.end()) {
    j.at("n3gppTai").get_to(o.m_N3gppTai);
    o.m_N3gppTaiIsSet = true;
  }
  if (j.find("n3IwfId") != j.end()) {
    j.at("n3IwfId").get_to(o.m_N3IwfId);
    o.m_N3IwfIdIsSet = true;
  }
  if (j.find("ueIpv4Addr") != j.end()) {
    j.at("ueIpv4Addr").get_to(o.m_UeIpv4Addr);
    o.m_UeIpv4AddrIsSet = true;
  }
  if (j.find("ueIpv6Addr") != j.end()) {
    j.at("ueIpv6Addr").get_to(o.m_UeIpv6Addr);
    o.m_UeIpv6AddrIsSet = true;
  }
  if (j.find("portNumber") != j.end()) {
    j.at("portNumber").get_to(o.m_PortNumber);
    o.m_PortNumberIsSet = true;
  }
  if (j.find("tnapId") != j.end()) {
    j.at("tnapId").get_to(o.m_TnapId);
    o.m_TnapIdIsSet = true;
  }
  if (j.find("protocol") != j.end()) {
    j.at("protocol").get_to(o.m_Protocol);
    o.m_ProtocolIsSet = true;
  }
  if (j.find("twapId") != j.end()) {
    j.at("twapId").get_to(o.m_TwapId);
    o.m_TwapIdIsSet = true;
  }
  if (j.find("hfcNodeId") != j.end()) {
    j.at("hfcNodeId").get_to(o.m_HfcNodeId);
    o.m_HfcNodeIdIsSet = true;
  }
  if (j.find("gli") != j.end()) {
    j.at("gli").get_to(o.m_Gli);
    o.m_GliIsSet = true;
  }
  if (j.find("w5gbanLineType") != j.end()) {
    j.at("w5gbanLineType").get_to(o.m_W5gbanLineType);
    o.m_W5gbanLineTypeIsSet = true;
  }
  if (j.find("gci") != j.end()) {
    j.at("gci").get_to(o.m_Gci);
    o.m_GciIsSet = true;
  }
}

ngkore::model::common::Tai N3gaLocation::getN3gppTai() const {
  return m_N3gppTai;
}
void N3gaLocation::setN3gppTai(ngkore::model::common::Tai const& value) {
  m_N3gppTai      = value;
  m_N3gppTaiIsSet = true;
}
bool N3gaLocation::n3gppTaiIsSet() const {
  return m_N3gppTaiIsSet;
}
void N3gaLocation::unsetN3gppTai() {
  m_N3gppTaiIsSet = false;
}
std::string N3gaLocation::getN3IwfId() const {
  return m_N3IwfId;
}
void N3gaLocation::setN3IwfId(std::string const& value) {
  m_N3IwfId      = value;
  m_N3IwfIdIsSet = true;
}
bool N3gaLocation::n3IwfIdIsSet() const {
  return m_N3IwfIdIsSet;
}
void N3gaLocation::unsetN3IwfId() {
  m_N3IwfIdIsSet = false;
}
std::string N3gaLocation::getUeIpv4Addr() const {
  return m_UeIpv4Addr;
}
void N3gaLocation::setUeIpv4Addr(std::string const& value) {
  m_UeIpv4Addr      = value;
  m_UeIpv4AddrIsSet = true;
}
bool N3gaLocation::ueIpv4AddrIsSet() const {
  return m_UeIpv4AddrIsSet;
}
void N3gaLocation::unsetUeIpv4Addr() {
  m_UeIpv4AddrIsSet = false;
}
ngkore::model::common::Ipv6Addr N3gaLocation::getUeIpv6Addr() const {
  return m_UeIpv6Addr;
}
void N3gaLocation::setUeIpv6Addr(ngkore::model::common::Ipv6Addr const& value) {
  m_UeIpv6Addr      = value;
  m_UeIpv6AddrIsSet = true;
}
bool N3gaLocation::ueIpv6AddrIsSet() const {
  return m_UeIpv6AddrIsSet;
}
void N3gaLocation::unsetUeIpv6Addr() {
  m_UeIpv6AddrIsSet = false;
}
int32_t N3gaLocation::getPortNumber() const {
  return m_PortNumber;
}
void N3gaLocation::setPortNumber(int32_t const value) {
  m_PortNumber      = value;
  m_PortNumberIsSet = true;
}
bool N3gaLocation::portNumberIsSet() const {
  return m_PortNumberIsSet;
}
void N3gaLocation::unsetPortNumber() {
  m_PortNumberIsSet = false;
}
ngkore::model::common::TnapId N3gaLocation::getTnapId() const {
  return m_TnapId;
}
void N3gaLocation::setTnapId(ngkore::model::common::TnapId const& value) {
  m_TnapId      = value;
  m_TnapIdIsSet = true;
}
bool N3gaLocation::tnapIdIsSet() const {
  return m_TnapIdIsSet;
}
void N3gaLocation::unsetTnapId() {
  m_TnapIdIsSet = false;
}
ngkore::model::common::TransportProtocol N3gaLocation::getProtocol() const {
  return m_Protocol;
}
void N3gaLocation::setProtocol(
    ngkore::model::common::TransportProtocol const& value) {
  m_Protocol      = value;
  m_ProtocolIsSet = true;
}
bool N3gaLocation::protocolIsSet() const {
  return m_ProtocolIsSet;
}
void N3gaLocation::unsetProtocol() {
  m_ProtocolIsSet = false;
}
ngkore::model::common::TwapId N3gaLocation::getTwapId() const {
  return m_TwapId;
}
void N3gaLocation::setTwapId(ngkore::model::common::TwapId const& value) {
  m_TwapId      = value;
  m_TwapIdIsSet = true;
}
bool N3gaLocation::twapIdIsSet() const {
  return m_TwapIdIsSet;
}
void N3gaLocation::unsetTwapId() {
  m_TwapIdIsSet = false;
}
ngkore::model::common::HfcNodeId N3gaLocation::getHfcNodeId() const {
  return m_HfcNodeId;
}
void N3gaLocation::setHfcNodeId(ngkore::model::common::HfcNodeId const& value) {
  m_HfcNodeId      = value;
  m_HfcNodeIdIsSet = true;
}
bool N3gaLocation::hfcNodeIdIsSet() const {
  return m_HfcNodeIdIsSet;
}
void N3gaLocation::unsetHfcNodeId() {
  m_HfcNodeIdIsSet = false;
}
std::string N3gaLocation::getGli() const {
  return m_Gli;
}
void N3gaLocation::setGli(std::string const& value) {
  m_Gli      = value;
  m_GliIsSet = true;
}
bool N3gaLocation::gliIsSet() const {
  return m_GliIsSet;
}
void N3gaLocation::unsetGli() {
  m_GliIsSet = false;
}
ngkore::model::common::LineType N3gaLocation::getW5gbanLineType() const {
  return m_W5gbanLineType;
}
void N3gaLocation::setW5gbanLineType(
    ngkore::model::common::LineType const& value) {
  m_W5gbanLineType      = value;
  m_W5gbanLineTypeIsSet = true;
}
bool N3gaLocation::w5gbanLineTypeIsSet() const {
  return m_W5gbanLineTypeIsSet;
}
void N3gaLocation::unsetW5gbanLineType() {
  m_W5gbanLineTypeIsSet = false;
}
std::string N3gaLocation::getGci() const {
  return m_Gci;
}
void N3gaLocation::setGci(std::string const& value) {
  m_Gci      = value;
  m_GciIsSet = true;
}
bool N3gaLocation::gciIsSet() const {
  return m_GciIsSet;
}
void N3gaLocation::unsetGci() {
  m_GciIsSet = false;
}

}  // namespace ngkore::model::common
