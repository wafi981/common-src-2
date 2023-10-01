
#include "TacInfo.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

TacInfo::TacInfo() {}

void TacInfo::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool TacInfo::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool TacInfo::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success                  = true;
  const std::string _pathPrefix = pathPrefix.empty() ? "TacInfo" : pathPrefix;

