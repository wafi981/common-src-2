
#include "RatType.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

RatType::RatType() {}

void RatType::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool RatType::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool RatType::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success                  = true;
  const std::string _pathPrefix = pathPrefix.empty() ? "RatType" : pathPrefix;

  if (!m_value.validate(msg)) {
    success = false;
  }
  return success;
}

bool RatType::operator==(const RatType& rhs) const {
  return

      getValue() == rhs.getValue();
}

bool RatType::operator!=(const RatType& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const RatType& o) {
  j = nlohmann::json();
  to_json(j, o.m_value);
}

void from_json(const nlohmann::json& j, RatType& o) {
  from_json(j, o.m_value);
}

RatType_anyOf RatType::getValue() const {
  return m_value;
}

void RatType::setValue(RatType_anyOf value) {
  m_value = value;
}

RatType_anyOf::eRatType_anyOf RatType::getEnumValue() const {
  return m_value.getValue();
}

void RatType::setEnumValue(RatType_anyOf::eRatType_anyOf value) {
  m_value.setValue(value);
}

}  // namespace ngkore::model::common
