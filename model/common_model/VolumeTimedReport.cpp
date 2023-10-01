
#include "VolumeTimedReport.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

VolumeTimedReport::VolumeTimedReport() {
  m_StartTimeStamp = "";
  m_EndTimeStamp   = "";
  m_DownlinkVolume = 0L;
  m_UplinkVolume   = 0L;
}

void VolumeTimedReport::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool VolumeTimedReport::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool VolumeTimedReport::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "VolumeTimedReport" : pathPrefix;

  return success;
}

bool VolumeTimedReport::operator==(const VolumeTimedReport& rhs) const {
  return

      (getStartTimeStamp() == rhs.getStartTimeStamp()) &&

      (getEndTimeStamp() == rhs.getEndTimeStamp()) &&

      (getDownlinkVolume() == rhs.getDownlinkVolume()) &&

      (getUplinkVolume() == rhs.getUplinkVolume())

          ;
}

bool VolumeTimedReport::operator!=(const VolumeTimedReport& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const VolumeTimedReport& o) {
  j                   = nlohmann::json();
  j["startTimeStamp"] = o.m_StartTimeStamp;
  j["endTimeStamp"]   = o.m_EndTimeStamp;
  j["downlinkVolume"] = o.m_DownlinkVolume;
  j["uplinkVolume"]   = o.m_UplinkVolume;
}

void from_json(const nlohmann::json& j, VolumeTimedReport& o) {
  j.at("startTimeStamp").get_to(o.m_StartTimeStamp);
  j.at("endTimeStamp").get_to(o.m_EndTimeStamp);
  j.at("downlinkVolume").get_to(o.m_DownlinkVolume);
  j.at("uplinkVolume").get_to(o.m_UplinkVolume);
}

std::string VolumeTimedReport::getStartTimeStamp() const {
  return m_StartTimeStamp;
}
void VolumeTimedReport::setStartTimeStamp(std::string const& value) {
  m_StartTimeStamp = value;
}
std::string VolumeTimedReport::getEndTimeStamp() const {
  return m_EndTimeStamp;
}
void VolumeTimedReport::setEndTimeStamp(std::string const& value) {
  m_EndTimeStamp = value;
}
int64_t VolumeTimedReport::getDownlinkVolume() const {
  return m_DownlinkVolume;
}
void VolumeTimedReport::setDownlinkVolume(int64_t const value) {
  m_DownlinkVolume = value;
}
int64_t VolumeTimedReport::getUplinkVolume() const {
  return m_UplinkVolume;
}
void VolumeTimedReport::setUplinkVolume(int64_t const value) {
  m_UplinkVolume = value;
}

}  // namespace ngkore::model::common
