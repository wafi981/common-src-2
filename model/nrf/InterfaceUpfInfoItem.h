
#ifndef InterfaceUpfInfoItem_H_
#define InterfaceUpfInfoItem_H_

#include <string>
#include "Ipv6Addr.h"
#include <vector>
#include "UPInterfaceType.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::nrf {

/// <summary>
/// Information of a given IP interface of an UPF
/// </summary>
class InterfaceUpfInfoItem {
 public:
  InterfaceUpfInfoItem();
  virtual ~InterfaceUpfInfoItem() = default;

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

  bool operator==(const InterfaceUpfInfoItem& rhs) const;
  bool operator!=(const InterfaceUpfInfoItem& rhs) const;

  /////////////////////////////////////////////
  /// InterfaceUpfInfoItem members

  /// <summary>
  ///
  /// </summary>
  ngkore::model::nrf::UPInterfaceType getInterfaceType() const;
  void setInterfaceType(ngkore::model::nrf::UPInterfaceType const& value);
  /// <summary>
  ///
  /// </summary>
  std::vector<std::string> getIpv4EndpointAddresses() const;
  void setIpv4EndpointAddresses(std::vector<std::string> const& value);
  bool ipv4EndpointAddressesIsSet() const;
  void unsetIpv4EndpointAddresses();
  /// <summary>
  ///
  /// </summary>
  std::vector<ngkore::model::common::Ipv6Addr> getIpv6EndpointAddresses() const;
  void setIpv6EndpointAddresses(
      std::vector<ngkore::model::common::Ipv6Addr> const& value);
  bool ipv6EndpointAddressesIsSet() const;
  void unsetIpv6EndpointAddresses();
  /// <summary>
  /// Fully Qualified Domain Name
  /// </summary>
  std::string getEndpointFqdn() const;
  void setEndpointFqdn(std::string const& value);
  bool endpointFqdnIsSet() const;
  void unsetEndpointFqdn();
  /// <summary>
  ///
  /// </summary>
  std::string getNetworkInstance() const;
  void setNetworkInstance(std::string const& value);
  bool networkInstanceIsSet() const;
  void unsetNetworkInstance();

  friend void to_json(nlohmann::json& j, const InterfaceUpfInfoItem& o);
  friend void from_json(const nlohmann::json& j, InterfaceUpfInfoItem& o);

  [[nodiscard]] std::string to_string(int indent_level) const;

 protected:
  ngkore::model::nrf::UPInterfaceType m_InterfaceType;

  std::vector<std::string> m_Ipv4EndpointAddresses;
  bool m_Ipv4EndpointAddressesIsSet;
  std::vector<ngkore::model::common::Ipv6Addr> m_Ipv6EndpointAddresses;
  bool m_Ipv6EndpointAddressesIsSet;
  std::string m_EndpointFqdn;
  bool m_EndpointFqdnIsSet;
  std::string m_NetworkInstance;
  bool m_NetworkInstanceIsSet;
};

}  // namespace ngkore::model::nrf

