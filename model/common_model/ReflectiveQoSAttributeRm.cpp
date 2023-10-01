
#include "ReflectiveQoSAttributeRm.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

ReflectiveQoSAttributeRm::ReflectiveQoSAttributeRm() {}

void ReflectiveQoSAttributeRm::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool ReflectiveQoSAttributeRm::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool ReflectiveQoSAttributeRm::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "ReflectiveQoSAttributeRm" : pathPrefix;

  return success;
}

bool ReflectiveQoSAttributeRm::operator==(
    const ReflectiveQoSAttributeRm& rhs) const {
  return

      ;
}

bool ReflectiveQoSAttributeRm::operator!=(
    const ReflectiveQoSAttributeRm& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const ReflectiveQoSAttributeRm& o) {
  j = nlohmann::json();
}

void from_json(const nlohmann::json& j, ReflectiveQoSAttributeRm& o) {}

}  // namespace ngkore::model::common
