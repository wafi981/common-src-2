
#include "TwapId.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

TwapId::TwapId() {
  m_SsId              = "";
  m_BssId             = "";
  m_BssIdIsSet        = false;
  m_CivicAddressIsSet = false;
}

void TwapId::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool TwapId::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool TwapId::validate(
  return success;
}

bool TwapId::operator==(const TwapId& rhs) const {
  return

      (getSsId() == rhs.getSsId()) &&

      ((!bssIdIsSet() && !rhs.bssIdIsSet()) ||
       (bssIdIsSet() && rhs.bssIdIsSet() && getBssId() == rhs.getBssId())) &&

      ((!civicAddressIsSet() && !rhs.civicAddressIsSet()) ||
       (civicAddressIsSet() && rhs.civicAddressIsSet() &&
        getCivicAddress() == rhs.getCivicAddress()))

          ;
}

bool TwapId::operator!=(const TwapId& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const TwapId& o) {
  j         = nlohmann::json();
  j["ssId"] = o.m_SsId;
  if (o.bssIdIsSet()) j["bssId"] = o.m_BssId;
  if (o.civicAddressIsSet()) j["civicAddress"] = o.m_CivicAddress;
}

void from_json(const nlohmann::json& j, TwapId& o) {
  j.at("ssId").get_to(o.m_SsId);
  if (j.find("bssId") != j.end()) {
    j.at("bssId").get_to(o.m_BssId);
    o.m_BssIdIsSet = true;
  }
  if (j.find("civicAddress") != j.end()) {
    j.at("civicAddress").get_to(o.m_CivicAddress);
    o.m_CivicAddressIsSet = true;
  }
}

std::string TwapId::getSsId() const {
  return m_SsId;
}
void TwapId::setSsId(std::string const& value) {
  m_SsId = value;
}
std::string TwapId::getBssId() const {
  return m_BssId;
}
void TwapId::setBssId(std::string const& value) {
  m_BssId      = value;
  m_BssIdIsSet = true;
}
bool TwapId::bssIdIsSet() const {
  return m_BssIdIsSet;
}
void TwapId::unsetBssId() {
  m_BssIdIsSet = false;
}
std::string TwapId::getCivicAddress() const {
  return m_CivicAddress;
}
void TwapId::setCivicAddress(std::string const& value) {
  m_CivicAddress      = value;
  m_CivicAddressIsSet = true;
}
bool TwapId::civicAddressIsSet() const {
  return m_CivicAddressIsSet;
}
void TwapId::unsetCivicAddress() {
  m_CivicAddressIsSet = false;
}

}  // namespace ngkore::model::common
