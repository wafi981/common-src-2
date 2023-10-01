
#include "RatTypeRm.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

RatTypeRm::RatTypeRm() {}

void RatTypeRm::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool RatTypeRm::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool RatTypeRm::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success                  = true;
  const std::string _pathPrefix = pathPrefix.empty() ? "RatTypeRm" : pathPrefix;

  return success;
}

bool RatTypeRm::operator==(const RatTypeRm& rhs) const {
  return

      ;
}

bool RatTypeRm::operator!=(const RatTypeRm& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const RatTypeRm& o) {
  j = nlohmann::json();
}

void from_json(const nlohmann::json& j, RatTypeRm& o) {}

}  // namespace ngkore::model::common
