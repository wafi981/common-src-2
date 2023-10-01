
#include "ScheduledCommunicationTypeRm.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

ScheduledCommunicationTypeRm::ScheduledCommunicationTypeRm() {}

void ScheduledCommunicationTypeRm::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool ScheduledCommunicationTypeRm::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool ScheduledCommunicationTypeRm::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "ScheduledCommunicationTypeRm" : pathPrefix;

  return success;
}

bool ScheduledCommunicationTypeRm::operator==(
    const ScheduledCommunicationTypeRm& rhs) const {
  return

      ;
}

bool ScheduledCommunicationTypeRm::operator!=(
    const ScheduledCommunicationTypeRm& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const ScheduledCommunicationTypeRm& o) {
  j = nlohmann::json();
}

void from_json(const nlohmann::json& j, ScheduledCommunicationTypeRm& o) {}

}  // namespace ngkore::model::common
