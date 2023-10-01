
#include "Ncgi.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

Ncgi::Ncgi() {
  m_NrCellId = "";
  m_Nid      = "";
  m_NidIsSet = false;
}

void Ncgi::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool Ncgi::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool Ncgi::validate(
  return success;
}

bool Ncgi::operator==(const Ncgi& rhs) const {
  return

      (getPlmnId() == rhs.getPlmnId()) &&

      (getNrCellId() == rhs.getNrCellId()) &&

      ((!nidIsSet() && !rhs.nidIsSet()) ||
       (nidIsSet() && rhs.nidIsSet() && getNid() == rhs.getNid()))

          ;
}

bool Ncgi::operator!=(const Ncgi& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const Ncgi& o) {
  j             = nlohmann::json();
  j["plmnId"]   = o.m_PlmnId;
  j["nrCellId"] = o.m_NrCellId;
  if (o.nidIsSet()) j["nid"] = o.m_Nid;
}

void from_json(const nlohmann::json& j, Ncgi& o) {
  j.at("plmnId").get_to(o.m_PlmnId);
  j.at("nrCellId").get_to(o.m_NrCellId);
  if (j.find("nid") != j.end()) {
    j.at("nid").get_to(o.m_Nid);
    o.m_NidIsSet = true;
  }
}

ngkore::model::common::PlmnId Ncgi::getPlmnId() const {
  return m_PlmnId;
}
void Ncgi::setPlmnId(ngkore::model::common::PlmnId const& value) {
  m_PlmnId = value;
}
std::string Ncgi::getNrCellId() const {
  return m_NrCellId;
}
void Ncgi::setNrCellId(std::string const& value) {
  m_NrCellId = value;
}
std::string Ncgi::getNid() const {
  return m_Nid;
}
void Ncgi::setNid(std::string const& value) {
  m_Nid      = value;
  m_NidIsSet = true;
}
bool Ncgi::nidIsSet() const {
  return m_NidIsSet;
}
void Ncgi::unsetNid() {
  m_NidIsSet = false;
}

}  // namespace ngkore::model::common
