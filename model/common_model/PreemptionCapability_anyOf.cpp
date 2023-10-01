
#include "PreemptionCapability_anyOf.h"
#include "Helpers.h"
#include <stdexcept>
#include <sstream>

namespace ngkore::model::common {

PreemptionCapability_anyOf::PreemptionCapability_anyOf() {}

void PreemptionCapability_anyOf::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool PreemptionCapability_anyOf::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool PreemptionCapability_anyOf::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "PreemptionCapability_anyOf" : pathPrefix;

  if (m_value == PreemptionCapability_anyOf::ePreemptionCapability_anyOf::
                     INVALID_VALUE_OPENAPI_GENERATED) {
    success = false;
    msg << _pathPrefix << ": has no value;";
  }

  return success;
}

bool PreemptionCapability_anyOf::operator==(
    const PreemptionCapability_anyOf& rhs) const {
  return getValue() == rhs.getValue()

      ;
}

bool PreemptionCapability_anyOf::operator!=(
    const PreemptionCapability_anyOf& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const PreemptionCapability_anyOf& o) {
  j = nlohmann::json();

  switch (o.getValue()) {
    case PreemptionCapability_anyOf::ePreemptionCapability_anyOf::
        INVALID_VALUE_OPENAPI_GENERATED:
      j = "INVALID_VALUE_OPENAPI_GENERATED";
      break;
    case PreemptionCapability_anyOf::ePreemptionCapability_anyOf::NOT_PREEMPT:
      j = "NOT_PREEMPT";
      break;
    case PreemptionCapability_anyOf::ePreemptionCapability_anyOf::MAY_PREEMPT:
      j = "MAY_PREEMPT";
      break;
  }
}

void from_json(const nlohmann::json& j, PreemptionCapability_anyOf& o) {
  auto s = j.get<std::string>();
  if (s == "NOT_PREEMPT") {
    o.setValue(
        PreemptionCapability_anyOf::ePreemptionCapability_anyOf::NOT_PREEMPT);
  } else if (s == "MAY_PREEMPT") {
    o.setValue(
        PreemptionCapability_anyOf::ePreemptionCapability_anyOf::MAY_PREEMPT);
  } else {
    std::stringstream ss;
    ss << "Unexpected value " << s << " in json"
       << " cannot be converted to enum of type"
       << " PreemptionCapability_anyOf::ePreemptionCapability_anyOf";
    throw std::invalid_argument(ss.str());
  }
}

PreemptionCapability_anyOf::ePreemptionCapability_anyOf
PreemptionCapability_anyOf::getValue() const {
  return m_value;
}
void PreemptionCapability_anyOf::setValue(
    PreemptionCapability_anyOf::ePreemptionCapability_anyOf value) {
  m_value = value;
}

}  // namespace ngkore::model::common
