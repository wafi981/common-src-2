
#include "SmallDataRateStatus.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

SmallDataRateStatus::SmallDataRateStatus() {
  m_RemainPacketsUl        = 0;
  m_RemainPacketsUlIsSet   = false;
  m_RemainPacketsDl        = 0;
  m_RemainPacketsDlIsSet   = false;
  m_ValidityTime           = "";
  m_ValidityTimeIsSet      = false;
  m_RemainExReportsUl      = 0;
  m_RemainExReportsUlIsSet = false;
  m_RemainExReportsDl      = 0;
  m_RemainExReportsDlIsSet = false;
}

void SmallDataRateStatus::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool SmallDataRateStatus::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool SmallDataRateStatus::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "SmallDataRateStatus" : pathPrefix;

  if (remainPacketsUlIsSet()) {
    const int32_t& value               = m_RemainPacketsUl;
    const std::string currentValuePath = _pathPrefix + ".remainPacketsUl";

    if (value < 0) {
      success = false;
      msg << currentValuePath << ": must be greater than or equal to 0;";
    }
  }

  if (remainPacketsDlIsSet()) {
    const int32_t& value               = m_RemainPacketsDl;
    const std::string currentValuePath = _pathPrefix + ".remainPacketsDl";

    if (value < 0) {
      success = false;
      msg << currentValuePath << ": must be greater than or equal to 0;";
    }
  }

  if (remainExReportsUlIsSet()) {
    const int32_t& value               = m_RemainExReportsUl;
    const std::string currentValuePath = _pathPrefix + ".remainExReportsUl";

    if (value < 0) {
      success = false;
      msg << currentValuePath << ": must be greater than or equal to 0;";
    }
  }

  if (remainExReportsDlIsSet()) {
    const int32_t& value               = m_RemainExReportsDl;
    const std::string currentValuePath = _pathPrefix + ".remainExReportsDl";

    if (value < 0) {
      success = false;
      msg << currentValuePath << ": must be greater than or equal to 0;";
    }
  }

  return success;
}

bool SmallDataRateStatus::operator==(const SmallDataRateStatus& rhs) const {
  return

      ((!remainPacketsUlIsSet() && !rhs.remainPacketsUlIsSet()) ||
       (remainPacketsUlIsSet() && rhs.remainPacketsUlIsSet() &&
        getRemainPacketsUl() == rhs.getRemainPacketsUl())) &&

      ((!remainPacketsDlIsSet() && !rhs.remainPacketsDlIsSet()) ||
       (remainPacketsDlIsSet() && rhs.remainPacketsDlIsSet() &&
        getRemainPacketsDl() == rhs.getRemainPacketsDl())) &&

      ((!validityTimeIsSet() && !rhs.validityTimeIsSet()) ||
       (validityTimeIsSet() && rhs.validityTimeIsSet() &&
        getValidityTime() == rhs.getValidityTime())) &&

      ((!remainExReportsUlIsSet() && !rhs.remainExReportsUlIsSet()) ||
       (remainExReportsUlIsSet() && rhs.remainExReportsUlIsSet() &&
        getRemainExReportsUl() == rhs.getRemainExReportsUl())) &&

      ((!remainExReportsDlIsSet() && !rhs.remainExReportsDlIsSet()) ||
       (remainExReportsDlIsSet() && rhs.remainExReportsDlIsSet() &&
        getRemainExReportsDl() == rhs.getRemainExReportsDl()))

          ;
}

bool SmallDataRateStatus::operator!=(const SmallDataRateStatus& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const SmallDataRateStatus& o) {
  j = nlohmann::json();
  if (o.remainPacketsUlIsSet()) j["remainPacketsUl"] = o.m_RemainPacketsUl;
  if (o.remainPacketsDlIsSet()) j["remainPacketsDl"] = o.m_RemainPacketsDl;
  if (o.validityTimeIsSet()) j["validityTime"] = o.m_ValidityTime;
  if (o.remainExReportsUlIsSet())
    j["remainExReportsUl"] = o.m_RemainExReportsUl;
  if (o.remainExReportsDlIsSet())
    j["remainExReportsDl"] = o.m_RemainExReportsDl;
}

void from_json(const nlohmann::json& j, SmallDataRateStatus& o) {
  if (j.find("remainPacketsUl") != j.end()) {
    j.at("remainPacketsUl").get_to(o.m_RemainPacketsUl);
    o.m_RemainPacketsUlIsSet = true;
  }
  if (j.find("remainPacketsDl") != j.end()) {
    j.at("remainPacketsDl").get_to(o.m_RemainPacketsDl);
    o.m_RemainPacketsDlIsSet = true;
  }
  if (j.find("validityTime") != j.end()) {
    j.at("validityTime").get_to(o.m_ValidityTime);
    o.m_ValidityTimeIsSet = true;
  }
  if (j.find("remainExReportsUl") != j.end()) {
    j.at("remainExReportsUl").get_to(o.m_RemainExReportsUl);
    o.m_RemainExReportsUlIsSet = true;
  }
  if (j.find("remainExReportsDl") != j.end()) {
    j.at("remainExReportsDl").get_to(o.m_RemainExReportsDl);
    o.m_RemainExReportsDlIsSet = true;
  }
}

int32_t SmallDataRateStatus::getRemainPacketsUl() const {
  return m_RemainPacketsUl;
}
void SmallDataRateStatus::setRemainPacketsUl(int32_t const value) {
  m_RemainPacketsUl      = value;
  m_RemainPacketsUlIsSet = true;
}
bool SmallDataRateStatus::remainPacketsUlIsSet() const {
  return m_RemainPacketsUlIsSet;
}
void SmallDataRateStatus::unsetRemainPacketsUl() {
  m_RemainPacketsUlIsSet = false;
}
int32_t SmallDataRateStatus::getRemainPacketsDl() const {
  return m_RemainPacketsDl;
}
void SmallDataRateStatus::setRemainPacketsDl(int32_t const value) {
  m_RemainPacketsDl      = value;
  m_RemainPacketsDlIsSet = true;
}
bool SmallDataRateStatus::remainPacketsDlIsSet() const {
  return m_RemainPacketsDlIsSet;
}
void SmallDataRateStatus::unsetRemainPacketsDl() {
  m_RemainPacketsDlIsSet = false;
}
std::string SmallDataRateStatus::getValidityTime() const {
  return m_ValidityTime;
}
void SmallDataRateStatus::setValidityTime(std::string const& value) {
  m_ValidityTime      = value;
  m_ValidityTimeIsSet = true;
}
bool SmallDataRateStatus::validityTimeIsSet() const {
  return m_ValidityTimeIsSet;
}
void SmallDataRateStatus::unsetValidityTime() {
  m_ValidityTimeIsSet = false;
}
int32_t SmallDataRateStatus::getRemainExReportsUl() const {
  return m_RemainExReportsUl;
}
void SmallDataRateStatus::setRemainExReportsUl(int32_t const value) {
  m_RemainExReportsUl      = value;
  m_RemainExReportsUlIsSet = true;
}
bool SmallDataRateStatus::remainExReportsUlIsSet() const {
  return m_RemainExReportsUlIsSet;
}
void SmallDataRateStatus::unsetRemainExReportsUl() {
  m_RemainExReportsUlIsSet = false;
}
int32_t SmallDataRateStatus::getRemainExReportsDl() const {
  return m_RemainExReportsDl;
}
void SmallDataRateStatus::setRemainExReportsDl(int32_t const value) {
  m_RemainExReportsDl      = value;
  m_RemainExReportsDlIsSet = true;
}
bool SmallDataRateStatus::remainExReportsDlIsSet() const {
  return m_RemainExReportsDlIsSet;
}
void SmallDataRateStatus::unsetRemainExReportsDl() {
  m_RemainExReportsDlIsSet = false;
}

}  // namespace ngkore::model::common
