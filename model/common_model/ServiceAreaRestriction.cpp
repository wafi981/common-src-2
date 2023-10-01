
#include "ServiceAreaRestriction.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

ServiceAreaRestriction::ServiceAreaRestriction() {
  m_RestrictionTypeIsSet               = false;
  m_AreasIsSet                         = false;
  m_MaxNumOfTAs                        = 0;
  m_MaxNumOfTAsIsSet                   = false;
  m_MaxNumOfTAsForNotAllowedAreas      = 0;
  m_MaxNumOfTAsForNotAllowedAreasIsSet = false;
}

void ServiceAreaRestriction::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool ServiceAreaRestriction::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool ServiceAreaRestriction::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "ServiceAreaRestriction" : pathPrefix;

  if (areasIsSet()) {
    const std::vector<ngkore::model::common::Area>& value = m_Areas;
    const std::string currentValuePath                 = _pathPrefix + ".areas";

    {  // Recursive validation of array elements
      const std::string oldValuePath = currentValuePath;
      int i                          = 0;
      for (const ngkore::model::common::Area& value : value) {
        const std::string currentValuePath =
            oldValuePath + "[" + std::to_string(i) + "]";

        success = value.validate(msg, currentValuePath + ".areas") && success;

        i++;
      }
    }
  }

  if (maxNumOfTAsIsSet()) {
    const int32_t& value               = m_MaxNumOfTAs;
    const std::string currentValuePath = _pathPrefix + ".maxNumOfTAs";

    if (value < 0) {
      success = false;
      msg << currentValuePath << ": must be greater than or equal to 0;";
    }
  }

  if (maxNumOfTAsForNotAllowedAreasIsSet()) {
    const int32_t& value = m_MaxNumOfTAsForNotAllowedAreas;
    const std::string currentValuePath =
        _pathPrefix + ".maxNumOfTAsForNotAllowedAreas";

    if (value < 0) {
      success = false;
      msg << currentValuePath << ": must be greater than or equal to 0;";
    }
  }

  return success;
}

bool ServiceAreaRestriction::operator==(
    const ServiceAreaRestriction& rhs) const {
  return

      ((!restrictionTypeIsSet() && !rhs.restrictionTypeIsSet()) ||
       (restrictionTypeIsSet() && rhs.restrictionTypeIsSet() &&
        getRestrictionType() == rhs.getRestrictionType())) &&

      ((!areasIsSet() && !rhs.areasIsSet()) ||
       (areasIsSet() && rhs.areasIsSet() && getAreas() == rhs.getAreas())) &&

      ((!maxNumOfTAsIsSet() && !rhs.maxNumOfTAsIsSet()) ||
       (maxNumOfTAsIsSet() && rhs.maxNumOfTAsIsSet() &&
        getMaxNumOfTAs() == rhs.getMaxNumOfTAs())) &&

      ((!maxNumOfTAsForNotAllowedAreasIsSet() &&
        !rhs.maxNumOfTAsForNotAllowedAreasIsSet()) ||
       (maxNumOfTAsForNotAllowedAreasIsSet() &&
        rhs.maxNumOfTAsForNotAllowedAreasIsSet() &&
        getMaxNumOfTAsForNotAllowedAreas() ==
            rhs.getMaxNumOfTAsForNotAllowedAreas()))

          ;
}

bool ServiceAreaRestriction::operator!=(
    const ServiceAreaRestriction& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const ServiceAreaRestriction& o) {
  j = nlohmann::json();
  if (o.restrictionTypeIsSet()) j["restrictionType"] = o.m_RestrictionType;
  if (o.areasIsSet() || !o.m_Areas.empty()) j["areas"] = o.m_Areas;
  if (o.maxNumOfTAsIsSet()) j["maxNumOfTAs"] = o.m_MaxNumOfTAs;
  if (o.maxNumOfTAsForNotAllowedAreasIsSet())
    j["maxNumOfTAsForNotAllowedAreas"] = o.m_MaxNumOfTAsForNotAllowedAreas;
}

void from_json(const nlohmann::json& j, ServiceAreaRestriction& o) {
  if (j.find("restrictionType") != j.end()) {
    j.at("restrictionType").get_to(o.m_RestrictionType);
    o.m_RestrictionTypeIsSet = true;
  }
  if (j.find("areas") != j.end()) {
    j.at("areas").get_to(o.m_Areas);
    o.m_AreasIsSet = true;
  }
  if (j.find("maxNumOfTAs") != j.end()) {
    j.at("maxNumOfTAs").get_to(o.m_MaxNumOfTAs);
    o.m_MaxNumOfTAsIsSet = true;
  }
  if (j.find("maxNumOfTAsForNotAllowedAreas") != j.end()) {
    j.at("maxNumOfTAsForNotAllowedAreas")
        .get_to(o.m_MaxNumOfTAsForNotAllowedAreas);
    o.m_MaxNumOfTAsForNotAllowedAreasIsSet = true;
  }
}

ngkore::model::common::RestrictionType ServiceAreaRestriction::getRestrictionType()
    const {
  return m_RestrictionType;
}
void ServiceAreaRestriction::setRestrictionType(
    ngkore::model::common::RestrictionType const& value) {
  m_RestrictionType      = value;
  m_RestrictionTypeIsSet = true;
}
bool ServiceAreaRestriction::restrictionTypeIsSet() const {
  return m_RestrictionTypeIsSet;
}
void ServiceAreaRestriction::unsetRestrictionType() {
  m_RestrictionTypeIsSet = false;
}
std::vector<ngkore::model::common::Area> ServiceAreaRestriction::getAreas() const {
  return m_Areas;
}
void ServiceAreaRestriction::setAreas(
    std::vector<ngkore::model::common::Area> const& value) {
  m_Areas      = value;
  m_AreasIsSet = true;
}
bool ServiceAreaRestriction::areasIsSet() const {
  return m_AreasIsSet;
}
void ServiceAreaRestriction::unsetAreas() {
  m_AreasIsSet = false;
}
int32_t ServiceAreaRestriction::getMaxNumOfTAs() const {
  return m_MaxNumOfTAs;
}
void ServiceAreaRestriction::setMaxNumOfTAs(int32_t const value) {
  m_MaxNumOfTAs      = value;
  m_MaxNumOfTAsIsSet = true;
}
bool ServiceAreaRestriction::maxNumOfTAsIsSet() const {
  return m_MaxNumOfTAsIsSet;
}
void ServiceAreaRestriction::unsetMaxNumOfTAs() {
  m_MaxNumOfTAsIsSet = false;
}
int32_t ServiceAreaRestriction::getMaxNumOfTAsForNotAllowedAreas() const {
  return m_MaxNumOfTAsForNotAllowedAreas;
}
void ServiceAreaRestriction::setMaxNumOfTAsForNotAllowedAreas(
    int32_t const value) {
  m_MaxNumOfTAsForNotAllowedAreas      = value;
  m_MaxNumOfTAsForNotAllowedAreasIsSet = true;
}
bool ServiceAreaRestriction::maxNumOfTAsForNotAllowedAreasIsSet() const {
  return m_MaxNumOfTAsForNotAllowedAreasIsSet;
}
void ServiceAreaRestriction::unsetMaxNumOfTAsForNotAllowedAreas() {
  m_MaxNumOfTAsForNotAllowedAreasIsSet = false;
}

}  // namespace ngkore::model::common
