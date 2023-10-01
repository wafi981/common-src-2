
#include "EutraLocationRm.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

EutraLocationRm::EutraLocationRm() {
  m_IgnoreTai                     = false;
  m_IgnoreTaiIsSet                = false;
  m_IgnoreEcgi                    = false;
  m_IgnoreEcgiIsSet               = false;
  m_AgeOfLocationInformation      = 0;
  m_AgeOfLocationInformationIsSet = false;
  m_UeLocationTimestamp           = "";
  m_UeLocationTimestampIsSet      = false;
  m_GeographicalInformation       = "";
  m_GeographicalInformationIsSet  = false;
  m_GeodeticInformation           = "";
  m_GeodeticInformationIsSet      = false;
  m_GlobalNgenbIdIsSet            = false;
  m_GlobalENbIdIsSet              = false;
}

void EutraLocationRm::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool EutraLocationRm::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool EutraLocationRm::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "EutraLocationRm" : pathPrefix;

  if (ageOfLocationInformationIsSet()) {
    const int32_t& value = m_AgeOfLocationInformation;
    const std::string currentValuePath =
        _pathPrefix + ".ageOfLocationInformation";

    if (value < 0) {
      success = false;
      msg << currentValuePath << ": must be greater than or equal to 0;";
    }
    if (value > 32767) {
      success = false;
      msg << currentValuePath << ": must be less than or equal to 32767;";
    }
  }

  if (geographicalInformationIsSet()) {
    const std::string& value = m_GeographicalInformation;
    const std::string currentValuePath =
        _pathPrefix + ".geographicalInformation";
  }

  if (geodeticInformationIsSet()) {
    const std::string& value           = m_GeodeticInformation;
    const std::string currentValuePath = _pathPrefix + ".geodeticInformation";
  }

  return success;
}

bool EutraLocationRm::operator==(const EutraLocationRm& rhs) const {
  return

      (getTai() == rhs.getTai()) &&

      ((!ignoreTaiIsSet() && !rhs.ignoreTaiIsSet()) ||
       (ignoreTaiIsSet() && rhs.ignoreTaiIsSet() &&
        isIgnoreTai() == rhs.isIgnoreTai())) &&

      (getEcgi() == rhs.getEcgi()) &&

      ((!ignoreEcgiIsSet() && !rhs.ignoreEcgiIsSet()) ||
       (ignoreEcgiIsSet() && rhs.ignoreEcgiIsSet() &&
        isIgnoreEcgi() == rhs.isIgnoreEcgi())) &&

      ((!ageOfLocationInformationIsSet() &&
        !rhs.ageOfLocationInformationIsSet()) ||
       (ageOfLocationInformationIsSet() &&
        rhs.ageOfLocationInformationIsSet() &&
        getAgeOfLocationInformation() == rhs.getAgeOfLocationInformation())) &&

      ((!ueLocationTimestampIsSet() && !rhs.ueLocationTimestampIsSet()) ||
       (ueLocationTimestampIsSet() && rhs.ueLocationTimestampIsSet() &&
        getUeLocationTimestamp() == rhs.getUeLocationTimestamp())) &&

      ((!geographicalInformationIsSet() &&
        !rhs.geographicalInformationIsSet()) ||
       (geographicalInformationIsSet() && rhs.geographicalInformationIsSet() &&
        getGeographicalInformation() == rhs.getGeographicalInformation())) &&

      ((!geodeticInformationIsSet() && !rhs.geodeticInformationIsSet()) ||
       (geodeticInformationIsSet() && rhs.geodeticInformationIsSet() &&
        getGeodeticInformation() == rhs.getGeodeticInformation())) &&

      ((!globalNgenbIdIsSet() && !rhs.globalNgenbIdIsSet()) ||
       (globalNgenbIdIsSet() && rhs.globalNgenbIdIsSet() &&
        getGlobalNgenbId() == rhs.getGlobalNgenbId())) &&

      ((!globalENbIdIsSet() && !rhs.globalENbIdIsSet()) ||
       (globalENbIdIsSet() && rhs.globalENbIdIsSet() &&
        getGlobalENbId() == rhs.getGlobalENbId()))

          ;
}

bool EutraLocationRm::operator!=(const EutraLocationRm& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const EutraLocationRm& o) {
  j        = nlohmann::json();
  j["tai"] = o.m_Tai;
  if (o.ignoreTaiIsSet()) j["ignoreTai"] = o.m_IgnoreTai;
  j["ecgi"] = o.m_Ecgi;
  if (o.ignoreEcgiIsSet()) j["ignoreEcgi"] = o.m_IgnoreEcgi;
  if (o.ageOfLocationInformationIsSet())
    j["ageOfLocationInformation"] = o.m_AgeOfLocationInformation;
  if (o.ueLocationTimestampIsSet())
    j["ueLocationTimestamp"] = o.m_UeLocationTimestamp;
  if (o.geographicalInformationIsSet())
    j["geographicalInformation"] = o.m_GeographicalInformation;
  if (o.geodeticInformationIsSet())
    j["geodeticInformation"] = o.m_GeodeticInformation;
  if (o.globalNgenbIdIsSet()) j["globalNgenbId"] = o.m_GlobalNgenbId;
  if (o.globalENbIdIsSet()) j["globalENbId"] = o.m_GlobalENbId;
}

void from_json(const nlohmann::json& j, EutraLocationRm& o) {
  j.at("tai").get_to(o.m_Tai);
  if (j.find("ignoreTai") != j.end()) {
    j.at("ignoreTai").get_to(o.m_IgnoreTai);
    o.m_IgnoreTaiIsSet = true;
  }
  j.at("ecgi").get_to(o.m_Ecgi);
  if (j.find("ignoreEcgi") != j.end()) {
    j.at("ignoreEcgi").get_to(o.m_IgnoreEcgi);
    o.m_IgnoreEcgiIsSet = true;
  }
  if (j.find("ageOfLocationInformation") != j.end()) {
    j.at("ageOfLocationInformation").get_to(o.m_AgeOfLocationInformation);
    o.m_AgeOfLocationInformationIsSet = true;
  }
  if (j.find("ueLocationTimestamp") != j.end()) {
    j.at("ueLocationTimestamp").get_to(o.m_UeLocationTimestamp);
    o.m_UeLocationTimestampIsSet = true;
  }
  if (j.find("geographicalInformation") != j.end()) {
    j.at("geographicalInformation").get_to(o.m_GeographicalInformation);
    o.m_GeographicalInformationIsSet = true;
  }
  if (j.find("geodeticInformation") != j.end()) {
    j.at("geodeticInformation").get_to(o.m_GeodeticInformation);
    o.m_GeodeticInformationIsSet = true;
  }
  if (j.find("globalNgenbId") != j.end()) {
    j.at("globalNgenbId").get_to(o.m_GlobalNgenbId);
    o.m_GlobalNgenbIdIsSet = true;
  }
  if (j.find("globalENbId") != j.end()) {
    j.at("globalENbId").get_to(o.m_GlobalENbId);
    o.m_GlobalENbIdIsSet = true;
  }
}

ngkore::model::common::Tai EutraLocationRm::getTai() const {
  return m_Tai;
}
void EutraLocationRm::setTai(ngkore::model::common::Tai const& value) {
  m_Tai = value;
}
bool EutraLocationRm::isIgnoreTai() const {
  return m_IgnoreTai;
}
void EutraLocationRm::setIgnoreTai(bool const value) {
  m_IgnoreTai      = value;
  m_IgnoreTaiIsSet = true;
}
bool EutraLocationRm::ignoreTaiIsSet() const {
  return m_IgnoreTaiIsSet;
}
void EutraLocationRm::unsetIgnoreTai() {
  m_IgnoreTaiIsSet = false;
}
ngkore::model::common::Ecgi EutraLocationRm::getEcgi() const {
  return m_Ecgi;
}
void EutraLocationRm::setEcgi(ngkore::model::common::Ecgi const& value) {
  m_Ecgi = value;
}
bool EutraLocationRm::isIgnoreEcgi() const {
  return m_IgnoreEcgi;
}
void EutraLocationRm::setIgnoreEcgi(bool const value) {
  m_IgnoreEcgi      = value;
  m_IgnoreEcgiIsSet = true;
}
bool EutraLocationRm::ignoreEcgiIsSet() const {
  return m_IgnoreEcgiIsSet;
}
void EutraLocationRm::unsetIgnoreEcgi() {
  m_IgnoreEcgiIsSet = false;
}
int32_t EutraLocationRm::getAgeOfLocationInformation() const {
  return m_AgeOfLocationInformation;
}
void EutraLocationRm::setAgeOfLocationInformation(int32_t const value) {
  m_AgeOfLocationInformation      = value;
  m_AgeOfLocationInformationIsSet = true;
}
bool EutraLocationRm::ageOfLocationInformationIsSet() const {
  return m_AgeOfLocationInformationIsSet;
}
void EutraLocationRm::unsetAgeOfLocationInformation() {
  m_AgeOfLocationInformationIsSet = false;
}
std::string EutraLocationRm::getUeLocationTimestamp() const {
  return m_UeLocationTimestamp;
}
void EutraLocationRm::setUeLocationTimestamp(std::string const& value) {
  m_UeLocationTimestamp      = value;
  m_UeLocationTimestampIsSet = true;
}
bool EutraLocationRm::ueLocationTimestampIsSet() const {
  return m_UeLocationTimestampIsSet;
}
void EutraLocationRm::unsetUeLocationTimestamp() {
  m_UeLocationTimestampIsSet = false;
}
std::string EutraLocationRm::getGeographicalInformation() const {
  return m_GeographicalInformation;
}
void EutraLocationRm::setGeographicalInformation(std::string const& value) {
  m_GeographicalInformation      = value;
  m_GeographicalInformationIsSet = true;
}
bool EutraLocationRm::geographicalInformationIsSet() const {
  return m_GeographicalInformationIsSet;
}
void EutraLocationRm::unsetGeographicalInformation() {
  m_GeographicalInformationIsSet = false;
}
std::string EutraLocationRm::getGeodeticInformation() const {
  return m_GeodeticInformation;
}
void EutraLocationRm::setGeodeticInformation(std::string const& value) {
  m_GeodeticInformation      = value;
  m_GeodeticInformationIsSet = true;
}
bool EutraLocationRm::geodeticInformationIsSet() const {
  return m_GeodeticInformationIsSet;
}
void EutraLocationRm::unsetGeodeticInformation() {
  m_GeodeticInformationIsSet = false;
}
ngkore::model::common::GlobalRanNodeId EutraLocationRm::getGlobalNgenbId() const {
  return m_GlobalNgenbId;
}
void EutraLocationRm::setGlobalNgenbId(
    ngkore::model::common::GlobalRanNodeId const& value) {
  m_GlobalNgenbId      = value;
  m_GlobalNgenbIdIsSet = true;
}
bool EutraLocationRm::globalNgenbIdIsSet() const {
  return m_GlobalNgenbIdIsSet;
}
void EutraLocationRm::unsetGlobalNgenbId() {
  m_GlobalNgenbIdIsSet = false;
}
ngkore::model::common::GlobalRanNodeId EutraLocationRm::getGlobalENbId() const {
  return m_GlobalENbId;
}
void EutraLocationRm::setGlobalENbId(
    ngkore::model::common::GlobalRanNodeId const& value) {
  m_GlobalENbId      = value;
  m_GlobalENbIdIsSet = true;
}
bool EutraLocationRm::globalENbIdIsSet() const {
  return m_GlobalENbIdIsSet;
}
void EutraLocationRm::unsetGlobalENbId() {
  m_GlobalENbIdIsSet = false;
}

}  // namespace ngkore::model::common
