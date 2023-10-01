
#include "PresenceInfoRm.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

PresenceInfoRm::PresenceInfoRm() {
  m_PraId                    = "";
  m_PraIdIsSet               = false;
  m_AdditionalPraId          = "";
  m_AdditionalPraIdIsSet     = false;
  m_PresenceStateIsSet       = false;
  m_TrackingAreaListIsSet    = false;
  m_EcgiListIsSet            = false;
  m_NcgiListIsSet            = false;
  m_GlobalRanNodeIdListIsSet = false;
  m_GlobaleNbIdListIsSet     = false;
}

void PresenceInfoRm::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool PresenceInfoRm::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool PresenceInfoRm::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "PresenceInfoRm" : pathPrefix;

  if (trackingAreaListIsSet()) {
    const std::vector<ngkore::model::common::Tai>& value = m_TrackingAreaList;
    const std::string currentValuePath = _pathPrefix + ".trackingAreaList";

    {  // Recursive validation of array elements
      const std::string oldValuePath = currentValuePath;
      int i                          = 0;
      for (const ngkore::model::common::Tai& value : value) {
        const std::string currentValuePath =
            oldValuePath + "[" + std::to_string(i) + "]";

        success = value.validate(msg, currentValuePath + ".trackingAreaList") &&
                  success;

        i++;
      }
    }
  }

  if (ecgiListIsSet()) {
    const std::vector<ngkore::model::common::Ecgi>& value = m_EcgiList;
    const std::string currentValuePath = _pathPrefix + ".ecgiList";

    {  // Recursive validation of array elements
      const std::string oldValuePath = currentValuePath;
      int i                          = 0;
      for (const ngkore::model::common::Ecgi& value : value) {
        const std::string currentValuePath =
            oldValuePath + "[" + std::to_string(i) + "]";

        success =
            value.validate(msg, currentValuePath + ".ecgiList") && success;

        i++;
      }
    }
  }

  if (ncgiListIsSet()) {
    const std::vector<ngkore::model::common::Ncgi>& value = m_NcgiList;
    const std::string currentValuePath = _pathPrefix + ".ncgiList";

    {  // Recursive validation of array elements
      const std::string oldValuePath = currentValuePath;
      int i                          = 0;
      for (const ngkore::model::common::Ncgi& value : value) {
        const std::string currentValuePath =
            oldValuePath + "[" + std::to_string(i) + "]";

        success =
            value.validate(msg, currentValuePath + ".ncgiList") && success;

        i++;
      }
    }
  }

  if (globalRanNodeIdListIsSet()) {
    const std::vector<ngkore::model::common::GlobalRanNodeId>& value =
        m_GlobalRanNodeIdList;
    const std::string currentValuePath = _pathPrefix + ".globalRanNodeIdList";

    {  // Recursive validation of array elements
      const std::string oldValuePath = currentValuePath;
      int i                          = 0;
      for (const ngkore::model::common::GlobalRanNodeId& value : value) {
        const std::string currentValuePath =
            oldValuePath + "[" + std::to_string(i) + "]";

        success =
            value.validate(msg, currentValuePath + ".globalRanNodeIdList") &&
            success;

        i++;
      }
    }
  }

  if (globaleNbIdListIsSet()) {
    const std::vector<ngkore::model::common::GlobalRanNodeId>& value =
        m_GlobaleNbIdList;
    const std::string currentValuePath = _pathPrefix + ".globaleNbIdList";

    if (value.size() < 1) {
      success = false;
      msg << currentValuePath << ": must have at least 1 elements;";
    }
    {  // Recursive validation of array elements
      const std::string oldValuePath = currentValuePath;
      int i                          = 0;
      for (const ngkore::model::common::GlobalRanNodeId& value : value) {
        const std::string currentValuePath =
            oldValuePath + "[" + std::to_string(i) + "]";

        success = value.validate(msg, currentValuePath + ".globaleNbIdList") &&
                  success;

        i++;
      }
    }
  }

  return success;
}

bool PresenceInfoRm::operator==(const PresenceInfoRm& rhs) const {
  return

      ((!praIdIsSet() && !rhs.praIdIsSet()) ||
       (praIdIsSet() && rhs.praIdIsSet() && getPraId() == rhs.getPraId())) &&

      ((!additionalPraIdIsSet() && !rhs.additionalPraIdIsSet()) ||
       (additionalPraIdIsSet() && rhs.additionalPraIdIsSet() &&
        getAdditionalPraId() == rhs.getAdditionalPraId())) &&

      ((!presenceStateIsSet() && !rhs.presenceStateIsSet()) ||
       (presenceStateIsSet() && rhs.presenceStateIsSet() &&
        getPresenceState() == rhs.getPresenceState())) &&

      ((!trackingAreaListIsSet() && !rhs.trackingAreaListIsSet()) ||
       (trackingAreaListIsSet() && rhs.trackingAreaListIsSet() &&
        getTrackingAreaList() == rhs.getTrackingAreaList())) &&

      ((!ecgiListIsSet() && !rhs.ecgiListIsSet()) ||
       (ecgiListIsSet() && rhs.ecgiListIsSet() &&
        getEcgiList() == rhs.getEcgiList())) &&

      ((!ncgiListIsSet() && !rhs.ncgiListIsSet()) ||
       (ncgiListIsSet() && rhs.ncgiListIsSet() &&
        getNcgiList() == rhs.getNcgiList())) &&

      ((!globalRanNodeIdListIsSet() && !rhs.globalRanNodeIdListIsSet()) ||
       (globalRanNodeIdListIsSet() && rhs.globalRanNodeIdListIsSet() &&
        getGlobalRanNodeIdList() == rhs.getGlobalRanNodeIdList())) &&

      ((!globaleNbIdListIsSet() && !rhs.globaleNbIdListIsSet()) ||
       (globaleNbIdListIsSet() && rhs.globaleNbIdListIsSet() &&
        getGlobaleNbIdList() == rhs.getGlobaleNbIdList()))

          ;
}

bool PresenceInfoRm::operator!=(const PresenceInfoRm& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const PresenceInfoRm& o) {
  j = nlohmann::json();
  if (o.praIdIsSet()) j["praId"] = o.m_PraId;
  if (o.additionalPraIdIsSet()) j["additionalPraId"] = o.m_AdditionalPraId;
  if (o.presenceStateIsSet()) j["presenceState"] = o.m_PresenceState;
  if (o.trackingAreaListIsSet() || !o.m_TrackingAreaList.empty())
    j["trackingAreaList"] = o.m_TrackingAreaList;
  if (o.ecgiListIsSet() || !o.m_EcgiList.empty()) j["ecgiList"] = o.m_EcgiList;
  if (o.ncgiListIsSet() || !o.m_NcgiList.empty()) j["ncgiList"] = o.m_NcgiList;
  if (o.globalRanNodeIdListIsSet() || !o.m_GlobalRanNodeIdList.empty())
    j["globalRanNodeIdList"] = o.m_GlobalRanNodeIdList;
  if (o.globaleNbIdListIsSet() || !o.m_GlobaleNbIdList.empty())
    j["globaleNbIdList"] = o.m_GlobaleNbIdList;
}

void from_json(const nlohmann::json& j, PresenceInfoRm& o) {
  if (j.find("praId") != j.end()) {
    j.at("praId").get_to(o.m_PraId);
    o.m_PraIdIsSet = true;
  }
  if (j.find("additionalPraId") != j.end()) {
    j.at("additionalPraId").get_to(o.m_AdditionalPraId);
    o.m_AdditionalPraIdIsSet = true;
  }
  if (j.find("presenceState") != j.end()) {
    j.at("presenceState").get_to(o.m_PresenceState);
    o.m_PresenceStateIsSet = true;
  }
  if (j.find("trackingAreaList") != j.end()) {
    j.at("trackingAreaList").get_to(o.m_TrackingAreaList);
    o.m_TrackingAreaListIsSet = true;
  }
  if (j.find("ecgiList") != j.end()) {
    j.at("ecgiList").get_to(o.m_EcgiList);
    o.m_EcgiListIsSet = true;
  }
  if (j.find("ncgiList") != j.end()) {
    j.at("ncgiList").get_to(o.m_NcgiList);
    o.m_NcgiListIsSet = true;
  }
  if (j.find("globalRanNodeIdList") != j.end()) {
    j.at("globalRanNodeIdList").get_to(o.m_GlobalRanNodeIdList);
    o.m_GlobalRanNodeIdListIsSet = true;
  }
  if (j.find("globaleNbIdList") != j.end()) {
    j.at("globaleNbIdList").get_to(o.m_GlobaleNbIdList);
    o.m_GlobaleNbIdListIsSet = true;
  }
}

std::string PresenceInfoRm::getPraId() const {
  return m_PraId;
}
void PresenceInfoRm::setPraId(std::string const& value) {
  m_PraId      = value;
  m_PraIdIsSet = true;
}
bool PresenceInfoRm::praIdIsSet() const {
  return m_PraIdIsSet;
}
void PresenceInfoRm::unsetPraId() {
  m_PraIdIsSet = false;
}
std::string PresenceInfoRm::getAdditionalPraId() const {
  return m_AdditionalPraId;
}
void PresenceInfoRm::setAdditionalPraId(std::string const& value) {
  m_AdditionalPraId      = value;
  m_AdditionalPraIdIsSet = true;
}
bool PresenceInfoRm::additionalPraIdIsSet() const {
  return m_AdditionalPraIdIsSet;
}
void PresenceInfoRm::unsetAdditionalPraId() {
  m_AdditionalPraIdIsSet = false;
}
ngkore::model::common::PresenceState PresenceInfoRm::getPresenceState() const {
  return m_PresenceState;
}
void PresenceInfoRm::setPresenceState(
    ngkore::model::common::PresenceState const& value) {
  m_PresenceState      = value;
  m_PresenceStateIsSet = true;
}
bool PresenceInfoRm::presenceStateIsSet() const {
  return m_PresenceStateIsSet;
}
void PresenceInfoRm::unsetPresenceState() {
  m_PresenceStateIsSet = false;
}
std::vector<ngkore::model::common::Tai> PresenceInfoRm::getTrackingAreaList()
    const {
  return m_TrackingAreaList;
}
void PresenceInfoRm::setTrackingAreaList(
    std::vector<ngkore::model::common::Tai> const& value) {
  m_TrackingAreaList      = value;
  m_TrackingAreaListIsSet = true;
}
bool PresenceInfoRm::trackingAreaListIsSet() const {
  return m_TrackingAreaListIsSet;
}
void PresenceInfoRm::unsetTrackingAreaList() {
  m_TrackingAreaListIsSet = false;
}
std::vector<ngkore::model::common::Ecgi> PresenceInfoRm::getEcgiList() const {
  return m_EcgiList;
}
void PresenceInfoRm::setEcgiList(
    std::vector<ngkore::model::common::Ecgi> const& value) {
  m_EcgiList      = value;
  m_EcgiListIsSet = true;
}
bool PresenceInfoRm::ecgiListIsSet() const {
  return m_EcgiListIsSet;
}
void PresenceInfoRm::unsetEcgiList() {
  m_EcgiListIsSet = false;
}
std::vector<ngkore::model::common::Ncgi> PresenceInfoRm::getNcgiList() const {
  return m_NcgiList;
}
void PresenceInfoRm::setNcgiList(
    std::vector<ngkore::model::common::Ncgi> const& value) {
  m_NcgiList      = value;
  m_NcgiListIsSet = true;
}
bool PresenceInfoRm::ncgiListIsSet() const {
  return m_NcgiListIsSet;
}
void PresenceInfoRm::unsetNcgiList() {
  m_NcgiListIsSet = false;
}
std::vector<ngkore::model::common::GlobalRanNodeId>
PresenceInfoRm::getGlobalRanNodeIdList() const {
  return m_GlobalRanNodeIdList;
}
void PresenceInfoRm::setGlobalRanNodeIdList(
    std::vector<ngkore::model::common::GlobalRanNodeId> const& value) {
  m_GlobalRanNodeIdList      = value;
  m_GlobalRanNodeIdListIsSet = true;
}
bool PresenceInfoRm::globalRanNodeIdListIsSet() const {
  return m_GlobalRanNodeIdListIsSet;
}
void PresenceInfoRm::unsetGlobalRanNodeIdList() {
  m_GlobalRanNodeIdListIsSet = false;
}
std::vector<ngkore::model::common::GlobalRanNodeId>
PresenceInfoRm::getGlobaleNbIdList() const {
  return m_GlobaleNbIdList;
}
void PresenceInfoRm::setGlobaleNbIdList(
    std::vector<ngkore::model::common::GlobalRanNodeId> const& value) {
  m_GlobaleNbIdList      = value;
  m_GlobaleNbIdListIsSet = true;
}
bool PresenceInfoRm::globaleNbIdListIsSet() const {
  return m_GlobaleNbIdListIsSet;
}
void PresenceInfoRm::unsetGlobaleNbIdList() {
  m_GlobaleNbIdListIsSet = false;
}

}  // namespace ngkore::model::common
