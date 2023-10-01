
#include "Link.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

Link::Link() {
  m_Href      = "";
  m_HrefIsSet = false;
}

void Link::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool Link::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool Link::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success                  = true;
  const std::string _pathPrefix = pathPrefix.empty() ? "Link" : pathPrefix;

  return success;
}

bool Link::operator==(const Link& rhs) const {
  return

      ((!hrefIsSet() && !rhs.hrefIsSet()) ||
       (hrefIsSet() && rhs.hrefIsSet() && getHref() == rhs.getHref()))

          ;
}

bool Link::operator!=(const Link& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const Link& o) {
  j = nlohmann::json();
  if (o.hrefIsSet()) j["href"] = o.m_Href;
}

void from_json(const nlohmann::json& j, Link& o) {
  if (j.find("href") != j.end()) {
    j.at("href").get_to(o.m_Href);
    o.m_HrefIsSet = true;
  }
}

std::string Link::getHref() const {
  return m_Href;
}
void Link::setHref(std::string const& value) {
  m_Href      = value;
  m_HrefIsSet = true;
}
bool Link::hrefIsSet() const {
  return m_HrefIsSet;
}
void Link::unsetHref() {
  m_HrefIsSet = false;
}

}  // namespace ngkore::model::common
