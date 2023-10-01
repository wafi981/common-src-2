
#include "BatteryIndicationRm.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

BatteryIndicationRm::BatteryIndicationRm() {
  m_BatteryInd           = false;
  m_BatteryIndIsSet      = false;
  m_ReplaceableInd       = false;
  m_ReplaceableIndIsSet  = false;
  m_RechargeableInd      = false;
  m_RechargeableIndIsSet = false;
}

void BatteryIndicationRm::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool BatteryIndicationRm::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool BatteryIndicationRm::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "BatteryIndicationRm" : pathPrefix;

  return success;
}

bool BatteryIndicationRm::operator==(const BatteryIndicationRm& rhs) const {
  return

      ((!batteryIndIsSet() && !rhs.batteryIndIsSet()) ||
       (batteryIndIsSet() && rhs.batteryIndIsSet() &&
        isBatteryInd() == rhs.isBatteryInd())) &&

      ((!replaceableIndIsSet() && !rhs.replaceableIndIsSet()) ||
       (replaceableIndIsSet() && rhs.replaceableIndIsSet() &&
        isReplaceableInd() == rhs.isReplaceableInd())) &&

      ((!rechargeableIndIsSet() && !rhs.rechargeableIndIsSet()) ||
       (rechargeableIndIsSet() && rhs.rechargeableIndIsSet() &&
        isRechargeableInd() == rhs.isRechargeableInd()))

          ;
}

bool BatteryIndicationRm::operator!=(const BatteryIndicationRm& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const BatteryIndicationRm& o) {
  j = nlohmann::json();
  if (o.batteryIndIsSet()) j["batteryInd"] = o.m_BatteryInd;
  if (o.replaceableIndIsSet()) j["replaceableInd"] = o.m_ReplaceableInd;
  if (o.rechargeableIndIsSet()) j["rechargeableInd"] = o.m_RechargeableInd;
}

void from_json(const nlohmann::json& j, BatteryIndicationRm& o) {
  if (j.find("batteryInd") != j.end()) {
    j.at("batteryInd").get_to(o.m_BatteryInd);
    o.m_BatteryIndIsSet = true;
  }
  if (j.find("replaceableInd") != j.end()) {
    j.at("replaceableInd").get_to(o.m_ReplaceableInd);
    o.m_ReplaceableIndIsSet = true;
  }
  if (j.find("rechargeableInd") != j.end()) {
    j.at("rechargeableInd").get_to(o.m_RechargeableInd);
    o.m_RechargeableIndIsSet = true;
  }
}

bool BatteryIndicationRm::isBatteryInd() const {
  return m_BatteryInd;
}
void BatteryIndicationRm::setBatteryInd(bool const value) {
  m_BatteryInd      = value;
  m_BatteryIndIsSet = true;
}
bool BatteryIndicationRm::batteryIndIsSet() const {
  return m_BatteryIndIsSet;
}
void BatteryIndicationRm::unsetBatteryInd() {
  m_BatteryIndIsSet = false;
}
bool BatteryIndicationRm::isReplaceableInd() const {
  return m_ReplaceableInd;
}
void BatteryIndicationRm::setReplaceableInd(bool const value) {
  m_ReplaceableInd      = value;
  m_ReplaceableIndIsSet = true;
}
bool BatteryIndicationRm::replaceableIndIsSet() const {
  return m_ReplaceableIndIsSet;
}
void BatteryIndicationRm::unsetReplaceableInd() {
  m_ReplaceableIndIsSet = false;
}
bool BatteryIndicationRm::isRechargeableInd() const {
  return m_RechargeableInd;
}
void BatteryIndicationRm::setRechargeableInd(bool const value) {
  m_RechargeableInd      = value;
  m_RechargeableIndIsSet = true;
}
bool BatteryIndicationRm::rechargeableIndIsSet() const {
  return m_RechargeableIndIsSet;
}
void BatteryIndicationRm::unsetRechargeableInd() {
  m_RechargeableIndIsSet = false;
}

}  // namespace ngkore::model::common
