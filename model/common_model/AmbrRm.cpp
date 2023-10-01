
#include "AmbrRm.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

AmbrRm::AmbrRm() {
  m_Uplink   = "";
  m_Downlink = "";
}

void AmbrRm::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool AmbrRm::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool AmbrRm::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success                  = true;
  const std::string _pathPrefix = pathPrefix.empty() ? "AmbrRm" : pathPrefix;

    const std::string& value           = m_Downlink;
    const std::string currentValuePath = _pathPrefix + ".downlink";
  }

  return success;
}

bool AmbrRm::operator==(const AmbrRm& rhs) const {
  return

      (getUplink() == rhs.getUplink()) &&

      (getDownlink() == rhs.getDownlink())

          ;
}

bool AmbrRm::operator!=(const AmbrRm& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const AmbrRm& o) {
  j             = nlohmann::json();
  j["uplink"]   = o.m_Uplink;
  j["downlink"] = o.m_Downlink;
}

void from_json(const nlohmann::json& j, AmbrRm& o) {
  j.at("uplink").get_to(o.m_Uplink);
  j.at("downlink").get_to(o.m_Downlink);
}

std::string AmbrRm::getUplink() const {
  return m_Uplink;
}
void AmbrRm::setUplink(std::string const& value) {
  m_Uplink = value;
}
std::string AmbrRm::getDownlink() const {
  return m_Downlink;
}
void AmbrRm::setDownlink(std::string const& value) {
  m_Downlink = value;
}

}  // namespace ngkore::model::common
