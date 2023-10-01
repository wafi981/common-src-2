
#include "RatType_anyOf.h"
#include "Helpers.h"
#include <stdexcept>
#include <sstream>

namespace ngkore::model::common {

RatType_anyOf::RatType_anyOf() {}

void RatType_anyOf::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool RatType_anyOf::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool RatType_anyOf::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "RatType_anyOf" : pathPrefix;

  if (m_value ==
      RatType_anyOf::eRatType_anyOf::INVALID_VALUE_OPENAPI_GENERATED) {
    success = false;
    msg << _pathPrefix << ": has no value;";
  }

  return success;
}

bool RatType_anyOf::operator==(const RatType_anyOf& rhs) const {
  return getValue() == rhs.getValue()

      ;
}

bool RatType_anyOf::operator!=(const RatType_anyOf& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const RatType_anyOf& o) {
  j = nlohmann::json();

  switch (o.getValue()) {
    case RatType_anyOf::eRatType_anyOf::INVALID_VALUE_OPENAPI_GENERATED:
      j = "INVALID_VALUE_OPENAPI_GENERATED";
      break;
    case RatType_anyOf::eRatType_anyOf::NR:
      j = "NR";
      break;
    case RatType_anyOf::eRatType_anyOf::EUTRA:
      j = "EUTRA";
      break;
    case RatType_anyOf::eRatType_anyOf::WLAN:
      j = "WLAN";
      break;
    case RatType_anyOf::eRatType_anyOf::VIRTUAL:
      j = "VIRTUAL";
      break;
    case RatType_anyOf::eRatType_anyOf::NBIOT:
      j = "NBIOT";
      break;
    case RatType_anyOf::eRatType_anyOf::WIRELINE:
      j = "WIRELINE";
      break;
    case RatType_anyOf::eRatType_anyOf::WIRELINE_CABLE:
      j = "WIRELINE_CABLE";
      break;
    case RatType_anyOf::eRatType_anyOf::WIRELINE_BBF:
      j = "WIRELINE_BBF";
      break;
    case RatType_anyOf::eRatType_anyOf::LTE_M:
      j = "LTE-M";
      break;
    case RatType_anyOf::eRatType_anyOf::NR_U:
      j = "NR_U";
      break;
    case RatType_anyOf::eRatType_anyOf::EUTRA_U:
      j = "EUTRA_U";
      break;
    case RatType_anyOf::eRatType_anyOf::TRUSTED_N3GA:
      j = "TRUSTED_N3GA";
      break;
    case RatType_anyOf::eRatType_anyOf::TRUSTED_WLAN:
      j = "TRUSTED_WLAN";
      break;
    case RatType_anyOf::eRatType_anyOf::UTRA:
      j = "UTRA";
      break;
    case RatType_anyOf::eRatType_anyOf::GERA:
      j = "GERA";
      break;
  }
}

void from_json(const nlohmann::json& j, RatType_anyOf& o) {
  auto s = j.get<std::string>();
  if (s == "NR") {
    o.setValue(RatType_anyOf::eRatType_anyOf::NR);
  } else if (s == "EUTRA") {
    o.setValue(RatType_anyOf::eRatType_anyOf::EUTRA);
  } else if (s == "WLAN") {
    o.setValue(RatType_anyOf::eRatType_anyOf::WLAN);
  } else if (s == "VIRTUAL") {
    o.setValue(RatType_anyOf::eRatType_anyOf::VIRTUAL);
  } else if (s == "NBIOT") {
    o.setValue(RatType_anyOf::eRatType_anyOf::NBIOT);
  } else if (s == "WIRELINE") {
    o.setValue(RatType_anyOf::eRatType_anyOf::WIRELINE);
  } else if (s == "WIRELINE_CABLE") {
    o.setValue(RatType_anyOf::eRatType_anyOf::WIRELINE_CABLE);
  } else if (s == "WIRELINE_BBF") {
    o.setValue(RatType_anyOf::eRatType_anyOf::WIRELINE_BBF);
  } else if (s == "LTE-M") {
    o.setValue(RatType_anyOf::eRatType_anyOf::LTE_M);
  } else if (s == "NR_U") {
    o.setValue(RatType_anyOf::eRatType_anyOf::NR_U);
  } else if (s == "EUTRA_U") {
    o.setValue(RatType_anyOf::eRatType_anyOf::EUTRA_U);
  } else if (s == "TRUSTED_N3GA") {
    o.setValue(RatType_anyOf::eRatType_anyOf::TRUSTED_N3GA);
  } else if (s == "TRUSTED_WLAN") {
    o.setValue(RatType_anyOf::eRatType_anyOf::TRUSTED_WLAN);
  } else if (s == "UTRA") {
    o.setValue(RatType_anyOf::eRatType_anyOf::UTRA);
  } else if (s == "GERA") {
    o.setValue(RatType_anyOf::eRatType_anyOf::GERA);
  } else {
    std::stringstream ss;
    ss << "Unexpected value " << s << " in json"
       << " cannot be converted to enum of type"
       << " RatType_anyOf::eRatType_anyOf";
    throw std::invalid_argument(ss.str());
  }
}

RatType_anyOf::eRatType_anyOf RatType_anyOf::getValue() const {
  return m_value;
}
void RatType_anyOf::setValue(RatType_anyOf::eRatType_anyOf value) {
  m_value = value;
}

}  // namespace ngkore::model::common
