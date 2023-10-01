
#include "OdbPacketServices.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

OdbPacketServices::OdbPacketServices() {}

void OdbPacketServices::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool OdbPacketServices::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool OdbPacketServices::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "OdbPacketServices" : pathPrefix;

  return success;
}

bool OdbPacketServices::operator==(const OdbPacketServices& rhs) const {
  return

      ;
}

bool OdbPacketServices::operator!=(const OdbPacketServices& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const OdbPacketServices& o) {
  j = nlohmann::json();
}

void from_json(const nlohmann::json& j, OdbPacketServices& o) {}

}  // namespace ngkore::model::common
