
#include "WirelineArea.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

WirelineArea::WirelineArea() {
  m_GlobalLineIdsIsSet = false;
  m_HfcNIdsIsSet       = false;
  m_AreaCodeB          = "";
  m_AreaCodeBIsSet     = false;
  m_AreaCodeC          = "";
  m_AreaCodeCIsSet     = false;
}

void WirelineArea::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool WirelineArea::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool WirelineArea::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "WirelineArea" : pathPrefix;

  if (globalLineIdsIsSet()) {
    const std::vector<std::string>& value = m_GlobalLineIds;
    const std::string currentValuePath    = _pathPrefix + ".globalLineIds";

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

  if (hfcNIdsIsSet()) {
    const std::vector<std::string>& value = m_HfcNIds;
    const std::string currentValuePath    = _pathPrefix + ".hfcNIds";

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

        if (value.length() > 6) {
          success = false;
          msg << currentValuePath << ": must be at most 6 characters long;";
        }

        i++;
      }
    }
  }

  return success;
}

bool WirelineArea::operator==(const WirelineArea& rhs) const {
  return

      ((!globalLineIdsIsSet() && !rhs.globalLineIdsIsSet()) ||
       (globalLineIdsIsSet() && rhs.globalLineIdsIsSet() &&
        getGlobalLineIds() == rhs.getGlobalLineIds())) &&

      ((!hfcNIdsIsSet() && !rhs.hfcNIdsIsSet()) ||
       (hfcNIdsIsSet() && rhs.hfcNIdsIsSet() &&
        getHfcNIds() == rhs.getHfcNIds())) &&

      ((!areaCodeBIsSet() && !rhs.areaCodeBIsSet()) ||
       (areaCodeBIsSet() && rhs.areaCodeBIsSet() &&
        getAreaCodeB() == rhs.getAreaCodeB())) &&

      ((!areaCodeCIsSet() && !rhs.areaCodeCIsSet()) ||
       (areaCodeCIsSet() && rhs.areaCodeCIsSet() &&
        getAreaCodeC() == rhs.getAreaCodeC()))

          ;
}

bool WirelineArea::operator!=(const WirelineArea& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const WirelineArea& o) {
  j = nlohmann::json();
  if (o.globalLineIdsIsSet() || !o.m_GlobalLineIds.empty())
    j["globalLineIds"] = o.m_GlobalLineIds;
  if (o.hfcNIdsIsSet() || !o.m_HfcNIds.empty()) j["hfcNIds"] = o.m_HfcNIds;
  if (o.areaCodeBIsSet()) j["areaCodeB"] = o.m_AreaCodeB;
  if (o.areaCodeCIsSet()) j["areaCodeC"] = o.m_AreaCodeC;
}

void from_json(const nlohmann::json& j, WirelineArea& o) {
  if (j.find("globalLineIds") != j.end()) {
    j.at("globalLineIds").get_to(o.m_GlobalLineIds);
    o.m_GlobalLineIdsIsSet = true;
  }
  if (j.find("hfcNIds") != j.end()) {
    j.at("hfcNIds").get_to(o.m_HfcNIds);
    o.m_HfcNIdsIsSet = true;
  }
  if (j.find("areaCodeB") != j.end()) {
    j.at("areaCodeB").get_to(o.m_AreaCodeB);
    o.m_AreaCodeBIsSet = true;
  }
  if (j.find("areaCodeC") != j.end()) {
    j.at("areaCodeC").get_to(o.m_AreaCodeC);
    o.m_AreaCodeCIsSet = true;
  }
}

std::vector<std::string> WirelineArea::getGlobalLineIds() const {
  return m_GlobalLineIds;
}
void WirelineArea::setGlobalLineIds(std::vector<std::string> const& value) {
  m_GlobalLineIds      = value;
  m_GlobalLineIdsIsSet = true;
}
bool WirelineArea::globalLineIdsIsSet() const {
  return m_GlobalLineIdsIsSet;
}
void WirelineArea::unsetGlobalLineIds() {
  m_GlobalLineIdsIsSet = false;
}
std::vector<std::string> WirelineArea::getHfcNIds() const {
  return m_HfcNIds;
}
void WirelineArea::setHfcNIds(std::vector<std::string> const& value) {
  m_HfcNIds      = value;
  m_HfcNIdsIsSet = true;
}
bool WirelineArea::hfcNIdsIsSet() const {
  return m_HfcNIdsIsSet;
}
void WirelineArea::unsetHfcNIds() {
  m_HfcNIdsIsSet = false;
}
std::string WirelineArea::getAreaCodeB() const {
  return m_AreaCodeB;
}
void WirelineArea::setAreaCodeB(std::string const& value) {
  m_AreaCodeB      = value;
  m_AreaCodeBIsSet = true;
}
bool WirelineArea::areaCodeBIsSet() const {
  return m_AreaCodeBIsSet;
}
void WirelineArea::unsetAreaCodeB() {
  m_AreaCodeBIsSet = false;
}
std::string WirelineArea::getAreaCodeC() const {
  return m_AreaCodeC;
}
void WirelineArea::setAreaCodeC(std::string const& value) {
  m_AreaCodeC      = value;
  m_AreaCodeCIsSet = true;
}
bool WirelineArea::areaCodeCIsSet() const {
  return m_AreaCodeCIsSet;
}
void WirelineArea::unsetAreaCodeC() {
  m_AreaCodeCIsSet = false;
}

}  // namespace ngkore::model::common
