
#include "LineType.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

LineType::LineType() {}

void LineType::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool LineType::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool LineType::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success                  = true;
  const std::string _pathPrefix = pathPrefix.empty() ? "LineType" : pathPrefix;

  if (!m_value.validate(msg)) {
    success = false;
  }
  return success;
}

bool LineType::operator==(const LineType& rhs) const {
  return

      getValue() == rhs.getValue();
}

bool LineType::operator!=(const LineType& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const LineType& o) {
  j = nlohmann::json();
  to_json(j, o.m_value);
}

void from_json(const nlohmann::json& j, LineType& o) {
  from_json(j, o.m_value);
}

LineType_anyOf LineType::getValue() const {
  return m_value;
}

void LineType::setValue(LineType_anyOf value) {
  m_value = value;
}

LineType_anyOf::eLineType_anyOf LineType::getEnumValue() const {
  return m_value.getValue();
}

void LineType::setEnumValue(LineType_anyOf::eLineType_anyOf value) {
  m_value.setValue(value);
}

}  // namespace ngkore::model::common
