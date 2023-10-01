
#include "ExtSnssai.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

ExtSnssai::ExtSnssai() {
  m_Sst             = 0;
  m_Sd              = "";
  m_SdIsSet         = false;
  m_SdRangesIsSet   = false;
  m_WildcardSd      = false;
  m_WildcardSdIsSet = false;
}

void ExtSnssai::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool ExtSnssai::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool ExtSnssai::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success                  = true;
  const std::string _pathPrefix = pathPrefix.empty() ? "ExtSnssai" : pathPrefix;

