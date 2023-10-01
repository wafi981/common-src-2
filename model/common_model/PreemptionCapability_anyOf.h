
#ifndef PreemptionCapability_anyOf_H_
#define PreemptionCapability_anyOf_H_

#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class PreemptionCapability_anyOf {
 public:
  PreemptionCapability_anyOf();
  virtual ~PreemptionCapability_anyOf() = default;

  enum class ePreemptionCapability_anyOf {
    // To have a valid default value.
    // Avoiding name clashes with user defined
    // enum values
    INVALID_VALUE_OPENAPI_GENERATED = 0,
    NOT_PREEMPT,
    MAY_PREEMPT
  };

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

  bool operator==(const PreemptionCapability_anyOf& rhs) const;
  bool operator!=(const PreemptionCapability_anyOf& rhs) const;

  /////////////////////////////////////////////
  /// PreemptionCapability_anyOf members

  PreemptionCapability_anyOf::ePreemptionCapability_anyOf getValue() const;
  void setValue(PreemptionCapability_anyOf::ePreemptionCapability_anyOf value);

  friend void to_json(nlohmann::json& j, const PreemptionCapability_anyOf& o);
  friend void from_json(const nlohmann::json& j, PreemptionCapability_anyOf& o);

 protected:
  PreemptionCapability_anyOf::ePreemptionCapability_anyOf m_value =
      PreemptionCapability_anyOf::ePreemptionCapability_anyOf::
          INVALID_VALUE_OPENAPI_GENERATED;
};

}  // namespace ngkore::model::common

