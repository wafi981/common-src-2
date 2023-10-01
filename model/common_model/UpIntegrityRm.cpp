
#include "UpIntegrityRm.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

UpIntegrityRm::UpIntegrityRm() {}

void UpIntegrityRm::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool UpIntegrityRm::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool UpIntegrityRm::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "UpIntegrityRm" : pathPrefix;

  return success;
}

bool UpIntegrityRm::operator==(const UpIntegrityRm& rhs) const {
  return

      ;
}

bool UpIntegrityRm::operator!=(const UpIntegrityRm& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const UpIntegrityRm& o) {
  j = nlohmann::json();
}

void from_json(const nlohmann::json& j, UpIntegrityRm& o) {}

}  // namespace ngkore::model::common
