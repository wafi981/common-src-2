
#include "QosResourceTypeRm.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

QosResourceTypeRm::QosResourceTypeRm() {}

void QosResourceTypeRm::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool QosResourceTypeRm::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool QosResourceTypeRm::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "QosResourceTypeRm" : pathPrefix;

  return success;
}

bool QosResourceTypeRm::operator==(const QosResourceTypeRm& rhs) const {
  return

      ;
}

bool QosResourceTypeRm::operator!=(const QosResourceTypeRm& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const QosResourceTypeRm& o) {
  j = nlohmann::json();
}

void from_json(const nlohmann::json& j, QosResourceTypeRm& o) {}

}  // namespace ngkore::model::common
