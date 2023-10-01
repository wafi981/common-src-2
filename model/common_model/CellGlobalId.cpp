
#include "CellGlobalId.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

CellGlobalId::CellGlobalId() {
  m_Lac    = "";
  m_CellId = "";
}

void CellGlobalId::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool CellGlobalId::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool CellGlobalId::validate(
  return success;
}

bool CellGlobalId::operator==(const CellGlobalId& rhs) const {
  return

      (getPlmnId() == rhs.getPlmnId()) &&

      (getLac() == rhs.getLac()) &&

      (getCellId() == rhs.getCellId())

          ;
}

bool CellGlobalId::operator!=(const CellGlobalId& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const CellGlobalId& o) {
  j           = nlohmann::json();
  j["plmnId"] = o.m_PlmnId;
  j["lac"]    = o.m_Lac;
  j["cellId"] = o.m_CellId;
}

void from_json(const nlohmann::json& j, CellGlobalId& o) {
  j.at("plmnId").get_to(o.m_PlmnId);
  j.at("lac").get_to(o.m_Lac);
  j.at("cellId").get_to(o.m_CellId);
}

ngkore::model::common::PlmnId CellGlobalId::getPlmnId() const {
  return m_PlmnId;
}
void CellGlobalId::setPlmnId(ngkore::model::common::PlmnId const& value) {
  m_PlmnId = value;
}
std::string CellGlobalId::getLac() const {
  return m_Lac;
}
void CellGlobalId::setLac(std::string const& value) {
  m_Lac = value;
}
std::string CellGlobalId::getCellId() const {
  return m_CellId;
}
void CellGlobalId::setCellId(std::string const& value) {
  m_CellId = value;
}

}  // namespace ngkore::model::common
