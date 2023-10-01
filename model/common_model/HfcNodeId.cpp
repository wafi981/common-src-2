
#include "HfcNodeId.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

HfcNodeId::HfcNodeId() {
  m_HfcNId = "";
}

void HfcNodeId::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool HfcNodeId::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool HfcNodeId::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success                  = true;
  const std::string _pathPrefix = pathPrefix.empty() ? "HfcNodeId" : pathPrefix;

