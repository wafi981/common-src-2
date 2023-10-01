
#ifndef AccessTokenReq_H_
#define AccessTokenReq_H_

#include "PlmnIdNid.h"
#include "NFType.h"
#include "PlmnId.h"
#include <string>
#include "Snssai.h"
#include <vector>
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
/// Contains information related to the access token request
/// </summary>
class AccessTokenReq {
 public:
  AccessTokenReq();
  virtual ~AccessTokenReq() = default;

  /// <summary>
  /// Validate the current data in the model. Throws a ValidationException on
  /// failure.
  /// </summary>
  void validate() const;

  /// <summary>
  /// Validate the current data in the model. Returns false on error and writes
  /// an error message into the given stringstream.
  /// </summary>
  bool validate(std::stringstream& msg) const;

  /// <summary>
  /// Helper overload for validate. Used when one model stores another model and
  /// calls it's validate. Not meant to be called outside that case.
  /// </summary>
  bool validate(std::stringstream& msg, const std::string& pathPrefix) const;

  bool operator==(const AccessTokenReq& rhs) const;
  bool operator!=(const AccessTokenReq& rhs) const;

  /////////////////////////////////////////////
  /// AccessTokenReq members

  /// <summary>
  ///
  /// </summary>
  std::string getGrantType() const;
  void setGrantType(std::string const& value);
  /// <summary>
  ///
  /// </summary>
  std::string getNfInstanceId() const;
  void setNfInstanceId(std::string const& value);
  /// <summary>
  ///
  /// </summary>
  ngkore::model::common::NFType getNfType() const;
  void setNfType(ngkore::model::common::NFType const& value);
  bool nfTypeIsSet() const;
  void unsetNfType();
  /// <summary>
  ///
  /// </summary>
  ngkore::model::common::NFType getTargetNfType() const;
  void setTargetNfType(ngkore::model::common::NFType const& value);
  bool targetNfTypeIsSet() const;
  void unsetTargetNfType();
  /// <summary>
  ///
  /// </summary>
  std::string getScope() const;
  void setScope(std::string const& value);
  /// <summary>
  ///
  /// </summary>
  std::string getTargetNfInstanceId() const;
  void setTargetNfInstanceId(std::string const& value);
  bool targetNfInstanceIdIsSet() const;
  void unsetTargetNfInstanceId();
  /// <summary>
  ///
  /// </summary>
  ngkore::model::common::PlmnId getRequesterPlmn() const;
  void setRequesterPlmn(ngkore::model::common::PlmnId const& value);
  bool requesterPlmnIsSet() const;
  void unsetRequesterPlmn();
  /// <summary>
  ///
  /// </summary>
  std::vector<ngkore::model::common::PlmnId> getRequesterPlmnList() const;
  void setRequesterPlmnList(
      std::vector<ngkore::model::common::PlmnId> const& value);
  bool requesterPlmnListIsSet() const;
  void unsetRequesterPlmnList();
  /// <summary>
  ///
  /// </summary>
  std::vector<ngkore::model::common::Snssai> getRequesterSnssaiList() const;
  void setRequesterSnssaiList(
      std::vector<ngkore::model::common::Snssai> const& value);
  bool requesterSnssaiListIsSet() const;
  void unsetRequesterSnssaiList();
  /// <summary>
  /// Fully Qualified Domain Name
  /// </summary>
  std::string getRequesterFqdn() const;
  void setRequesterFqdn(std::string const& value);
  bool requesterFqdnIsSet() const;
  void unsetRequesterFqdn();
  /// <summary>
  ///
  /// </summary>
  std::vector<ngkore::model::common::PlmnIdNid> getRequesterSnpnList() const;
  void setRequesterSnpnList(
      std::vector<ngkore::model::common::PlmnIdNid> const& value);
  bool requesterSnpnListIsSet() const;
  void unsetRequesterSnpnList();
  /// <summary>
  ///
  /// </summary>
  ngkore::model::common::PlmnId getTargetPlmn() const;
  void setTargetPlmn(ngkore::model::common::PlmnId const& value);
  bool targetPlmnIsSet() const;
  void unsetTargetPlmn();
  /// <summary>
  ///
  /// </summary>
  std::vector<ngkore::model::common::Snssai> getTargetSnssaiList() const;
  void setTargetSnssaiList(
      std::vector<ngkore::model::common::Snssai> const& value);
  bool targetSnssaiListIsSet() const;
  void unsetTargetSnssaiList();
  /// <summary>
  ///
  /// </summary>
  std::vector<std::string> getTargetNsiList() const;
  void setTargetNsiList(std::vector<std::string> const& value);
  bool targetNsiListIsSet() const;
  void unsetTargetNsiList();
  /// <summary>
  ///
  /// </summary>
  std::string getTargetNfSetId() const;
  void setTargetNfSetId(std::string const& value);
  bool targetNfSetIdIsSet() const;
  void unsetTargetNfSetId();
  /// <summary>
  ///
  /// </summary>
  std::string getTargetNfServiceSetId() const;
  void setTargetNfServiceSetId(std::string const& value);
  bool targetNfServiceSetIdIsSet() const;
  void unsetTargetNfServiceSetId();

  friend void to_json(nlohmann::json& j, const AccessTokenReq& o);
  friend void from_json(const nlohmann::json& j, AccessTokenReq& o);

 protected:
  std::string m_Grant_type;

  std::string m_NfInstanceId;

  ngkore::model::common::NFType m_NfType;
  bool m_NfTypeIsSet;
  ngkore::model::common::NFType m_TargetNfType;
  bool m_TargetNfTypeIsSet;
  std::string m_Scope;

  std::string m_TargetNfInstanceId;
  bool m_TargetNfInstanceIdIsSet;
  ngkore::model::common::PlmnId m_RequesterPlmn;
  bool m_RequesterPlmnIsSet;
  std::vector<ngkore::model::common::PlmnId> m_RequesterPlmnList;
  bool m_RequesterPlmnListIsSet;
  std::vector<ngkore::model::common::Snssai> m_RequesterSnssaiList;
  bool m_RequesterSnssaiListIsSet;
  std::string m_RequesterFqdn;
  bool m_RequesterFqdnIsSet;
  std::vector<ngkore::model::common::PlmnIdNid> m_RequesterSnpnList;
  bool m_RequesterSnpnListIsSet;
  ngkore::model::common::PlmnId m_TargetPlmn;
  bool m_TargetPlmnIsSet;
  std::vector<ngkore::model::common::Snssai> m_TargetSnssaiList;
  bool m_TargetSnssaiListIsSet;
  std::vector<std::string> m_TargetNsiList;
  bool m_TargetNsiListIsSet;
  std::string m_TargetNfSetId;
  bool m_TargetNfSetIdIsSet;
  std::string m_TargetNfServiceSetId;
  bool m_TargetNfServiceSetIdIsSet;
};

}  // namespace ngkore::model::common

