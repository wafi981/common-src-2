
#include "NssaaStatus.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

NssaaStatus::NssaaStatus() {}

void NssaaStatus::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool NssaaStatus::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool NssaaStatus::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "NssaaStatus" : pathPrefix;

  return success;
}

bool NssaaStatus::operator==(const NssaaStatus& rhs) const {
  return

      (getSnssai() == rhs.getSnssai()) &&

      (getStatus() == rhs.getStatus())

          ;
}

bool NssaaStatus::operator!=(const NssaaStatus& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const NssaaStatus& o) {
  j           = nlohmann::json();
  j["snssai"] = o.m_Snssai;
  j["status"] = o.m_Status;
}

void from_json(const nlohmann::json& j, NssaaStatus& o) {
  j.at("snssai").get_to(o.m_Snssai);
  j.at("status").get_to(o.m_Status);
}

ngkore::model::common::Snssai NssaaStatus::getSnssai() const {
  return m_Snssai;
}
void NssaaStatus::setSnssai(ngkore::model::common::Snssai const& value) {
  m_Snssai = value;
}
ngkore::model::common::AuthStatus NssaaStatus::getStatus() const {
  return m_Status;
}
void NssaaStatus::setStatus(ngkore::model::common::AuthStatus const& value) {
  m_Status = value;
}

}  // namespace ngkore::model::common
