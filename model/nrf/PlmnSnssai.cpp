
#include "PlmnSnssai.h"

namespace ngkore::model::nrf {
using namespace ngkore::model::common;

PlmnSnssai::PlmnSnssai() {}

PlmnSnssai::~PlmnSnssai() {}

void PlmnSnssai::validate() {
  // TODO: implement validation
}

void to_json(nlohmann::json& j, const PlmnSnssai& o) {
  j               = nlohmann::json();
  j["plmnId"]     = o.m_PlmnId;
  j["sNssaiList"] = o.m_SNssaiList;
}

void from_json(const nlohmann::json& j, PlmnSnssai& o) {
  j.at("plmnId").get_to(o.m_PlmnId);
  j.at("sNssaiList").get_to(o.m_SNssaiList);
}

PlmnId PlmnSnssai::getPlmnId() const {
  return m_PlmnId;
}
void PlmnSnssai::setPlmnId(PlmnId const& value) {
  m_PlmnId = value;
}
std::vector<Snssai>& PlmnSnssai::getSNssaiList() {
  return m_SNssaiList;
}
void PlmnSnssai::setSNssaiList(std::vector<Snssai> const& value) {
  m_SNssaiList = value;
}

}  // namespace ngkore::model::nrf
