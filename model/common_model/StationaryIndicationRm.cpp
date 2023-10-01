
#include "StationaryIndicationRm.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

StationaryIndicationRm::StationaryIndicationRm() {}

void StationaryIndicationRm::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool StationaryIndicationRm::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool StationaryIndicationRm::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "StationaryIndicationRm" : pathPrefix;

  return success;
}

bool StationaryIndicationRm::operator==(
    const StationaryIndicationRm& rhs) const {
  return

      ;
}

bool StationaryIndicationRm::operator!=(
    const StationaryIndicationRm& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const StationaryIndicationRm& o) {
  j = nlohmann::json();
}

void from_json(const nlohmann::json& j, StationaryIndicationRm& o) {}

}  // namespace ngkore::model::common
