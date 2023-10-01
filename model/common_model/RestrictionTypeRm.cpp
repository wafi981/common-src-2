
#include "RestrictionTypeRm.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

RestrictionTypeRm::RestrictionTypeRm() {}

void RestrictionTypeRm::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool RestrictionTypeRm::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool RestrictionTypeRm::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "RestrictionTypeRm" : pathPrefix;

  return success;
}

bool RestrictionTypeRm::operator==(const RestrictionTypeRm& rhs) const {
  return

      ;
}

bool RestrictionTypeRm::operator!=(const RestrictionTypeRm& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const RestrictionTypeRm& o) {
  j = nlohmann::json();
}

void from_json(const nlohmann::json& j, RestrictionTypeRm& o) {}

}  // namespace ngkore::model::common
