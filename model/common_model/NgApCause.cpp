
#include "NgApCause.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

NgApCause::NgApCause() {
  m_Group = 0;
  m_Value = 0;
}

void NgApCause::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool NgApCause::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool NgApCause::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success                  = true;
  const std::string _pathPrefix = pathPrefix.empty() ? "NgApCause" : pathPrefix;

    const int32_t& value               = m_Value;
    const std::string currentValuePath = _pathPrefix + ".value";

    if (value < 0) {
      success = false;
      msg << currentValuePath << ": must be greater than or equal to 0;";
    }
  }

  return success;
}

bool NgApCause::operator==(const NgApCause& rhs) const {
  return

      (getGroup() == rhs.getGroup()) &&

      (getValue() == rhs.getValue())

          ;
}

bool NgApCause::operator!=(const NgApCause& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const NgApCause& o) {
  j          = nlohmann::json();
  j["group"] = o.m_Group;
  j["value"] = o.m_Value;
}

void from_json(const nlohmann::json& j, NgApCause& o) {
  j.at("group").get_to(o.m_Group);
  j.at("value").get_to(o.m_Value);
}

int32_t NgApCause::getGroup() const {
  return m_Group;
}
void NgApCause::setGroup(int32_t const value) {
  m_Group = value;
}
int32_t NgApCause::getValue() const {
  return m_Value;
}
void NgApCause::setValue(int32_t const value) {
  m_Value = value;
}

}  // namespace ngkore::model::common
