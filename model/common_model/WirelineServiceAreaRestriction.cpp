
#include "WirelineServiceAreaRestriction.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

WirelineServiceAreaRestriction::WirelineServiceAreaRestriction() {
  m_RestrictionTypeIsSet = false;
  m_AreasIsSet           = false;
}

void WirelineServiceAreaRestriction::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool WirelineServiceAreaRestriction::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool WirelineServiceAreaRestriction::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "WirelineServiceAreaRestriction" : pathPrefix;

  if (areasIsSet()) {
    const std::vector<ngkore::model::common::WirelineArea>& value = m_Areas;
    const std::string currentValuePath = _pathPrefix + ".areas";

    {  // Recursive validation of array elements
      const std::string oldValuePath = currentValuePath;
      int i                          = 0;
      for (const ngkore::model::common::WirelineArea& value : value) {
        const std::string currentValuePath =
            oldValuePath + "[" + std::to_string(i) + "]";

        success = value.validate(msg, currentValuePath + ".areas") && success;

        i++;
      }
    }
  }

  return success;
}

bool WirelineServiceAreaRestriction::operator==(
    const WirelineServiceAreaRestriction& rhs) const {
  return

      ((!restrictionTypeIsSet() && !rhs.restrictionTypeIsSet()) ||
       (restrictionTypeIsSet() && rhs.restrictionTypeIsSet() &&
        getRestrictionType() == rhs.getRestrictionType())) &&

      ((!areasIsSet() && !rhs.areasIsSet()) ||
       (areasIsSet() && rhs.areasIsSet() && getAreas() == rhs.getAreas()))

          ;
}

bool WirelineServiceAreaRestriction::operator!=(
    const WirelineServiceAreaRestriction& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const WirelineServiceAreaRestriction& o) {
  j = nlohmann::json();
  if (o.restrictionTypeIsSet()) j["restrictionType"] = o.m_RestrictionType;
  if (o.areasIsSet() || !o.m_Areas.empty()) j["areas"] = o.m_Areas;
}

void from_json(const nlohmann::json& j, WirelineServiceAreaRestriction& o) {
  if (j.find("restrictionType") != j.end()) {
    j.at("restrictionType").get_to(o.m_RestrictionType);
    o.m_RestrictionTypeIsSet = true;
  }
  if (j.find("areas") != j.end()) {
    j.at("areas").get_to(o.m_Areas);
    o.m_AreasIsSet = true;
  }
}

ngkore::model::common::RestrictionType
WirelineServiceAreaRestriction::getRestrictionType() const {
  return m_RestrictionType;
}
void WirelineServiceAreaRestriction::setRestrictionType(
    ngkore::model::common::RestrictionType const& value) {
  m_RestrictionType      = value;
  m_RestrictionTypeIsSet = true;
}
bool WirelineServiceAreaRestriction::restrictionTypeIsSet() const {
  return m_RestrictionTypeIsSet;
}
void WirelineServiceAreaRestriction::unsetRestrictionType() {
  m_RestrictionTypeIsSet = false;
}
std::vector<ngkore::model::common::WirelineArea>
WirelineServiceAreaRestriction::getAreas() const {
  return m_Areas;
}
void WirelineServiceAreaRestriction::setAreas(
    std::vector<ngkore::model::common::WirelineArea> const& value) {
  m_Areas      = value;
  m_AreasIsSet = true;
}
bool WirelineServiceAreaRestriction::areasIsSet() const {
  return m_AreasIsSet;
}
void WirelineServiceAreaRestriction::unsetAreas() {
  m_AreasIsSet = false;
}

}  // namespace ngkore::model::common
