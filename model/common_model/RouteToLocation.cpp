
#include "RouteToLocation.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

RouteToLocation::RouteToLocation() {
  m_Dnai             = "";
  m_RouteInfoIsSet   = false;
  m_RouteProfId      = "";
  m_RouteProfIdIsSet = false;
}

void RouteToLocation::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool RouteToLocation::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool RouteToLocation::validate(
  return success;
}

bool RouteToLocation::operator==(const RouteToLocation& rhs) const {
  return

      (getDnai() == rhs.getDnai()) &&

      ((!routeInfoIsSet() && !rhs.routeInfoIsSet()) ||
       (routeInfoIsSet() && rhs.routeInfoIsSet() &&
        getRouteInfo() == rhs.getRouteInfo())) &&

      ((!routeProfIdIsSet() && !rhs.routeProfIdIsSet()) ||
       (routeProfIdIsSet() && rhs.routeProfIdIsSet() &&
        getRouteProfId() == rhs.getRouteProfId()))

          ;
}

bool RouteToLocation::operator!=(const RouteToLocation& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const RouteToLocation& o) {
  j         = nlohmann::json();
  j["dnai"] = o.m_Dnai;
  if (o.routeInfoIsSet()) j["routeInfo"] = o.m_RouteInfo;
  if (o.routeProfIdIsSet()) j["routeProfId"] = o.m_RouteProfId;
}

void from_json(const nlohmann::json& j, RouteToLocation& o) {
  j.at("dnai").get_to(o.m_Dnai);
  if (j.find("routeInfo") != j.end()) {
    j.at("routeInfo").get_to(o.m_RouteInfo);
    o.m_RouteInfoIsSet = true;
  }
  if (j.find("routeProfId") != j.end()) {
    j.at("routeProfId").get_to(o.m_RouteProfId);
    o.m_RouteProfIdIsSet = true;
  }
}

std::string RouteToLocation::getDnai() const {
  return m_Dnai;
}
void RouteToLocation::setDnai(std::string const& value) {
  m_Dnai = value;
}
ngkore::model::common::RouteInformation RouteToLocation::getRouteInfo() const {
  return m_RouteInfo;
}
void RouteToLocation::setRouteInfo(
    ngkore::model::common::RouteInformation const& value) {
  m_RouteInfo      = value;
  m_RouteInfoIsSet = true;
}
bool RouteToLocation::routeInfoIsSet() const {
  return m_RouteInfoIsSet;
}
void RouteToLocation::unsetRouteInfo() {
  m_RouteInfoIsSet = false;
}
std::string RouteToLocation::getRouteProfId() const {
  return m_RouteProfId;
}
void RouteToLocation::setRouteProfId(std::string const& value) {
  m_RouteProfId      = value;
  m_RouteProfIdIsSet = true;
}
bool RouteToLocation::routeProfIdIsSet() const {
  return m_RouteProfIdIsSet;
}
void RouteToLocation::unsetRouteProfId() {
  m_RouteProfIdIsSet = false;
}

}  // namespace ngkore::model::common
