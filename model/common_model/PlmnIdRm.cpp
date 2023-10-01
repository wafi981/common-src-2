
#include "PlmnIdRm.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

PlmnIdRm::PlmnIdRm() {
  m_Mcc = "";
  m_Mnc = "";
}

void PlmnIdRm::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool PlmnIdRm::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool PlmnIdRm::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success                  = true;
  const std::string _pathPrefix = pathPrefix.empty() ? "PlmnIdRm" : pathPrefix;

    const std::string& value           = m_Mnc;
    const std::string currentValuePath = _pathPrefix + ".mnc";
  }

  return success;
}

bool PlmnIdRm::operator==(const PlmnIdRm& rhs) const {
  return

      (getMcc() == rhs.getMcc()) &&

      (getMnc() == rhs.getMnc())

          ;
}

bool PlmnIdRm::operator!=(const PlmnIdRm& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const PlmnIdRm& o) {
  j        = nlohmann::json();
  j["mcc"] = o.m_Mcc;
  j["mnc"] = o.m_Mnc;
}

void from_json(const nlohmann::json& j, PlmnIdRm& o) {
  j.at("mcc").get_to(o.m_Mcc);
  j.at("mnc").get_to(o.m_Mnc);
}

std::string PlmnIdRm::getMcc() const {
  return m_Mcc;
}
void PlmnIdRm::setMcc(std::string const& value) {
  m_Mcc = value;
}
std::string PlmnIdRm::getMnc() const {
  return m_Mnc;
}
void PlmnIdRm::setMnc(std::string const& value) {
  m_Mnc = value;
}

}  // namespace ngkore::model::common
