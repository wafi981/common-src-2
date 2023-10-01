
#include "ComplexQuery.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

ComplexQuery::ComplexQuery() {}

void ComplexQuery::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool ComplexQuery::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool ComplexQuery::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "ComplexQuery" : pathPrefix;

    const std::vector<ngkore::model::common::DnfUnit>& value = m_DnfUnits;
    const std::string currentValuePath = _pathPrefix + ".dnfUnits";

    if (value.size() < 1) {
      success = false;
      msg << currentValuePath << ": must have at least 1 elements;";
    }
    {  // Recursive validation of array elements
      const std::string oldValuePath = currentValuePath;
      int i                          = 0;
      for (const ngkore::model::common::DnfUnit& value : value) {
        const std::string currentValuePath =
            oldValuePath + "[" + std::to_string(i) + "]";

        success =
            value.validate(msg, currentValuePath + ".dnfUnits") && success;

        i++;
      }
    }
  }

  return success;
}

bool ComplexQuery::operator==(const ComplexQuery& rhs) const {
  return

      (getCnfUnits() == rhs.getCnfUnits()) &&

      (getDnfUnits() == rhs.getDnfUnits())

          ;
}

bool ComplexQuery::operator!=(const ComplexQuery& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const ComplexQuery& o) {
  j             = nlohmann::json();
  j["cnfUnits"] = o.m_CnfUnits;
  j["dnfUnits"] = o.m_DnfUnits;
}

void from_json(const nlohmann::json& j, ComplexQuery& o) {
  j.at("cnfUnits").get_to(o.m_CnfUnits);
  j.at("dnfUnits").get_to(o.m_DnfUnits);
}

std::vector<ngkore::model::common::CnfUnit> ComplexQuery::getCnfUnits() const {
  return m_CnfUnits;
}
void ComplexQuery::setCnfUnits(
    std::vector<ngkore::model::common::CnfUnit> const& value) {
  m_CnfUnits = value;
}
std::vector<ngkore::model::common::DnfUnit> ComplexQuery::getDnfUnits() const {
  return m_DnfUnits;
}
void ComplexQuery::setDnfUnits(
    std::vector<ngkore::model::common::DnfUnit> const& value) {
  m_DnfUnits = value;
}

}  // namespace ngkore::model::common
