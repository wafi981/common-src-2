
#include "UpfInfo.h"
#include "Helpers.h"
#include "config.hpp"

#include <sstream>

namespace ngkore::model::nrf {
using namespace ngkore::model::common;

UpfInfo::UpfInfo() {
  m_SmfServingAreaIsSet       = false;
  m_InterfaceUpfInfoListIsSet = false;
  m_IwkEpsInd                 = false;
  m_IwkEpsIndIsSet            = false;
  m_PduSessionTypesIsSet      = false;
  m_AtsssCapabilityIsSet      = false;
  m_UeIpAddrInd               = false;
  m_UeIpAddrIndIsSet          = false;
  m_TaiListIsSet              = false;
  m_WAgfInfoIsSet             = false;
  m_TngfInfoIsSet             = false;
  m_TwifInfoIsSet             = false;
  m_Priority                  = 0;
  m_PriorityIsSet             = false;
  m_RedundantGtpu             = false;
  m_RedundantGtpuIsSet        = false;
  m_Ipups                     = false;
  m_IpupsIsSet                = false;
  m_DataForwarding            = false;
  m_DataForwardingIsSet       = false;
}

void UpfInfo::validate(bool check_snssai) const {
  std::stringstream msg;
  if (!validate(msg, check_snssai)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool UpfInfo::validate(std::stringstream& msg, bool check_snssai) const {
  return validate(msg, "", check_snssai);
}

bool UpfInfo::validate(
    std::stringstream& msg, const std::string& pathPrefix,
    bool check_snssai) const {
  bool success                  = true;
  const std::string _pathPrefix = pathPrefix.empty() ? "UpfInfo" : pathPrefix;

  if (check_snssai) {
    const std::vector<ngkore::model::nrf::SnssaiUpfInfoItem>& value =
        m_SNssaiUpfInfoList;
    const std::string currentValuePath = _pathPrefix + ".sNssaiUpfInfoList";

    if (value.size() < 1) {
      success = false;
      msg << currentValuePath << ": must have at least 1 elements;";
    }
    {  // Recursive validation of array elements
      const std::string oldValuePath = currentValuePath;
      int i                          = 0;
      for (const ngkore::model::nrf::SnssaiUpfInfoItem& value : value) {
        const std::string currentValuePath =
            oldValuePath + "[" + std::to_string(i) + "]";

        success =
            value.validate(msg, currentValuePath + ".sNssaiUpfInfoList") &&
            success;

        i++;
      }
    }
  }

  if (smfServingAreaIsSet()) {
    const std::vector<std::string>& value = m_SmfServingArea;
    const std::string currentValuePath    = _pathPrefix + ".smfServingArea";

    if (value.size() < 1) {
      success = false;
      msg << currentValuePath << ": must have at least 1 elements;";
    }
    {  // Recursive validation of array elements
      const std::string oldValuePath = currentValuePath;
      int i                          = 0;
      for (const std::string& value : value) {
        const std::string currentValuePath =
            oldValuePath + "[" + std::to_string(i) + "]";

        i++;
      }
    }
  }

  if (interfaceUpfInfoListIsSet()) {
    const std::vector<ngkore::model::nrf::InterfaceUpfInfoItem>& value =
        m_InterfaceUpfInfoList;
    const std::string currentValuePath = _pathPrefix + ".interfaceUpfInfoList";

    if (value.size() < 1) {
      success = false;
      msg << currentValuePath << ": must have at least 1 elements;";
    }
    {  // Recursive validation of array elements
      const std::string oldValuePath = currentValuePath;
      int i                          = 0;
      for (const ngkore::model::nrf::InterfaceUpfInfoItem& value : value) {
        const std::string currentValuePath =
            oldValuePath + "[" + std::to_string(i) + "]";

        success =
            value.validate(msg, currentValuePath + ".interfaceUpfInfoList") &&
            success;

        i++;
      }
    }
  }

  if (pduSessionTypesIsSet()) {
    const std::vector<ngkore::model::nrf::PduSessionType>& value =
        m_PduSessionTypes;
    const std::string currentValuePath = _pathPrefix + ".pduSessionTypes";

    if (value.size() < 1) {
      success = false;
      msg << currentValuePath << ": must have at least 1 elements;";
    }
    {  // Recursive validation of array elements
      const std::string oldValuePath = currentValuePath;
      int i                          = 0;
      for (const ngkore::model::nrf::PduSessionType& value : value) {
        const std::string currentValuePath =
            oldValuePath + "[" + std::to_string(i) + "]";

        success = value.validate(msg, currentValuePath + ".pduSessionTypes") &&
                  success;

        i++;
      }
    }
  }

  if (taiListIsSet()) {
    const std::vector<ngkore::model::nrf::Tai>& value = m_TaiList;
    const std::string currentValuePath             = _pathPrefix + ".taiList";

    if (value.size() < 1) {
      success = false;
      msg << currentValuePath << ": must have at least 1 elements;";
    }
    {  // Recursive validation of array elements
      const std::string oldValuePath = currentValuePath;
      int i                          = 0;
      for (const ngkore::model::nrf::Tai& value : value) {
        const std::string currentValuePath =
            oldValuePath + "[" + std::to_string(i) + "]";

        success = value.validate(msg, currentValuePath + ".taiList") && success;

        i++;
      }
    }
  }

  if (priorityIsSet()) {
    const int32_t& value               = m_Priority;
    const std::string currentValuePath = _pathPrefix + ".priority";

    if (value < 0) {
      success = false;
      msg << currentValuePath << ": must be greater than or equal to 0;";
    }
    if (value > 65535) {
      success = false;
      msg << currentValuePath << ": must be less than or equal to 65535;";
    }
  }

  return success;
}

bool UpfInfo::operator==(const UpfInfo& rhs) const {
  return

      (getSNssaiUpfInfoList() == rhs.getSNssaiUpfInfoList()) &&

      ((!smfServingAreaIsSet() && !rhs.smfServingAreaIsSet()) ||
       (smfServingAreaIsSet() && rhs.smfServingAreaIsSet() &&
        getSmfServingArea() == rhs.getSmfServingArea())) &&

      ((!interfaceUpfInfoListIsSet() && !rhs.interfaceUpfInfoListIsSet()) ||
       (interfaceUpfInfoListIsSet() && rhs.interfaceUpfInfoListIsSet() &&
        getInterfaceUpfInfoList() == rhs.getInterfaceUpfInfoList())) &&

      ((!iwkEpsIndIsSet() && !rhs.iwkEpsIndIsSet()) ||
       (iwkEpsIndIsSet() && rhs.iwkEpsIndIsSet() &&
        isIwkEpsInd() == rhs.isIwkEpsInd())) &&

      ((!pduSessionTypesIsSet() && !rhs.pduSessionTypesIsSet()) ||
       (pduSessionTypesIsSet() && rhs.pduSessionTypesIsSet() &&
        getPduSessionTypes() == rhs.getPduSessionTypes())) &&

      ((!atsssCapabilityIsSet() && !rhs.atsssCapabilityIsSet()) ||
       (atsssCapabilityIsSet() && rhs.atsssCapabilityIsSet() &&
        getAtsssCapability() == rhs.getAtsssCapability())) &&

      ((!ueIpAddrIndIsSet() && !rhs.ueIpAddrIndIsSet()) ||
       (ueIpAddrIndIsSet() && rhs.ueIpAddrIndIsSet() &&
        isUeIpAddrInd() == rhs.isUeIpAddrInd())) &&

      ((!taiListIsSet() && !rhs.taiListIsSet()) ||
       (taiListIsSet() && rhs.taiListIsSet() &&
        getTaiList() == rhs.getTaiList())) &&

      ((!wAgfInfoIsSet() && !rhs.wAgfInfoIsSet()) ||
       (wAgfInfoIsSet() && rhs.wAgfInfoIsSet() &&
        getWAgfInfo() == rhs.getWAgfInfo())) &&

      ((!tngfInfoIsSet() && !rhs.tngfInfoIsSet()) ||
       (tngfInfoIsSet() && rhs.tngfInfoIsSet() &&
        getTngfInfo() == rhs.getTngfInfo())) &&

      ((!twifInfoIsSet() && !rhs.twifInfoIsSet()) ||
       (twifInfoIsSet() && rhs.twifInfoIsSet() &&
        getTwifInfo() == rhs.getTwifInfo())) &&

      ((!priorityIsSet() && !rhs.priorityIsSet()) ||
       (priorityIsSet() && rhs.priorityIsSet() &&
        getPriority() == rhs.getPriority())) &&

      ((!redundantGtpuIsSet() && !rhs.redundantGtpuIsSet()) ||
       (redundantGtpuIsSet() && rhs.redundantGtpuIsSet() &&
        isRedundantGtpu() == rhs.isRedundantGtpu())) &&

      ((!ipupsIsSet() && !rhs.ipupsIsSet()) ||
       (ipupsIsSet() && rhs.ipupsIsSet() && isIpups() == rhs.isIpups())) &&

      ((!dataForwardingIsSet() && !rhs.dataForwardingIsSet()) ||
       (dataForwardingIsSet() && rhs.dataForwardingIsSet() &&
        isDataForwarding() == rhs.isDataForwarding()))

          ;
}

bool UpfInfo::operator!=(const UpfInfo& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const UpfInfo& o) {
  j                      = nlohmann::json();
  j["sNssaiUpfInfoList"] = o.m_SNssaiUpfInfoList;
  if (o.smfServingAreaIsSet() || !o.m_SmfServingArea.empty())
    j["smfServingArea"] = o.m_SmfServingArea;
  if (o.interfaceUpfInfoListIsSet() || !o.m_InterfaceUpfInfoList.empty())
    j["interfaceUpfInfoList"] = o.m_InterfaceUpfInfoList;
  if (o.iwkEpsIndIsSet()) j["iwkEpsInd"] = o.m_IwkEpsInd;
  if (o.pduSessionTypesIsSet() || !o.m_PduSessionTypes.empty())
    j["pduSessionTypes"] = o.m_PduSessionTypes;
  if (o.atsssCapabilityIsSet()) j["atsssCapability"] = o.m_AtsssCapability;
  if (o.ueIpAddrIndIsSet()) j["ueIpAddrInd"] = o.m_UeIpAddrInd;
  if (o.taiListIsSet() || !o.m_TaiList.empty()) j["taiList"] = o.m_TaiList;
  if (o.wAgfInfoIsSet()) j["wAgfInfo"] = o.m_WAgfInfo;
  if (o.tngfInfoIsSet()) j["tngfInfo"] = o.m_TngfInfo;
  if (o.twifInfoIsSet()) j["twifInfo"] = o.m_TwifInfo;
  if (o.priorityIsSet()) j["priority"] = o.m_Priority;
  if (o.redundantGtpuIsSet()) j["redundantGtpu"] = o.m_RedundantGtpu;
  if (o.ipupsIsSet()) j["ipups"] = o.m_Ipups;
  if (o.dataForwardingIsSet()) j["dataForwarding"] = o.m_DataForwarding;
}

void from_json(const nlohmann::json& j, UpfInfo& o) {
  // "sNssaiUpfInfoList is mandatory, but because we use it also from yaml
  // config, we have to check it here
  if (j.find("sNssaiUpfInfoList") != j.end()) {
    j.at("sNssaiUpfInfoList").get_to(o.m_SNssaiUpfInfoList);
  }
  if (j.find("smfServingArea") != j.end()) {
    j.at("smfServingArea").get_to(o.m_SmfServingArea);
    o.m_SmfServingAreaIsSet = true;
  }
  if (j.find("interfaceUpfInfoList") != j.end()) {
    j.at("interfaceUpfInfoList").get_to(o.m_InterfaceUpfInfoList);
    o.m_InterfaceUpfInfoListIsSet = true;
  }
  if (j.find("iwkEpsInd") != j.end()) {
    j.at("iwkEpsInd").get_to(o.m_IwkEpsInd);
    o.m_IwkEpsIndIsSet = true;
  }
  if (j.find("pduSessionTypes") != j.end()) {
    j.at("pduSessionTypes").get_to(o.m_PduSessionTypes);
    o.m_PduSessionTypesIsSet = true;
  }
  if (j.find("atsssCapability") != j.end()) {
    j.at("atsssCapability").get_to(o.m_AtsssCapability);
    o.m_AtsssCapabilityIsSet = true;
  }
  if (j.find("ueIpAddrInd") != j.end()) {
    j.at("ueIpAddrInd").get_to(o.m_UeIpAddrInd);
    o.m_UeIpAddrIndIsSet = true;
  }
  if (j.find("taiList") != j.end()) {
    j.at("taiList").get_to(o.m_TaiList);
    o.m_TaiListIsSet = true;
  }
  if (j.find("wAgfInfo") != j.end()) {
    j.at("wAgfInfo").get_to(o.m_WAgfInfo);
    o.m_WAgfInfoIsSet = true;
  }
  if (j.find("tngfInfo") != j.end()) {
    j.at("tngfInfo").get_to(o.m_TngfInfo);
    o.m_TngfInfoIsSet = true;
  }
  if (j.find("twifInfo") != j.end()) {
    j.at("twifInfo").get_to(o.m_TwifInfo);
    o.m_TwifInfoIsSet = true;
  }
  if (j.find("priority") != j.end()) {
    j.at("priority").get_to(o.m_Priority);
    o.m_PriorityIsSet = true;
  }
  if (j.find("redundantGtpu") != j.end()) {
    j.at("redundantGtpu").get_to(o.m_RedundantGtpu);
    o.m_RedundantGtpuIsSet = true;
  }
  if (j.find("ipups") != j.end()) {
    j.at("ipups").get_to(o.m_Ipups);
    o.m_IpupsIsSet = true;
  }
  if (j.find("dataForwarding") != j.end()) {
    j.at("dataForwarding").get_to(o.m_DataForwarding);
    o.m_DataForwardingIsSet = true;
  }
}

std::vector<ngkore::model::nrf::SnssaiUpfInfoItem> UpfInfo::getSNssaiUpfInfoList()
    const {
  return m_SNssaiUpfInfoList;
}
void UpfInfo::setSNssaiUpfInfoList(
    std::vector<ngkore::model::nrf::SnssaiUpfInfoItem> const& value) {
  m_SNssaiUpfInfoList = value;
}
std::vector<std::string> UpfInfo::getSmfServingArea() const {
  return m_SmfServingArea;
}
void UpfInfo::setSmfServingArea(std::vector<std::string> const& value) {
  m_SmfServingArea      = value;
  m_SmfServingAreaIsSet = true;
}
bool UpfInfo::smfServingAreaIsSet() const {
  return m_SmfServingAreaIsSet;
}
void UpfInfo::unsetSmfServingArea() {
  m_SmfServingAreaIsSet = false;
}
std::vector<ngkore::model::nrf::InterfaceUpfInfoItem>
UpfInfo::getInterfaceUpfInfoList() const {
  return m_InterfaceUpfInfoList;
}
void UpfInfo::setInterfaceUpfInfoList(
    std::vector<ngkore::model::nrf::InterfaceUpfInfoItem> const& value) {
  m_InterfaceUpfInfoList      = value;
  m_InterfaceUpfInfoListIsSet = true;
}
bool UpfInfo::interfaceUpfInfoListIsSet() const {
  return m_InterfaceUpfInfoListIsSet;
}
void UpfInfo::unsetInterfaceUpfInfoList() {
  m_InterfaceUpfInfoListIsSet = false;
}
bool UpfInfo::isIwkEpsInd() const {
  return m_IwkEpsInd;
}
void UpfInfo::setIwkEpsInd(bool const value) {
  m_IwkEpsInd      = value;
  m_IwkEpsIndIsSet = true;
}
bool UpfInfo::iwkEpsIndIsSet() const {
  return m_IwkEpsIndIsSet;
}
void UpfInfo::unsetIwkEpsInd() {
  m_IwkEpsIndIsSet = false;
}
std::vector<ngkore::model::nrf::PduSessionType> UpfInfo::getPduSessionTypes()
    const {
  return m_PduSessionTypes;
}
void UpfInfo::setPduSessionTypes(
    std::vector<ngkore::model::nrf::PduSessionType> const& value) {
  m_PduSessionTypes      = value;
  m_PduSessionTypesIsSet = true;
}
bool UpfInfo::pduSessionTypesIsSet() const {
  return m_PduSessionTypesIsSet;
}
void UpfInfo::unsetPduSessionTypes() {
  m_PduSessionTypesIsSet = false;
}
ngkore::model::nrf::AtsssCapability UpfInfo::getAtsssCapability() const {
  return m_AtsssCapability;
}
void UpfInfo::setAtsssCapability(
    ngkore::model::nrf::AtsssCapability const& value) {
  m_AtsssCapability      = value;
  m_AtsssCapabilityIsSet = true;
}
bool UpfInfo::atsssCapabilityIsSet() const {
  return m_AtsssCapabilityIsSet;
}
void UpfInfo::unsetAtsssCapability() {
  m_AtsssCapabilityIsSet = false;
}
bool UpfInfo::isUeIpAddrInd() const {
  return m_UeIpAddrInd;
}
void UpfInfo::setUeIpAddrInd(bool const value) {
  m_UeIpAddrInd      = value;
  m_UeIpAddrIndIsSet = true;
}
bool UpfInfo::ueIpAddrIndIsSet() const {
  return m_UeIpAddrIndIsSet;
}
void UpfInfo::unsetUeIpAddrInd() {
  m_UeIpAddrIndIsSet = false;
}
std::vector<ngkore::model::nrf::Tai> UpfInfo::getTaiList() const {
  return m_TaiList;
}
void UpfInfo::setTaiList(std::vector<ngkore::model::nrf::Tai> const& value) {
  m_TaiList      = value;
  m_TaiListIsSet = true;
}
bool UpfInfo::taiListIsSet() const {
  return m_TaiListIsSet;
}
void UpfInfo::unsetTaiList() {
  m_TaiListIsSet = false;
}
ngkore::model::nrf::WAgfInfo UpfInfo::getWAgfInfo() const {
  return m_WAgfInfo;
}
void UpfInfo::setWAgfInfo(ngkore::model::nrf::WAgfInfo const& value) {
  m_WAgfInfo      = value;
  m_WAgfInfoIsSet = true;
}
bool UpfInfo::wAgfInfoIsSet() const {
  return m_WAgfInfoIsSet;
}
void UpfInfo::unsetWAgfInfo() {
  m_WAgfInfoIsSet = false;
}
ngkore::model::nrf::TngfInfo UpfInfo::getTngfInfo() const {
  return m_TngfInfo;
}
void UpfInfo::setTngfInfo(ngkore::model::nrf::TngfInfo const& value) {
  m_TngfInfo      = value;
  m_TngfInfoIsSet = true;
}
bool UpfInfo::tngfInfoIsSet() const {
  return m_TngfInfoIsSet;
}
void UpfInfo::unsetTngfInfo() {
  m_TngfInfoIsSet = false;
}
ngkore::model::nrf::TwifInfo UpfInfo::getTwifInfo() const {
  return m_TwifInfo;
}
void UpfInfo::setTwifInfo(ngkore::model::nrf::TwifInfo const& value) {
  m_TwifInfo      = value;
  m_TwifInfoIsSet = true;
}
bool UpfInfo::twifInfoIsSet() const {
  return m_TwifInfoIsSet;
}
void UpfInfo::unsetTwifInfo() {
  m_TwifInfoIsSet = false;
}
int32_t UpfInfo::getPriority() const {
  return m_Priority;
}
void UpfInfo::setPriority(int32_t const value) {
  m_Priority      = value;
  m_PriorityIsSet = true;
}
bool UpfInfo::priorityIsSet() const {
  return m_PriorityIsSet;
}
void UpfInfo::unsetPriority() {
  m_PriorityIsSet = false;
}
bool UpfInfo::isRedundantGtpu() const {
  return m_RedundantGtpu;
}
void UpfInfo::setRedundantGtpu(bool const value) {
  m_RedundantGtpu      = value;
  m_RedundantGtpuIsSet = true;
}
bool UpfInfo::redundantGtpuIsSet() const {
  return m_RedundantGtpuIsSet;
}
void UpfInfo::unsetRedundantGtpu() {
  m_RedundantGtpuIsSet = false;
}
bool UpfInfo::isIpups() const {
  return m_Ipups;
}
void UpfInfo::setIpups(bool const value) {
  m_Ipups      = value;
  m_IpupsIsSet = true;
}
bool UpfInfo::ipupsIsSet() const {
  return m_IpupsIsSet;
}
void UpfInfo::unsetIpups() {
  m_IpupsIsSet = false;
}
bool UpfInfo::isDataForwarding() const {
  return m_DataForwarding;
}
void UpfInfo::setDataForwarding(bool const value) {
  m_DataForwarding      = value;
  m_DataForwardingIsSet = true;
}
bool UpfInfo::dataForwardingIsSet() const {
  return m_DataForwardingIsSet;
}
void UpfInfo::unsetDataForwarding() {
  m_DataForwardingIsSet = false;
}

std::string UpfInfo::to_string(int indent_level) const {
  std::string out;

  std::string fmt_title = ngkore::config::get_title_formatter(indent_level);
  out.append(fmt::format(fmt_title, "upf_info:"));

  if (!m_SNssaiUpfInfoList.empty()) {
    for (const auto& info : m_SNssaiUpfInfoList) {
      out.append(info.to_string(indent_level + 1));
    }
  }
  if (!m_InterfaceUpfInfoList.empty()) {
    for (const auto& iface : m_InterfaceUpfInfoList) {
      out.append(iface.to_string(indent_level + 1));
    }
  }
  return out;
  // TODO other values
}
}  // namespace ngkore::model::nrf
