
#include "ArpRm.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

ArpRm::ArpRm() {
  m_PriorityLevel = 0;
}

void ArpRm::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool ArpRm::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool ArpRm::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success                  = true;
  const std::string _pathPrefix = pathPrefix.empty() ? "ArpRm" : pathPrefix;

