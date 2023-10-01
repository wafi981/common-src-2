
#include "GuamiRm.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

GuamiRm::GuamiRm() {
  m_AmfId = "";
}

void GuamiRm::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool GuamiRm::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool GuamiRm::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success                  = true;
  const std::string _pathPrefix = pathPrefix.empty() ? "GuamiRm" : pathPrefix;

