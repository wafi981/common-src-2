
#include "HfcNodeIdRm.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

HfcNodeIdRm::HfcNodeIdRm() {
  m_HfcNId = "";
}

void HfcNodeIdRm::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool HfcNodeIdRm::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool HfcNodeIdRm::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "HfcNodeIdRm" : pathPrefix;

