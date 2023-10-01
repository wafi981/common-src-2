
#include "AccessTokenReq.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

AccessTokenReq::AccessTokenReq() {
  m_Grant_type                = "";
  m_NfInstanceId              = "";
  m_NfTypeIsSet               = false;
  m_TargetNfTypeIsSet         = false;
  m_Scope                     = "";
  m_TargetNfInstanceId        = "";
  m_TargetNfInstanceIdIsSet   = false;
  m_RequesterPlmnIsSet        = false;
  m_RequesterPlmnListIsSet    = false;
  m_RequesterSnssaiListIsSet  = false;
  m_RequesterFqdn             = "";
  m_RequesterFqdnIsSet        = false;
  m_RequesterSnpnListIsSet    = false;
  m_TargetPlmnIsSet           = false;
  m_TargetSnssaiListIsSet     = false;
  m_TargetNsiListIsSet        = false;
  m_TargetNfSetId             = "";
  m_TargetNfSetIdIsSet        = false;
  m_TargetNfServiceSetId      = "";
  m_TargetNfServiceSetIdIsSet = false;
}

void AccessTokenReq::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool AccessTokenReq::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool AccessTokenReq::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "AccessTokenReq" : pathPrefix;


  if (requesterPlmnListIsSet()) {
    const std::vector<ngkore::model::common::PlmnId>& value = m_RequesterPlmnList;
    const std::string currentValuePath = _pathPrefix + ".requesterPlmnList";

    if (value.size() < 2) {
      success = false;
      msg << currentValuePath << ": must have at least 2 elements;";
    }
    {  // Recursive validation of array elements
      const std::string oldValuePath = currentValuePath;
      int i                          = 0;
      for (const ngkore::model::common::PlmnId& value : value) {
        const std::string currentValuePath =
            oldValuePath + "[" + std::to_string(i) + "]";

        success =
            value.validate(msg, currentValuePath + ".requesterPlmnList") &&
            success;

        i++;
      }
    }
  }

  if (requesterSnssaiListIsSet()) {
    const std::vector<ngkore::model::common::Snssai>& value =
        m_RequesterSnssaiList;
    const std::string currentValuePath = _pathPrefix + ".requesterSnssaiList";

    if (value.size() < 1) {
      success = false;
      msg << currentValuePath << ": must have at least 1 elements;";
    }
    {  // Recursive validation of array elements
      const std::string oldValuePath = currentValuePath;
      int i                          = 0;
      for (const ngkore::model::common::Snssai& value : value) {
        const std::string currentValuePath =
            oldValuePath + "[" + std::to_string(i) + "]";

        success =
            value.validate(msg, currentValuePath + ".requesterSnssaiList") &&
            success;

        i++;
      }
    }
  }

  if (requesterSnpnListIsSet()) {
    const std::vector<ngkore::model::common::PlmnIdNid>& value =
        m_RequesterSnpnList;
    const std::string currentValuePath = _pathPrefix + ".requesterSnpnList";

    if (value.size() < 1) {
      success = false;
      msg << currentValuePath << ": must have at least 1 elements;";
    }
    {  // Recursive validation of array elements
      const std::string oldValuePath = currentValuePath;
      int i                          = 0;
      for (const ngkore::model::common::PlmnIdNid& value : value) {
        const std::string currentValuePath =
            oldValuePath + "[" + std::to_string(i) + "]";

        success =
            value.validate(msg, currentValuePath + ".requesterSnpnList") &&
            success;

        i++;
      }
    }
  }

  if (targetSnssaiListIsSet()) {
    const std::vector<ngkore::model::common::Snssai>& value = m_TargetSnssaiList;
    const std::string currentValuePath = _pathPrefix + ".targetSnssaiList";

    if (value.size() < 1) {
      success = false;
      msg << currentValuePath << ": must have at least 1 elements;";
    }
    {  // Recursive validation of array elements
      const std::string oldValuePath = currentValuePath;
      int i                          = 0;
      for (const ngkore::model::common::Snssai& value : value) {
        const std::string currentValuePath =
            oldValuePath + "[" + std::to_string(i) + "]";

        success = value.validate(msg, currentValuePath + ".targetSnssaiList") &&
                  success;

        i++;
      }
    }
  }

  if (targetNsiListIsSet()) {
    const std::vector<std::string>& value = m_TargetNsiList;
    const std::string currentValuePath    = _pathPrefix + ".targetNsiList";

    if (value.size() < 1) {
      success = false;
      msg << currentValuePath << ": must have at least 1 elements;";
    }
  }

  return success;
}

bool AccessTokenReq::operator==(const AccessTokenReq& rhs) const {
  return

      (getGrantType() == rhs.getGrantType()) &&

      (getNfInstanceId() == rhs.getNfInstanceId()) &&

      ((!nfTypeIsSet() && !rhs.nfTypeIsSet()) ||
       (nfTypeIsSet() && rhs.nfTypeIsSet() &&
        getNfType() == rhs.getNfType())) &&

      ((!targetNfTypeIsSet() && !rhs.targetNfTypeIsSet()) ||
       (targetNfTypeIsSet() && rhs.targetNfTypeIsSet() &&
        getTargetNfType() == rhs.getTargetNfType())) &&

      (getScope() == rhs.getScope()) &&

      ((!targetNfInstanceIdIsSet() && !rhs.targetNfInstanceIdIsSet()) ||
       (targetNfInstanceIdIsSet() && rhs.targetNfInstanceIdIsSet() &&
        getTargetNfInstanceId() == rhs.getTargetNfInstanceId())) &&

      ((!requesterPlmnIsSet() && !rhs.requesterPlmnIsSet()) ||
       (requesterPlmnIsSet() && rhs.requesterPlmnIsSet() &&
        getRequesterPlmn() == rhs.getRequesterPlmn())) &&

      ((!requesterPlmnListIsSet() && !rhs.requesterPlmnListIsSet()) ||
       (requesterPlmnListIsSet() && rhs.requesterPlmnListIsSet() &&
        getRequesterPlmnList() == rhs.getRequesterPlmnList())) &&

      ((!requesterSnssaiListIsSet() && !rhs.requesterSnssaiListIsSet()) ||
       (requesterSnssaiListIsSet() && rhs.requesterSnssaiListIsSet() &&
        getRequesterSnssaiList() == rhs.getRequesterSnssaiList())) &&

      ((!requesterFqdnIsSet() && !rhs.requesterFqdnIsSet()) ||
       (requesterFqdnIsSet() && rhs.requesterFqdnIsSet() &&
        getRequesterFqdn() == rhs.getRequesterFqdn())) &&

      ((!requesterSnpnListIsSet() && !rhs.requesterSnpnListIsSet()) ||
       (requesterSnpnListIsSet() && rhs.requesterSnpnListIsSet() &&
        getRequesterSnpnList() == rhs.getRequesterSnpnList())) &&

      ((!targetPlmnIsSet() && !rhs.targetPlmnIsSet()) ||
       (targetPlmnIsSet() && rhs.targetPlmnIsSet() &&
        getTargetPlmn() == rhs.getTargetPlmn())) &&

      ((!targetSnssaiListIsSet() && !rhs.targetSnssaiListIsSet()) ||
       (targetSnssaiListIsSet() && rhs.targetSnssaiListIsSet() &&
        getTargetSnssaiList() == rhs.getTargetSnssaiList())) &&

      ((!targetNsiListIsSet() && !rhs.targetNsiListIsSet()) ||
       (targetNsiListIsSet() && rhs.targetNsiListIsSet() &&
        getTargetNsiList() == rhs.getTargetNsiList())) &&

      ((!targetNfSetIdIsSet() && !rhs.targetNfSetIdIsSet()) ||
       (targetNfSetIdIsSet() && rhs.targetNfSetIdIsSet() &&
        getTargetNfSetId() == rhs.getTargetNfSetId())) &&

      ((!targetNfServiceSetIdIsSet() && !rhs.targetNfServiceSetIdIsSet()) ||
       (targetNfServiceSetIdIsSet() && rhs.targetNfServiceSetIdIsSet() &&
        getTargetNfServiceSetId() == rhs.getTargetNfServiceSetId()))

          ;
}

bool AccessTokenReq::operator!=(const AccessTokenReq& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const AccessTokenReq& o) {
  j                 = nlohmann::json();
  j["grant_type"]   = o.m_Grant_type;
  j["nfInstanceId"] = o.m_NfInstanceId;
  if (o.nfTypeIsSet()) j["nfType"] = o.m_NfType;
  if (o.targetNfTypeIsSet()) j["targetNfType"] = o.m_TargetNfType;
  j["scope"] = o.m_Scope;
  if (o.targetNfInstanceIdIsSet())
    j["targetNfInstanceId"] = o.m_TargetNfInstanceId;
  if (o.requesterPlmnIsSet()) j["requesterPlmn"] = o.m_RequesterPlmn;
  if (o.requesterPlmnListIsSet() || !o.m_RequesterPlmnList.empty())
    j["requesterPlmnList"] = o.m_RequesterPlmnList;
  if (o.requesterSnssaiListIsSet() || !o.m_RequesterSnssaiList.empty())
    j["requesterSnssaiList"] = o.m_RequesterSnssaiList;
  if (o.requesterFqdnIsSet()) j["requesterFqdn"] = o.m_RequesterFqdn;
  if (o.requesterSnpnListIsSet() || !o.m_RequesterSnpnList.empty())
    j["requesterSnpnList"] = o.m_RequesterSnpnList;
  if (o.targetPlmnIsSet()) j["targetPlmn"] = o.m_TargetPlmn;
  if (o.targetSnssaiListIsSet() || !o.m_TargetSnssaiList.empty())
    j["targetSnssaiList"] = o.m_TargetSnssaiList;
  if (o.targetNsiListIsSet() || !o.m_TargetNsiList.empty())
    j["targetNsiList"] = o.m_TargetNsiList;
  if (o.targetNfSetIdIsSet()) j["targetNfSetId"] = o.m_TargetNfSetId;
  if (o.targetNfServiceSetIdIsSet())
    j["targetNfServiceSetId"] = o.m_TargetNfServiceSetId;
}

void from_json(const nlohmann::json& j, AccessTokenReq& o) {
  j.at("grant_type").get_to(o.m_Grant_type);
  j.at("nfInstanceId").get_to(o.m_NfInstanceId);
  if (j.find("nfType") != j.end()) {
    j.at("nfType").get_to(o.m_NfType);
    o.m_NfTypeIsSet = true;
  }
  if (j.find("targetNfType") != j.end()) {
    j.at("targetNfType").get_to(o.m_TargetNfType);
    o.m_TargetNfTypeIsSet = true;
  }
  j.at("scope").get_to(o.m_Scope);
  if (j.find("targetNfInstanceId") != j.end()) {
    j.at("targetNfInstanceId").get_to(o.m_TargetNfInstanceId);
    o.m_TargetNfInstanceIdIsSet = true;
  }
  if (j.find("requesterPlmn") != j.end()) {
    j.at("requesterPlmn").get_to(o.m_RequesterPlmn);
    o.m_RequesterPlmnIsSet = true;
  }
  if (j.find("requesterPlmnList") != j.end()) {
    j.at("requesterPlmnList").get_to(o.m_RequesterPlmnList);
    o.m_RequesterPlmnListIsSet = true;
  }
  if (j.find("requesterSnssaiList") != j.end()) {
    j.at("requesterSnssaiList").get_to(o.m_RequesterSnssaiList);
    o.m_RequesterSnssaiListIsSet = true;
  }
  if (j.find("requesterFqdn") != j.end()) {
    j.at("requesterFqdn").get_to(o.m_RequesterFqdn);
    o.m_RequesterFqdnIsSet = true;
  }
  if (j.find("requesterSnpnList") != j.end()) {
    j.at("requesterSnpnList").get_to(o.m_RequesterSnpnList);
    o.m_RequesterSnpnListIsSet = true;
  }
  if (j.find("targetPlmn") != j.end()) {
    j.at("targetPlmn").get_to(o.m_TargetPlmn);
    o.m_TargetPlmnIsSet = true;
  }
  if (j.find("targetSnssaiList") != j.end()) {
    j.at("targetSnssaiList").get_to(o.m_TargetSnssaiList);
    o.m_TargetSnssaiListIsSet = true;
  }
  if (j.find("targetNsiList") != j.end()) {
    j.at("targetNsiList").get_to(o.m_TargetNsiList);
    o.m_TargetNsiListIsSet = true;
  }
  if (j.find("targetNfSetId") != j.end()) {
    j.at("targetNfSetId").get_to(o.m_TargetNfSetId);
    o.m_TargetNfSetIdIsSet = true;
  }
  if (j.find("targetNfServiceSetId") != j.end()) {
    j.at("targetNfServiceSetId").get_to(o.m_TargetNfServiceSetId);
    o.m_TargetNfServiceSetIdIsSet = true;
  }
}

std::string AccessTokenReq::getGrantType() const {
  return m_Grant_type;
}
void AccessTokenReq::setGrantType(std::string const& value) {
  m_Grant_type = value;
}
std::string AccessTokenReq::getNfInstanceId() const {
  return m_NfInstanceId;
}
void AccessTokenReq::setNfInstanceId(std::string const& value) {
  m_NfInstanceId = value;
}
ngkore::model::common::NFType AccessTokenReq::getNfType() const {
  return m_NfType;
}
void AccessTokenReq::setNfType(ngkore::model::common::NFType const& value) {
  m_NfType      = value;
  m_NfTypeIsSet = true;
}
bool AccessTokenReq::nfTypeIsSet() const {
  return m_NfTypeIsSet;
}
void AccessTokenReq::unsetNfType() {
  m_NfTypeIsSet = false;
}
ngkore::model::common::NFType AccessTokenReq::getTargetNfType() const {
  return m_TargetNfType;
}
void AccessTokenReq::setTargetNfType(ngkore::model::common::NFType const& value) {
  m_TargetNfType      = value;
  m_TargetNfTypeIsSet = true;
}
bool AccessTokenReq::targetNfTypeIsSet() const {
  return m_TargetNfTypeIsSet;
}
void AccessTokenReq::unsetTargetNfType() {
  m_TargetNfTypeIsSet = false;
}
std::string AccessTokenReq::getScope() const {
  return m_Scope;
}
void AccessTokenReq::setScope(std::string const& value) {
  m_Scope = value;
}
std::string AccessTokenReq::getTargetNfInstanceId() const {
  return m_TargetNfInstanceId;
}
void AccessTokenReq::setTargetNfInstanceId(std::string const& value) {
  m_TargetNfInstanceId      = value;
  m_TargetNfInstanceIdIsSet = true;
}
bool AccessTokenReq::targetNfInstanceIdIsSet() const {
  return m_TargetNfInstanceIdIsSet;
}
void AccessTokenReq::unsetTargetNfInstanceId() {
  m_TargetNfInstanceIdIsSet = false;
}
ngkore::model::common::PlmnId AccessTokenReq::getRequesterPlmn() const {
  return m_RequesterPlmn;
}
void AccessTokenReq::setRequesterPlmn(ngkore::model::common::PlmnId const& value) {
  m_RequesterPlmn      = value;
  m_RequesterPlmnIsSet = true;
}
bool AccessTokenReq::requesterPlmnIsSet() const {
  return m_RequesterPlmnIsSet;
}
void AccessTokenReq::unsetRequesterPlmn() {
  m_RequesterPlmnIsSet = false;
}
std::vector<ngkore::model::common::PlmnId> AccessTokenReq::getRequesterPlmnList()
    const {
  return m_RequesterPlmnList;
}
void AccessTokenReq::setRequesterPlmnList(
    std::vector<ngkore::model::common::PlmnId> const& value) {
  m_RequesterPlmnList      = value;
  m_RequesterPlmnListIsSet = true;
}
bool AccessTokenReq::requesterPlmnListIsSet() const {
  return m_RequesterPlmnListIsSet;
}
void AccessTokenReq::unsetRequesterPlmnList() {
  m_RequesterPlmnListIsSet = false;
}
std::vector<ngkore::model::common::Snssai> AccessTokenReq::getRequesterSnssaiList()
    const {
  return m_RequesterSnssaiList;
}
void AccessTokenReq::setRequesterSnssaiList(
    std::vector<ngkore::model::common::Snssai> const& value) {
  m_RequesterSnssaiList      = value;
  m_RequesterSnssaiListIsSet = true;
}
bool AccessTokenReq::requesterSnssaiListIsSet() const {
  return m_RequesterSnssaiListIsSet;
}
void AccessTokenReq::unsetRequesterSnssaiList() {
  m_RequesterSnssaiListIsSet = false;
}
std::string AccessTokenReq::getRequesterFqdn() const {
  return m_RequesterFqdn;
}
void AccessTokenReq::setRequesterFqdn(std::string const& value) {
  m_RequesterFqdn      = value;
  m_RequesterFqdnIsSet = true;
}
bool AccessTokenReq::requesterFqdnIsSet() const {
  return m_RequesterFqdnIsSet;
}
void AccessTokenReq::unsetRequesterFqdn() {
  m_RequesterFqdnIsSet = false;
}
std::vector<ngkore::model::common::PlmnIdNid>
AccessTokenReq::getRequesterSnpnList() const {
  return m_RequesterSnpnList;
}
void AccessTokenReq::setRequesterSnpnList(
    std::vector<ngkore::model::common::PlmnIdNid> const& value) {
  m_RequesterSnpnList      = value;
  m_RequesterSnpnListIsSet = true;
}
bool AccessTokenReq::requesterSnpnListIsSet() const {
  return m_RequesterSnpnListIsSet;
}
void AccessTokenReq::unsetRequesterSnpnList() {
  m_RequesterSnpnListIsSet = false;
}
ngkore::model::common::PlmnId AccessTokenReq::getTargetPlmn() const {
  return m_TargetPlmn;
}
void AccessTokenReq::setTargetPlmn(ngkore::model::common::PlmnId const& value) {
  m_TargetPlmn      = value;
  m_TargetPlmnIsSet = true;
}
bool AccessTokenReq::targetPlmnIsSet() const {
  return m_TargetPlmnIsSet;
}
void AccessTokenReq::unsetTargetPlmn() {
  m_TargetPlmnIsSet = false;
}
std::vector<ngkore::model::common::Snssai> AccessTokenReq::getTargetSnssaiList()
    const {
  return m_TargetSnssaiList;
}
void AccessTokenReq::setTargetSnssaiList(
    std::vector<ngkore::model::common::Snssai> const& value) {
  m_TargetSnssaiList      = value;
  m_TargetSnssaiListIsSet = true;
}
bool AccessTokenReq::targetSnssaiListIsSet() const {
  return m_TargetSnssaiListIsSet;
}
void AccessTokenReq::unsetTargetSnssaiList() {
  m_TargetSnssaiListIsSet = false;
}
std::vector<std::string> AccessTokenReq::getTargetNsiList() const {
  return m_TargetNsiList;
}
void AccessTokenReq::setTargetNsiList(std::vector<std::string> const& value) {
  m_TargetNsiList      = value;
  m_TargetNsiListIsSet = true;
}
bool AccessTokenReq::targetNsiListIsSet() const {
  return m_TargetNsiListIsSet;
}
void AccessTokenReq::unsetTargetNsiList() {
  m_TargetNsiListIsSet = false;
}
std::string AccessTokenReq::getTargetNfSetId() const {
  return m_TargetNfSetId;
}
void AccessTokenReq::setTargetNfSetId(std::string const& value) {
  m_TargetNfSetId      = value;
  m_TargetNfSetIdIsSet = true;
}
bool AccessTokenReq::targetNfSetIdIsSet() const {
  return m_TargetNfSetIdIsSet;
}
void AccessTokenReq::unsetTargetNfSetId() {
  m_TargetNfSetIdIsSet = false;
}
std::string AccessTokenReq::getTargetNfServiceSetId() const {
  return m_TargetNfServiceSetId;
}
void AccessTokenReq::setTargetNfServiceSetId(std::string const& value) {
  m_TargetNfServiceSetId      = value;
  m_TargetNfServiceSetIdIsSet = true;
}
bool AccessTokenReq::targetNfServiceSetIdIsSet() const {
  return m_TargetNfServiceSetIdIsSet;
}
void AccessTokenReq::unsetTargetNfServiceSetId() {
  m_TargetNfServiceSetIdIsSet = false;
}

}  // namespace ngkore::model::common
