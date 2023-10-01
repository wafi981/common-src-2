
#include "GlobalRanNodeId.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

GlobalRanNodeId::GlobalRanNodeId() {
  m_N3IwfId      = "";
  m_N3IwfIdIsSet = false;
  m_GNbIdIsSet   = false;
  m_NgeNbId      = "";
  m_NgeNbIdIsSet = false;
  m_WagfId       = "";
  m_WagfIdIsSet  = false;
  m_TngfId       = "";
  m_TngfIdIsSet  = false;
  m_Nid          = "";
  m_NidIsSet     = false;
  m_ENbId        = "";
  m_ENbIdIsSet   = false;
}

void GlobalRanNodeId::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool GlobalRanNodeId::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool GlobalRanNodeId::validate(
  return success;
}

bool GlobalRanNodeId::operator==(const GlobalRanNodeId& rhs) const {
  return

      (getPlmnId() == rhs.getPlmnId()) &&

      ((!n3IwfIdIsSet() && !rhs.n3IwfIdIsSet()) ||
       (n3IwfIdIsSet() && rhs.n3IwfIdIsSet() &&
        getN3IwfId() == rhs.getN3IwfId())) &&

      ((!gNbIdIsSet() && !rhs.gNbIdIsSet()) ||
       (gNbIdIsSet() && rhs.gNbIdIsSet() && getGNbId() == rhs.getGNbId())) &&

      ((!ngeNbIdIsSet() && !rhs.ngeNbIdIsSet()) ||
       (ngeNbIdIsSet() && rhs.ngeNbIdIsSet() &&
        getNgeNbId() == rhs.getNgeNbId())) &&

      ((!wagfIdIsSet() && !rhs.wagfIdIsSet()) ||
       (wagfIdIsSet() && rhs.wagfIdIsSet() &&
        getWagfId() == rhs.getWagfId())) &&

      ((!tngfIdIsSet() && !rhs.tngfIdIsSet()) ||
       (tngfIdIsSet() && rhs.tngfIdIsSet() &&
        getTngfId() == rhs.getTngfId())) &&

      ((!nidIsSet() && !rhs.nidIsSet()) ||
       (nidIsSet() && rhs.nidIsSet() && getNid() == rhs.getNid())) &&

      ((!eNbIdIsSet() && !rhs.eNbIdIsSet()) ||
       (eNbIdIsSet() && rhs.eNbIdIsSet() && getENbId() == rhs.getENbId()))

          ;
}

bool GlobalRanNodeId::operator!=(const GlobalRanNodeId& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const GlobalRanNodeId& o) {
  j           = nlohmann::json();
  j["plmnId"] = o.m_PlmnId;
  if (o.n3IwfIdIsSet()) j["n3IwfId"] = o.m_N3IwfId;
  if (o.gNbIdIsSet()) j["gNbId"] = o.m_GNbId;
  if (o.ngeNbIdIsSet()) j["ngeNbId"] = o.m_NgeNbId;
  if (o.wagfIdIsSet()) j["wagfId"] = o.m_WagfId;
  if (o.tngfIdIsSet()) j["tngfId"] = o.m_TngfId;
  if (o.nidIsSet()) j["nid"] = o.m_Nid;
  if (o.eNbIdIsSet()) j["eNbId"] = o.m_ENbId;
}

void from_json(const nlohmann::json& j, GlobalRanNodeId& o) {
  j.at("plmnId").get_to(o.m_PlmnId);
  if (j.find("n3IwfId") != j.end()) {
    j.at("n3IwfId").get_to(o.m_N3IwfId);
    o.m_N3IwfIdIsSet = true;
  }
  if (j.find("gNbId") != j.end()) {
    j.at("gNbId").get_to(o.m_GNbId);
    o.m_GNbIdIsSet = true;
  }
  if (j.find("ngeNbId") != j.end()) {
    j.at("ngeNbId").get_to(o.m_NgeNbId);
    o.m_NgeNbIdIsSet = true;
  }
  if (j.find("wagfId") != j.end()) {
    j.at("wagfId").get_to(o.m_WagfId);
    o.m_WagfIdIsSet = true;
  }
  if (j.find("tngfId") != j.end()) {
    j.at("tngfId").get_to(o.m_TngfId);
    o.m_TngfIdIsSet = true;
  }
  if (j.find("nid") != j.end()) {
    j.at("nid").get_to(o.m_Nid);
    o.m_NidIsSet = true;
  }
  if (j.find("eNbId") != j.end()) {
    j.at("eNbId").get_to(o.m_ENbId);
    o.m_ENbIdIsSet = true;
  }
}

ngkore::model::common::PlmnId GlobalRanNodeId::getPlmnId() const {
  return m_PlmnId;
}
void GlobalRanNodeId::setPlmnId(ngkore::model::common::PlmnId const& value) {
  m_PlmnId = value;
}
std::string GlobalRanNodeId::getN3IwfId() const {
  return m_N3IwfId;
}
void GlobalRanNodeId::setN3IwfId(std::string const& value) {
  m_N3IwfId      = value;
  m_N3IwfIdIsSet = true;
}
bool GlobalRanNodeId::n3IwfIdIsSet() const {
  return m_N3IwfIdIsSet;
}
void GlobalRanNodeId::unsetN3IwfId() {
  m_N3IwfIdIsSet = false;
}
ngkore::model::common::GNbId GlobalRanNodeId::getGNbId() const {
  return m_GNbId;
}
void GlobalRanNodeId::setGNbId(ngkore::model::common::GNbId const& value) {
  m_GNbId      = value;
  m_GNbIdIsSet = true;
}
bool GlobalRanNodeId::gNbIdIsSet() const {
  return m_GNbIdIsSet;
}
void GlobalRanNodeId::unsetGNbId() {
  m_GNbIdIsSet = false;
}
std::string GlobalRanNodeId::getNgeNbId() const {
  return m_NgeNbId;
}
void GlobalRanNodeId::setNgeNbId(std::string const& value) {
  m_NgeNbId      = value;
  m_NgeNbIdIsSet = true;
}
bool GlobalRanNodeId::ngeNbIdIsSet() const {
  return m_NgeNbIdIsSet;
}
void GlobalRanNodeId::unsetNgeNbId() {
  m_NgeNbIdIsSet = false;
}
std::string GlobalRanNodeId::getWagfId() const {
  return m_WagfId;
}
void GlobalRanNodeId::setWagfId(std::string const& value) {
  m_WagfId      = value;
  m_WagfIdIsSet = true;
}
bool GlobalRanNodeId::wagfIdIsSet() const {
  return m_WagfIdIsSet;
}
void GlobalRanNodeId::unsetWagfId() {
  m_WagfIdIsSet = false;
}
std::string GlobalRanNodeId::getTngfId() const {
  return m_TngfId;
}
void GlobalRanNodeId::setTngfId(std::string const& value) {
  m_TngfId      = value;
  m_TngfIdIsSet = true;
}
bool GlobalRanNodeId::tngfIdIsSet() const {
  return m_TngfIdIsSet;
}
void GlobalRanNodeId::unsetTngfId() {
  m_TngfIdIsSet = false;
}
std::string GlobalRanNodeId::getNid() const {
  return m_Nid;
}
void GlobalRanNodeId::setNid(std::string const& value) {
  m_Nid      = value;
  m_NidIsSet = true;
}
bool GlobalRanNodeId::nidIsSet() const {
  return m_NidIsSet;
}
void GlobalRanNodeId::unsetNid() {
  m_NidIsSet = false;
}
std::string GlobalRanNodeId::getENbId() const {
  return m_ENbId;
}
void GlobalRanNodeId::setENbId(std::string const& value) {
  m_ENbId      = value;
  m_ENbIdIsSet = true;
}
bool GlobalRanNodeId::eNbIdIsSet() const {
  return m_ENbIdIsSet;
}
void GlobalRanNodeId::unsetENbId() {
  m_ENbIdIsSet = false;
}

}  // namespace ngkore::model::common