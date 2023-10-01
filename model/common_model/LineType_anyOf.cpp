
#include "LineType_anyOf.h"
#include "Helpers.h"
#include <stdexcept>
#include <sstream>

namespace ngkore::model::common {

LineType_anyOf::LineType_anyOf() {}

void LineType_anyOf::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool LineType_anyOf::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool LineType_anyOf::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "LineType_anyOf" : pathPrefix;

  if (m_value ==
      LineType_anyOf::eLineType_anyOf::INVALID_VALUE_OPENAPI_GENERATED) {
    success = false;
    msg << _pathPrefix << ": has no value;";
  }

  return success;
}

bool LineType_anyOf::operator==(const LineType_anyOf& rhs) const {
  return getValue() == rhs.getValue()

      ;
}

bool LineType_anyOf::operator!=(const LineType_anyOf& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const LineType_anyOf& o) {
  j = nlohmann::json();

  switch (o.getValue()) {
    case LineType_anyOf::eLineType_anyOf::INVALID_VALUE_OPENAPI_GENERATED:
      j = "INVALID_VALUE_OPENAPI_GENERATED";
      break;
    case LineType_anyOf::eLineType_anyOf::DSL:
      j = "DSL";
      break;
    case LineType_anyOf::eLineType_anyOf::PON:
      j = "PON";
      break;
  }
}

void from_json(const nlohmann::json& j, LineType_anyOf& o) {
  auto s = j.get<std::string>();
  if (s == "DSL") {
    o.setValue(LineType_anyOf::eLineType_anyOf::DSL);
  } else if (s == "PON") {
    o.setValue(LineType_anyOf::eLineType_anyOf::PON);
  } else {
    std::stringstream ss;
    ss << "Unexpected value " << s << " in json"
       << " cannot be converted to enum of type"
       << " LineType_anyOf::eLineType_anyOf";
    throw std::invalid_argument(ss.str());
  }
}

LineType_anyOf::eLineType_anyOf LineType_anyOf::getValue() const {
  return m_value;
}
void LineType_anyOf::setValue(LineType_anyOf::eLineType_anyOf value) {
  m_value = value;
}

}  // namespace ngkore::model::common
