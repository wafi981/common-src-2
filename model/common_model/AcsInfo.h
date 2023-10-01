
#ifndef AcsInfo_H_
#define AcsInfo_H_

#include <string>
#include "Ipv6Addr.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class AcsInfo {
 public:
  AcsInfo();
  virtual ~AcsInfo() = default;

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

  bool operator==(const AcsInfo& rhs) const;
  bool operator!=(const AcsInfo& rhs) const;

  /////////////////////////////////////////////
  /// AcsInfo members

  /// <summary>
  ///
  /// </summary>
  std::string getAcsUrl() const;
  void setAcsUrl(std::string const& value);
  bool acsUrlIsSet() const;
  void unsetAcsUrl();
  /// <summary>
  ///
  /// </summary>
  std::string getAcsIpv4Addr() const;
  void setAcsIpv4Addr(std::string const& value);
  bool acsIpv4AddrIsSet() const;
  void unsetAcsIpv4Addr();
  /// <summary>
  ///
  /// </summary>
  ngkore::model::common::Ipv6Addr getAcsIpv6Addr() const;
  void setAcsIpv6Addr(ngkore::model::common::Ipv6Addr const& value);
  bool acsIpv6AddrIsSet() const;
  void unsetAcsIpv6Addr();

  friend void to_json(nlohmann::json& j, const AcsInfo& o);
  friend void from_json(const nlohmann::json& j, AcsInfo& o);

 protected:
  std::string m_AcsUrl;
  bool m_AcsUrlIsSet;
  std::string m_AcsIpv4Addr;
  bool m_AcsIpv4AddrIsSet;
  ngkore::model::common::Ipv6Addr m_AcsIpv6Addr;
  bool m_AcsIpv6AddrIsSet;
};

}  // namespace ngkore::model::common

