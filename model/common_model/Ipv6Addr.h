
#ifndef Ipv6Addr_H_
#define Ipv6Addr_H_

#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class Ipv6Addr {
 public:
  Ipv6Addr();
  virtual ~Ipv6Addr() = default;

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
  virtual bool validate(
      std::stringstream& msg, const std::string& pathPrefix) const;

  bool operator==(const Ipv6Addr& rhs) const;
  bool operator!=(const Ipv6Addr& rhs) const;

  /////////////////////////////////////////////
  /// Ipv6Addr members

  friend void to_json(nlohmann::json& j, const Ipv6Addr& o);
  friend void from_json(const nlohmann::json& j, Ipv6Addr& o);

  std::string getIpv6Addr() const;
  void setIpv6Addr(std::string const& value);

 protected:
  std::string m_Ipv6Addr;
};

}  // namespace ngkore::model::common

