
#include "NullValue.h"
#include "Helpers.h"
#include <stdexcept>
#include <sstream>

namespace ngkore::model::common {

NullValue::NullValue() {}

void NullValue::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool NullValue::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool NullValue::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success                  = true;
  const std::string _pathPrefix = pathPrefix.empty() ? "NullValue" : pathPrefix;

  if (m_value == NullValue::eNullValue::INVALID_VALUE_OPENAPI_GENERATED) {
    success = false;
    msg << _pathPrefix << ": has no value;";
  }

  return success;
}

bool NullValue::operator==(const NullValue& rhs) const {
  return getValue() == rhs.getValue()

      ;
}

bool NullValue::operator!=(const NullValue& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const NullValue& o) {
  j = nlohmann::json();

  switch (o.getValue()) {
    case NullValue::eNullValue::INVALID_VALUE_OPENAPI_GENERATED:
      j = "INVALID_VALUE_OPENAPI_GENERATED";
      break;
    case NullValue::eNullValue::_NULL:
      j = "null";
      break;
  }
}

void from_json(const nlohmann::json& j, NullValue& o) {
  auto s = j.get<std::string>();
  if (s == "null") {
    o.setValue(NullValue::eNullValue::_NULL);
  } else {
    std::stringstream ss;
    ss << "Unexpected value " << s << " in json"
       << " cannot be converted to enum of type"
       << " NullValue::eNullValue";
    throw std::invalid_argument(ss.str());
  }
}

NullValue::eNullValue NullValue::getValue() const {
  return m_value;
}
void NullValue::setValue(NullValue::eNullValue value) {
  m_value = value;
}

}  // namespace ngkore::model::common
