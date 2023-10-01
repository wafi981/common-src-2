
#include "SubscribedDefaultQos.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

SubscribedDefaultQos::SubscribedDefaultQos() {
  m_r_5qi              = 0;
  m_PriorityLevel      = 0;
  m_PriorityLevelIsSet = false;
}

void SubscribedDefaultQos::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool SubscribedDefaultQos::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool SubscribedDefaultQos::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "SubscribedDefaultQos" : pathPrefix;

