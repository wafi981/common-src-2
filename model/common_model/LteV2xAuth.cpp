
#include "LteV2xAuth.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

LteV2xAuth::LteV2xAuth() {
  m_VehicleUeAuthIsSet    = false;
  m_PedestrianUeAuthIsSet = false;
}

void LteV2xAuth::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool LteV2xAuth::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool LteV2xAuth::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "LteV2xAuth" : pathPrefix;

  return success;
}

bool LteV2xAuth::operator==(const LteV2xAuth& rhs) const {
  return

      ((!vehicleUeAuthIsSet() && !rhs.vehicleUeAuthIsSet()) ||
       (vehicleUeAuthIsSet() && rhs.vehicleUeAuthIsSet() &&
        getVehicleUeAuth() == rhs.getVehicleUeAuth())) &&

      ((!pedestrianUeAuthIsSet() && !rhs.pedestrianUeAuthIsSet()) ||
       (pedestrianUeAuthIsSet() && rhs.pedestrianUeAuthIsSet() &&
        getPedestrianUeAuth() == rhs.getPedestrianUeAuth()))

          ;
}

bool LteV2xAuth::operator!=(const LteV2xAuth& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const LteV2xAuth& o) {
  j = nlohmann::json();
  if (o.vehicleUeAuthIsSet()) j["vehicleUeAuth"] = o.m_VehicleUeAuth;
  if (o.pedestrianUeAuthIsSet()) j["pedestrianUeAuth"] = o.m_PedestrianUeAuth;
}

void from_json(const nlohmann::json& j, LteV2xAuth& o) {
  if (j.find("vehicleUeAuth") != j.end()) {
    j.at("vehicleUeAuth").get_to(o.m_VehicleUeAuth);
    o.m_VehicleUeAuthIsSet = true;
  }
  if (j.find("pedestrianUeAuth") != j.end()) {
    j.at("pedestrianUeAuth").get_to(o.m_PedestrianUeAuth);
    o.m_PedestrianUeAuthIsSet = true;
  }
}

ngkore::model::common::UeAuth LteV2xAuth::getVehicleUeAuth() const {
  return m_VehicleUeAuth;
}
void LteV2xAuth::setVehicleUeAuth(ngkore::model::common::UeAuth const& value) {
  m_VehicleUeAuth      = value;
  m_VehicleUeAuthIsSet = true;
}
bool LteV2xAuth::vehicleUeAuthIsSet() const {
  return m_VehicleUeAuthIsSet;
}
void LteV2xAuth::unsetVehicleUeAuth() {
  m_VehicleUeAuthIsSet = false;
}
ngkore::model::common::UeAuth LteV2xAuth::getPedestrianUeAuth() const {
  return m_PedestrianUeAuth;
}
void LteV2xAuth::setPedestrianUeAuth(ngkore::model::common::UeAuth const& value) {
  m_PedestrianUeAuth      = value;
  m_PedestrianUeAuthIsSet = true;
}
bool LteV2xAuth::pedestrianUeAuthIsSet() const {
  return m_PedestrianUeAuthIsSet;
}
void LteV2xAuth::unsetPedestrianUeAuth() {
  m_PedestrianUeAuthIsSet = false;
}

}  // namespace ngkore::model::common
