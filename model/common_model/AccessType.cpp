
#include "AccessType.h"
#include "Helpers.h"
#include <stdexcept>
#include <sstream>

namespace ngkore::model::common {

AccessType::AccessType() {}

void AccessType::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool AccessType::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool AccessType::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "AccessType" : pathPrefix;

  if (m_value == AccessType::eAccessType::INVALID_VALUE_OPENAPI_GENERATED) {
    success = false;
    msg << _pathPrefix << ": has no value;";
  }

  return success;
}

bool AccessType::operator==(const AccessType& rhs) const {
  return getValue() == rhs.getValue()

      ;
}

bool AccessType::operator!=(const AccessType& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const AccessType& o) {
  j = nlohmann::json();

  switch (o.getValue()) {
    case AccessType::eAccessType::INVALID_VALUE_OPENAPI_GENERATED:
      j = "INVALID_VALUE_OPENAPI_GENERATED";
      break;
    case AccessType::eAccessType::_3GPP_ACCESS:
      j = "3GPP_ACCESS";
      break;
    case AccessType::eAccessType::NON_3GPP_ACCESS:
      j = "NON_3GPP_ACCESS";
      break;
  }
}

void from_json(const nlohmann::json& j, AccessType& o) {
  auto s = j.get<std::string>();
  if (s == "3GPP_ACCESS") {
    o.setValue(AccessType::eAccessType::_3GPP_ACCESS);
  } else if (s == "NON_3GPP_ACCESS") {
    o.setValue(AccessType::eAccessType::NON_3GPP_ACCESS);
  } else {
    std::stringstream ss;
    ss << "Unexpected value " << s << " in json"
       << " cannot be converted to enum of type"
       << " AccessType::eAccessType";
    throw std::invalid_argument(ss.str());
  }
}

AccessType::eAccessType AccessType::getValue() const {
  return m_value;
}
void AccessType::setValue(AccessType::eAccessType value) {
  m_value = value;
}

}  // namespace ngkore::model::common
