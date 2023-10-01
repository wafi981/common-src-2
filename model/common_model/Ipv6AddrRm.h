
#ifndef Ipv6AddrRm_H_
#define Ipv6AddrRm_H_

#include <nlohmann/json.hpp>
#include "Ipv6Addr.h"

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class Ipv6AddrRm : public Ipv6Addr {
 public:
  Ipv6AddrRm();
  virtual ~Ipv6AddrRm() = default;

  /// <summary>
  /// Helper overload for validate. Used when one model stores another model and
  /// calls it's validate. Not meant to be called outside that case.
  /// </summary>
  bool validate(
      std::stringstream& msg, const std::string& pathPrefix) const override;
  /////////////////////////////////////////////
  /// Ipv6AddrRm members

  friend void to_json(nlohmann::json& j, const Ipv6AddrRm& o);
  friend void from_json(const nlohmann::json& j, Ipv6AddrRm& o);

 protected:
};

}  // namespace ngkore::model::common

