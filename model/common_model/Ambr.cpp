
#include "Ambr.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

Ambr::Ambr() {
  m_Uplink   = "";
  m_Downlink = "";
}

void Ambr::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool Ambr::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool Ambr::validate(
  return success;
}

bool Ambr::operator==(const Ambr& rhs) const {
  return

      (getUplink() == rhs.getUplink()) &&

      (getDownlink() == rhs.getDownlink())

          ;
}

bool Ambr::operator!=(const Ambr& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const Ambr& o) {
  j             = nlohmann::json();
  j["uplink"]   = o.m_Uplink;
  j["downlink"] = o.m_Downlink;
}

void from_json(const nlohmann::json& j, Ambr& o) {
  j.at("uplink").get_to(o.m_Uplink);
  j.at("downlink").get_to(o.m_Downlink);
}

std::string Ambr::getUplink() const {
  return m_Uplink;
}
void Ambr::setUplink(std::string const& value) {
  m_Uplink = value;
}
std::string Ambr::getDownlink() const {
  return m_Downlink;
}
void Ambr::setDownlink(std::string const& value) {
  m_Downlink = value;
}

}  // namespace ngkore::model::common
