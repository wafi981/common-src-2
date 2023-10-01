
#ifndef PresenceState_anyOf_H_
#define PresenceState_anyOf_H_

#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class PresenceState_anyOf {
 public:
  PresenceState_anyOf();
  virtual ~PresenceState_anyOf() = default;

  enum class ePresenceState_anyOf {
    // To have a valid default value.
    // Avoiding name clashes with user defined
    // enum values
    INVALID_VALUE_OPENAPI_GENERATED = 0,
    IN_AREA,
    OUT_OF_AREA,
    UNKNOWN,
    INACTIVE
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

  bool operator==(const PresenceState_anyOf& rhs) const;
  bool operator!=(const PresenceState_anyOf& rhs) const;

  /////////////////////////////////////////////
  /// PresenceState_anyOf members

  PresenceState_anyOf::ePresenceState_anyOf getValue() const;
  void setValue(PresenceState_anyOf::ePresenceState_anyOf value);

  friend void to_json(nlohmann::json& j, const PresenceState_anyOf& o);
  friend void from_json(const nlohmann::json& j, PresenceState_anyOf& o);

 protected:
  PresenceState_anyOf::ePresenceState_anyOf m_value = PresenceState_anyOf::
      ePresenceState_anyOf::INVALID_VALUE_OPENAPI_GENERATED;
};

}  // namespace ngkore::model::common

