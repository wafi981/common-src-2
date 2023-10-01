
#include "PatchResult.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

PatchResult::PatchResult() {}

void PatchResult::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool PatchResult::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool PatchResult::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "PatchResult" : pathPrefix;

