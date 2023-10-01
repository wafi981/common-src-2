
#include "LinksValueSchema.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

LinksValueSchema::LinksValueSchema() {
  m_Href      = "";
  m_HrefIsSet = false;
}

void LinksValueSchema::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool LinksValueSchema::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool LinksValueSchema::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "LinksValueSchema" : pathPrefix;

  return success;
}

bool LinksValueSchema::operator==(const LinksValueSchema& rhs) const {
  return

      ((!hrefIsSet() && !rhs.hrefIsSet()) ||
       (hrefIsSet() && rhs.hrefIsSet() && getHref() == rhs.getHref()))

          ;
}

bool LinksValueSchema::operator!=(const LinksValueSchema& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const LinksValueSchema& o) {
  j = nlohmann::json();
  if (o.hrefIsSet()) j["href"] = o.m_Href;
}

void from_json(const nlohmann::json& j, LinksValueSchema& o) {
  if (j.find("href") != j.end()) {
    j.at("href").get_to(o.m_Href);
    o.m_HrefIsSet = true;
  }
}

std::string LinksValueSchema::getHref() const {
  return m_Href;
}
void LinksValueSchema::setHref(std::string const& value) {
  m_Href      = value;
  m_HrefIsSet = true;
}
bool LinksValueSchema::hrefIsSet() const {
  return m_HrefIsSet;
}
void LinksValueSchema::unsetHref() {
  m_HrefIsSet = false;
}

}  // namespace ngkore::model::common
