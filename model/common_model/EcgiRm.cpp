
#include "EcgiRm.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

EcgiRm::EcgiRm() {
  m_EutraCellId = "";
  m_Nid         = "";
  m_NidIsSet    = false;
}

void EcgiRm::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool EcgiRm::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool EcgiRm::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success                  = true;
  const std::string _pathPrefix = pathPrefix.empty() ? "EcgiRm" : pathPrefix;

