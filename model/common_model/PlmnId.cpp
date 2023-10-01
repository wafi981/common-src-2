
#include "PlmnId.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

PlmnId::PlmnId() {
  m_Mcc = "";
  m_Mnc = "";
}

void PlmnId::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool PlmnId::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool PlmnId::validate(
  return success;
}

bool PlmnId::operator==(const PlmnId& rhs) const {
  return

      (getMcc() == rhs.getMcc()) &&

      (getMnc() == rhs.getMnc())

          ;
}

bool PlmnId::operator!=(const PlmnId& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const PlmnId& o) {
  j        = nlohmann::json();
  j["mcc"] = o.m_Mcc;
  j["mnc"] = o.m_Mnc;
}

void from_json(const nlohmann::json& j, PlmnId& o) {
  j.at("mcc").get_to(o.m_Mcc);
  j.at("mnc").get_to(o.m_Mnc);
}

std::string PlmnId::getMcc() const {
  return m_Mcc;
}
void PlmnId::setMcc(std::string const& value) {
  m_Mcc = value;
}
std::string PlmnId::getMnc() const {
  return m_Mnc;
}
void PlmnId::setMnc(std::string const& value) {
  m_Mnc = value;
}

}  // namespace ngkore::model::common
