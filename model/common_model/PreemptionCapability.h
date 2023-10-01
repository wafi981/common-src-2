
#ifndef PreemptionCapability_H_
#define PreemptionCapability_H_

#include "PreemptionCapability_anyOf.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class PreemptionCapability {
 public:
  PreemptionCapability();
  virtual ~PreemptionCapability() = default;

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

  bool operator==(const PreemptionCapability& rhs) const;
  bool operator!=(const PreemptionCapability& rhs) const;

  /////////////////////////////////////////////
  /// PreemptionCapability members

  PreemptionCapability_anyOf getValue() const;
  void setValue(PreemptionCapability_anyOf value);
  PreemptionCapability_anyOf::ePreemptionCapability_anyOf getEnumValue() const;
  void setEnumValue(
      PreemptionCapability_anyOf::ePreemptionCapability_anyOf value);
  friend void to_json(nlohmann::json& j, const PreemptionCapability& o);
  friend void from_json(const nlohmann::json& j, PreemptionCapability& o);
  friend void to_json(nlohmann::json& j, const PreemptionCapability_anyOf& o);
  friend void from_json(const nlohmann::json& j, PreemptionCapability_anyOf& o);

 protected:
  PreemptionCapability_anyOf m_value;
};

}  // namespace ngkore::model::common

