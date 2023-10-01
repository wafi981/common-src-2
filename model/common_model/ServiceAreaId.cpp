
#include "ServiceAreaId.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

ServiceAreaId::ServiceAreaId() {
  m_Lac = "";
  m_Sac = "";
}

void ServiceAreaId::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool ServiceAreaId::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool ServiceAreaId::validate(
  return success;
}

bool ServiceAreaId::operator==(const ServiceAreaId& rhs) const {
  return

      (getPlmnId() == rhs.getPlmnId()) &&

      (getLac() == rhs.getLac()) &&

      (getSac() == rhs.getSac())

          ;
}

bool ServiceAreaId::operator!=(const ServiceAreaId& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const ServiceAreaId& o) {
  j           = nlohmann::json();
  j["plmnId"] = o.m_PlmnId;
  j["lac"]    = o.m_Lac;
  j["sac"]    = o.m_Sac;
}

void from_json(const nlohmann::json& j, ServiceAreaId& o) {
  j.at("plmnId").get_to(o.m_PlmnId);
  j.at("lac").get_to(o.m_Lac);
  j.at("sac").get_to(o.m_Sac);
}

ngkore::model::common::PlmnId ServiceAreaId::getPlmnId() const {
  return m_PlmnId;
}
void ServiceAreaId::setPlmnId(ngkore::model::common::PlmnId const& value) {
  m_PlmnId = value;
}
std::string ServiceAreaId::getLac() const {
  return m_Lac;
}
void ServiceAreaId::setLac(std::string const& value) {
  m_Lac = value;
}
std::string ServiceAreaId::getSac() const {
  return m_Sac;
}
void ServiceAreaId::setSac(std::string const& value) {
  m_Sac = value;
}

}  // namespace ngkore::model::common
