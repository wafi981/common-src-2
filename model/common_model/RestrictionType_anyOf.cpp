
#include "RestrictionType_anyOf.h"
#include "Helpers.h"
#include <stdexcept>
#include <sstream>

namespace ngkore::model::common {

RestrictionType_anyOf::RestrictionType_anyOf() {}

void RestrictionType_anyOf::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool RestrictionType_anyOf::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool RestrictionType_anyOf::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "RestrictionType_anyOf" : pathPrefix;

  if (m_value == RestrictionType_anyOf::eRestrictionType_anyOf::
                     INVALID_VALUE_OPENAPI_GENERATED) {
    success = false;
    msg << _pathPrefix << ": has no value;";
  }

  return success;
}

bool RestrictionType_anyOf::operator==(const RestrictionType_anyOf& rhs) const {
  return getValue() == rhs.getValue()

      ;
}

bool RestrictionType_anyOf::operator!=(const RestrictionType_anyOf& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const RestrictionType_anyOf& o) {
  j = nlohmann::json();

  switch (o.getValue()) {
    case RestrictionType_anyOf::eRestrictionType_anyOf::
        INVALID_VALUE_OPENAPI_GENERATED:
      j = "INVALID_VALUE_OPENAPI_GENERATED";
      break;
    case RestrictionType_anyOf::eRestrictionType_anyOf::ALLOWED_AREAS:
      j = "ALLOWED_AREAS";
      break;
    case RestrictionType_anyOf::eRestrictionType_anyOf::NOT_ALLOWED_AREAS:
      j = "NOT_ALLOWED_AREAS";
      break;
  }
}

void from_json(const nlohmann::json& j, RestrictionType_anyOf& o) {
  auto s = j.get<std::string>();
  if (s == "ALLOWED_AREAS") {
    o.setValue(RestrictionType_anyOf::eRestrictionType_anyOf::ALLOWED_AREAS);
  } else if (s == "NOT_ALLOWED_AREAS") {
    o.setValue(
        RestrictionType_anyOf::eRestrictionType_anyOf::NOT_ALLOWED_AREAS);
  } else {
    std::stringstream ss;
    ss << "Unexpected value " << s << " in json"
       << " cannot be converted to enum of type"
       << " RestrictionType_anyOf::eRestrictionType_anyOf";
    throw std::invalid_argument(ss.str());
  }
}

RestrictionType_anyOf::eRestrictionType_anyOf RestrictionType_anyOf::getValue()
    const {
  return m_value;
}
void RestrictionType_anyOf::setValue(
    RestrictionType_anyOf::eRestrictionType_anyOf value) {
  m_value = value;
}

}  // namespace ngkore::model::common
