
#include "UpConfidentialityRm.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

UpConfidentialityRm::UpConfidentialityRm() {}

void UpConfidentialityRm::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool UpConfidentialityRm::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool UpConfidentialityRm::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "UpConfidentialityRm" : pathPrefix;

  return success;
}

bool UpConfidentialityRm::operator==(const UpConfidentialityRm& rhs) const {
  return

      ;
}

bool UpConfidentialityRm::operator!=(const UpConfidentialityRm& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const UpConfidentialityRm& o) {
  j = nlohmann::json();
}

void from_json(const nlohmann::json& j, UpConfidentialityRm& o) {}

}  // namespace ngkore::model::common
