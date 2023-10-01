
#include "SecondaryRatUsageInfo.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

SecondaryRatUsageInfo::SecondaryRatUsageInfo() {
  m_QosFlowsUsageDataIsSet   = false;
  m_PduSessionUsageDataIsSet = false;
}

void SecondaryRatUsageInfo::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool SecondaryRatUsageInfo::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool SecondaryRatUsageInfo::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "SecondaryRatUsageInfo" : pathPrefix;

  if (qosFlowsUsageDataIsSet()) {
    const std::vector<ngkore::model::common::QosFlowUsageReport>& value =
        m_QosFlowsUsageData;
    const std::string currentValuePath = _pathPrefix + ".qosFlowsUsageData";

    if (value.size() < 1) {
      success = false;
      msg << currentValuePath << ": must have at least 1 elements;";
    }
    {  // Recursive validation of array elements
      const std::string oldValuePath = currentValuePath;
      int i                          = 0;
      for (const ngkore::model::common::QosFlowUsageReport& value : value) {
        const std::string currentValuePath =
            oldValuePath + "[" + std::to_string(i) + "]";

        success =
            value.validate(msg, currentValuePath + ".qosFlowsUsageData") &&
            success;

        i++;
      }
    }
  }

  if (pduSessionUsageDataIsSet()) {
    const std::vector<ngkore::model::common::VolumeTimedReport>& value =
        m_PduSessionUsageData;
    const std::string currentValuePath = _pathPrefix + ".pduSessionUsageData";

    if (value.size() < 1) {
      success = false;
      msg << currentValuePath << ": must have at least 1 elements;";
    }
    {  // Recursive validation of array elements
      const std::string oldValuePath = currentValuePath;
      int i                          = 0;
      for (const ngkore::model::common::VolumeTimedReport& value : value) {
        const std::string currentValuePath =
            oldValuePath + "[" + std::to_string(i) + "]";

        success =
            value.validate(msg, currentValuePath + ".pduSessionUsageData") &&
            success;

        i++;
      }
    }
  }

  return success;
}

bool SecondaryRatUsageInfo::operator==(const SecondaryRatUsageInfo& rhs) const {
  return

      (getSecondaryRatType() == rhs.getSecondaryRatType()) &&

      ((!qosFlowsUsageDataIsSet() && !rhs.qosFlowsUsageDataIsSet()) ||
       (qosFlowsUsageDataIsSet() && rhs.qosFlowsUsageDataIsSet() &&
        getQosFlowsUsageData() == rhs.getQosFlowsUsageData())) &&

      ((!pduSessionUsageDataIsSet() && !rhs.pduSessionUsageDataIsSet()) ||
       (pduSessionUsageDataIsSet() && rhs.pduSessionUsageDataIsSet() &&
        getPduSessionUsageData() == rhs.getPduSessionUsageData()))

          ;
}

bool SecondaryRatUsageInfo::operator!=(const SecondaryRatUsageInfo& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const SecondaryRatUsageInfo& o) {
  j                     = nlohmann::json();
  j["secondaryRatType"] = o.m_SecondaryRatType;
  if (o.qosFlowsUsageDataIsSet() || !o.m_QosFlowsUsageData.empty())
    j["qosFlowsUsageData"] = o.m_QosFlowsUsageData;
  if (o.pduSessionUsageDataIsSet() || !o.m_PduSessionUsageData.empty())
    j["pduSessionUsageData"] = o.m_PduSessionUsageData;
}

void from_json(const nlohmann::json& j, SecondaryRatUsageInfo& o) {
  j.at("secondaryRatType").get_to(o.m_SecondaryRatType);
  if (j.find("qosFlowsUsageData") != j.end()) {
    j.at("qosFlowsUsageData").get_to(o.m_QosFlowsUsageData);
    o.m_QosFlowsUsageDataIsSet = true;
  }
  if (j.find("pduSessionUsageData") != j.end()) {
    j.at("pduSessionUsageData").get_to(o.m_PduSessionUsageData);
    o.m_PduSessionUsageDataIsSet = true;
  }
}

ngkore::model::common::RatType SecondaryRatUsageInfo::getSecondaryRatType() const {
  return m_SecondaryRatType;
}
void SecondaryRatUsageInfo::setSecondaryRatType(
    ngkore::model::common::RatType const& value) {
  m_SecondaryRatType = value;
}
std::vector<ngkore::model::common::QosFlowUsageReport>
SecondaryRatUsageInfo::getQosFlowsUsageData() const {
  return m_QosFlowsUsageData;
}
void SecondaryRatUsageInfo::setQosFlowsUsageData(
    std::vector<ngkore::model::common::QosFlowUsageReport> const& value) {
  m_QosFlowsUsageData      = value;
  m_QosFlowsUsageDataIsSet = true;
}
bool SecondaryRatUsageInfo::qosFlowsUsageDataIsSet() const {
  return m_QosFlowsUsageDataIsSet;
}
void SecondaryRatUsageInfo::unsetQosFlowsUsageData() {
  m_QosFlowsUsageDataIsSet = false;
}
std::vector<ngkore::model::common::VolumeTimedReport>
SecondaryRatUsageInfo::getPduSessionUsageData() const {
  return m_PduSessionUsageData;
}
void SecondaryRatUsageInfo::setPduSessionUsageData(
    std::vector<ngkore::model::common::VolumeTimedReport> const& value) {
  m_PduSessionUsageData      = value;
  m_PduSessionUsageDataIsSet = true;
}
bool SecondaryRatUsageInfo::pduSessionUsageDataIsSet() const {
  return m_PduSessionUsageDataIsSet;
}
void SecondaryRatUsageInfo::unsetPduSessionUsageData() {
  m_PduSessionUsageDataIsSet = false;
}

}  // namespace ngkore::model::common
