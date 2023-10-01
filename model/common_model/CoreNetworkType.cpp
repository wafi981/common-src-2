
#include "CoreNetworkType.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

CoreNetworkType::CoreNetworkType() {}

void CoreNetworkType::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool CoreNetworkType::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool CoreNetworkType::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "CoreNetworkType" : pathPrefix;

  if (!m_value.validate(msg)) {
    success = false;
  }
  return success;
}

bool CoreNetworkType::operator==(const CoreNetworkType& rhs) const {
  return

      getValue() == rhs.getValue();
}

bool CoreNetworkType::operator!=(const CoreNetworkType& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const CoreNetworkType& o) {
  j = nlohmann::json();
  to_json(j, o.m_value);
}

void from_json(const nlohmann::json& j, CoreNetworkType& o) {
  from_json(j, o.m_value);
}

CoreNetworkType_anyOf CoreNetworkType::getValue() const {
  return m_value;
}

void CoreNetworkType::setValue(CoreNetworkType_anyOf value) {
  m_value = value;
}

CoreNetworkType_anyOf::eCoreNetworkType_anyOf CoreNetworkType::getEnumValue()
    const {
  return m_value.getValue();
}

void CoreNetworkType::setEnumValue(
    CoreNetworkType_anyOf::eCoreNetworkType_anyOf value) {
  m_value.setValue(value);
}

}  // namespace ngkore::model::common
