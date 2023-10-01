
#include "Guami.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

Guami::Guami() {
  m_AmfId = "";
}

void Guami::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool Guami::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool Guami::validate(
  return success;
}

bool Guami::operator==(const Guami& rhs) const {
  return

      (getPlmnId() == rhs.getPlmnId()) &&

      (getAmfId() == rhs.getAmfId())

          ;
}

bool Guami::operator!=(const Guami& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const Guami& o) {
  j           = nlohmann::json();
  j["plmnId"] = o.m_PlmnId;
  j["amfId"]  = o.m_AmfId;
}

void from_json(const nlohmann::json& j, Guami& o) {
  j.at("plmnId").get_to(o.m_PlmnId);
  j.at("amfId").get_to(o.m_AmfId);
}

ngkore::model::common::PlmnIdNid Guami::getPlmnId() const {
  return m_PlmnId;
}
void Guami::setPlmnId(ngkore::model::common::PlmnIdNid const& value) {
  m_PlmnId = value;
}
std::string Guami::getAmfId() const {
  return m_AmfId;
}
void Guami::setAmfId(std::string const& value) {
  m_AmfId = value;
}

}  // namespace ngkore::model::common
