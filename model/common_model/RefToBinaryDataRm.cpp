
#include "RefToBinaryDataRm.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

RefToBinaryDataRm::RefToBinaryDataRm() {
  m_ContentId = "";
}

void RefToBinaryDataRm::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool RefToBinaryDataRm::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool RefToBinaryDataRm::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "RefToBinaryDataRm" : pathPrefix;

  return success;
}

bool RefToBinaryDataRm::operator==(const RefToBinaryDataRm& rhs) const {
  return

      (getContentId() == rhs.getContentId())

          ;
}

bool RefToBinaryDataRm::operator!=(const RefToBinaryDataRm& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const RefToBinaryDataRm& o) {
  j              = nlohmann::json();
  j["contentId"] = o.m_ContentId;
}

void from_json(const nlohmann::json& j, RefToBinaryDataRm& o) {
  j.at("contentId").get_to(o.m_ContentId);
}

std::string RefToBinaryDataRm::getContentId() const {
  return m_ContentId;
}
void RefToBinaryDataRm::setContentId(std::string const& value) {
  m_ContentId = value;
}

}  // namespace ngkore::model::common
