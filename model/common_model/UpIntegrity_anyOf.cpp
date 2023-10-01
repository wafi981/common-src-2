
#include "UpIntegrity_anyOf.h"
#include "Helpers.h"
#include <stdexcept>
#include <sstream>

namespace ngkore::model::common {

UpIntegrity_anyOf::UpIntegrity_anyOf() {}

void UpIntegrity_anyOf::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool UpIntegrity_anyOf::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool UpIntegrity_anyOf::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "UpIntegrity_anyOf" : pathPrefix;

  if (m_value ==
      UpIntegrity_anyOf::eUpIntegrity_anyOf::INVALID_VALUE_OPENAPI_GENERATED) {
    success = false;
    msg << _pathPrefix << ": has no value;";
  }

  return success;
}

bool UpIntegrity_anyOf::operator==(const UpIntegrity_anyOf& rhs) const {
  return getValue() == rhs.getValue()

      ;
}

bool UpIntegrity_anyOf::operator!=(const UpIntegrity_anyOf& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const UpIntegrity_anyOf& o) {
  j = nlohmann::json();

  switch (o.getValue()) {
    case UpIntegrity_anyOf::eUpIntegrity_anyOf::INVALID_VALUE_OPENAPI_GENERATED:
      j = "INVALID_VALUE_OPENAPI_GENERATED";
      break;
    case UpIntegrity_anyOf::eUpIntegrity_anyOf::REQUIRED:
      j = "REQUIRED";
      break;
    case UpIntegrity_anyOf::eUpIntegrity_anyOf::PREFERRED:
      j = "PREFERRED";
      break;
    case UpIntegrity_anyOf::eUpIntegrity_anyOf::NOT_NEEDED:
      j = "NOT_NEEDED";
      break;
  }
}

void from_json(const nlohmann::json& j, UpIntegrity_anyOf& o) {
  auto s = j.get<std::string>();
  if (s == "REQUIRED") {
    o.setValue(UpIntegrity_anyOf::eUpIntegrity_anyOf::REQUIRED);
  } else if (s == "PREFERRED") {
    o.setValue(UpIntegrity_anyOf::eUpIntegrity_anyOf::PREFERRED);
  } else if (s == "NOT_NEEDED") {
    o.setValue(UpIntegrity_anyOf::eUpIntegrity_anyOf::NOT_NEEDED);
  } else {
    std::stringstream ss;
    ss << "Unexpected value " << s << " in json"
       << " cannot be converted to enum of type"
       << " UpIntegrity_anyOf::eUpIntegrity_anyOf";
    throw std::invalid_argument(ss.str());
  }
}

UpIntegrity_anyOf::eUpIntegrity_anyOf UpIntegrity_anyOf::getValue() const {
  return m_value;
}
void UpIntegrity_anyOf::setValue(UpIntegrity_anyOf::eUpIntegrity_anyOf value) {
  m_value = value;
}

}  // namespace ngkore::model::common