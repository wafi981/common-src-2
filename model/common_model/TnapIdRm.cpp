
#include "TnapIdRm.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

TnapIdRm::TnapIdRm() {
  m_SsId              = "";
  m_SsIdIsSet         = false;
  m_BssId             = "";
  m_BssIdIsSet        = false;
  m_CivicAddressIsSet = false;
}

void TnapIdRm::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool TnapIdRm::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool TnapIdRm::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success                  = true;
  const std::string _pathPrefix = pathPrefix.empty() ? "TnapIdRm" : pathPrefix;

  return success;
}

bool TnapIdRm::operator==(const TnapIdRm& rhs) const {
  return

      ((!ssIdIsSet() && !rhs.ssIdIsSet()) ||
       (ssIdIsSet() && rhs.ssIdIsSet() && getSsId() == rhs.getSsId())) &&

      ((!bssIdIsSet() && !rhs.bssIdIsSet()) ||
       (bssIdIsSet() && rhs.bssIdIsSet() && getBssId() == rhs.getBssId())) &&

      ((!civicAddressIsSet() && !rhs.civicAddressIsSet()) ||
       (civicAddressIsSet() && rhs.civicAddressIsSet() &&
        getCivicAddress() == rhs.getCivicAddress()))

          ;
}

bool TnapIdRm::operator!=(const TnapIdRm& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const TnapIdRm& o) {
  j = nlohmann::json();
  if (o.ssIdIsSet()) j["ssId"] = o.m_SsId;
  if (o.bssIdIsSet()) j["bssId"] = o.m_BssId;
  if (o.civicAddressIsSet()) j["civicAddress"] = o.m_CivicAddress;
}

void from_json(const nlohmann::json& j, TnapIdRm& o) {
  if (j.find("ssId") != j.end()) {
    j.at("ssId").get_to(o.m_SsId);
    o.m_SsIdIsSet = true;
  }
  if (j.find("bssId") != j.end()) {
    j.at("bssId").get_to(o.m_BssId);
    o.m_BssIdIsSet = true;
  }
  if (j.find("civicAddress") != j.end()) {
    j.at("civicAddress").get_to(o.m_CivicAddress);
    o.m_CivicAddressIsSet = true;
  }
}

std::string TnapIdRm::getSsId() const {
  return m_SsId;
}
void TnapIdRm::setSsId(std::string const& value) {
  m_SsId      = value;
  m_SsIdIsSet = true;
}
bool TnapIdRm::ssIdIsSet() const {
  return m_SsIdIsSet;
}
void TnapIdRm::unsetSsId() {
  m_SsIdIsSet = false;
}
std::string TnapIdRm::getBssId() const {
  return m_BssId;
}
void TnapIdRm::setBssId(std::string const& value) {
  m_BssId      = value;
  m_BssIdIsSet = true;
}
bool TnapIdRm::bssIdIsSet() const {
  return m_BssIdIsSet;
}
void TnapIdRm::unsetBssId() {
  m_BssIdIsSet = false;
}
std::string TnapIdRm::getCivicAddress() const {
  return m_CivicAddress;
}
void TnapIdRm::setCivicAddress(std::string const& value) {
  m_CivicAddress      = value;
  m_CivicAddressIsSet = true;
}
bool TnapIdRm::civicAddressIsSet() const {
  return m_CivicAddressIsSet;
}
void TnapIdRm::unsetCivicAddress() {
  m_CivicAddressIsSet = false;
}

}  // namespace ngkore::model::common
