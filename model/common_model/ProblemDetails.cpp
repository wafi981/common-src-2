
#include "ProblemDetails.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

ProblemDetails::ProblemDetails() {
  m_Type                    = "";
  m_TypeIsSet               = false;
  m_Title                   = "";
  m_TitleIsSet              = false;
  m_Status                  = 0;
  m_StatusIsSet             = false;
  m_Detail                  = "";
  m_DetailIsSet             = false;
  m_Instance                = "";
  m_InstanceIsSet           = false;
  m_Cause                   = "";
  m_CauseIsSet              = false;
  m_InvalidParamsIsSet      = false;
  m_SupportedFeatures       = "";
  m_SupportedFeaturesIsSet  = false;
  m_AccessTokenErrorIsSet   = false;
  m_AccessTokenRequestIsSet = false;
  m_NrfId                   = "";
  m_NrfIdIsSet              = false;
}

void ProblemDetails::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool ProblemDetails::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool ProblemDetails::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "ProblemDetails" : pathPrefix;

  if (invalidParamsIsSet()) {
    const std::vector<ngkore::model::common::InvalidParam>& value =
        m_InvalidParams;
    const std::string currentValuePath = _pathPrefix + ".invalidParams";

    if (value.size() < 1) {
      success = false;
      msg << currentValuePath << ": must have at least 1 elements;";
    }
    {  // Recursive validation of array elements
      const std::string oldValuePath = currentValuePath;
      int i                          = 0;
      for (const ngkore::model::common::InvalidParam& value : value) {
        const std::string currentValuePath =
            oldValuePath + "[" + std::to_string(i) + "]";

        success =
            value.validate(msg, currentValuePath + ".invalidParams") && success;

        i++;
      }
    }
  }
  return success;
}

bool ProblemDetails::operator==(const ProblemDetails& rhs) const {
  return

      ((!typeIsSet() && !rhs.typeIsSet()) ||
       (typeIsSet() && rhs.typeIsSet() && getType() == rhs.getType())) &&

      ((!titleIsSet() && !rhs.titleIsSet()) ||
       (titleIsSet() && rhs.titleIsSet() && getTitle() == rhs.getTitle())) &&

      ((!statusIsSet() && !rhs.statusIsSet()) ||
       (statusIsSet() && rhs.statusIsSet() &&
        getStatus() == rhs.getStatus())) &&

      ((!detailIsSet() && !rhs.detailIsSet()) ||
       (detailIsSet() && rhs.detailIsSet() &&
        getDetail() == rhs.getDetail())) &&

      ((!instanceIsSet() && !rhs.instanceIsSet()) ||
       (instanceIsSet() && rhs.instanceIsSet() &&
        getInstance() == rhs.getInstance())) &&

      ((!causeIsSet() && !rhs.causeIsSet()) ||
       (causeIsSet() && rhs.causeIsSet() && getCause() == rhs.getCause())) &&

      ((!invalidParamsIsSet() && !rhs.invalidParamsIsSet()) ||
       (invalidParamsIsSet() && rhs.invalidParamsIsSet() &&
        getInvalidParams() == rhs.getInvalidParams())) &&

      ((!supportedFeaturesIsSet() && !rhs.supportedFeaturesIsSet()) ||
       (supportedFeaturesIsSet() && rhs.supportedFeaturesIsSet() &&
        getSupportedFeatures() == rhs.getSupportedFeatures())) &&

      ((!accessTokenErrorIsSet() && !rhs.accessTokenErrorIsSet()) ||
       (accessTokenErrorIsSet() && rhs.accessTokenErrorIsSet() &&
        getAccessTokenError() == rhs.getAccessTokenError())) &&

      ((!accessTokenRequestIsSet() && !rhs.accessTokenRequestIsSet()) ||
       (accessTokenRequestIsSet() && rhs.accessTokenRequestIsSet() &&
        getAccessTokenRequest() == rhs.getAccessTokenRequest())) &&

      ((!nrfIdIsSet() && !rhs.nrfIdIsSet()) ||
       (nrfIdIsSet() && rhs.nrfIdIsSet() && getNrfId() == rhs.getNrfId()))

          ;
}

bool ProblemDetails::operator!=(const ProblemDetails& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const ProblemDetails& o) {
  j = nlohmann::json();
  if (o.typeIsSet()) j["type"] = o.m_Type;
  if (o.titleIsSet()) j["title"] = o.m_Title;
  if (o.statusIsSet()) j["status"] = o.m_Status;
  if (o.detailIsSet()) j["detail"] = o.m_Detail;
  if (o.instanceIsSet()) j["instance"] = o.m_Instance;
  if (o.causeIsSet()) j["cause"] = o.m_Cause;
  if (o.invalidParamsIsSet() || !o.m_InvalidParams.empty())
    j["invalidParams"] = o.m_InvalidParams;
  if (o.supportedFeaturesIsSet())
    j["supportedFeatures"] = o.m_SupportedFeatures;
  if (o.accessTokenErrorIsSet()) j["accessTokenError"] = o.m_AccessTokenError;
  if (o.accessTokenRequestIsSet())
    j["accessTokenRequest"] = o.m_AccessTokenRequest;
  if (o.nrfIdIsSet()) j["nrfId"] = o.m_NrfId;
}

void from_json(const nlohmann::json& j, ProblemDetails& o) {
  if (j.find("type") != j.end()) {
    j.at("type").get_to(o.m_Type);
    o.m_TypeIsSet = true;
  }
  if (j.find("title") != j.end()) {
    j.at("title").get_to(o.m_Title);
    o.m_TitleIsSet = true;
  }
  if (j.find("status") != j.end()) {
    j.at("status").get_to(o.m_Status);
    o.m_StatusIsSet = true;
  }
  if (j.find("detail") != j.end()) {
    j.at("detail").get_to(o.m_Detail);
    o.m_DetailIsSet = true;
  }
  if (j.find("instance") != j.end()) {
    j.at("instance").get_to(o.m_Instance);
    o.m_InstanceIsSet = true;
  }
  if (j.find("cause") != j.end()) {
    j.at("cause").get_to(o.m_Cause);
    o.m_CauseIsSet = true;
  }
  if (j.find("invalidParams") != j.end()) {
    j.at("invalidParams").get_to(o.m_InvalidParams);
    o.m_InvalidParamsIsSet = true;
  }
  if (j.find("supportedFeatures") != j.end()) {
    j.at("supportedFeatures").get_to(o.m_SupportedFeatures);
    o.m_SupportedFeaturesIsSet = true;
  }
  if (j.find("accessTokenError") != j.end()) {
    j.at("accessTokenError").get_to(o.m_AccessTokenError);
    o.m_AccessTokenErrorIsSet = true;
  }
  if (j.find("accessTokenRequest") != j.end()) {
    j.at("accessTokenRequest").get_to(o.m_AccessTokenRequest);
    o.m_AccessTokenRequestIsSet = true;
  }
  if (j.find("nrfId") != j.end()) {
    j.at("nrfId").get_to(o.m_NrfId);
    o.m_NrfIdIsSet = true;
  }
}

std::string ProblemDetails::getType() const {
  return m_Type;
}
void ProblemDetails::setType(std::string const& value) {
  m_Type      = value;
  m_TypeIsSet = true;
}
bool ProblemDetails::typeIsSet() const {
  return m_TypeIsSet;
}
void ProblemDetails::unsetType() {
  m_TypeIsSet = false;
}
std::string ProblemDetails::getTitle() const {
  return m_Title;
}
void ProblemDetails::setTitle(std::string const& value) {
  m_Title      = value;
  m_TitleIsSet = true;
}
bool ProblemDetails::titleIsSet() const {
  return m_TitleIsSet;
}
void ProblemDetails::unsetTitle() {
  m_TitleIsSet = false;
}
int32_t ProblemDetails::getStatus() const {
  return m_Status;
}
void ProblemDetails::setStatus(int32_t const value) {
  m_Status      = value;
  m_StatusIsSet = true;
}
bool ProblemDetails::statusIsSet() const {
  return m_StatusIsSet;
}
void ProblemDetails::unsetStatus() {
  m_StatusIsSet = false;
}
std::string ProblemDetails::getDetail() const {
  return m_Detail;
}
void ProblemDetails::setDetail(std::string const& value) {
  m_Detail      = value;
  m_DetailIsSet = true;
}
bool ProblemDetails::detailIsSet() const {
  return m_DetailIsSet;
}
void ProblemDetails::unsetDetail() {
  m_DetailIsSet = false;
}
std::string ProblemDetails::getInstance() const {
  return m_Instance;
}
void ProblemDetails::setInstance(std::string const& value) {
  m_Instance      = value;
  m_InstanceIsSet = true;
}
bool ProblemDetails::instanceIsSet() const {
  return m_InstanceIsSet;
}
void ProblemDetails::unsetInstance() {
  m_InstanceIsSet = false;
}
std::string ProblemDetails::getCause() const {
  return m_Cause;
}
void ProblemDetails::setCause(std::string const& value) {
  m_Cause      = value;
  m_CauseIsSet = true;
}
bool ProblemDetails::causeIsSet() const {
  return m_CauseIsSet;
}
void ProblemDetails::unsetCause() {
  m_CauseIsSet = false;
}
std::vector<ngkore::model::common::InvalidParam> ProblemDetails::getInvalidParams()
    const {
  return m_InvalidParams;
}
void ProblemDetails::setInvalidParams(
    std::vector<ngkore::model::common::InvalidParam> const& value) {
  m_InvalidParams      = value;
  m_InvalidParamsIsSet = true;
}
bool ProblemDetails::invalidParamsIsSet() const {
  return m_InvalidParamsIsSet;
}
void ProblemDetails::unsetInvalidParams() {
  m_InvalidParamsIsSet = false;
}
std::string ProblemDetails::getSupportedFeatures() const {
  return m_SupportedFeatures;
}
void ProblemDetails::setSupportedFeatures(std::string const& value) {
  m_SupportedFeatures      = value;
  m_SupportedFeaturesIsSet = true;
}
bool ProblemDetails::supportedFeaturesIsSet() const {
  return m_SupportedFeaturesIsSet;
}
void ProblemDetails::unsetSupportedFeatures() {
  m_SupportedFeaturesIsSet = false;
}
ngkore::model::common::AccessTokenErr ProblemDetails::getAccessTokenError() const {
  return m_AccessTokenError;
}
void ProblemDetails::setAccessTokenError(
    ngkore::model::common::AccessTokenErr const& value) {
  m_AccessTokenError      = value;
  m_AccessTokenErrorIsSet = true;
}
bool ProblemDetails::accessTokenErrorIsSet() const {
  return m_AccessTokenErrorIsSet;
}
void ProblemDetails::unsetAccessTokenError() {
  m_AccessTokenErrorIsSet = false;
}
ngkore::model::common::AccessTokenReq ProblemDetails::getAccessTokenRequest()
    const {
  return m_AccessTokenRequest;
}
void ProblemDetails::setAccessTokenRequest(
    ngkore::model::common::AccessTokenReq const& value) {
  m_AccessTokenRequest      = value;
  m_AccessTokenRequestIsSet = true;
}
bool ProblemDetails::accessTokenRequestIsSet() const {
  return m_AccessTokenRequestIsSet;
}
void ProblemDetails::unsetAccessTokenRequest() {
  m_AccessTokenRequestIsSet = false;
}
std::string ProblemDetails::getNrfId() const {
  return m_NrfId;
}
void ProblemDetails::setNrfId(std::string const& value) {
  m_NrfId      = value;
  m_NrfIdIsSet = true;
}
bool ProblemDetails::nrfIdIsSet() const {
  return m_NrfIdIsSet;
}
void ProblemDetails::unsetNrfId() {
  m_NrfIdIsSet = false;
}

}  // namespace ngkore::model::common
