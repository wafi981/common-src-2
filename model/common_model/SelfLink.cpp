
#include "SelfLink.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

SelfLink::SelfLink() {}

void SelfLink::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool SelfLink::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool SelfLink::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success                  = true;
  const std::string _pathPrefix = pathPrefix.empty() ? "SelfLink" : pathPrefix;

  return success;
}

bool SelfLink::operator==(const SelfLink& rhs) const {
  return

      (getSelf() == rhs.getSelf())

          ;
}

bool SelfLink::operator!=(const SelfLink& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const SelfLink& o) {
  j         = nlohmann::json();
  j["self"] = o.m_Self;
}

void from_json(const nlohmann::json& j, SelfLink& o) {
  j.at("self").get_to(o.m_Self);
}

ngkore::model::common::Link SelfLink::getSelf() const {
  return m_Self;
}
void SelfLink::setSelf(ngkore::model::common::Link const& value) {
  m_Self = value;
}

}  // namespace ngkore::model::common
