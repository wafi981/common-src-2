
#include "DnnUpfInfoItem.h"
#include "Helpers.h"
#include "config.hpp"

#include <sstream>

namespace ngkore::model::nrf {

using namespace ngkore::model::common;

DnnUpfInfoItem::DnnUpfInfoItem() {
  m_Dnn                     = "";
  m_DnaiListIsSet           = false;
  m_PduSessionTypesIsSet    = false;
  m_Ipv4AddressRangesIsSet  = false;
  m_Ipv6PrefixRangesIsSet   = false;
  m_DnaiNwInstanceListIsSet = false;
}

DnnUpfInfoItem::DnnUpfInfoItem(const std::string& dnn) : DnnUpfInfoItem() {
  m_Dnn = dnn;
}

void DnnUpfInfoItem::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool DnnUpfInfoItem::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool DnnUpfInfoItem::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "DnnUpfInfoItem" : pathPrefix;

  if (dnaiListIsSet()) {
    const std::vector<std::string>& value = m_DnaiList;
    const std::string currentValuePath    = _pathPrefix + ".dnaiList";

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

  if (pduSessionTypesIsSet()) {
    const std::vector<PduSessionType>& value = m_PduSessionTypes;
    const std::string currentValuePath       = _pathPrefix + ".pduSessionTypes";

    if (value.size() < 1) {
      success = false;
      msg << currentValuePath << ": must have at least 1 elements;";
    }
    {  // Recursive validation of array elements
      const std::string oldValuePath = currentValuePath;
      int i                          = 0;
      for (const PduSessionType& value : value) {
        const std::string currentValuePath =
            oldValuePath + "[" + std::to_string(i) + "]";

        success = value.validate(msg, currentValuePath + ".pduSessionTypes") &&
                  success;

        i++;
      }
    }
  }

  if (ipv4AddressRangesIsSet()) {
    const std::vector<ngkore::model::nrf::Ipv4AddressRange>& value =
        m_Ipv4AddressRanges;
    const std::string currentValuePath = _pathPrefix + ".ipv4AddressRanges";

    if (value.size() < 1) {
      success = false;
      msg << currentValuePath << ": must have at least 1 elements;";
    }
    {  // Recursive validation of array elements
      const std::string oldValuePath = currentValuePath;
      int i                          = 0;
      for (const ngkore::model::nrf::Ipv4AddressRange& value : value) {
        const std::string currentValuePath =
            oldValuePath + "[" + std::to_string(i) + "]";

        success =
            value.validate(msg, currentValuePath + ".ipv4AddressRanges") &&
            success;

        i++;
      }
    }
  }

  if (ipv6PrefixRangesIsSet()) {
    const std::vector<ngkore::model::nrf::Ipv6PrefixRange>& value =
        m_Ipv6PrefixRanges;
    const std::string currentValuePath = _pathPrefix + ".ipv6PrefixRanges";

    if (value.size() < 1) {
      success = false;
      msg << currentValuePath << ": must have at least 1 elements;";
    }
    {  // Recursive validation of array elements
      const std::string oldValuePath = currentValuePath;
      int i                          = 0;
      for (const ngkore::model::nrf::Ipv6PrefixRange& value : value) {
        const std::string currentValuePath =
            oldValuePath + "[" + std::to_string(i) + "]";

        success = value.validate(msg, currentValuePath + ".ipv6PrefixRanges") &&
                  success;

        i++;
      }
    }
  }

  if (dnaiNwInstanceListIsSet()) {
    const std::map<std::string, std::string>& value = m_DnaiNwInstanceList;
    const std::string currentValuePath = _pathPrefix + ".dnaiNwInstanceList";
  }

  return success;
}

bool DnnUpfInfoItem::operator==(const DnnUpfInfoItem& rhs) const {
  return

      (getDnn() == rhs.getDnn()) &&

      ((!dnaiListIsSet() && !rhs.dnaiListIsSet()) ||
       (dnaiListIsSet() && rhs.dnaiListIsSet() &&
        getDnaiList() == rhs.getDnaiList())) &&

      ((!pduSessionTypesIsSet() && !rhs.pduSessionTypesIsSet()) ||
       (pduSessionTypesIsSet() && rhs.pduSessionTypesIsSet() &&
        getPduSessionTypes() == rhs.getPduSessionTypes())) &&

      ((!ipv4AddressRangesIsSet() && !rhs.ipv4AddressRangesIsSet()) ||
       (ipv4AddressRangesIsSet() && rhs.ipv4AddressRangesIsSet() &&
        getIpv4AddressRanges() == rhs.getIpv4AddressRanges())) &&

      ((!ipv6PrefixRangesIsSet() && !rhs.ipv6PrefixRangesIsSet()) ||
       (ipv6PrefixRangesIsSet() && rhs.ipv6PrefixRangesIsSet() &&
        getIpv6PrefixRanges() == rhs.getIpv6PrefixRanges())) &&

      ((!dnaiNwInstanceListIsSet() && !rhs.dnaiNwInstanceListIsSet()) ||
       (dnaiNwInstanceListIsSet() && rhs.dnaiNwInstanceListIsSet() &&
        getDnaiNwInstanceList() == rhs.getDnaiNwInstanceList()))

          ;
}

bool DnnUpfInfoItem::operator!=(const DnnUpfInfoItem& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const DnnUpfInfoItem& o) {
  j        = nlohmann::json();
  j["dnn"] = o.m_Dnn;
  if (o.dnaiListIsSet() || !o.m_DnaiList.empty()) j["dnaiList"] = o.m_DnaiList;
  if (o.pduSessionTypesIsSet() || !o.m_PduSessionTypes.empty())
    j["pduSessionTypes"] = o.m_PduSessionTypes;
  if (o.ipv4AddressRangesIsSet() || !o.m_Ipv4AddressRanges.empty())
    j["ipv4AddressRanges"] = o.m_Ipv4AddressRanges;
  if (o.ipv6PrefixRangesIsSet() || !o.m_Ipv6PrefixRanges.empty())
    j["ipv6PrefixRanges"] = o.m_Ipv6PrefixRanges;
  if (o.dnaiNwInstanceListIsSet() || !o.m_DnaiNwInstanceList.empty())
    j["dnaiNwInstanceList"] = o.m_DnaiNwInstanceList;
}

void from_json(const nlohmann::json& j, DnnUpfInfoItem& o) {
  j.at("dnn").get_to(o.m_Dnn);
  if (j.find("dnaiList") != j.end()) {
    j.at("dnaiList").get_to(o.m_DnaiList);
    o.m_DnaiListIsSet = true;
  }
  if (j.find("pduSessionTypes") != j.end()) {
    j.at("pduSessionTypes").get_to(o.m_PduSessionTypes);
    o.m_PduSessionTypesIsSet = true;
  }
  if (j.find("ipv4AddressRanges") != j.end()) {
    j.at("ipv4AddressRanges").get_to(o.m_Ipv4AddressRanges);
    o.m_Ipv4AddressRangesIsSet = true;
  }
  if (j.find("ipv6PrefixRanges") != j.end()) {
    j.at("ipv6PrefixRanges").get_to(o.m_Ipv6PrefixRanges);
    o.m_Ipv6PrefixRangesIsSet = true;
  }
  if (j.find("dnaiNwInstanceList") != j.end()) {
    j.at("dnaiNwInstanceList").get_to(o.m_DnaiNwInstanceList);
    o.m_DnaiNwInstanceListIsSet = true;
  }
}

std::string DnnUpfInfoItem::getDnn() const {
  return m_Dnn;
}
void DnnUpfInfoItem::setDnn(std::string const& value) {
  m_Dnn = value;
}
std::vector<std::string> DnnUpfInfoItem::getDnaiList() const {
  return m_DnaiList;
}
void DnnUpfInfoItem::setDnaiList(std::vector<std::string> const& value) {
  m_DnaiList      = value;
  m_DnaiListIsSet = true;
}
bool DnnUpfInfoItem::dnaiListIsSet() const {
  return m_DnaiListIsSet;
}
void DnnUpfInfoItem::unsetDnaiList() {
  m_DnaiListIsSet = false;
}
std::vector<PduSessionType> DnnUpfInfoItem::getPduSessionTypes() const {
  return m_PduSessionTypes;
}
void DnnUpfInfoItem::setPduSessionTypes(
    std::vector<PduSessionType> const& value) {
  m_PduSessionTypes      = value;
  m_PduSessionTypesIsSet = true;
}
bool DnnUpfInfoItem::pduSessionTypesIsSet() const {
  return m_PduSessionTypesIsSet;
}
void DnnUpfInfoItem::unsetPduSessionTypes() {
  m_PduSessionTypesIsSet = false;
}
std::vector<ngkore::model::nrf::Ipv4AddressRange>
DnnUpfInfoItem::getIpv4AddressRanges() const {
  return m_Ipv4AddressRanges;
}
void DnnUpfInfoItem::setIpv4AddressRanges(
    std::vector<ngkore::model::nrf::Ipv4AddressRange> const& value) {
  m_Ipv4AddressRanges      = value;
  m_Ipv4AddressRangesIsSet = true;
}
bool DnnUpfInfoItem::ipv4AddressRangesIsSet() const {
  return m_Ipv4AddressRangesIsSet;
}
void DnnUpfInfoItem::unsetIpv4AddressRanges() {
  m_Ipv4AddressRangesIsSet = false;
}
std::vector<ngkore::model::nrf::Ipv6PrefixRange>
DnnUpfInfoItem::getIpv6PrefixRanges() const {
  return m_Ipv6PrefixRanges;
}
void DnnUpfInfoItem::setIpv6PrefixRanges(
    std::vector<ngkore::model::nrf::Ipv6PrefixRange> const& value) {
  m_Ipv6PrefixRanges      = value;
  m_Ipv6PrefixRangesIsSet = true;
}
bool DnnUpfInfoItem::ipv6PrefixRangesIsSet() const {
  return m_Ipv6PrefixRangesIsSet;
}
void DnnUpfInfoItem::unsetIpv6PrefixRanges() {
  m_Ipv6PrefixRangesIsSet = false;
}
std::map<std::string, std::string> DnnUpfInfoItem::getDnaiNwInstanceList()
    const {
  return m_DnaiNwInstanceList;
}
void DnnUpfInfoItem::setDnaiNwInstanceList(
    std::map<std::string, std::string> const& value) {
  m_DnaiNwInstanceList      = value;
  m_DnaiNwInstanceListIsSet = true;
}
bool DnnUpfInfoItem::dnaiNwInstanceListIsSet() const {
  return m_DnaiNwInstanceListIsSet;
}
void DnnUpfInfoItem::unsetDnaiNwInstanceList() {
  m_DnaiNwInstanceListIsSet = false;
}

std::string DnnUpfInfoItem::to_string(int indent_level) const {
  std::string out;
  std::string fmt_value = ngkore::config::get_value_formatter(indent_level);
  std::string fmt_value_inner =
      ngkore::config::get_value_formatter(indent_level + 1);
  std::string fmt_title = ngkore::config::get_title_formatter(indent_level);
  out.append(fmt::format(fmt_value, "dnn", m_Dnn));

  if (m_DnaiListIsSet) {
    out.append(fmt::format(fmt_title, "dnai_list:"));
    for (const auto& dnai : m_DnaiList) {
      out.append(fmt::format(fmt_value_inner, "dnai", dnai));
    }
  }
  if (m_DnaiNwInstanceListIsSet) {
    out.append(fmt::format(fmt_title, "dnai_nw_instance_list:"));
    for (const auto& nwi : m_DnaiNwInstanceList) {
      out.append(fmt::format(fmt_value_inner, nwi.first, nwi.second));
    }
  }

  // TODO other values
  return out;
}
}  // namespace ngkore::model::nrf
