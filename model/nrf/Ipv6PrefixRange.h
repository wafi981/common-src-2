
#ifndef Ipv6PrefixRange_H_
#define Ipv6PrefixRange_H_

#include "Ipv6Prefix.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::nrf {

/// <summary>
/// Range of IPv6 prefixes
/// </summary>
class Ipv6PrefixRange {
 public:
  Ipv6PrefixRange();
  virtual ~Ipv6PrefixRange() = default;

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

  bool operator==(const Ipv6PrefixRange& rhs) const;
  bool operator!=(const Ipv6PrefixRange& rhs) const;

  /////////////////////////////////////////////
  /// Ipv6PrefixRange members

  /// <summary>
  ///
  /// </summary>
  ngkore::model::common::Ipv6Prefix getStart() const;
  void setStart(ngkore::model::common::Ipv6Prefix const& value);
  bool startIsSet() const;
  void unsetStart();
  /// <summary>
  ///
  /// </summary>
  ngkore::model::common::Ipv6Prefix getEnd() const;
  void setEnd(ngkore::model::common::Ipv6Prefix const& value);
  bool endIsSet() const;
  void unsetEnd();

  friend void to_json(nlohmann::json& j, const Ipv6PrefixRange& o);
  friend void from_json(const nlohmann::json& j, Ipv6PrefixRange& o);

 protected:
  ngkore::model::common::Ipv6Prefix m_Start;
  bool m_StartIsSet;
  ngkore::model::common::Ipv6Prefix m_End;
  bool m_EndIsSet;
};

}  // namespace ngkore::model::nrf

