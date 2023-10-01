
#include "ReportAmountMdt_anyOf.h"
#include "Helpers.h"
#include <stdexcept>
#include <sstream>

namespace ngkore::model::common {

ReportAmountMdt_anyOf::ReportAmountMdt_anyOf() {}

void ReportAmountMdt_anyOf::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool ReportAmountMdt_anyOf::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool ReportAmountMdt_anyOf::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "ReportAmountMdt_anyOf" : pathPrefix;

  if (m_value == ReportAmountMdt_anyOf::eReportAmountMdt_anyOf::
                     INVALID_VALUE_OPENAPI_GENERATED) {
    success = false;
    msg << _pathPrefix << ": has no value;";
  }

  return success;
}

bool ReportAmountMdt_anyOf::operator==(const ReportAmountMdt_anyOf& rhs) const {
  return getValue() == rhs.getValue()

      ;
}

bool ReportAmountMdt_anyOf::operator!=(const ReportAmountMdt_anyOf& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const ReportAmountMdt_anyOf& o) {
  j = nlohmann::json();

  switch (o.getValue()) {
    case ReportAmountMdt_anyOf::eReportAmountMdt_anyOf::
        INVALID_VALUE_OPENAPI_GENERATED:
      j = "INVALID_VALUE_OPENAPI_GENERATED";
      break;
    case ReportAmountMdt_anyOf::eReportAmountMdt_anyOf::_1:
      j = "1";
      break;
    case ReportAmountMdt_anyOf::eReportAmountMdt_anyOf::_2:
      j = "2";
      break;
    case ReportAmountMdt_anyOf::eReportAmountMdt_anyOf::_4:
      j = "4";
      break;
    case ReportAmountMdt_anyOf::eReportAmountMdt_anyOf::_8:
      j = "8";
      break;
    case ReportAmountMdt_anyOf::eReportAmountMdt_anyOf::_16:
      j = "16";
      break;
    case ReportAmountMdt_anyOf::eReportAmountMdt_anyOf::_32:
      j = "32";
      break;
    case ReportAmountMdt_anyOf::eReportAmountMdt_anyOf::_64:
      j = "64";
      break;
    case ReportAmountMdt_anyOf::eReportAmountMdt_anyOf::_INFINITY:
      j = "infinity";
      break;
  }
}

void from_json(const nlohmann::json& j, ReportAmountMdt_anyOf& o) {
  auto s = j.get<std::string>();
  if (s == "1") {
    o.setValue(ReportAmountMdt_anyOf::eReportAmountMdt_anyOf::_1);
  } else if (s == "2") {
    o.setValue(ReportAmountMdt_anyOf::eReportAmountMdt_anyOf::_2);
  } else if (s == "4") {
    o.setValue(ReportAmountMdt_anyOf::eReportAmountMdt_anyOf::_4);
  } else if (s == "8") {
    o.setValue(ReportAmountMdt_anyOf::eReportAmountMdt_anyOf::_8);
  } else if (s == "16") {
    o.setValue(ReportAmountMdt_anyOf::eReportAmountMdt_anyOf::_16);
  } else if (s == "32") {
    o.setValue(ReportAmountMdt_anyOf::eReportAmountMdt_anyOf::_32);
  } else if (s == "64") {
    o.setValue(ReportAmountMdt_anyOf::eReportAmountMdt_anyOf::_64);
  } else if (s == "infinity") {
    o.setValue(ReportAmountMdt_anyOf::eReportAmountMdt_anyOf::_INFINITY);
  } else {
    std::stringstream ss;
    ss << "Unexpected value " << s << " in json"
       << " cannot be converted to enum of type"
       << " ReportAmountMdt_anyOf::eReportAmountMdt_anyOf";
    throw std::invalid_argument(ss.str());
  }
}

ReportAmountMdt_anyOf::eReportAmountMdt_anyOf ReportAmountMdt_anyOf::getValue()
    const {
  return m_value;
}
void ReportAmountMdt_anyOf::setValue(
    ReportAmountMdt_anyOf::eReportAmountMdt_anyOf value) {
  m_value = value;
}

}  // namespace ngkore::model::common
