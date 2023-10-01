
#include "LinkRm.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

LinkRm::LinkRm() {
  m_Href      = "";
  m_HrefIsSet = false;
}

void LinkRm::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool LinkRm::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool LinkRm::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success                  = true;
  const std::string _pathPrefix = pathPrefix.empty() ? "LinkRm" : pathPrefix;

  return success;
}

bool LinkRm::operator==(const LinkRm& rhs) const {
  return

      ((!hrefIsSet() && !rhs.hrefIsSet()) ||
       (hrefIsSet() && rhs.hrefIsSet() && getHref() == rhs.getHref()))

          ;
}

bool LinkRm::operator!=(const LinkRm& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const LinkRm& o) {
  j = nlohmann::json();
  if (o.hrefIsSet()) j["href"] = o.m_Href;
}

void from_json(const nlohmann::json& j, LinkRm& o) {
  if (j.find("href") != j.end()) {
    j.at("href").get_to(o.m_Href);
    o.m_HrefIsSet = true;
  }
}

std::string LinkRm::getHref() const {
  return m_Href;
}
void LinkRm::setHref(std::string const& value) {
  m_Href      = value;
  m_HrefIsSet = true;
}
bool LinkRm::hrefIsSet() const {
  return m_HrefIsSet;
}
void LinkRm::unsetHref() {
  m_HrefIsSet = false;
}

}  // namespace ngkore::model::common
