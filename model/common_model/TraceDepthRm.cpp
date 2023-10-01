
#include "TraceDepthRm.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

TraceDepthRm::TraceDepthRm() {}

void TraceDepthRm::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool TraceDepthRm::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool TraceDepthRm::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "TraceDepthRm" : pathPrefix;

  return success;
}

bool TraceDepthRm::operator==(const TraceDepthRm& rhs) const {
  return

      ;
}

bool TraceDepthRm::operator!=(const TraceDepthRm& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const TraceDepthRm& o) {
  j = nlohmann::json();
}

void from_json(const nlohmann::json& j, TraceDepthRm& o) {}

}  // namespace ngkore::model::common
