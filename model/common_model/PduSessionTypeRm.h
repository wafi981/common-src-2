
#ifndef PduSessionTypeRm_H_
#define PduSessionTypeRm_H_

#include "PduSessionType.h"
#include "NullValue.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class PduSessionTypeRm : PduSessionType {
 public:
  PduSessionTypeRm();
  virtual ~PduSessionTypeRm() = default;

  /// <summary>
  /// Helper overload for validate. Used when one model stores another model and
  /// calls it's validate. Not meant to be called outside that case.
  /// </summary>
  bool validate(
      std::stringstream& msg, const std::string& pathPrefix) const override;

  /////////////////////////////////////////////
  /// PduSessionTypeRm members

  friend void to_json(nlohmann::json& j, const PduSessionTypeRm& o);
  friend void from_json(const nlohmann::json& j, PduSessionTypeRm& o);

 protected:
};

}  // namespace ngkore::model::common

