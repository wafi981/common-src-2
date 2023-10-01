
#include "Ecgi.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

Ecgi::Ecgi() {
  m_EutraCellId = "";
  m_Nid         = "";
  m_NidIsSet    = false;
}

void Ecgi::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool Ecgi::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool Ecgi::validate(
  return success;
}

bool Ecgi::operator==(const Ecgi& rhs) const {
  return

      (getPlmnId() == rhs.getPlmnId()) &&

      (getEutraCellId() == rhs.getEutraCellId()) &&

      ((!nidIsSet() && !rhs.nidIsSet()) ||
       (nidIsSet() && rhs.nidIsSet() && getNid() == rhs.getNid()))

          ;
}

bool Ecgi::operator!=(const Ecgi& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const Ecgi& o) {
  j                = nlohmann::json();
  j["plmnId"]      = o.m_PlmnId;
  j["eutraCellId"] = o.m_EutraCellId;
  if (o.nidIsSet()) j["nid"] = o.m_Nid;
}

void from_json(const nlohmann::json& j, Ecgi& o) {
  j.at("plmnId").get_to(o.m_PlmnId);
  j.at("eutraCellId").get_to(o.m_EutraCellId);
  if (j.find("nid") != j.end()) {
    j.at("nid").get_to(o.m_Nid);
    o.m_NidIsSet = true;
  }
}

ngkore::model::common::PlmnId Ecgi::getPlmnId() const {
  return m_PlmnId;
}
void Ecgi::setPlmnId(ngkore::model::common::PlmnId const& value) {
  m_PlmnId = value;
}
std::string Ecgi::getEutraCellId() const {
  return m_EutraCellId;
}
void Ecgi::setEutraCellId(std::string const& value) {
  m_EutraCellId = value;
}
std::string Ecgi::getNid() const {
  return m_Nid;
}
void Ecgi::setNid(std::string const& value) {
  m_Nid      = value;
  m_NidIsSet = true;
}
bool Ecgi::nidIsSet() const {
  return m_NidIsSet;
}
void Ecgi::unsetNid() {
  m_NidIsSet = false;
}

}  // namespace ngkore::model::common
