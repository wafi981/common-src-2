
#include "TacRange.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::nrf {

TacRange::TacRange() {
  m_Start        = "";
  m_StartIsSet   = false;
  m_End          = "";
  m_EndIsSet     = false;
  m_Pattern      = "";
  m_PatternIsSet = false;
}

void TacRange::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool TacRange::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool TacRange::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success                  = true;
  const std::string _pathPrefix = pathPrefix.empty() ? "TacRange" : pathPrefix;

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

bool TacRange::operator==(const TacRange& rhs) const {
  return

      ((!startIsSet() && !rhs.startIsSet()) ||
       (startIsSet() && rhs.startIsSet() && getStart() == rhs.getStart())) &&

      ((!endIsSet() && !rhs.endIsSet()) ||
       (endIsSet() && rhs.endIsSet() && getEnd() == rhs.getEnd())) &&

      ((!patternIsSet() && !rhs.patternIsSet()) ||
       (patternIsSet() && rhs.patternIsSet() &&
        getPattern() == rhs.getPattern()))

          ;
}

bool TacRange::operator!=(const TacRange& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const TacRange& o) {
  j = nlohmann::json::object();
  if (o.startIsSet()) j["start"] = o.m_Start;
  if (o.endIsSet()) j["end"] = o.m_End;
  if (o.patternIsSet()) j["pattern"] = o.m_Pattern;
}

void from_json(const nlohmann::json& j, TacRange& o) {
  if (j.find("start") != j.end()) {
    j.at("start").get_to(o.m_Start);
    o.m_StartIsSet = true;
  }
  if (j.find("end") != j.end()) {
    j.at("end").get_to(o.m_End);
    o.m_EndIsSet = true;
  }
  if (j.find("pattern") != j.end()) {
    j.at("pattern").get_to(o.m_Pattern);
    o.m_PatternIsSet = true;
  }
}

std::string TacRange::getStart() const {
  return m_Start;
}
void TacRange::setStart(std::string const& value) {
  m_Start      = value;
  m_StartIsSet = true;
}
bool TacRange::startIsSet() const {
  return m_StartIsSet;
}
void TacRange::unsetStart() {
  m_StartIsSet = false;
}
std::string TacRange::getEnd() const {
  return m_End;
}
void TacRange::setEnd(std::string const& value) {
  m_End      = value;
  m_EndIsSet = true;
}
bool TacRange::endIsSet() const {
  return m_EndIsSet;
}
void TacRange::unsetEnd() {
  m_EndIsSet = false;
}
std::string TacRange::getPattern() const {
  return m_Pattern;
}
void TacRange::setPattern(std::string const& value) {
  m_Pattern      = value;
  m_PatternIsSet = true;
}
bool TacRange::patternIsSet() const {
  return m_PatternIsSet;
}
void TacRange::unsetPattern() {
  m_PatternIsSet = false;
}

}  // namespace ngkore::model::nrf
