
#include "DlDataDeliveryStatus_anyOf.h"
#include "Helpers.h"
#include <stdexcept>
#include <sstream>

namespace ngkore::model::common {

DlDataDeliveryStatus_anyOf::DlDataDeliveryStatus_anyOf() {}

void DlDataDeliveryStatus_anyOf::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool DlDataDeliveryStatus_anyOf::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool DlDataDeliveryStatus_anyOf::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "DlDataDeliveryStatus_anyOf" : pathPrefix;

  if (m_value == DlDataDeliveryStatus_anyOf::eDlDataDeliveryStatus_anyOf::
                     INVALID_VALUE_OPENAPI_GENERATED) {
    success = false;
    msg << _pathPrefix << ": has no value;";
  }

  return success;
}

bool DlDataDeliveryStatus_anyOf::operator==(
    const DlDataDeliveryStatus_anyOf& rhs) const {
  return getValue() == rhs.getValue()

      ;
}

bool DlDataDeliveryStatus_anyOf::operator!=(
    const DlDataDeliveryStatus_anyOf& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const DlDataDeliveryStatus_anyOf& o) {
  j = nlohmann::json();

  switch (o.getValue()) {
    case DlDataDeliveryStatus_anyOf::eDlDataDeliveryStatus_anyOf::
        INVALID_VALUE_OPENAPI_GENERATED:
      j = "INVALID_VALUE_OPENAPI_GENERATED";
      break;
    case DlDataDeliveryStatus_anyOf::eDlDataDeliveryStatus_anyOf::BUFFERED:
      j = "BUFFERED";
      break;
    case DlDataDeliveryStatus_anyOf::eDlDataDeliveryStatus_anyOf::TRANSMITTED:
      j = "TRANSMITTED";
      break;
    case DlDataDeliveryStatus_anyOf::eDlDataDeliveryStatus_anyOf::DISCARDED:
      j = "DISCARDED";
      break;
  }
}

void from_json(const nlohmann::json& j, DlDataDeliveryStatus_anyOf& o) {
  auto s = j.get<std::string>();
  if (s == "BUFFERED") {
    o.setValue(
        DlDataDeliveryStatus_anyOf::eDlDataDeliveryStatus_anyOf::BUFFERED);
  } else if (s == "TRANSMITTED") {
    o.setValue(
        DlDataDeliveryStatus_anyOf::eDlDataDeliveryStatus_anyOf::TRANSMITTED);
  } else if (s == "DISCARDED") {
    o.setValue(
        DlDataDeliveryStatus_anyOf::eDlDataDeliveryStatus_anyOf::DISCARDED);
  } else {
    std::stringstream ss;
    ss << "Unexpected value " << s << " in json"
       << " cannot be converted to enum of type"
       << " DlDataDeliveryStatus_anyOf::eDlDataDeliveryStatus_anyOf";
    throw std::invalid_argument(ss.str());
  }
}

DlDataDeliveryStatus_anyOf::eDlDataDeliveryStatus_anyOf
DlDataDeliveryStatus_anyOf::getValue() const {
  return m_value;
}
void DlDataDeliveryStatus_anyOf::setValue(
    DlDataDeliveryStatus_anyOf::eDlDataDeliveryStatus_anyOf value) {
  m_value = value;
}

}  // namespace ngkore::model::common
