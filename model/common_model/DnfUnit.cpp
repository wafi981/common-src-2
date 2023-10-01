
#include "DnfUnit.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

DnfUnit::DnfUnit() {}

void DnfUnit::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool DnfUnit::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool DnfUnit::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success                  = true;
  const std::string _pathPrefix = pathPrefix.empty() ? "DnfUnit" : pathPrefix;

