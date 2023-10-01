
#include "BackupAmfInfo.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

BackupAmfInfo::BackupAmfInfo() {
  m_BackupAmf      = "";
  m_GuamiListIsSet = false;
}

void BackupAmfInfo::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool BackupAmfInfo::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool BackupAmfInfo::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "BackupAmfInfo" : pathPrefix;

  if (guamiListIsSet()) {
    const std::vector<ngkore::model::common::Guami>& value = m_GuamiList;
    const std::string currentValuePath = _pathPrefix + ".guamiList";

    if (value.size() < 1) {
      success = false;
      msg << currentValuePath << ": must have at least 1 elements;";
    }
    {  // Recursive validation of array elements
      const std::string oldValuePath = currentValuePath;
      int i                          = 0;
      for (const ngkore::model::common::Guami& value : value) {
        const std::string currentValuePath =
            oldValuePath + "[" + std::to_string(i) + "]";

        success =
            value.validate(msg, currentValuePath + ".guamiList") && success;

        i++;
      }
    }
  }

  return success;
}

bool BackupAmfInfo::operator==(const BackupAmfInfo& rhs) const {
  return

      (getBackupAmf() == rhs.getBackupAmf()) &&

      ((!guamiListIsSet() && !rhs.guamiListIsSet()) ||
       (guamiListIsSet() && rhs.guamiListIsSet() &&
        getGuamiList() == rhs.getGuamiList()))

          ;
}

bool BackupAmfInfo::operator!=(const BackupAmfInfo& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const BackupAmfInfo& o) {
  j              = nlohmann::json();
  j["backupAmf"] = o.m_BackupAmf;
  if (o.guamiListIsSet() || !o.m_GuamiList.empty())
    j["guamiList"] = o.m_GuamiList;
}

void from_json(const nlohmann::json& j, BackupAmfInfo& o) {
  j.at("backupAmf").get_to(o.m_BackupAmf);
  if (j.find("guamiList") != j.end()) {
    j.at("guamiList").get_to(o.m_GuamiList);
    o.m_GuamiListIsSet = true;
  }
}

std::string BackupAmfInfo::getBackupAmf() const {
  return m_BackupAmf;
}
void BackupAmfInfo::setBackupAmf(std::string const& value) {
  m_BackupAmf = value;
}
std::vector<ngkore::model::common::Guami> BackupAmfInfo::getGuamiList() const {
  return m_GuamiList;
}
void BackupAmfInfo::setGuamiList(
    std::vector<ngkore::model::common::Guami> const& value) {
  m_GuamiList      = value;
  m_GuamiListIsSet = true;
}
bool BackupAmfInfo::guamiListIsSet() const {
  return m_GuamiListIsSet;
}
void BackupAmfInfo::unsetGuamiList() {
  m_GuamiListIsSet = false;
}

}  // namespace ngkore::model::common
