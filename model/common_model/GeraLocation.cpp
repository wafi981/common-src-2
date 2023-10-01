
#include "GeraLocation.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

GeraLocation::GeraLocation() {
  m_LocationNumber                = "";
  m_LocationNumberIsSet           = false;
  m_CgiIsSet                      = false;
  m_RaiIsSet                      = false;
  m_SaiIsSet                      = false;
  m_LaiIsSet                      = false;
  m_VlrNumber                     = "";
  m_VlrNumberIsSet                = false;
  m_MscNumber                     = "";
  m_MscNumberIsSet                = false;
  m_AgeOfLocationInformation      = 0;
  m_AgeOfLocationInformationIsSet = false;
  m_UeLocationTimestamp           = "";
  m_UeLocationTimestampIsSet      = false;
  m_GeographicalInformation       = "";
  m_GeographicalInformationIsSet  = false;
  m_GeodeticInformation           = "";
  m_GeodeticInformationIsSet      = false;
}

void GeraLocation::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool GeraLocation::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool GeraLocation::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "GeraLocation" : pathPrefix;

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

bool GeraLocation::operator==(const GeraLocation& rhs) const {
  return

      ((!locationNumberIsSet() && !rhs.locationNumberIsSet()) ||
       (locationNumberIsSet() && rhs.locationNumberIsSet() &&
        getLocationNumber() == rhs.getLocationNumber())) &&

      ((!cgiIsSet() && !rhs.cgiIsSet()) ||
       (cgiIsSet() && rhs.cgiIsSet() && getCgi() == rhs.getCgi())) &&

      ((!raiIsSet() && !rhs.raiIsSet()) ||
       (raiIsSet() && rhs.raiIsSet() && getRai() == rhs.getRai())) &&

      ((!saiIsSet() && !rhs.saiIsSet()) ||
       (saiIsSet() && rhs.saiIsSet() && getSai() == rhs.getSai())) &&

      ((!laiIsSet() && !rhs.laiIsSet()) ||
       (laiIsSet() && rhs.laiIsSet() && getLai() == rhs.getLai())) &&

      ((!vlrNumberIsSet() && !rhs.vlrNumberIsSet()) ||
       (vlrNumberIsSet() && rhs.vlrNumberIsSet() &&
        getVlrNumber() == rhs.getVlrNumber())) &&

      ((!mscNumberIsSet() && !rhs.mscNumberIsSet()) ||
       (mscNumberIsSet() && rhs.mscNumberIsSet() &&
        getMscNumber() == rhs.getMscNumber())) &&

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

bool GeraLocation::operator!=(const GeraLocation& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const GeraLocation& o) {
  j = nlohmann::json();
  if (o.locationNumberIsSet()) j["locationNumber"] = o.m_LocationNumber;
  if (o.cgiIsSet()) j["cgi"] = o.m_Cgi;
  if (o.raiIsSet()) j["rai"] = o.m_Rai;
  if (o.saiIsSet()) j["sai"] = o.m_Sai;
  if (o.laiIsSet()) j["lai"] = o.m_Lai;
  if (o.vlrNumberIsSet()) j["vlrNumber"] = o.m_VlrNumber;
  if (o.mscNumberIsSet()) j["mscNumber"] = o.m_MscNumber;
  if (o.ageOfLocationInformationIsSet())
    j["ageOfLocationInformation"] = o.m_AgeOfLocationInformation;
  if (o.ueLocationTimestampIsSet())
    j["ueLocationTimestamp"] = o.m_UeLocationTimestamp;
  if (o.geographicalInformationIsSet())
    j["geographicalInformation"] = o.m_GeographicalInformation;
  if (o.geodeticInformationIsSet())
    j["geodeticInformation"] = o.m_GeodeticInformation;
}

void from_json(const nlohmann::json& j, GeraLocation& o) {
  if (j.find("locationNumber") != j.end()) {
    j.at("locationNumber").get_to(o.m_LocationNumber);
    o.m_LocationNumberIsSet = true;
  }
  if (j.find("cgi") != j.end()) {
    j.at("cgi").get_to(o.m_Cgi);
    o.m_CgiIsSet = true;
  }
  if (j.find("rai") != j.end()) {
    j.at("rai").get_to(o.m_Rai);
    o.m_RaiIsSet = true;
  }
  if (j.find("sai") != j.end()) {
    j.at("sai").get_to(o.m_Sai);
    o.m_SaiIsSet = true;
  }
  if (j.find("lai") != j.end()) {
    j.at("lai").get_to(o.m_Lai);
    o.m_LaiIsSet = true;
  }
  if (j.find("vlrNumber") != j.end()) {
    j.at("vlrNumber").get_to(o.m_VlrNumber);
    o.m_VlrNumberIsSet = true;
  }
  if (j.find("mscNumber") != j.end()) {
    j.at("mscNumber").get_to(o.m_MscNumber);
    o.m_MscNumberIsSet = true;
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

std::string GeraLocation::getLocationNumber() const {
  return m_LocationNumber;
}
void GeraLocation::setLocationNumber(std::string const& value) {
  m_LocationNumber      = value;
  m_LocationNumberIsSet = true;
}
bool GeraLocation::locationNumberIsSet() const {
  return m_LocationNumberIsSet;
}
void GeraLocation::unsetLocationNumber() {
  m_LocationNumberIsSet = false;
}
ngkore::model::common::CellGlobalId GeraLocation::getCgi() const {
  return m_Cgi;
}
void GeraLocation::setCgi(ngkore::model::common::CellGlobalId const& value) {
  m_Cgi      = value;
  m_CgiIsSet = true;
}
bool GeraLocation::cgiIsSet() const {
  return m_CgiIsSet;
}
void GeraLocation::unsetCgi() {
  m_CgiIsSet = false;
}
ngkore::model::common::RoutingAreaId GeraLocation::getRai() const {
  return m_Rai;
}
void GeraLocation::setRai(ngkore::model::common::RoutingAreaId const& value) {
  m_Rai      = value;
  m_RaiIsSet = true;
}
bool GeraLocation::raiIsSet() const {
  return m_RaiIsSet;
}
void GeraLocation::unsetRai() {
  m_RaiIsSet = false;
}
ngkore::model::common::ServiceAreaId GeraLocation::getSai() const {
  return m_Sai;
}
void GeraLocation::setSai(ngkore::model::common::ServiceAreaId const& value) {
  m_Sai      = value;
  m_SaiIsSet = true;
}
bool GeraLocation::saiIsSet() const {
  return m_SaiIsSet;
}
void GeraLocation::unsetSai() {
  m_SaiIsSet = false;
}
ngkore::model::common::LocationAreaId GeraLocation::getLai() const {
  return m_Lai;
}
void GeraLocation::setLai(ngkore::model::common::LocationAreaId const& value) {
  m_Lai      = value;
  m_LaiIsSet = true;
}
bool GeraLocation::laiIsSet() const {
  return m_LaiIsSet;
}
void GeraLocation::unsetLai() {
  m_LaiIsSet = false;
}
std::string GeraLocation::getVlrNumber() const {
  return m_VlrNumber;
}
void GeraLocation::setVlrNumber(std::string const& value) {
  m_VlrNumber      = value;
  m_VlrNumberIsSet = true;
}
bool GeraLocation::vlrNumberIsSet() const {
  return m_VlrNumberIsSet;
}
void GeraLocation::unsetVlrNumber() {
  m_VlrNumberIsSet = false;
}
std::string GeraLocation::getMscNumber() const {
  return m_MscNumber;
}
void GeraLocation::setMscNumber(std::string const& value) {
  m_MscNumber      = value;
  m_MscNumberIsSet = true;
}
bool GeraLocation::mscNumberIsSet() const {
  return m_MscNumberIsSet;
}
void GeraLocation::unsetMscNumber() {
  m_MscNumberIsSet = false;
}
int32_t GeraLocation::getAgeOfLocationInformation() const {
  return m_AgeOfLocationInformation;
}
void GeraLocation::setAgeOfLocationInformation(int32_t const value) {
  m_AgeOfLocationInformation      = value;
  m_AgeOfLocationInformationIsSet = true;
}
bool GeraLocation::ageOfLocationInformationIsSet() const {
  return m_AgeOfLocationInformationIsSet;
}
void GeraLocation::unsetAgeOfLocationInformation() {
  m_AgeOfLocationInformationIsSet = false;
}
std::string GeraLocation::getUeLocationTimestamp() const {
  return m_UeLocationTimestamp;
}
void GeraLocation::setUeLocationTimestamp(std::string const& value) {
  m_UeLocationTimestamp      = value;
  m_UeLocationTimestampIsSet = true;
}
bool GeraLocation::ueLocationTimestampIsSet() const {
  return m_UeLocationTimestampIsSet;
}
void GeraLocation::unsetUeLocationTimestamp() {
  m_UeLocationTimestampIsSet = false;
}
std::string GeraLocation::getGeographicalInformation() const {
  return m_GeographicalInformation;
}
void GeraLocation::setGeographicalInformation(std::string const& value) {
  m_GeographicalInformation      = value;
  m_GeographicalInformationIsSet = true;
}
bool GeraLocation::geographicalInformationIsSet() const {
  return m_GeographicalInformationIsSet;
}
void GeraLocation::unsetGeographicalInformation() {
  m_GeographicalInformationIsSet = false;
}
std::string GeraLocation::getGeodeticInformation() const {
  return m_GeodeticInformation;
}
void GeraLocation::setGeodeticInformation(std::string const& value) {
  m_GeodeticInformation      = value;
  m_GeodeticInformationIsSet = true;
}
bool GeraLocation::geodeticInformationIsSet() const {
  return m_GeodeticInformationIsSet;
}
void GeraLocation::unsetGeodeticInformation() {
  m_GeodeticInformationIsSet = false;
}

}  // namespace ngkore::model::common
