
#include "MeasurementLteForMdt_anyOf.h"
#include "Helpers.h"
#include <stdexcept>
#include <sstream>

namespace ngkore::model::common {

MeasurementLteForMdt_anyOf::MeasurementLteForMdt_anyOf() {}

void MeasurementLteForMdt_anyOf::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool MeasurementLteForMdt_anyOf::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool MeasurementLteForMdt_anyOf::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "MeasurementLteForMdt_anyOf" : pathPrefix;

  if (m_value == MeasurementLteForMdt_anyOf::eMeasurementLteForMdt_anyOf::
                     INVALID_VALUE_OPENAPI_GENERATED) {
    success = false;
    msg << _pathPrefix << ": has no value;";
  }

  return success;
}

bool MeasurementLteForMdt_anyOf::operator==(
    const MeasurementLteForMdt_anyOf& rhs) const {
  return getValue() == rhs.getValue()

      ;
}

bool MeasurementLteForMdt_anyOf::operator!=(
    const MeasurementLteForMdt_anyOf& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const MeasurementLteForMdt_anyOf& o) {
  j = nlohmann::json();

  switch (o.getValue()) {
    case MeasurementLteForMdt_anyOf::eMeasurementLteForMdt_anyOf::
        INVALID_VALUE_OPENAPI_GENERATED:
      j = "INVALID_VALUE_OPENAPI_GENERATED";
      break;
    case MeasurementLteForMdt_anyOf::eMeasurementLteForMdt_anyOf::M1:
      j = "M1";
      break;
    case MeasurementLteForMdt_anyOf::eMeasurementLteForMdt_anyOf::M2:
      j = "M2";
      break;
    case MeasurementLteForMdt_anyOf::eMeasurementLteForMdt_anyOf::M3:
      j = "M3";
      break;
    case MeasurementLteForMdt_anyOf::eMeasurementLteForMdt_anyOf::M4_DL:
      j = "M4_DL";
      break;
    case MeasurementLteForMdt_anyOf::eMeasurementLteForMdt_anyOf::M4_UL:
      j = "M4_UL";
      break;
    case MeasurementLteForMdt_anyOf::eMeasurementLteForMdt_anyOf::M5_DL:
      j = "M5_DL";
      break;
    case MeasurementLteForMdt_anyOf::eMeasurementLteForMdt_anyOf::M5_UL:
      j = "M5_UL";
      break;
    case MeasurementLteForMdt_anyOf::eMeasurementLteForMdt_anyOf::M6_DL:
      j = "M6_DL";
      break;
    case MeasurementLteForMdt_anyOf::eMeasurementLteForMdt_anyOf::M6_UL:
      j = "M6_UL";
      break;
    case MeasurementLteForMdt_anyOf::eMeasurementLteForMdt_anyOf::M7_DL:
      j = "M7_DL";
      break;
    case MeasurementLteForMdt_anyOf::eMeasurementLteForMdt_anyOf::M7_UL:
      j = "M7_UL";
      break;
    case MeasurementLteForMdt_anyOf::eMeasurementLteForMdt_anyOf::M8:
      j = "M8";
      break;
    case MeasurementLteForMdt_anyOf::eMeasurementLteForMdt_anyOf::M9:
      j = "M9";
      break;
  }
}

void from_json(const nlohmann::json& j, MeasurementLteForMdt_anyOf& o) {
  auto s = j.get<std::string>();
  if (s == "M1") {
    o.setValue(MeasurementLteForMdt_anyOf::eMeasurementLteForMdt_anyOf::M1);
  } else if (s == "M2") {
    o.setValue(MeasurementLteForMdt_anyOf::eMeasurementLteForMdt_anyOf::M2);
  } else if (s == "M3") {
    o.setValue(MeasurementLteForMdt_anyOf::eMeasurementLteForMdt_anyOf::M3);
  } else if (s == "M4_DL") {
    o.setValue(MeasurementLteForMdt_anyOf::eMeasurementLteForMdt_anyOf::M4_DL);
  } else if (s == "M4_UL") {
    o.setValue(MeasurementLteForMdt_anyOf::eMeasurementLteForMdt_anyOf::M4_UL);
  } else if (s == "M5_DL") {
    o.setValue(MeasurementLteForMdt_anyOf::eMeasurementLteForMdt_anyOf::M5_DL);
  } else if (s == "M5_UL") {
    o.setValue(MeasurementLteForMdt_anyOf::eMeasurementLteForMdt_anyOf::M5_UL);
  } else if (s == "M6_DL") {
    o.setValue(MeasurementLteForMdt_anyOf::eMeasurementLteForMdt_anyOf::M6_DL);
  } else if (s == "M6_UL") {
    o.setValue(MeasurementLteForMdt_anyOf::eMeasurementLteForMdt_anyOf::M6_UL);
  } else if (s == "M7_DL") {
    o.setValue(MeasurementLteForMdt_anyOf::eMeasurementLteForMdt_anyOf::M7_DL);
  } else if (s == "M7_UL") {
    o.setValue(MeasurementLteForMdt_anyOf::eMeasurementLteForMdt_anyOf::M7_UL);
  } else if (s == "M8") {
    o.setValue(MeasurementLteForMdt_anyOf::eMeasurementLteForMdt_anyOf::M8);
  } else if (s == "M9") {
    o.setValue(MeasurementLteForMdt_anyOf::eMeasurementLteForMdt_anyOf::M9);
  } else {
    std::stringstream ss;
    ss << "Unexpected value " << s << " in json"
       << " cannot be converted to enum of type"
       << " MeasurementLteForMdt_anyOf::eMeasurementLteForMdt_anyOf";
    throw std::invalid_argument(ss.str());
  }
}

MeasurementLteForMdt_anyOf::eMeasurementLteForMdt_anyOf
MeasurementLteForMdt_anyOf::getValue() const {
  return m_value;
}
void MeasurementLteForMdt_anyOf::setValue(
    MeasurementLteForMdt_anyOf::eMeasurementLteForMdt_anyOf value) {
  m_value = value;
}

}  // namespace ngkore::model::common
