
#include "AreaScope.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

AreaScope::AreaScope() {
  m_EutraCellIdListIsSet = false;
  m_NrCellIdListIsSet    = false;
  m_TacListIsSet         = false;
  m_TacInfoPerPlmnIsSet  = false;
}

void AreaScope::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool AreaScope::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool AreaScope::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success                  = true;
  const std::string _pathPrefix = pathPrefix.empty() ? "AreaScope" : pathPrefix;

  if (eutraCellIdListIsSet()) {
    const std::vector<std::string>& value = m_EutraCellIdList;
    const std::string currentValuePath    = _pathPrefix + ".eutraCellIdList";

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

  if (nrCellIdListIsSet()) {
    const std::vector<std::string>& value = m_NrCellIdList;
    const std::string currentValuePath    = _pathPrefix + ".nrCellIdList";

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

  if (tacListIsSet()) {
    const std::vector<std::string>& value = m_TacList;
    const std::string currentValuePath    = _pathPrefix + ".tacList";

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

bool AreaScope::operator==(const AreaScope& rhs) const {
  return

      ((!eutraCellIdListIsSet() && !rhs.eutraCellIdListIsSet()) ||
       (eutraCellIdListIsSet() && rhs.eutraCellIdListIsSet() &&
        getEutraCellIdList() == rhs.getEutraCellIdList())) &&

      ((!nrCellIdListIsSet() && !rhs.nrCellIdListIsSet()) ||
       (nrCellIdListIsSet() && rhs.nrCellIdListIsSet() &&
        getNrCellIdList() == rhs.getNrCellIdList())) &&

      ((!tacListIsSet() && !rhs.tacListIsSet()) ||
       (tacListIsSet() && rhs.tacListIsSet() &&
        getTacList() == rhs.getTacList())) &&

      ((!tacInfoPerPlmnIsSet() && !rhs.tacInfoPerPlmnIsSet()) ||
       (tacInfoPerPlmnIsSet() && rhs.tacInfoPerPlmnIsSet() &&
        getTacInfoPerPlmn() == rhs.getTacInfoPerPlmn()))

          ;
}

bool AreaScope::operator!=(const AreaScope& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const AreaScope& o) {
  j = nlohmann::json();
  if (o.eutraCellIdListIsSet() || !o.m_EutraCellIdList.empty())
    j["eutraCellIdList"] = o.m_EutraCellIdList;
  if (o.nrCellIdListIsSet() || !o.m_NrCellIdList.empty())
    j["nrCellIdList"] = o.m_NrCellIdList;
  if (o.tacListIsSet() || !o.m_TacList.empty()) j["tacList"] = o.m_TacList;
  if (o.tacInfoPerPlmnIsSet() || !o.m_TacInfoPerPlmn.empty())
    j["tacInfoPerPlmn"] = o.m_TacInfoPerPlmn;
}

void from_json(const nlohmann::json& j, AreaScope& o) {
  if (j.find("eutraCellIdList") != j.end()) {
    j.at("eutraCellIdList").get_to(o.m_EutraCellIdList);
    o.m_EutraCellIdListIsSet = true;
  }
  if (j.find("nrCellIdList") != j.end()) {
    j.at("nrCellIdList").get_to(o.m_NrCellIdList);
    o.m_NrCellIdListIsSet = true;
  }
  if (j.find("tacList") != j.end()) {
    j.at("tacList").get_to(o.m_TacList);
    o.m_TacListIsSet = true;
  }
  if (j.find("tacInfoPerPlmn") != j.end()) {
    j.at("tacInfoPerPlmn").get_to(o.m_TacInfoPerPlmn);
    o.m_TacInfoPerPlmnIsSet = true;
  }
}

std::vector<std::string> AreaScope::getEutraCellIdList() const {
  return m_EutraCellIdList;
}
void AreaScope::setEutraCellIdList(std::vector<std::string> const& value) {
  m_EutraCellIdList      = value;
  m_EutraCellIdListIsSet = true;
}
bool AreaScope::eutraCellIdListIsSet() const {
  return m_EutraCellIdListIsSet;
}
void AreaScope::unsetEutraCellIdList() {
  m_EutraCellIdListIsSet = false;
}
std::vector<std::string> AreaScope::getNrCellIdList() const {
  return m_NrCellIdList;
}
void AreaScope::setNrCellIdList(std::vector<std::string> const& value) {
  m_NrCellIdList      = value;
  m_NrCellIdListIsSet = true;
}
bool AreaScope::nrCellIdListIsSet() const {
  return m_NrCellIdListIsSet;
}
void AreaScope::unsetNrCellIdList() {
  m_NrCellIdListIsSet = false;
}
std::vector<std::string> AreaScope::getTacList() const {
  return m_TacList;
}
void AreaScope::setTacList(std::vector<std::string> const& value) {
  m_TacList      = value;
  m_TacListIsSet = true;
}
bool AreaScope::tacListIsSet() const {
  return m_TacListIsSet;
}
void AreaScope::unsetTacList() {
  m_TacListIsSet = false;
}
std::map<std::string, ngkore::model::common::TacInfo>
AreaScope::getTacInfoPerPlmn() const {
  return m_TacInfoPerPlmn;
}
void AreaScope::setTacInfoPerPlmn(
    std::map<std::string, ngkore::model::common::TacInfo> const& value) {
  m_TacInfoPerPlmn      = value;
  m_TacInfoPerPlmnIsSet = true;
}
bool AreaScope::tacInfoPerPlmnIsSet() const {
  return m_TacInfoPerPlmnIsSet;
}
void AreaScope::unsetTacInfoPerPlmn() {
  m_TacInfoPerPlmnIsSet = false;
}

}  // namespace ngkore::model::common
