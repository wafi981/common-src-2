
#include "TrafficProfileRm.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

TrafficProfileRm::TrafficProfileRm() {}

void TrafficProfileRm::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool TrafficProfileRm::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool TrafficProfileRm::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "TrafficProfileRm" : pathPrefix;

  return success;
}

bool TrafficProfileRm::operator==(const TrafficProfileRm& rhs) const {
  return

      ;
}

bool TrafficProfileRm::operator!=(const TrafficProfileRm& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const TrafficProfileRm& o) {
  j = nlohmann::json();
}

void from_json(const nlohmann::json& j, TrafficProfileRm& o) {}

}  // namespace ngkore::model::common
