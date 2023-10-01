
#include "SecondaryRatUsageReport.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

SecondaryRatUsageReport::SecondaryRatUsageReport() {}

void SecondaryRatUsageReport::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool SecondaryRatUsageReport::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool SecondaryRatUsageReport::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "SecondaryRatUsageReport" : pathPrefix;

