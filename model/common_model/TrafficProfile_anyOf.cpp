
#include "TrafficProfile_anyOf.h"
#include "Helpers.h"
#include <stdexcept>
#include <sstream>

namespace ngkore::model::common {

TrafficProfile_anyOf::TrafficProfile_anyOf() {}

void TrafficProfile_anyOf::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool TrafficProfile_anyOf::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool TrafficProfile_anyOf::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "TrafficProfile_anyOf" : pathPrefix;

  if (m_value == TrafficProfile_anyOf::eTrafficProfile_anyOf::
                     INVALID_VALUE_OPENAPI_GENERATED) {
    success = false;
    msg << _pathPrefix << ": has no value;";
  }

  return success;
}

bool TrafficProfile_anyOf::operator==(const TrafficProfile_anyOf& rhs) const {
  return getValue() == rhs.getValue()

      ;
}

bool TrafficProfile_anyOf::operator!=(const TrafficProfile_anyOf& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const TrafficProfile_anyOf& o) {
  j = nlohmann::json();

  switch (o.getValue()) {
    case TrafficProfile_anyOf::eTrafficProfile_anyOf::
        INVALID_VALUE_OPENAPI_GENERATED:
      j = "INVALID_VALUE_OPENAPI_GENERATED";
      break;
    case TrafficProfile_anyOf::eTrafficProfile_anyOf::SINGLE_TRANS_UL:
      j = "SINGLE_TRANS_UL";
      break;
    case TrafficProfile_anyOf::eTrafficProfile_anyOf::SINGLE_TRANS_DL:
      j = "SINGLE_TRANS_DL";
      break;
    case TrafficProfile_anyOf::eTrafficProfile_anyOf::DUAL_TRANS_UL_FIRST:
      j = "DUAL_TRANS_UL_FIRST";
      break;
    case TrafficProfile_anyOf::eTrafficProfile_anyOf::DUAL_TRANS_DL_FIRST:
      j = "DUAL_TRANS_DL_FIRST";
      break;
    case TrafficProfile_anyOf::eTrafficProfile_anyOf::MULTI_TRANS:
      j = "MULTI_TRANS";
      break;
  }
}

void from_json(const nlohmann::json& j, TrafficProfile_anyOf& o) {
  auto s = j.get<std::string>();
  if (s == "SINGLE_TRANS_UL") {
    o.setValue(TrafficProfile_anyOf::eTrafficProfile_anyOf::SINGLE_TRANS_UL);
  } else if (s == "SINGLE_TRANS_DL") {
    o.setValue(TrafficProfile_anyOf::eTrafficProfile_anyOf::SINGLE_TRANS_DL);
  } else if (s == "DUAL_TRANS_UL_FIRST") {
    o.setValue(
        TrafficProfile_anyOf::eTrafficProfile_anyOf::DUAL_TRANS_UL_FIRST);
  } else if (s == "DUAL_TRANS_DL_FIRST") {
    o.setValue(
        TrafficProfile_anyOf::eTrafficProfile_anyOf::DUAL_TRANS_DL_FIRST);
  } else if (s == "MULTI_TRANS") {
    o.setValue(TrafficProfile_anyOf::eTrafficProfile_anyOf::MULTI_TRANS);
  } else {
    std::stringstream ss;
    ss << "Unexpected value " << s << " in json"
       << " cannot be converted to enum of type"
       << " TrafficProfile_anyOf::eTrafficProfile_anyOf";
    throw std::invalid_argument(ss.str());
  }
}

TrafficProfile_anyOf::eTrafficProfile_anyOf TrafficProfile_anyOf::getValue()
    const {
  return m_value;
}
void TrafficProfile_anyOf::setValue(
    TrafficProfile_anyOf::eTrafficProfile_anyOf value) {
  m_value = value;
}

}  // namespace ngkore::model::common
