
#ifndef UpfInfo_H_
#define UpfInfo_H_

#include "AtsssCapability.h"
#include "TwifInfo.h"
#include "WAgfInfo.h"
#include "Tai.h"
#include "InterfaceUpfInfoItem.h"
#include "SnssaiUpfInfoItem.h"
#include <string>
#include "PduSessionType.h"
#include <vector>
#include "TngfInfo.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::nrf {

/// <summary>
/// Information of an UPF NF Instance
/// </summary>
class UpfInfo {
 public:
  UpfInfo();
  virtual ~UpfInfo() = default;

  /// <summary>
  /// Validate the current data in the model. Throws a ValidationException on
  /// failure.
  /// </summary>
  void validate(bool check_nssai = true) const;

  /// <summary>
  /// Validate the current data in the model. Returns false on error and writes
  /// an error message into the given stringstream.
  /// </summary>
  bool validate(std::stringstream& msg, bool check_nssai = true) const;

  /// <summary>
  /// Helper overload for validate. Used when one model stores another model and
  /// calls it's validate. Not meant to be called outside that case.
  /// </summary>
  bool validate(
      std::stringstream& msg, const std::string& pathPrefix,
      bool check_nssai = true) const;

  bool operator==(const UpfInfo& rhs) const;
  bool operator!=(const UpfInfo& rhs) const;

  /////////////////////////////////////////////
  /// UpfInfo members

  /// <summary>
  ///
  /// </summary>
  std::vector<ngkore::model::nrf::SnssaiUpfInfoItem> getSNssaiUpfInfoList() const;
  void setSNssaiUpfInfoList(
      std::vector<ngkore::model::nrf::SnssaiUpfInfoItem> const& value);
  /// <summary>
  ///
  /// </summary>
  std::vector<std::string> getSmfServingArea() const;
  void setSmfServingArea(std::vector<std::string> const& value);
  bool smfServingAreaIsSet() const;
  void unsetSmfServingArea();
  /// <summary>
  ///
  /// </summary>
  std::vector<ngkore::model::nrf::InterfaceUpfInfoItem> getInterfaceUpfInfoList()
      const;
  void setInterfaceUpfInfoList(
      std::vector<ngkore::model::nrf::InterfaceUpfInfoItem> const& value);
  bool interfaceUpfInfoListIsSet() const;
  void unsetInterfaceUpfInfoList();
  /// <summary>
  ///
  /// </summary>
  bool isIwkEpsInd() const;
  void setIwkEpsInd(bool const value);
  bool iwkEpsIndIsSet() const;
  void unsetIwkEpsInd();
  /// <summary>
  ///
  /// </summary>
  std::vector<ngkore::model::common::PduSessionType> getPduSessionTypes() const;
  void setPduSessionTypes(
      std::vector<ngkore::model::common::PduSessionType> const& value);
  bool pduSessionTypesIsSet() const;
  void unsetPduSessionTypes();
  /// <summary>
  ///
  /// </summary>
  ngkore::model::common::AtsssCapability getAtsssCapability() const;
  void setAtsssCapability(ngkore::model::common::AtsssCapability const& value);
  bool atsssCapabilityIsSet() const;
  void unsetAtsssCapability();
  /// <summary>
  ///
  /// </summary>
  bool isUeIpAddrInd() const;
  void setUeIpAddrInd(bool const value);
  bool ueIpAddrIndIsSet() const;
  void unsetUeIpAddrInd();
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
  ngkore::model::nrf::WAgfInfo getWAgfInfo() const;
  void setWAgfInfo(ngkore::model::nrf::WAgfInfo const& value);
  bool wAgfInfoIsSet() const;
  void unsetWAgfInfo();
  /// <summary>
  ///
  /// </summary>
  ngkore::model::nrf::TngfInfo getTngfInfo() const;
  void setTngfInfo(ngkore::model::nrf::TngfInfo const& value);
  bool tngfInfoIsSet() const;
  void unsetTngfInfo();
  /// <summary>
  ///
  /// </summary>
  ngkore::model::nrf::TwifInfo getTwifInfo() const;
  void setTwifInfo(ngkore::model::nrf::TwifInfo const& value);
  bool twifInfoIsSet() const;
  void unsetTwifInfo();
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
  bool isRedundantGtpu() const;
  void setRedundantGtpu(bool const value);
  bool redundantGtpuIsSet() const;
  void unsetRedundantGtpu();
  /// <summary>
  ///
  /// </summary>
  bool isIpups() const;
  void setIpups(bool const value);
  bool ipupsIsSet() const;
  void unsetIpups();
  /// <summary>
  ///
  /// </summary>
  bool isDataForwarding() const;
  void setDataForwarding(bool const value);
  bool dataForwardingIsSet() const;
  void unsetDataForwarding();

  friend void to_json(nlohmann::json& j, const UpfInfo& o);
  friend void from_json(const nlohmann::json& j, UpfInfo& o);

  [[nodiscard]] std::string to_string(int indent_level) const;

 protected:
  std::vector<ngkore::model::nrf::SnssaiUpfInfoItem> m_SNssaiUpfInfoList;

  std::vector<std::string> m_SmfServingArea;
  bool m_SmfServingAreaIsSet;
  std::vector<ngkore::model::nrf::InterfaceUpfInfoItem> m_InterfaceUpfInfoList;
  bool m_InterfaceUpfInfoListIsSet;
  bool m_IwkEpsInd;
  bool m_IwkEpsIndIsSet;
  std::vector<ngkore::model::common::PduSessionType> m_PduSessionTypes;
  bool m_PduSessionTypesIsSet;
  ngkore::model::common::AtsssCapability m_AtsssCapability;
  bool m_AtsssCapabilityIsSet;
  bool m_UeIpAddrInd;
  bool m_UeIpAddrIndIsSet;
  std::vector<ngkore::model::common::Tai> m_TaiList;
  bool m_TaiListIsSet;
  ngkore::model::nrf::WAgfInfo m_WAgfInfo;
  bool m_WAgfInfoIsSet;
  ngkore::model::nrf::TngfInfo m_TngfInfo;
  bool m_TngfInfoIsSet;
  ngkore::model::nrf::TwifInfo m_TwifInfo;
  bool m_TwifInfoIsSet;
  int32_t m_Priority;
  bool m_PriorityIsSet;
  bool m_RedundantGtpu;
  bool m_RedundantGtpuIsSet;
  bool m_Ipups;
  bool m_IpupsIsSet;
  bool m_DataForwarding;
  bool m_DataForwardingIsSet;
};

}  // namespace ngkore::model::nrf

