
#include "Area.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

Area::Area() {
  m_TacsIsSet     = false;
  m_AreaCode      = "";
  m_AreaCodeIsSet = false;
}

void Area::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool Area::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool Area::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success                  = true;
  const std::string _pathPrefix = pathPrefix.empty() ? "Area" : pathPrefix;

  if (tacsIsSet()) {
    const std::vector<std::string>& value = m_Tacs;
    const std::string currentValuePath    = _pathPrefix + ".tacs";

    if (value.size() < 1) {
      success = false;
      msg << currentValuePath << ": must have at least 1 elements;";
    }
    {  // Recursive validation of array elements
      const std::string oldValuePath = currentValuePath;
      int i                          = 0;
      for (const std::string& value : value) {
        const std::string currentValuePath =
            oldValuePath + "[" + std::to_string(i) + "]";

        i++;
      }
    }
  }

  return success;
}

bool Area::operator==(const Area& rhs) const {
  return

      ((!tacsIsSet() && !rhs.tacsIsSet()) ||
       (tacsIsSet() && rhs.tacsIsSet() && getTacs() == rhs.getTacs())) &&

      ((!areaCodeIsSet() && !rhs.areaCodeIsSet()) ||
       (areaCodeIsSet() && rhs.areaCodeIsSet() &&
        getAreaCode() == rhs.getAreaCode()))

          ;
}

bool Area::operator!=(const Area& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const Area& o) {
  j = nlohmann::json();
  if (o.tacsIsSet() || !o.m_Tacs.empty()) j["tacs"] = o.m_Tacs;
  if (o.areaCodeIsSet()) j["areaCode"] = o.m_AreaCode;
}

void from_json(const nlohmann::json& j, Area& o) {
  if (j.find("tacs") != j.end()) {
    j.at("tacs").get_to(o.m_Tacs);
    o.m_TacsIsSet = true;
  }
  if (j.find("areaCode") != j.end()) {
    j.at("areaCode").get_to(o.m_AreaCode);
    o.m_AreaCodeIsSet = true;
  }
}

std::vector<std::string> Area::getTacs() const {
  return m_Tacs;
}
void Area::setTacs(std::vector<std::string> const& value) {
  m_Tacs      = value;
  m_TacsIsSet = true;
}
bool Area::tacsIsSet() const {
  return m_TacsIsSet;
}
void Area::unsetTacs() {
  m_TacsIsSet = false;
}
std::string Area::getAreaCode() const {
  return m_AreaCode;
}
void Area::setAreaCode(std::string const& value) {
  m_AreaCode      = value;
  m_AreaCodeIsSet = true;
}
bool Area::areaCodeIsSet() const {
  return m_AreaCodeIsSet;
}
void Area::unsetAreaCode() {
  m_AreaCodeIsSet = false;
}

}  // namespace ngkore::model::common
