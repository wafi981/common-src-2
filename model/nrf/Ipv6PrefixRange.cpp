
#include "Ipv6PrefixRange.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::nrf {

using namespace ngkore::model::common;

Ipv6PrefixRange::Ipv6PrefixRange() {
  m_StartIsSet = false;
  m_EndIsSet   = false;
}

void Ipv6PrefixRange::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool Ipv6PrefixRange::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool Ipv6PrefixRange::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "Ipv6PrefixRange" : pathPrefix;

  return success;
}

bool Ipv6PrefixRange::operator==(const Ipv6PrefixRange& rhs) const {
  return

      ((!startIsSet() && !rhs.startIsSet()) ||
       (startIsSet() && rhs.startIsSet() && getStart() == rhs.getStart())) &&

      ((!endIsSet() && !rhs.endIsSet()) ||
       (endIsSet() && rhs.endIsSet() && getEnd() == rhs.getEnd()))

          ;
}

bool Ipv6PrefixRange::operator!=(const Ipv6PrefixRange& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const Ipv6PrefixRange& o) {
  j = nlohmann::json();
  if (o.startIsSet()) j["start"] = o.m_Start;
  if (o.endIsSet()) j["end"] = o.m_End;
}

void from_json(const nlohmann::json& j, Ipv6PrefixRange& o) {
  if (j.find("start") != j.end()) {
    j.at("start").get_to(o.m_Start);
    o.m_StartIsSet = true;
  }
  if (j.find("end") != j.end()) {
    j.at("end").get_to(o.m_End);
    o.m_EndIsSet = true;
  }
}

Ipv6Prefix Ipv6PrefixRange::getStart() const {
  return m_Start;
}
void Ipv6PrefixRange::setStart(Ipv6Prefix const& value) {
  m_Start      = value;
  m_StartIsSet = true;
}
bool Ipv6PrefixRange::startIsSet() const {
  return m_StartIsSet;
}
void Ipv6PrefixRange::unsetStart() {
  m_StartIsSet = false;
}
Ipv6Prefix Ipv6PrefixRange::getEnd() const {
  return m_End;
}
void Ipv6PrefixRange::setEnd(Ipv6Prefix const& value) {
  m_End      = value;
  m_EndIsSet = true;
}
bool Ipv6PrefixRange::endIsSet() const {
  return m_EndIsSet;
}
void Ipv6PrefixRange::unsetEnd() {
  m_EndIsSet = false;
}

}  // namespace ngkore::model::nrf
