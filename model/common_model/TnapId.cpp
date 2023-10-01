
#include "TnapId.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

TnapId::TnapId() {
  m_SsId              = "";
  m_SsIdIsSet         = false;
  m_BssId             = "";
  m_BssIdIsSet        = false;
  m_CivicAddressIsSet = false;
}

void TnapId::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool TnapId::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool TnapId::validate(
  return success;
}

bool TnapId::operator==(const TnapId& rhs) const {
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

bool TnapId::operator!=(const TnapId& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const TnapId& o) {
  j = nlohmann::json();
  if (o.ssIdIsSet()) j["ssId"] = o.m_SsId;
  if (o.bssIdIsSet()) j["bssId"] = o.m_BssId;
  if (o.civicAddressIsSet()) j["civicAddress"] = o.m_CivicAddress;
}

void from_json(const nlohmann::json& j, TnapId& o) {
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

std::string TnapId::getSsId() const {
  return m_SsId;
}
void TnapId::setSsId(std::string const& value) {
  m_SsId      = value;
  m_SsIdIsSet = true;
}
bool TnapId::ssIdIsSet() const {
  return m_SsIdIsSet;
}
void TnapId::unsetSsId() {
  m_SsIdIsSet = false;
}
std::string TnapId::getBssId() const {
  return m_BssId;
}
void TnapId::setBssId(std::string const& value) {
  m_BssId      = value;
  m_BssIdIsSet = true;
}
bool TnapId::bssIdIsSet() const {
  return m_BssIdIsSet;
}
void TnapId::unsetBssId() {
  m_BssIdIsSet = false;
}
std::string TnapId::getCivicAddress() const {
  return m_CivicAddress;
}
void TnapId::setCivicAddress(std::string const& value) {
  m_CivicAddress      = value;
  m_CivicAddressIsSet = true;
}
bool TnapId::civicAddressIsSet() const {
  return m_CivicAddressIsSet;
}
void TnapId::unsetCivicAddress() {
  m_CivicAddressIsSet = false;
}

}  // namespace ngkore::model::common
