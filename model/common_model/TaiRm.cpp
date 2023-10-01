
#include "TaiRm.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

TaiRm::TaiRm() {
  m_Tac      = "";
  m_Nid      = "";
  m_NidIsSet = false;
}

void TaiRm::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool TaiRm::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool TaiRm::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success                  = true;
  const std::string _pathPrefix = pathPrefix.empty() ? "TaiRm" : pathPrefix;

