
#ifndef TwifInfo_H_
#define TwifInfo_H_

#include <string>
#include "Ipv6Addr.h"
#include <vector>
#include <nlohmann/json.hpp>

namespace ngkore::model::nrf {

/// <summary>
/// Addressing information (IP addresses, FQDN) of the TWIF
/// </summary>
class TwifInfo {
 public:
  TwifInfo();
  virtual ~TwifInfo() = default;

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

  bool operator==(const TwifInfo& rhs) const;
  bool operator!=(const TwifInfo& rhs) const;

  /////////////////////////////////////////////
  /// TwifInfo members

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

  friend void to_json(nlohmann::json& j, const TwifInfo& o);
  friend void from_json(const nlohmann::json& j, TwifInfo& o);

 protected:
  std::vector<std::string> m_Ipv4EndpointAddresses;
  bool m_Ipv4EndpointAddressesIsSet;
  std::vector<ngkore::model::common::Ipv6Addr> m_Ipv6EndpointAddresses;
  bool m_Ipv6EndpointAddressesIsSet;
  std::string m_EndpointFqdn;
  bool m_EndpointFqdnIsSet;
};

}  // namespace ngkore::model::nrf

