
#include "RedirectResponse.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

RedirectResponse::RedirectResponse() {
  m_Cause           = "";
  m_CauseIsSet      = false;
  m_TargetScp       = "";
  m_TargetScpIsSet  = false;
  m_TargetSepp      = "";
  m_TargetSeppIsSet = false;
}

void RedirectResponse::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool RedirectResponse::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool RedirectResponse::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "RedirectResponse" : pathPrefix;

  return success;
}

bool RedirectResponse::operator==(const RedirectResponse& rhs) const {
  return

      ((!causeIsSet() && !rhs.causeIsSet()) ||
       (causeIsSet() && rhs.causeIsSet() && getCause() == rhs.getCause())) &&

      ((!targetScpIsSet() && !rhs.targetScpIsSet()) ||
       (targetScpIsSet() && rhs.targetScpIsSet() &&
        getTargetScp() == rhs.getTargetScp())) &&

      ((!targetSeppIsSet() && !rhs.targetSeppIsSet()) ||
       (targetSeppIsSet() && rhs.targetSeppIsSet() &&
        getTargetSepp() == rhs.getTargetSepp()))

          ;
}

bool RedirectResponse::operator!=(const RedirectResponse& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const RedirectResponse& o) {
  j = nlohmann::json();
  if (o.causeIsSet()) j["cause"] = o.m_Cause;
  if (o.targetScpIsSet()) j["targetScp"] = o.m_TargetScp;
  if (o.targetSeppIsSet()) j["targetSepp"] = o.m_TargetSepp;
}

void from_json(const nlohmann::json& j, RedirectResponse& o) {
  if (j.find("cause") != j.end()) {
    j.at("cause").get_to(o.m_Cause);
    o.m_CauseIsSet = true;
  }
  if (j.find("targetScp") != j.end()) {
    j.at("targetScp").get_to(o.m_TargetScp);
    o.m_TargetScpIsSet = true;
  }
  if (j.find("targetSepp") != j.end()) {
    j.at("targetSepp").get_to(o.m_TargetSepp);
    o.m_TargetSeppIsSet = true;
  }
}

std::string RedirectResponse::getCause() const {
  return m_Cause;
}
void RedirectResponse::setCause(std::string const& value) {
  m_Cause      = value;
  m_CauseIsSet = true;
}
bool RedirectResponse::causeIsSet() const {
  return m_CauseIsSet;
}
void RedirectResponse::unsetCause() {
  m_CauseIsSet = false;
}
std::string RedirectResponse::getTargetScp() const {
  return m_TargetScp;
}
void RedirectResponse::setTargetScp(std::string const& value) {
  m_TargetScp      = value;
  m_TargetScpIsSet = true;
}
bool RedirectResponse::targetScpIsSet() const {
  return m_TargetScpIsSet;
}
void RedirectResponse::unsetTargetScp() {
  m_TargetScpIsSet = false;
}
std::string RedirectResponse::getTargetSepp() const {
  return m_TargetSepp;
}
void RedirectResponse::setTargetSepp(std::string const& value) {
  m_TargetSepp      = value;
  m_TargetSeppIsSet = true;
}
bool RedirectResponse::targetSeppIsSet() const {
  return m_TargetSeppIsSet;
}
void RedirectResponse::unsetTargetSepp() {
  m_TargetSeppIsSet = false;
}

}  // namespace ngkore::model::common
