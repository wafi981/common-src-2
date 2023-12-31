
#include "RoamingOdb_anyOf.h"
#include "Helpers.h"
#include <stdexcept>
#include <sstream>

namespace ngkore::model::common {

RoamingOdb_anyOf::RoamingOdb_anyOf() {}

void RoamingOdb_anyOf::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool RoamingOdb_anyOf::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool RoamingOdb_anyOf::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "RoamingOdb_anyOf" : pathPrefix;

  if (m_value ==
      RoamingOdb_anyOf::eRoamingOdb_anyOf::INVALID_VALUE_OPENAPI_GENERATED) {
    success = false;
    msg << _pathPrefix << ": has no value;";
  }

  return success;
}

bool RoamingOdb_anyOf::operator==(const RoamingOdb_anyOf& rhs) const {
  return getValue() == rhs.getValue()

      ;
}

bool RoamingOdb_anyOf::operator!=(const RoamingOdb_anyOf& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const RoamingOdb_anyOf& o) {
  j = nlohmann::json();

  switch (o.getValue()) {
    case RoamingOdb_anyOf::eRoamingOdb_anyOf::INVALID_VALUE_OPENAPI_GENERATED:
      j = "INVALID_VALUE_OPENAPI_GENERATED";
      break;
    case RoamingOdb_anyOf::eRoamingOdb_anyOf::PLMN:
      j = "OUTSIDE_HOME_PLMN";
      break;
    case RoamingOdb_anyOf::eRoamingOdb_anyOf::PLMN_COUNTRY:
      j = "OUTSIDE_HOME_PLMN_COUNTRY";
      break;
  }
}

void from_json(const nlohmann::json& j, RoamingOdb_anyOf& o) {
  auto s = j.get<std::string>();
  if (s == "OUTSIDE_HOME_PLMN") {
    o.setValue(RoamingOdb_anyOf::eRoamingOdb_anyOf::PLMN);
  } else if (s == "OUTSIDE_HOME_PLMN_COUNTRY") {
    o.setValue(RoamingOdb_anyOf::eRoamingOdb_anyOf::PLMN_COUNTRY);
  } else {
    std::stringstream ss;
    ss << "Unexpected value " << s << " in json"
       << " cannot be converted to enum of type"
       << " RoamingOdb_anyOf::eRoamingOdb_anyOf";
    throw std::invalid_argument(ss.str());
  }
}

RoamingOdb_anyOf::eRoamingOdb_anyOf RoamingOdb_anyOf::getValue() const {
  return m_value;
}
void RoamingOdb_anyOf::setValue(RoamingOdb_anyOf::eRoamingOdb_anyOf value) {
  m_value = value;
}

}  // namespace ngkore::model::common
