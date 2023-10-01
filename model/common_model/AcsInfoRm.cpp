
#include "AcsInfoRm.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

AcsInfoRm::AcsInfoRm() {
  m_AcsUrl           = "";
  m_AcsUrlIsSet      = false;
  m_AcsIpv4Addr      = "";
  m_AcsIpv4AddrIsSet = false;
  m_AcsIpv6AddrIsSet = false;
}

void AcsInfoRm::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool AcsInfoRm::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool AcsInfoRm::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success                  = true;
  const std::string _pathPrefix = pathPrefix.empty() ? "AcsInfoRm" : pathPrefix;

  if (acsIpv4AddrIsSet()) {
    const std::string& value           = m_AcsIpv4Addr;
    const std::string currentValuePath = _pathPrefix + ".acsIpv4Addr";
  }

  return success;
}

bool AcsInfoRm::operator==(const AcsInfoRm& rhs) const {
  return

      ((!acsUrlIsSet() && !rhs.acsUrlIsSet()) ||
       (acsUrlIsSet() && rhs.acsUrlIsSet() &&
        getAcsUrl() == rhs.getAcsUrl())) &&

      ((!acsIpv4AddrIsSet() && !rhs.acsIpv4AddrIsSet()) ||
       (acsIpv4AddrIsSet() && rhs.acsIpv4AddrIsSet() &&
        getAcsIpv4Addr() == rhs.getAcsIpv4Addr())) &&

      ((!acsIpv6AddrIsSet() && !rhs.acsIpv6AddrIsSet()) ||
       (acsIpv6AddrIsSet() && rhs.acsIpv6AddrIsSet() &&
        getAcsIpv6Addr() == rhs.getAcsIpv6Addr()))

          ;
}

bool AcsInfoRm::operator!=(const AcsInfoRm& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const AcsInfoRm& o) {
  j = nlohmann::json();
  if (o.acsUrlIsSet()) j["acsUrl"] = o.m_AcsUrl;
  if (o.acsIpv4AddrIsSet()) j["acsIpv4Addr"] = o.m_AcsIpv4Addr;
  if (o.acsIpv6AddrIsSet()) j["acsIpv6Addr"] = o.m_AcsIpv6Addr;
}

void from_json(const nlohmann::json& j, AcsInfoRm& o) {
  if (j.find("acsUrl") != j.end()) {
    j.at("acsUrl").get_to(o.m_AcsUrl);
    o.m_AcsUrlIsSet = true;
  }
  if (j.find("acsIpv4Addr") != j.end()) {
    j.at("acsIpv4Addr").get_to(o.m_AcsIpv4Addr);
    o.m_AcsIpv4AddrIsSet = true;
  }
  if (j.find("acsIpv6Addr") != j.end()) {
    j.at("acsIpv6Addr").get_to(o.m_AcsIpv6Addr);
    o.m_AcsIpv6AddrIsSet = true;
  }
}

std::string AcsInfoRm::getAcsUrl() const {
  return m_AcsUrl;
}
void AcsInfoRm::setAcsUrl(std::string const& value) {
  m_AcsUrl      = value;
  m_AcsUrlIsSet = true;
}
bool AcsInfoRm::acsUrlIsSet() const {
  return m_AcsUrlIsSet;
}
void AcsInfoRm::unsetAcsUrl() {
  m_AcsUrlIsSet = false;
}
std::string AcsInfoRm::getAcsIpv4Addr() const {
  return m_AcsIpv4Addr;
}
void AcsInfoRm::setAcsIpv4Addr(std::string const& value) {
  m_AcsIpv4Addr      = value;
  m_AcsIpv4AddrIsSet = true;
}
bool AcsInfoRm::acsIpv4AddrIsSet() const {
  return m_AcsIpv4AddrIsSet;
}
void AcsInfoRm::unsetAcsIpv4Addr() {
  m_AcsIpv4AddrIsSet = false;
}
ngkore::model::common::Ipv6Addr AcsInfoRm::getAcsIpv6Addr() const {
  return m_AcsIpv6Addr;
}
void AcsInfoRm::setAcsIpv6Addr(ngkore::model::common::Ipv6Addr const& value) {
  m_AcsIpv6Addr      = value;
  m_AcsIpv6AddrIsSet = true;
}
bool AcsInfoRm::acsIpv6AddrIsSet() const {
  return m_AcsIpv6AddrIsSet;
}
void AcsInfoRm::unsetAcsIpv6Addr() {
  m_AcsIpv6AddrIsSet = false;
}

}  // namespace ngkore::model::common
