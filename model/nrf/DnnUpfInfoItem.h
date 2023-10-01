
#ifndef DnnUpfInfoItem_H_
#define DnnUpfInfoItem_H_

#include <string>
#include "Ipv4AddressRange.h"
#include "PduSessionType.h"
#include <map>
#include <vector>
#include "Ipv6PrefixRange.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::nrf {

/// <summary>
/// Set of parameters supported by UPF for a given DNN
/// </summary>
class DnnUpfInfoItem {
 public:
  DnnUpfInfoItem();

  explicit DnnUpfInfoItem(const std::string& dnn);

  virtual ~DnnUpfInfoItem() = default;

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

  bool operator==(const DnnUpfInfoItem& rhs) const;
  bool operator!=(const DnnUpfInfoItem& rhs) const;

  /////////////////////////////////////////////
  /// DnnUpfInfoItem members

  /// <summary>
  ///
  /// </summary>
  std::string getDnn() const;
  void setDnn(std::string const& value);
  /// <summary>
  ///
  /// </summary>
  std::vector<std::string> getDnaiList() const;
  void setDnaiList(std::vector<std::string> const& value);
  bool dnaiListIsSet() const;
  void unsetDnaiList();
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
  std::vector<ngkore::model::nrf::Ipv4AddressRange> getIpv4AddressRanges() const;
  void setIpv4AddressRanges(
      std::vector<ngkore::model::nrf::Ipv4AddressRange> const& value);
  bool ipv4AddressRangesIsSet() const;
  void unsetIpv4AddressRanges();
  /// <summary>
  ///
  /// </summary>
  std::vector<ngkore::model::nrf::Ipv6PrefixRange> getIpv6PrefixRanges() const;
  void setIpv6PrefixRanges(
      std::vector<ngkore::model::nrf::Ipv6PrefixRange> const& value);
  bool ipv6PrefixRangesIsSet() const;
  void unsetIpv6PrefixRanges();
  /// <summary>
  /// Map of network instance per DNAI for the DNN, where the key of the map is
  /// the DNAI. When present, the value of each entry of the map shall contain a
  /// N6 network instance that is configured for the DNAI indicated by the key.
  /// </summary>
  std::map<std::string, std::string> getDnaiNwInstanceList() const;
  void setDnaiNwInstanceList(std::map<std::string, std::string> const& value);
  bool dnaiNwInstanceListIsSet() const;
  void unsetDnaiNwInstanceList();

  friend void to_json(nlohmann::json& j, const DnnUpfInfoItem& o);
  friend void from_json(const nlohmann::json& j, DnnUpfInfoItem& o);

  [[nodiscard]] std::string to_string(int indent_level) const;

 protected:
  std::string m_Dnn;

  std::vector<std::string> m_DnaiList;
  bool m_DnaiListIsSet;
  std::vector<ngkore::model::common::PduSessionType> m_PduSessionTypes;
  bool m_PduSessionTypesIsSet;
  std::vector<ngkore::model::nrf::Ipv4AddressRange> m_Ipv4AddressRanges;
  bool m_Ipv4AddressRangesIsSet;
  std::vector<ngkore::model::nrf::Ipv6PrefixRange> m_Ipv6PrefixRanges;
  bool m_Ipv6PrefixRangesIsSet;
  std::map<std::string, std::string> m_DnaiNwInstanceList;
  bool m_DnaiNwInstanceListIsSet;
};

}  // namespace ngkore::model::nrf
