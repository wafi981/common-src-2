
#ifndef PreemptionCapabilityRm_H_
#define PreemptionCapabilityRm_H_

#include "PreemptionCapability.h"
#include "NullValue.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class PreemptionCapabilityRm {
 public:
  PreemptionCapabilityRm();
  virtual ~PreemptionCapabilityRm() = default;

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

  bool operator==(const PreemptionCapabilityRm& rhs) const;
  bool operator!=(const PreemptionCapabilityRm& rhs) const;

  /////////////////////////////////////////////
  /// PreemptionCapabilityRm members

  friend void to_json(nlohmann::json& j, const PreemptionCapabilityRm& o);
  friend void from_json(const nlohmann::json& j, PreemptionCapabilityRm& o);

 protected:
};

}  // namespace ngkore::model::common

