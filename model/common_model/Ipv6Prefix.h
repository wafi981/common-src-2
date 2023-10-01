
#ifndef Ipv6Prefix_H_
#define Ipv6Prefix_H_

#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class Ipv6Prefix {
 public:
  Ipv6Prefix();
  virtual ~Ipv6Prefix() = default;

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

  bool operator==(const Ipv6Prefix& rhs) const;
  bool operator!=(const Ipv6Prefix& rhs) const;

  /////////////////////////////////////////////
  /// Ipv6Prefix members

  std::string getIpv6Prefix() const;
  void setIpv6Prefix(std::string const& value);

  friend void to_json(nlohmann::json& j, const Ipv6Prefix& o);
  friend void from_json(const nlohmann::json& j, Ipv6Prefix& o);

 protected:
  std::string m_Ipv6Prefix;
};

}  // namespace ngkore::model::common

