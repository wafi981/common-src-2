
#include "CnfUnit.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

CnfUnit::CnfUnit() {}

void CnfUnit::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool CnfUnit::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool CnfUnit::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success                  = true;
  const std::string _pathPrefix = pathPrefix.empty() ? "CnfUnit" : pathPrefix;

