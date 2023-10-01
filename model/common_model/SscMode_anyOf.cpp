
#include "SscMode_anyOf.h"
#include "Helpers.h"
#include <stdexcept>
#include <sstream>

namespace ngkore::model::common {

SscMode_anyOf::SscMode_anyOf() {}

void SscMode_anyOf::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool SscMode_anyOf::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool SscMode_anyOf::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "SscMode_anyOf" : pathPrefix;

  if (m_value ==
      SscMode_anyOf::eSscMode_anyOf::INVALID_VALUE_OPENAPI_GENERATED) {
    success = false;
    msg << _pathPrefix << ": has no value;";
  }

  return success;
}

bool SscMode_anyOf::operator==(const SscMode_anyOf& rhs) const {
  return getValue() == rhs.getValue()

      ;
}

bool SscMode_anyOf::operator!=(const SscMode_anyOf& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const SscMode_anyOf& o) {
  j = nlohmann::json();

  switch (o.getValue()) {
    case SscMode_anyOf::eSscMode_anyOf::INVALID_VALUE_OPENAPI_GENERATED:
      j = "INVALID_VALUE_OPENAPI_GENERATED";
      break;
    case SscMode_anyOf::eSscMode_anyOf::_1:
      j = "SSC_MODE_1";
      break;
    case SscMode_anyOf::eSscMode_anyOf::_2:
      j = "SSC_MODE_2";
      break;
    case SscMode_anyOf::eSscMode_anyOf::_3:
      j = "SSC_MODE_3";
      break;
  }
}

void from_json(const nlohmann::json& j, SscMode_anyOf& o) {
  auto s = j.get<std::string>();
  if (s == "SSC_MODE_1") {
    o.setValue(SscMode_anyOf::eSscMode_anyOf::_1);
  } else if (s == "SSC_MODE_2") {
    o.setValue(SscMode_anyOf::eSscMode_anyOf::_2);
  } else if (s == "SSC_MODE_3") {
    o.setValue(SscMode_anyOf::eSscMode_anyOf::_3);
  } else {
    std::stringstream ss;
    ss << "Unexpected value " << s << " in json"
       << " cannot be converted to enum of type"
       << " SscMode_anyOf::eSscMode_anyOf";
    throw std::invalid_argument(ss.str());
  }
}

SscMode_anyOf::eSscMode_anyOf SscMode_anyOf::getValue() const {
  return m_value;
}
void SscMode_anyOf::setValue(SscMode_anyOf::eSscMode_anyOf value) {
  m_value = value;
}

}  // namespace ngkore::model::common
