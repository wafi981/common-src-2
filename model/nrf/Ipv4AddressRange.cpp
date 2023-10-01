
#include "Ipv4AddressRange.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::nrf {

Ipv4AddressRange::Ipv4AddressRange() {
  m_Start      = "";
  m_StartIsSet = false;
  m_End        = "";
  m_EndIsSet   = false;
}

void Ipv4AddressRange::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool Ipv4AddressRange::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool Ipv4AddressRange::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "Ipv4AddressRange" : pathPrefix;

  if (startIsSet()) {
    const std::string& value           = m_Start;
    const std::string currentValuePath = _pathPrefix + ".start";
  }

  if (endIsSet()) {
    const std::string& value           = m_End;
    const std::string currentValuePath = _pathPrefix + ".end";
  }

  return success;
}

bool Ipv4AddressRange::operator==(const Ipv4AddressRange& rhs) const {
  return

      ((!startIsSet() && !rhs.startIsSet()) ||
       (startIsSet() && rhs.startIsSet() && getStart() == rhs.getStart())) &&

      ((!endIsSet() && !rhs.endIsSet()) ||
       (endIsSet() && rhs.endIsSet() && getEnd() == rhs.getEnd()))

          ;
}

bool Ipv4AddressRange::operator!=(const Ipv4AddressRange& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const Ipv4AddressRange& o) {
  j = nlohmann::json();
  if (o.startIsSet()) j["start"] = o.m_Start;
  if (o.endIsSet()) j["end"] = o.m_End;
}

void from_json(const nlohmann::json& j, Ipv4AddressRange& o) {
  if (j.find("start") != j.end()) {
    j.at("start").get_to(o.m_Start);
    o.m_StartIsSet = true;
  }
  if (j.find("end") != j.end()) {
    j.at("end").get_to(o.m_End);
    o.m_EndIsSet = true;
  }
}

std::string Ipv4AddressRange::getStart() const {
  return m_Start;
}
void Ipv4AddressRange::setStart(std::string const& value) {
  m_Start      = value;
  m_StartIsSet = true;
}
bool Ipv4AddressRange::startIsSet() const {
  return m_StartIsSet;
}
void Ipv4AddressRange::unsetStart() {
  m_StartIsSet = false;
}
std::string Ipv4AddressRange::getEnd() const {
  return m_End;
}
void Ipv4AddressRange::setEnd(std::string const& value) {
  m_End      = value;
  m_EndIsSet = true;
}
bool Ipv4AddressRange::endIsSet() const {
  return m_EndIsSet;
}
void Ipv4AddressRange::unsetEnd() {
  m_EndIsSet = false;
}

}  // namespace ngkore::model::nrf
