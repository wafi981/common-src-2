
#include "NcgiRm.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

NcgiRm::NcgiRm() {
  m_NrCellId = "";
  m_Nid      = "";
  m_NidIsSet = false;
}

void NcgiRm::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool NcgiRm::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool NcgiRm::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success                  = true;
  const std::string _pathPrefix = pathPrefix.empty() ? "NcgiRm" : pathPrefix;

