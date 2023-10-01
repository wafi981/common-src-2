
#include "SscModeRm.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

SscModeRm::SscModeRm() {}

void SscModeRm::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool SscModeRm::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool SscModeRm::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success                  = true;
  const std::string _pathPrefix = pathPrefix.empty() ? "SscModeRm" : pathPrefix;

  return success;
}

bool SscModeRm::operator==(const SscModeRm& rhs) const {
  return

      ;
}

bool SscModeRm::operator!=(const SscModeRm& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const SscModeRm& o) {
  j = nlohmann::json();
}

void from_json(const nlohmann::json& j, SscModeRm& o) {}

}  // namespace ngkore::model::common
