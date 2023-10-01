
#include "RefToBinaryData.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

RefToBinaryData::RefToBinaryData() {
  m_ContentId = "";
}

void RefToBinaryData::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool RefToBinaryData::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool RefToBinaryData::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "RefToBinaryData" : pathPrefix;

  return success;
}

bool RefToBinaryData::operator==(const RefToBinaryData& rhs) const {
  return

      (getContentId() == rhs.getContentId())

          ;
}

bool RefToBinaryData::operator!=(const RefToBinaryData& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const RefToBinaryData& o) {
  j              = nlohmann::json();
  j["contentId"] = o.m_ContentId;
}

void from_json(const nlohmann::json& j, RefToBinaryData& o) {
  j.at("contentId").get_to(o.m_ContentId);
}

std::string RefToBinaryData::getContentId() const {
  return m_ContentId;
}
void RefToBinaryData::setContentId(std::string const& value) {
  m_ContentId = value;
}

}  // namespace ngkore::model::common
