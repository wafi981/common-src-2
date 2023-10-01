
#include "RoutingAreaId.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

RoutingAreaId::RoutingAreaId() {
  m_Lac = "";
  m_Rac = "";
}

void RoutingAreaId::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool RoutingAreaId::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool RoutingAreaId::validate(
  return success;
}

bool RoutingAreaId::operator==(const RoutingAreaId& rhs) const {
  return

      (getPlmnId() == rhs.getPlmnId()) &&

      (getLac() == rhs.getLac()) &&

      (getRac() == rhs.getRac())

          ;
}

bool RoutingAreaId::operator!=(const RoutingAreaId& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const RoutingAreaId& o) {
  j           = nlohmann::json();
  j["plmnId"] = o.m_PlmnId;
  j["lac"]    = o.m_Lac;
  j["rac"]    = o.m_Rac;
}

void from_json(const nlohmann::json& j, RoutingAreaId& o) {
  j.at("plmnId").get_to(o.m_PlmnId);
  j.at("lac").get_to(o.m_Lac);
  j.at("rac").get_to(o.m_Rac);
}

ngkore::model::common::PlmnId RoutingAreaId::getPlmnId() const {
  return m_PlmnId;
}
void RoutingAreaId::setPlmnId(ngkore::model::common::PlmnId const& value) {
  m_PlmnId = value;
}
std::string RoutingAreaId::getLac() const {
  return m_Lac;
}
void RoutingAreaId::setLac(std::string const& value) {
  m_Lac = value;
}
std::string RoutingAreaId::getRac() const {
  return m_Rac;
}
void RoutingAreaId::setRac(std::string const& value) {
  m_Rac = value;
}

}  // namespace ngkore::model::common
