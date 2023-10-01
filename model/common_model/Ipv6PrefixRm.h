
#ifndef Ipv6PrefixRm_H_
#define Ipv6PrefixRm_H_

#include <nlohmann/json.hpp>
#include "Ipv6Prefix.h"

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class Ipv6PrefixRm : public Ipv6Prefix {
 public:
  Ipv6PrefixRm();
  virtual ~Ipv6PrefixRm() = default;

  /// <summary>
  /// Helper overload for validate. Used when one model stores another model and
  /// calls it's validate. Not meant to be called outside that case.
  /// </summary>
  bool validate(
      std::stringstream& msg, const std::string& pathPrefix) const override;
  /////////////////////////////////////////////
  /// Ipv6PrefixRm members

  friend void to_json(nlohmann::json& j, const Ipv6PrefixRm& o);
  friend void from_json(const nlohmann::json& j, Ipv6PrefixRm& o);

 protected:
};

}  // namespace ngkore::model::common

