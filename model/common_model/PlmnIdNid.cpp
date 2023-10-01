
#include "PlmnIdNid.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

PlmnIdNid::PlmnIdNid() {
  m_Mcc      = "";
  m_Mnc      = "";
  m_Nid      = "";
  m_NidIsSet = false;
}

void PlmnIdNid::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool PlmnIdNid::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool PlmnIdNid::validate(
  return success;
}

bool PlmnIdNid::operator==(const PlmnIdNid& rhs) const {
  return

      (getMcc() == rhs.getMcc()) &&

      (getMnc() == rhs.getMnc()) &&

      ((!nidIsSet() && !rhs.nidIsSet()) ||
       (nidIsSet() && rhs.nidIsSet() && getNid() == rhs.getNid()))

          ;
}

bool PlmnIdNid::operator!=(const PlmnIdNid& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const PlmnIdNid& o) {
  j        = nlohmann::json();
  j["mcc"] = o.m_Mcc;
  j["mnc"] = o.m_Mnc;
  if (o.nidIsSet()) j["nid"] = o.m_Nid;
}

void from_json(const nlohmann::json& j, PlmnIdNid& o) {
  j.at("mcc").get_to(o.m_Mcc);
  j.at("mnc").get_to(o.m_Mnc);
  if (j.find("nid") != j.end()) {
    j.at("nid").get_to(o.m_Nid);
    o.m_NidIsSet = true;
  }
}

std::string PlmnIdNid::getMcc() const {
  return m_Mcc;
}
void PlmnIdNid::setMcc(std::string const& value) {
  m_Mcc = value;
}
std::string PlmnIdNid::getMnc() const {
  return m_Mnc;
}
void PlmnIdNid::setMnc(std::string const& value) {
  m_Mnc = value;
}
std::string PlmnIdNid::getNid() const {
  return m_Nid;
}
void PlmnIdNid::setNid(std::string const& value) {
  m_Nid      = value;
  m_NidIsSet = true;
}
bool PlmnIdNid::nidIsSet() const {
  return m_NidIsSet;
}
void PlmnIdNid::unsetNid() {
  m_NidIsSet = false;
}

}  // namespace ngkore::model::common
