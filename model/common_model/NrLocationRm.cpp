
#include "NrLocationRm.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

NrLocationRm::NrLocationRm() {
  m_IgnoreNcgi                    = false;
  m_IgnoreNcgiIsSet               = false;
  m_AgeOfLocationInformation      = 0;
  m_AgeOfLocationInformationIsSet = false;
  m_UeLocationTimestamp           = "";
  m_UeLocationTimestampIsSet      = false;
  m_GeographicalInformation       = "";
  m_GeographicalInformationIsSet  = false;
  m_GeodeticInformation           = "";
  m_GeodeticInformationIsSet      = false;
  m_GlobalGnbIdIsSet              = false;
}

void NrLocationRm::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool NrLocationRm::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool NrLocationRm::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "NrLocationRm" : pathPrefix;

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

bool NrLocationRm::operator==(const NrLocationRm& rhs) const {
  return

      (getTai() == rhs.getTai()) &&

      (getNcgi() == rhs.getNcgi()) &&

      ((!ignoreNcgiIsSet() && !rhs.ignoreNcgiIsSet()) ||
       (ignoreNcgiIsSet() && rhs.ignoreNcgiIsSet() &&
        isIgnoreNcgi() == rhs.isIgnoreNcgi())) &&

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

      ((!globalGnbIdIsSet() && !rhs.globalGnbIdIsSet()) ||
       (globalGnbIdIsSet() && rhs.globalGnbIdIsSet() &&
        getGlobalGnbId() == rhs.getGlobalGnbId()))

          ;
}

bool NrLocationRm::operator!=(const NrLocationRm& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const NrLocationRm& o) {
  j         = nlohmann::json();
  j["tai"]  = o.m_Tai;
  j["ncgi"] = o.m_Ncgi;
  if (o.ignoreNcgiIsSet()) j["ignoreNcgi"] = o.m_IgnoreNcgi;
  if (o.ageOfLocationInformationIsSet())
    j["ageOfLocationInformation"] = o.m_AgeOfLocationInformation;
  if (o.ueLocationTimestampIsSet())
    j["ueLocationTimestamp"] = o.m_UeLocationTimestamp;
  if (o.geographicalInformationIsSet())
    j["geographicalInformation"] = o.m_GeographicalInformation;
  if (o.geodeticInformationIsSet())
    j["geodeticInformation"] = o.m_GeodeticInformation;
  if (o.globalGnbIdIsSet()) j["globalGnbId"] = o.m_GlobalGnbId;
}

void from_json(const nlohmann::json& j, NrLocationRm& o) {
  j.at("tai").get_to(o.m_Tai);
  j.at("ncgi").get_to(o.m_Ncgi);
  if (j.find("ignoreNcgi") != j.end()) {
    j.at("ignoreNcgi").get_to(o.m_IgnoreNcgi);
    o.m_IgnoreNcgiIsSet = true;
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
  if (j.find("globalGnbId") != j.end()) {
    j.at("globalGnbId").get_to(o.m_GlobalGnbId);
    o.m_GlobalGnbIdIsSet = true;
  }
}

ngkore::model::common::Tai NrLocationRm::getTai() const {
  return m_Tai;
}
void NrLocationRm::setTai(ngkore::model::common::Tai const& value) {
  m_Tai = value;
}
ngkore::model::common::Ncgi NrLocationRm::getNcgi() const {
  return m_Ncgi;
}
void NrLocationRm::setNcgi(ngkore::model::common::Ncgi const& value) {
  m_Ncgi = value;
}
bool NrLocationRm::isIgnoreNcgi() const {
  return m_IgnoreNcgi;
}
void NrLocationRm::setIgnoreNcgi(bool const value) {
  m_IgnoreNcgi      = value;
  m_IgnoreNcgiIsSet = true;
}
bool NrLocationRm::ignoreNcgiIsSet() const {
  return m_IgnoreNcgiIsSet;
}
void NrLocationRm::unsetIgnoreNcgi() {
  m_IgnoreNcgiIsSet = false;
}
int32_t NrLocationRm::getAgeOfLocationInformation() const {
  return m_AgeOfLocationInformation;
}
void NrLocationRm::setAgeOfLocationInformation(int32_t const value) {
  m_AgeOfLocationInformation      = value;
  m_AgeOfLocationInformationIsSet = true;
}
bool NrLocationRm::ageOfLocationInformationIsSet() const {
  return m_AgeOfLocationInformationIsSet;
}
void NrLocationRm::unsetAgeOfLocationInformation() {
  m_AgeOfLocationInformationIsSet = false;
}
std::string NrLocationRm::getUeLocationTimestamp() const {
  return m_UeLocationTimestamp;
}
void NrLocationRm::setUeLocationTimestamp(std::string const& value) {
  m_UeLocationTimestamp      = value;
  m_UeLocationTimestampIsSet = true;
}
bool NrLocationRm::ueLocationTimestampIsSet() const {
  return m_UeLocationTimestampIsSet;
}
void NrLocationRm::unsetUeLocationTimestamp() {
  m_UeLocationTimestampIsSet = false;
}
std::string NrLocationRm::getGeographicalInformation() const {
  return m_GeographicalInformation;
}
void NrLocationRm::setGeographicalInformation(std::string const& value) {
  m_GeographicalInformation      = value;
  m_GeographicalInformationIsSet = true;
}
bool NrLocationRm::geographicalInformationIsSet() const {
  return m_GeographicalInformationIsSet;
}
void NrLocationRm::unsetGeographicalInformation() {
  m_GeographicalInformationIsSet = false;
}
std::string NrLocationRm::getGeodeticInformation() const {
  return m_GeodeticInformation;
}
void NrLocationRm::setGeodeticInformation(std::string const& value) {
  m_GeodeticInformation      = value;
  m_GeodeticInformationIsSet = true;
}
bool NrLocationRm::geodeticInformationIsSet() const {
  return m_GeodeticInformationIsSet;
}
void NrLocationRm::unsetGeodeticInformation() {
  m_GeodeticInformationIsSet = false;
}
ngkore::model::common::GlobalRanNodeId NrLocationRm::getGlobalGnbId() const {
  return m_GlobalGnbId;
}
void NrLocationRm::setGlobalGnbId(
    ngkore::model::common::GlobalRanNodeId const& value) {
  m_GlobalGnbId      = value;
  m_GlobalGnbIdIsSet = true;
}
bool NrLocationRm::globalGnbIdIsSet() const {
  return m_GlobalGnbIdIsSet;
}
void NrLocationRm::unsetGlobalGnbId() {
  m_GlobalGnbIdIsSet = false;
}

}  // namespace ngkore::model::common
