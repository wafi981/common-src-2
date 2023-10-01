
#include "QosFlowUsageReport.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

QosFlowUsageReport::QosFlowUsageReport() {
  m_Qfi            = 0;
  m_StartTimeStamp = "";
  m_EndTimeStamp   = "";
  m_DownlinkVolume = 0L;
  m_UplinkVolume   = 0L;
}

void QosFlowUsageReport::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool QosFlowUsageReport::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool QosFlowUsageReport::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "QosFlowUsageReport" : pathPrefix;

