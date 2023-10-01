
#include "AdditionalQosFlowInfo.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

AdditionalQosFlowInfo::AdditionalQosFlowInfo() {}

void AdditionalQosFlowInfo::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool AdditionalQosFlowInfo::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool AdditionalQosFlowInfo::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "AdditionalQosFlowInfo" : pathPrefix;

  return success;
}

bool AdditionalQosFlowInfo::operator==(const AdditionalQosFlowInfo& rhs) const {
  return

      ;
}

bool AdditionalQosFlowInfo::operator!=(const AdditionalQosFlowInfo& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const AdditionalQosFlowInfo& o) {
  j = nlohmann::json();
}

void from_json(const nlohmann::json& j, AdditionalQosFlowInfo& o) {}

}  // namespace ngkore::model::common
