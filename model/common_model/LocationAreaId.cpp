
#include "LocationAreaId.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

LocationAreaId::LocationAreaId() {
  m_Lac = "";
}

void LocationAreaId::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool LocationAreaId::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool LocationAreaId::validate(
  return success;
}

bool LocationAreaId::operator==(const LocationAreaId& rhs) const {
  return

      (getPlmnId() == rhs.getPlmnId()) &&

      (getLac() == rhs.getLac())

          ;
}

bool LocationAreaId::operator!=(const LocationAreaId& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const LocationAreaId& o) {
  j           = nlohmann::json();
  j["plmnId"] = o.m_PlmnId;
  j["lac"]    = o.m_Lac;
}

void from_json(const nlohmann::json& j, LocationAreaId& o) {
  j.at("plmnId").get_to(o.m_PlmnId);
  j.at("lac").get_to(o.m_Lac);
}

ngkore::model::common::PlmnId LocationAreaId::getPlmnId() const {
  return m_PlmnId;
}
void LocationAreaId::setPlmnId(ngkore::model::common::PlmnId const& value) {
  m_PlmnId = value;
}
std::string LocationAreaId::getLac() const {
  return m_Lac;
}
void LocationAreaId::setLac(std::string const& value) {
  m_Lac = value;
}

}  // namespace ngkore::model::common
