
#include "TwapIdRm.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

TwapIdRm::TwapIdRm() {
  m_SsId              = "";
  m_BssId             = "";
  m_BssIdIsSet        = false;
  m_CivicAddressIsSet = false;
}

void TwapIdRm::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool TwapIdRm::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool TwapIdRm::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success                  = true;
  const std::string _pathPrefix = pathPrefix.empty() ? "TwapIdRm" : pathPrefix;

  return success;
}

bool TwapIdRm::operator==(const TwapIdRm& rhs) const {
  return

      (getSsId() == rhs.getSsId()) &&

      ((!bssIdIsSet() && !rhs.bssIdIsSet()) ||
       (bssIdIsSet() && rhs.bssIdIsSet() && getBssId() == rhs.getBssId())) &&

      ((!civicAddressIsSet() && !rhs.civicAddressIsSet()) ||
       (civicAddressIsSet() && rhs.civicAddressIsSet() &&
        getCivicAddress() == rhs.getCivicAddress()))

          ;
}

bool TwapIdRm::operator!=(const TwapIdRm& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const TwapIdRm& o) {
  j         = nlohmann::json();
  j["ssId"] = o.m_SsId;
  if (o.bssIdIsSet()) j["bssId"] = o.m_BssId;
  if (o.civicAddressIsSet()) j["civicAddress"] = o.m_CivicAddress;
}

void from_json(const nlohmann::json& j, TwapIdRm& o) {
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

std::string TwapIdRm::getSsId() const {
  return m_SsId;
}
void TwapIdRm::setSsId(std::string const& value) {
  m_SsId = value;
}
std::string TwapIdRm::getBssId() const {
  return m_BssId;
}
void TwapIdRm::setBssId(std::string const& value) {
  m_BssId      = value;
  m_BssIdIsSet = true;
}
bool TwapIdRm::bssIdIsSet() const {
  return m_BssIdIsSet;
}
void TwapIdRm::unsetBssId() {
  m_BssIdIsSet = false;
}
std::string TwapIdRm::getCivicAddress() const {
  return m_CivicAddress;
}
void TwapIdRm::setCivicAddress(std::string const& value) {
  m_CivicAddress      = value;
  m_CivicAddressIsSet = true;
}
bool TwapIdRm::civicAddressIsSet() const {
  return m_CivicAddressIsSet;
}
void TwapIdRm::unsetCivicAddress() {
  m_CivicAddressIsSet = false;
}

}  // namespace ngkore::model::common
