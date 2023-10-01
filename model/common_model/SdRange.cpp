
#include "SdRange.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

SdRange::SdRange() {
  m_Start      = "";
  m_StartIsSet = false;
  m_End        = "";
  m_EndIsSet   = false;
}

void SdRange::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool SdRange::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool SdRange::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success                  = true;
  const std::string _pathPrefix = pathPrefix.empty() ? "SdRange" : pathPrefix;

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

bool SdRange::operator==(const SdRange& rhs) const {
  return

      ((!startIsSet() && !rhs.startIsSet()) ||
       (startIsSet() && rhs.startIsSet() && getStart() == rhs.getStart())) &&

      ((!endIsSet() && !rhs.endIsSet()) ||
       (endIsSet() && rhs.endIsSet() && getEnd() == rhs.getEnd()))

          ;
}

bool SdRange::operator!=(const SdRange& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const SdRange& o) {
  j = nlohmann::json();
  if (o.startIsSet()) j["start"] = o.m_Start;
  if (o.endIsSet()) j["end"] = o.m_End;
}

void from_json(const nlohmann::json& j, SdRange& o) {
  if (j.find("start") != j.end()) {
    j.at("start").get_to(o.m_Start);
    o.m_StartIsSet = true;
  }
  if (j.find("end") != j.end()) {
    j.at("end").get_to(o.m_End);
    o.m_EndIsSet = true;
  }
}

std::string SdRange::getStart() const {
  return m_Start;
}
void SdRange::setStart(std::string const& value) {
  m_Start      = value;
  m_StartIsSet = true;
}
bool SdRange::startIsSet() const {
  return m_StartIsSet;
}
void SdRange::unsetStart() {
  m_StartIsSet = false;
}
std::string SdRange::getEnd() const {
  return m_End;
}
void SdRange::setEnd(std::string const& value) {
  m_End      = value;
  m_EndIsSet = true;
}
bool SdRange::endIsSet() const {
  return m_EndIsSet;
}
void SdRange::unsetEnd() {
  m_EndIsSet = false;
}

}  // namespace ngkore::model::common
