
#include "ReportIntervalNrMdt_anyOf.h"
#include "Helpers.h"
#include <stdexcept>
#include <sstream>

namespace ngkore::model::common {

ReportIntervalNrMdt_anyOf::ReportIntervalNrMdt_anyOf() {}

void ReportIntervalNrMdt_anyOf::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool ReportIntervalNrMdt_anyOf::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool ReportIntervalNrMdt_anyOf::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "ReportIntervalNrMdt_anyOf" : pathPrefix;

  if (m_value == ReportIntervalNrMdt_anyOf::eReportIntervalNrMdt_anyOf::
                     INVALID_VALUE_OPENAPI_GENERATED) {
    success = false;
    msg << _pathPrefix << ": has no value;";
  }

  return success;
}

bool ReportIntervalNrMdt_anyOf::operator==(
    const ReportIntervalNrMdt_anyOf& rhs) const {
  return getValue() == rhs.getValue()

      ;
}

bool ReportIntervalNrMdt_anyOf::operator!=(
    const ReportIntervalNrMdt_anyOf& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const ReportIntervalNrMdt_anyOf& o) {
  j = nlohmann::json();

  switch (o.getValue()) {
    case ReportIntervalNrMdt_anyOf::eReportIntervalNrMdt_anyOf::
        INVALID_VALUE_OPENAPI_GENERATED:
      j = "INVALID_VALUE_OPENAPI_GENERATED";
      break;
    case ReportIntervalNrMdt_anyOf::eReportIntervalNrMdt_anyOf::_120:
      j = "120";
      break;
    case ReportIntervalNrMdt_anyOf::eReportIntervalNrMdt_anyOf::_240:
      j = "240";
      break;
    case ReportIntervalNrMdt_anyOf::eReportIntervalNrMdt_anyOf::_480:
      j = "480";
      break;
    case ReportIntervalNrMdt_anyOf::eReportIntervalNrMdt_anyOf::_640:
      j = "640";
      break;
    case ReportIntervalNrMdt_anyOf::eReportIntervalNrMdt_anyOf::_1024:
      j = "1024";
      break;
    case ReportIntervalNrMdt_anyOf::eReportIntervalNrMdt_anyOf::_2048:
      j = "2048";
      break;
    case ReportIntervalNrMdt_anyOf::eReportIntervalNrMdt_anyOf::_5120:
      j = "5120";
      break;
    case ReportIntervalNrMdt_anyOf::eReportIntervalNrMdt_anyOf::_10240:
      j = "10240";
      break;
    case ReportIntervalNrMdt_anyOf::eReportIntervalNrMdt_anyOf::_20480:
      j = "20480";
      break;
    case ReportIntervalNrMdt_anyOf::eReportIntervalNrMdt_anyOf::_40960:
      j = "40960";
      break;
    case ReportIntervalNrMdt_anyOf::eReportIntervalNrMdt_anyOf::_60000:
      j = "60000";
      break;
    case ReportIntervalNrMdt_anyOf::eReportIntervalNrMdt_anyOf::_360000:
      j = "360000";
      break;
    case ReportIntervalNrMdt_anyOf::eReportIntervalNrMdt_anyOf::_720000:
      j = "720000";
      break;
    case ReportIntervalNrMdt_anyOf::eReportIntervalNrMdt_anyOf::_1800000:
      j = "1800000";
      break;
    case ReportIntervalNrMdt_anyOf::eReportIntervalNrMdt_anyOf::_3600000:
      j = "3600000";
      break;
  }
}

void from_json(const nlohmann::json& j, ReportIntervalNrMdt_anyOf& o) {
  auto s = j.get<std::string>();
  if (s == "120") {
    o.setValue(ReportIntervalNrMdt_anyOf::eReportIntervalNrMdt_anyOf::_120);
  } else if (s == "240") {
    o.setValue(ReportIntervalNrMdt_anyOf::eReportIntervalNrMdt_anyOf::_240);
  } else if (s == "480") {
    o.setValue(ReportIntervalNrMdt_anyOf::eReportIntervalNrMdt_anyOf::_480);
  } else if (s == "640") {
    o.setValue(ReportIntervalNrMdt_anyOf::eReportIntervalNrMdt_anyOf::_640);
  } else if (s == "1024") {
    o.setValue(ReportIntervalNrMdt_anyOf::eReportIntervalNrMdt_anyOf::_1024);
  } else if (s == "2048") {
    o.setValue(ReportIntervalNrMdt_anyOf::eReportIntervalNrMdt_anyOf::_2048);
  } else if (s == "5120") {
    o.setValue(ReportIntervalNrMdt_anyOf::eReportIntervalNrMdt_anyOf::_5120);
  } else if (s == "10240") {
    o.setValue(ReportIntervalNrMdt_anyOf::eReportIntervalNrMdt_anyOf::_10240);
  } else if (s == "20480") {
    o.setValue(ReportIntervalNrMdt_anyOf::eReportIntervalNrMdt_anyOf::_20480);
  } else if (s == "40960") {
    o.setValue(ReportIntervalNrMdt_anyOf::eReportIntervalNrMdt_anyOf::_40960);
  } else if (s == "60000") {
    o.setValue(ReportIntervalNrMdt_anyOf::eReportIntervalNrMdt_anyOf::_60000);
  } else if (s == "360000") {
    o.setValue(ReportIntervalNrMdt_anyOf::eReportIntervalNrMdt_anyOf::_360000);
  } else if (s == "720000") {
    o.setValue(ReportIntervalNrMdt_anyOf::eReportIntervalNrMdt_anyOf::_720000);
  } else if (s == "1800000") {
    o.setValue(ReportIntervalNrMdt_anyOf::eReportIntervalNrMdt_anyOf::_1800000);
  } else if (s == "3600000") {
    o.setValue(ReportIntervalNrMdt_anyOf::eReportIntervalNrMdt_anyOf::_3600000);
  } else {
    std::stringstream ss;
    ss << "Unexpected value " << s << " in json"
       << " cannot be converted to enum of type"
       << " ReportIntervalNrMdt_anyOf::eReportIntervalNrMdt_anyOf";
    throw std::invalid_argument(ss.str());
  }
}

ReportIntervalNrMdt_anyOf::eReportIntervalNrMdt_anyOf
ReportIntervalNrMdt_anyOf::getValue() const {
  return m_value;
}
void ReportIntervalNrMdt_anyOf::setValue(
    ReportIntervalNrMdt_anyOf::eReportIntervalNrMdt_anyOf value) {
  m_value = value;
}

}  // namespace ngkore::model::common
