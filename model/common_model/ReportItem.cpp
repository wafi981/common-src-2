
#include "ReportItem.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

ReportItem::ReportItem() {
  m_Path = "";
}

void ReportItem::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool ReportItem::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool ReportItem::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "ReportItem" : pathPrefix;

  return success;
}

bool ReportItem::operator==(const ReportItem& rhs) const {
  return

      (getPath() == rhs.getPath())

          ;
}

bool ReportItem::operator!=(const ReportItem& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const ReportItem& o) {
  j         = nlohmann::json();
  j["path"] = o.m_Path;
}

void from_json(const nlohmann::json& j, ReportItem& o) {
  j.at("path").get_to(o.m_Path);
}

std::string ReportItem::getPath() const {
  return m_Path;
}
void ReportItem::setPath(std::string const& value) {
  m_Path = value;
}

}  // namespace ngkore::model::common
