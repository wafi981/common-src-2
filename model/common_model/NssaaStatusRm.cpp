
#include "NssaaStatusRm.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

NssaaStatusRm::NssaaStatusRm() {}

void NssaaStatusRm::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool NssaaStatusRm::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool NssaaStatusRm::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "NssaaStatusRm" : pathPrefix;

  return success;
}

bool NssaaStatusRm::operator==(const NssaaStatusRm& rhs) const {
  return

      (getSnssai() == rhs.getSnssai()) &&

      (getStatus() == rhs.getStatus())

          ;
}

bool NssaaStatusRm::operator!=(const NssaaStatusRm& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const NssaaStatusRm& o) {
  j           = nlohmann::json();
  j["snssai"] = o.m_Snssai;
  j["status"] = o.m_Status;
}

void from_json(const nlohmann::json& j, NssaaStatusRm& o) {
  j.at("snssai").get_to(o.m_Snssai);
  j.at("status").get_to(o.m_Status);
}

ngkore::model::common::Snssai NssaaStatusRm::getSnssai() const {
  return m_Snssai;
}
void NssaaStatusRm::setSnssai(ngkore::model::common::Snssai const& value) {
  m_Snssai = value;
}
ngkore::model::common::AuthStatus NssaaStatusRm::getStatus() const {
  return m_Status;
}
void NssaaStatusRm::setStatus(ngkore::model::common::AuthStatus const& value) {
  m_Status = value;
}

}  // namespace ngkore::model::common
