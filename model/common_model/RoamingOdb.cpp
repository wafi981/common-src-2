
#include "RoamingOdb.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

RoamingOdb::RoamingOdb() {}

void RoamingOdb::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool RoamingOdb::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool RoamingOdb::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "RoamingOdb" : pathPrefix;

  if (!m_value.validate(msg)) {
    success = false;
  }
  return success;
}

bool RoamingOdb::operator==(const RoamingOdb& rhs) const {
  return

      getValue() == rhs.getValue();
}

bool RoamingOdb::operator!=(const RoamingOdb& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const RoamingOdb& o) {
  j = nlohmann::json();
  to_json(j, o.m_value);
}

void from_json(const nlohmann::json& j, RoamingOdb& o) {
  from_json(j, o.m_value);
}

RoamingOdb_anyOf RoamingOdb::getValue() const {
  return m_value;
}

void RoamingOdb::setValue(RoamingOdb_anyOf value) {
  m_value = value;
}

RoamingOdb_anyOf::eRoamingOdb_anyOf RoamingOdb::getEnumValue() const {
  return m_value.getValue();
}

void RoamingOdb::setEnumValue(RoamingOdb_anyOf::eRoamingOdb_anyOf value) {
  m_value.setValue(value);
}

}  // namespace ngkore::model::common
