
#include "PreemptionCapabilityRm.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

PreemptionCapabilityRm::PreemptionCapabilityRm() {}

void PreemptionCapabilityRm::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool PreemptionCapabilityRm::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool PreemptionCapabilityRm::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "PreemptionCapabilityRm" : pathPrefix;

  return success;
}

bool PreemptionCapabilityRm::operator==(
    const PreemptionCapabilityRm& rhs) const {
  return

      ;
}

bool PreemptionCapabilityRm::operator!=(
    const PreemptionCapabilityRm& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const PreemptionCapabilityRm& o) {
  j = nlohmann::json();
}

void from_json(const nlohmann::json& j, PreemptionCapabilityRm& o) {}

}  // namespace ngkore::model::common
