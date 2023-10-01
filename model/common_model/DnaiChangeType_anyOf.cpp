
#include "DnaiChangeType_anyOf.h"
#include "Helpers.h"
#include <stdexcept>
#include <sstream>

namespace ngkore::model::common {

DnaiChangeType_anyOf::DnaiChangeType_anyOf() {}

void DnaiChangeType_anyOf::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool DnaiChangeType_anyOf::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool DnaiChangeType_anyOf::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "DnaiChangeType_anyOf" : pathPrefix;

  if (m_value == DnaiChangeType_anyOf::eDnaiChangeType_anyOf::
                     INVALID_VALUE_OPENAPI_GENERATED) {
    success = false;
    msg << _pathPrefix << ": has no value;";
  }

  return success;
}

bool DnaiChangeType_anyOf::operator==(const DnaiChangeType_anyOf& rhs) const {
  return getValue() == rhs.getValue()

      ;
}

bool DnaiChangeType_anyOf::operator!=(const DnaiChangeType_anyOf& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const DnaiChangeType_anyOf& o) {
  j = nlohmann::json();

  switch (o.getValue()) {
    case DnaiChangeType_anyOf::eDnaiChangeType_anyOf::
        INVALID_VALUE_OPENAPI_GENERATED:
      j = "INVALID_VALUE_OPENAPI_GENERATED";
      break;
    case DnaiChangeType_anyOf::eDnaiChangeType_anyOf::EARLY:
      j = "EARLY";
      break;
    case DnaiChangeType_anyOf::eDnaiChangeType_anyOf::EARLY_LATE:
      j = "EARLY_LATE";
      break;
    case DnaiChangeType_anyOf::eDnaiChangeType_anyOf::LATE:
      j = "LATE";
      break;
  }
}

void from_json(const nlohmann::json& j, DnaiChangeType_anyOf& o) {
  auto s = j.get<std::string>();
  if (s == "EARLY") {
    o.setValue(DnaiChangeType_anyOf::eDnaiChangeType_anyOf::EARLY);
  } else if (s == "EARLY_LATE") {
    o.setValue(DnaiChangeType_anyOf::eDnaiChangeType_anyOf::EARLY_LATE);
  } else if (s == "LATE") {
    o.setValue(DnaiChangeType_anyOf::eDnaiChangeType_anyOf::LATE);
  } else {
    std::stringstream ss;
    ss << "Unexpected value " << s << " in json"
       << " cannot be converted to enum of type"
       << " DnaiChangeType_anyOf::eDnaiChangeType_anyOf";
    throw std::invalid_argument(ss.str());
  }
}

DnaiChangeType_anyOf::eDnaiChangeType_anyOf DnaiChangeType_anyOf::getValue()
    const {
  return m_value;
}
void DnaiChangeType_anyOf::setValue(
    DnaiChangeType_anyOf::eDnaiChangeType_anyOf value) {
  m_value = value;
}

}  // namespace ngkore::model::common
