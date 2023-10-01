
#include "Tai.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

Tai::Tai() {
  m_Tac      = "";
  m_Nid      = "";
  m_NidIsSet = false;
}

void Tai::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool Tai::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool Tai::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success                  = true;
  const std::string _pathPrefix = pathPrefix.empty() ? "Tai" : pathPrefix;

  if (!m_PlmnId.validate(msg)) {
    msg << _pathPrefix << ": PlmnId is invalid;";
    success = false;
  }

  return success;
}

bool Tai::operator==(const Tai& rhs) const {
  return

      (getPlmnId() == rhs.getPlmnId()) &&

      (getTac() == rhs.getTac()) &&

      ((!nidIsSet() && !rhs.nidIsSet()) ||
       (nidIsSet() && rhs.nidIsSet() && getNid() == rhs.getNid()))

          ;
}

bool Tai::operator!=(const Tai& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const Tai& o) {
  j           = nlohmann::json();
  j["plmnId"] = o.m_PlmnId;
  j["tac"]    = o.m_Tac;
  if (o.nidIsSet()) j["nid"] = o.m_Nid;
}

void from_json(const nlohmann::json& j, Tai& o) {
  j.at("plmnId").get_to(o.m_PlmnId);
  j.at("tac").get_to(o.m_Tac);
  if (j.find("nid") != j.end()) {
    j.at("nid").get_to(o.m_Nid);
    o.m_NidIsSet = true;
  }
}

ngkore::model::common::PlmnId Tai::getPlmnId() const {
  return m_PlmnId;
}
void Tai::setPlmnId(ngkore::model::common::PlmnId const& value) {
  m_PlmnId = value;
}
std::string Tai::getTac() const {
  return m_Tac;
}
void Tai::setTac(std::string const& value) {
  m_Tac = value;
}
std::string Tai::getNid() const {
  return m_Nid;
}
void Tai::setNid(std::string const& value) {
  m_Nid      = value;
  m_NidIsSet = true;
}
bool Tai::nidIsSet() const {
  return m_NidIsSet;
}
void Tai::unsetNid() {
  m_NidIsSet = false;
}

}  // namespace ngkore::model::common
