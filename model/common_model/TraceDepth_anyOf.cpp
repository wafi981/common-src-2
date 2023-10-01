
#include "TraceDepth_anyOf.h"
#include "Helpers.h"
#include <stdexcept>
#include <sstream>

namespace ngkore::model::common {

TraceDepth_anyOf::TraceDepth_anyOf() {}

void TraceDepth_anyOf::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool TraceDepth_anyOf::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool TraceDepth_anyOf::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "TraceDepth_anyOf" : pathPrefix;

  if (m_value ==
      TraceDepth_anyOf::eTraceDepth_anyOf::INVALID_VALUE_OPENAPI_GENERATED) {
    success = false;
    msg << _pathPrefix << ": has no value;";
  }

  return success;
}

bool TraceDepth_anyOf::operator==(const TraceDepth_anyOf& rhs) const {
  return getValue() == rhs.getValue()

      ;
}

bool TraceDepth_anyOf::operator!=(const TraceDepth_anyOf& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const TraceDepth_anyOf& o) {
  j = nlohmann::json();

  switch (o.getValue()) {
    case TraceDepth_anyOf::eTraceDepth_anyOf::INVALID_VALUE_OPENAPI_GENERATED:
      j = "INVALID_VALUE_OPENAPI_GENERATED";
      break;
    case TraceDepth_anyOf::eTraceDepth_anyOf::MINIMUM:
      j = "MINIMUM";
      break;
    case TraceDepth_anyOf::eTraceDepth_anyOf::MEDIUM:
      j = "MEDIUM";
      break;
    case TraceDepth_anyOf::eTraceDepth_anyOf::MAXIMUM:
      j = "MAXIMUM";
      break;
    case TraceDepth_anyOf::eTraceDepth_anyOf::MINIMUM_WO_VENDOR_EXTENSION:
      j = "MINIMUM_WO_VENDOR_EXTENSION";
      break;
    case TraceDepth_anyOf::eTraceDepth_anyOf::MEDIUM_WO_VENDOR_EXTENSION:
      j = "MEDIUM_WO_VENDOR_EXTENSION";
      break;
    case TraceDepth_anyOf::eTraceDepth_anyOf::MAXIMUM_WO_VENDOR_EXTENSION:
      j = "MAXIMUM_WO_VENDOR_EXTENSION";
      break;
  }
}

void from_json(const nlohmann::json& j, TraceDepth_anyOf& o) {
  auto s = j.get<std::string>();
  if (s == "MINIMUM") {
    o.setValue(TraceDepth_anyOf::eTraceDepth_anyOf::MINIMUM);
  } else if (s == "MEDIUM") {
    o.setValue(TraceDepth_anyOf::eTraceDepth_anyOf::MEDIUM);
  } else if (s == "MAXIMUM") {
    o.setValue(TraceDepth_anyOf::eTraceDepth_anyOf::MAXIMUM);
  } else if (s == "MINIMUM_WO_VENDOR_EXTENSION") {
    o.setValue(
        TraceDepth_anyOf::eTraceDepth_anyOf::MINIMUM_WO_VENDOR_EXTENSION);
  } else if (s == "MEDIUM_WO_VENDOR_EXTENSION") {
    o.setValue(TraceDepth_anyOf::eTraceDepth_anyOf::MEDIUM_WO_VENDOR_EXTENSION);
  } else if (s == "MAXIMUM_WO_VENDOR_EXTENSION") {
    o.setValue(
        TraceDepth_anyOf::eTraceDepth_anyOf::MAXIMUM_WO_VENDOR_EXTENSION);
  } else {
    std::stringstream ss;
    ss << "Unexpected value " << s << " in json"
       << " cannot be converted to enum of type"
       << " TraceDepth_anyOf::eTraceDepth_anyOf";
    throw std::invalid_argument(ss.str());
  }
}

TraceDepth_anyOf::eTraceDepth_anyOf TraceDepth_anyOf::getValue() const {
  return m_value;
}
void TraceDepth_anyOf::setValue(TraceDepth_anyOf::eTraceDepth_anyOf value) {
  m_value = value;
}

}  // namespace ngkore::model::common
