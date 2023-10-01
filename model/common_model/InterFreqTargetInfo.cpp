
#include "InterFreqTargetInfo.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

InterFreqTargetInfo::InterFreqTargetInfo() {
  m_DlCarrierFreq   = 0;
  m_CellIdListIsSet = false;
}

void InterFreqTargetInfo::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool InterFreqTargetInfo::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool InterFreqTargetInfo::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "InterFreqTargetInfo" : pathPrefix;

