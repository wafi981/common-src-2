
#include "DlDataDeliveryStatus.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

DlDataDeliveryStatus::DlDataDeliveryStatus() {}

void DlDataDeliveryStatus::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool DlDataDeliveryStatus::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool DlDataDeliveryStatus::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "DlDataDeliveryStatus" : pathPrefix;

  if (!m_value.validate(msg)) {
    success = false;
  }
  return success;
}

bool DlDataDeliveryStatus::operator==(const DlDataDeliveryStatus& rhs) const {
  return

      getValue() == rhs.getValue();
}

bool DlDataDeliveryStatus::operator!=(const DlDataDeliveryStatus& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const DlDataDeliveryStatus& o) {
  j = nlohmann::json();
  to_json(j, o.m_value);
}

void from_json(const nlohmann::json& j, DlDataDeliveryStatus& o) {
  from_json(j, o.m_value);
}

DlDataDeliveryStatus_anyOf DlDataDeliveryStatus::getValue() const {
  return m_value;
}

void DlDataDeliveryStatus::setValue(DlDataDeliveryStatus_anyOf value) {
  m_value = value;
}

DlDataDeliveryStatus_anyOf::eDlDataDeliveryStatus_anyOf
DlDataDeliveryStatus::getEnumValue() const {
  return m_value.getValue();
}

void DlDataDeliveryStatus::setEnumValue(
    DlDataDeliveryStatus_anyOf::eDlDataDeliveryStatus_anyOf value) {
  m_value.setValue(value);
}

}  // namespace ngkore::model::common
