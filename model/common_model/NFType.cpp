
#include "NFType.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

NFType::NFType() {}

void NFType::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool NFType::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool NFType::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success                  = true;
  const std::string _pathPrefix = pathPrefix.empty() ? "NFType" : pathPrefix;

  if (!m_value.validate(msg)) {
    success = false;
  }
  return success;
}

bool NFType::operator==(const NFType& rhs) const {
  return

      getValue() == rhs.getValue();
}

bool NFType::operator!=(const NFType& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const NFType& o) {
  j = nlohmann::json();
  to_json(j, o.m_value);
}

void from_json(const nlohmann::json& j, NFType& o) {
  from_json(j, o.m_value);
}

NFType_anyOf NFType::getValue() const {
  return m_value;
}

void NFType::setValue(NFType_anyOf value) {
  m_value = value;
}

NFType_anyOf::eNFType_anyOf NFType::getEnumValue() const {
  return m_value.getValue();
}

std::string NFType::getEnumString() const {
  return helpers::enumToString(m_value);
}

void NFType::setEnumValue(NFType_anyOf::eNFType_anyOf value) {
  m_value.setValue(value);
}

}  // namespace ngkore::model::common
