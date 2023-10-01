
#ifndef RouteInformation_H_
#define RouteInformation_H_

#include <string>
#include "Ipv6Addr.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class RouteInformation {
 public:
  RouteInformation();
  virtual ~RouteInformation() = default;

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

  bool operator==(const RouteInformation& rhs) const;
  bool operator!=(const RouteInformation& rhs) const;

  /////////////////////////////////////////////
  /// RouteInformation members

  /// <summary>
  ///
  /// </summary>
  std::string getIpv4Addr() const;
  void setIpv4Addr(std::string const& value);
  bool ipv4AddrIsSet() const;
  void unsetIpv4Addr();
  /// <summary>
  ///
  /// </summary>
  ngkore::model::common::Ipv6Addr getIpv6Addr() const;
  void setIpv6Addr(ngkore::model::common::Ipv6Addr const& value);
  bool ipv6AddrIsSet() const;
  void unsetIpv6Addr();
  /// <summary>
  ///
  /// </summary>
  int32_t getPortNumber() const;
  void setPortNumber(int32_t const value);

  friend void to_json(nlohmann::json& j, const RouteInformation& o);
  friend void from_json(const nlohmann::json& j, RouteInformation& o);

 protected:
  std::string m_Ipv4Addr;
  bool m_Ipv4AddrIsSet;
  ngkore::model::common::Ipv6Addr m_Ipv6Addr;
  bool m_Ipv6AddrIsSet;
  int32_t m_PortNumber;
};

}  // namespace ngkore::model::common

