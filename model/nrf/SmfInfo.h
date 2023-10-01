
#ifndef SmfInfo_H_
#define SmfInfo_H_

#include "Tai.h"
#include <string>
#include "SnssaiSmfInfoItem.h"
#include "TaiRange.h"
#include <vector>
#include "AccessType.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::nrf {

/// <summary>
/// Information of an SMF NF Instance
/// </summary>
class SmfInfo {
 public:
  SmfInfo();
  virtual ~SmfInfo() = default;

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

  bool operator==(const SmfInfo& rhs) const;
  bool operator!=(const SmfInfo& rhs) const;

  /////////////////////////////////////////////
  /// SmfInfo members

  /// <summary>
  ///
  /// </summary>
  std::vector<ngkore::model::nrf::SnssaiSmfInfoItem> getSNssaiSmfInfoList() const;
  void setSNssaiSmfInfoList(
      std::vector<ngkore::model::nrf::SnssaiSmfInfoItem> const& value);
  /// <summary>
  ///
  /// </summary>
  std::vector<ngkore::model::common::Tai> getTaiList() const;
  void setTaiList(std::vector<ngkore::model::common::Tai> const& value);
  bool taiListIsSet() const;
  void unsetTaiList();
  /// <summary>
  ///
  /// </summary>
  std::vector<ngkore::model::nrf::TaiRange> getTaiRangeList() const;
  void setTaiRangeList(std::vector<ngkore::model::nrf::TaiRange> const& value);
  bool taiRangeListIsSet() const;
  void unsetTaiRangeList();
  /// <summary>
  /// Fully Qualified Domain Name
  /// </summary>
  std::string getPgwFqdn() const;
  void setPgwFqdn(std::string const& value);
  bool pgwFqdnIsSet() const;
  void unsetPgwFqdn();
  /// <summary>
  ///
  /// </summary>
  std::vector<ngkore::model::common::AccessType> getAccessType() const;
  void setAccessType(std::vector<ngkore::model::common::AccessType> const& value);
  bool accessTypeIsSet() const;
  void unsetAccessType();
  /// <summary>
  ///
  /// </summary>
  int32_t getPriority() const;
  void setPriority(int32_t const value);
  bool priorityIsSet() const;
  void unsetPriority();
  /// <summary>
  ///
  /// </summary>
  bool isVsmfSupportInd() const;
  void setVsmfSupportInd(bool const value);
  bool vsmfSupportIndIsSet() const;
  void unsetVsmfSupportInd();

  friend void to_json(nlohmann::json& j, const SmfInfo& o);
  friend void from_json(const nlohmann::json& j, SmfInfo& o);

  [[nodiscard]] std::string to_string(int indent_level) const;

 protected:
  std::vector<ngkore::model::nrf::SnssaiSmfInfoItem> m_SNssaiSmfInfoList;

  std::vector<ngkore::model::common::Tai> m_TaiList;
  bool m_TaiListIsSet;
  std::vector<ngkore::model::nrf::TaiRange> m_TaiRangeList;
  bool m_TaiRangeListIsSet;
  std::string m_PgwFqdn;
  bool m_PgwFqdnIsSet;
  std::vector<ngkore::model::common::AccessType> m_AccessType;
  bool m_AccessTypeIsSet;
  int32_t m_Priority;
  bool m_PriorityIsSet;
  bool m_VsmfSupportInd;
  bool m_VsmfSupportIndIsSet;
};

}  // namespace ngkore::model::nrf

