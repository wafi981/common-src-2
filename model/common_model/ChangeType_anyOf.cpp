
#include "ChangeType_anyOf.h"
#include "Helpers.h"
#include <stdexcept>
#include <sstream>

namespace ngkore::model::common {

ChangeType_anyOf::ChangeType_anyOf() {}

void ChangeType_anyOf::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool ChangeType_anyOf::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool ChangeType_anyOf::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "ChangeType_anyOf" : pathPrefix;

  if (m_value ==
      ChangeType_anyOf::eChangeType_anyOf::INVALID_VALUE_OPENAPI_GENERATED) {
    success = false;
    msg << _pathPrefix << ": has no value;";
  }

  return success;
}

bool ChangeType_anyOf::operator==(const ChangeType_anyOf& rhs) const {
  return getValue() == rhs.getValue()

      ;
}

bool ChangeType_anyOf::operator!=(const ChangeType_anyOf& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const ChangeType_anyOf& o) {
  j = nlohmann::json();

  switch (o.getValue()) {
    case ChangeType_anyOf::eChangeType_anyOf::INVALID_VALUE_OPENAPI_GENERATED:
      j = "INVALID_VALUE_OPENAPI_GENERATED";
      break;
    case ChangeType_anyOf::eChangeType_anyOf::ADD:
      j = "ADD";
      break;
    case ChangeType_anyOf::eChangeType_anyOf::MOVE:
      j = "MOVE";
      break;
    case ChangeType_anyOf::eChangeType_anyOf::REMOVE:
      j = "REMOVE";
      break;
    case ChangeType_anyOf::eChangeType_anyOf::REPLACE:
      j = "REPLACE";
      break;
  }
}

void from_json(const nlohmann::json& j, ChangeType_anyOf& o) {
  auto s = j.get<std::string>();
  if (s == "ADD") {
    o.setValue(ChangeType_anyOf::eChangeType_anyOf::ADD);
  } else if (s == "MOVE") {
    o.setValue(ChangeType_anyOf::eChangeType_anyOf::MOVE);
  } else if (s == "REMOVE") {
    o.setValue(ChangeType_anyOf::eChangeType_anyOf::REMOVE);
  } else if (s == "REPLACE") {
    o.setValue(ChangeType_anyOf::eChangeType_anyOf::REPLACE);
  } else {
    std::stringstream ss;
    ss << "Unexpected value " << s << " in json"
       << " cannot be converted to enum of type"
       << " ChangeType_anyOf::eChangeType_anyOf";
    throw std::invalid_argument(ss.str());
  }
}

ChangeType_anyOf::eChangeType_anyOf ChangeType_anyOf::getValue() const {
  return m_value;
}
void ChangeType_anyOf::setValue(ChangeType_anyOf::eChangeType_anyOf value) {
  m_value = value;
}

}  // namespace ngkore::model::common
