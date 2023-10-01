
#ifndef PresenceState_H_
#define PresenceState_H_

#include "PresenceState_anyOf.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class PresenceState {
 public:
  PresenceState();
  virtual ~PresenceState() = default;

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

  bool operator==(const PresenceState& rhs) const;
  bool operator!=(const PresenceState& rhs) const;

  /////////////////////////////////////////////
  /// PresenceState members

  PresenceState_anyOf getValue() const;
  void setValue(PresenceState_anyOf value);
  PresenceState_anyOf::ePresenceState_anyOf getEnumValue() const;
  void setEnumValue(PresenceState_anyOf::ePresenceState_anyOf value);
  friend void to_json(nlohmann::json& j, const PresenceState& o);
  friend void from_json(const nlohmann::json& j, PresenceState& o);
  friend void to_json(nlohmann::json& j, const PresenceState_anyOf& o);
  friend void from_json(const nlohmann::json& j, PresenceState_anyOf& o);

 protected:
  PresenceState_anyOf m_value;
};

}  // namespace ngkore::model::common

