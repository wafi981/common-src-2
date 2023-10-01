
#include "UtraLocation.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

UtraLocation::UtraLocation() {
  m_CgiIsSet                      = false;
  m_SaiIsSet                      = false;
  m_LaiIsSet                      = false;
  m_RaiIsSet                      = false;
  m_AgeOfLocationInformation      = 0;
  m_AgeOfLocationInformationIsSet = false;
  m_UeLocationTimestamp           = "";
  m_UeLocationTimestampIsSet      = false;
  m_GeographicalInformation       = "";
  m_GeographicalInformationIsSet  = false;
  m_GeodeticInformation           = "";
  m_GeodeticInformationIsSet      = false;
}

void UtraLocation::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool UtraLocation::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool UtraLocation::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "UtraLocation" : pathPrefix;

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
  return success;
}

bool UtraLocation::operator==(const UtraLocation& rhs) const {
  return

      ((!cgiIsSet() && !rhs.cgiIsSet()) ||
       (cgiIsSet() && rhs.cgiIsSet() && getCgi() == rhs.getCgi())) &&

      ((!saiIsSet() && !rhs.saiIsSet()) ||
       (saiIsSet() && rhs.saiIsSet() && getSai() == rhs.getSai())) &&

      ((!laiIsSet() && !rhs.laiIsSet()) ||
       (laiIsSet() && rhs.laiIsSet() && getLai() == rhs.getLai())) &&

      ((!raiIsSet() && !rhs.raiIsSet()) ||
       (raiIsSet() && rhs.raiIsSet() && getRai() == rhs.getRai())) &&

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
        getGeodeticInformation() == rhs.getGeodeticInformation()))

          ;
}

bool UtraLocation::operator!=(const UtraLocation& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const UtraLocation& o) {
  j = nlohmann::json();
  if (o.cgiIsSet()) j["cgi"] = o.m_Cgi;
  if (o.saiIsSet()) j["sai"] = o.m_Sai;
  if (o.laiIsSet()) j["lai"] = o.m_Lai;
  if (o.raiIsSet()) j["rai"] = o.m_Rai;
  if (o.ageOfLocationInformationIsSet())
    j["ageOfLocationInformation"] = o.m_AgeOfLocationInformation;
  if (o.ueLocationTimestampIsSet())
    j["ueLocationTimestamp"] = o.m_UeLocationTimestamp;
  if (o.geographicalInformationIsSet())
    j["geographicalInformation"] = o.m_GeographicalInformation;
  if (o.geodeticInformationIsSet())
    j["geodeticInformation"] = o.m_GeodeticInformation;
}

void from_json(const nlohmann::json& j, UtraLocation& o) {
  if (j.find("cgi") != j.end()) {
    j.at("cgi").get_to(o.m_Cgi);
    o.m_CgiIsSet = true;
  }
  if (j.find("sai") != j.end()) {
    j.at("sai").get_to(o.m_Sai);
    o.m_SaiIsSet = true;
  }
  if (j.find("lai") != j.end()) {
    j.at("lai").get_to(o.m_Lai);
    o.m_LaiIsSet = true;
  }
  if (j.find("rai") != j.end()) {
    j.at("rai").get_to(o.m_Rai);
    o.m_RaiIsSet = true;
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
}

ngkore::model::common::CellGlobalId UtraLocation::getCgi() const {
  return m_Cgi;
}
void UtraLocation::setCgi(ngkore::model::common::CellGlobalId const& value) {
  m_Cgi      = value;
  m_CgiIsSet = true;
}
bool UtraLocation::cgiIsSet() const {
  return m_CgiIsSet;
}
void UtraLocation::unsetCgi() {
  m_CgiIsSet = false;
}
ngkore::model::common::ServiceAreaId UtraLocation::getSai() const {
  return m_Sai;
}
void UtraLocation::setSai(ngkore::model::common::ServiceAreaId const& value) {
  m_Sai      = value;
  m_SaiIsSet = true;
}
bool UtraLocation::saiIsSet() const {
  return m_SaiIsSet;
}
void UtraLocation::unsetSai() {
  m_SaiIsSet = false;
}
ngkore::model::common::LocationAreaId UtraLocation::getLai() const {
  return m_Lai;
}
void UtraLocation::setLai(ngkore::model::common::LocationAreaId const& value) {
  m_Lai      = value;
  m_LaiIsSet = true;
}
bool UtraLocation::laiIsSet() const {
  return m_LaiIsSet;
}
void UtraLocation::unsetLai() {
  m_LaiIsSet = false;
}
ngkore::model::common::RoutingAreaId UtraLocation::getRai() const {
  return m_Rai;
}
void UtraLocation::setRai(ngkore::model::common::RoutingAreaId const& value) {
  m_Rai      = value;
  m_RaiIsSet = true;
}
bool UtraLocation::raiIsSet() const {
  return m_RaiIsSet;
}
void UtraLocation::unsetRai() {
  m_RaiIsSet = false;
}
int32_t UtraLocation::getAgeOfLocationInformation() const {
  return m_AgeOfLocationInformation;
}
void UtraLocation::setAgeOfLocationInformation(int32_t const value) {
  m_AgeOfLocationInformation      = value;
  m_AgeOfLocationInformationIsSet = true;
}
bool UtraLocation::ageOfLocationInformationIsSet() const {
  return m_AgeOfLocationInformationIsSet;
}
void UtraLocation::unsetAgeOfLocationInformation() {
  m_AgeOfLocationInformationIsSet = false;
}
std::string UtraLocation::getUeLocationTimestamp() const {
  return m_UeLocationTimestamp;
}
void UtraLocation::setUeLocationTimestamp(std::string const& value) {
  m_UeLocationTimestamp      = value;
  m_UeLocationTimestampIsSet = true;
}
bool UtraLocation::ueLocationTimestampIsSet() const {
  return m_UeLocationTimestampIsSet;
}
void UtraLocation::unsetUeLocationTimestamp() {
  m_UeLocationTimestampIsSet = false;
}
std::string UtraLocation::getGeographicalInformation() const {
  return m_GeographicalInformation;
}
void UtraLocation::setGeographicalInformation(std::string const& value) {
  m_GeographicalInformation      = value;
  m_GeographicalInformationIsSet = true;
}
bool UtraLocation::geographicalInformationIsSet() const {
  return m_GeographicalInformationIsSet;
}
void UtraLocation::unsetGeographicalInformation() {
  m_GeographicalInformationIsSet = false;
}
std::string UtraLocation::getGeodeticInformation() const {
  return m_GeodeticInformation;
}
void UtraLocation::setGeodeticInformation(std::string const& value) {
  m_GeodeticInformation      = value;
  m_GeodeticInformationIsSet = true;
}
bool UtraLocation::geodeticInformationIsSet() const {
  return m_GeodeticInformationIsSet;
}
void UtraLocation::unsetGeodeticInformation() {
  m_GeodeticInformationIsSet = false;
}

}  // namespace ngkore::model::common
