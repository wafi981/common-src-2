
#ifndef NotificationControl_H_
#define NotificationControl_H_

#include "NotificationControl_anyOf.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class NotificationControl {
 public:
  NotificationControl();
  virtual ~NotificationControl() = default;

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

  bool operator==(const NotificationControl& rhs) const;
  bool operator!=(const NotificationControl& rhs) const;

  /////////////////////////////////////////////
  /// NotificationControl members

  NotificationControl_anyOf getValue() const;
  void setValue(NotificationControl_anyOf value);
  NotificationControl_anyOf::eNotificationControl_anyOf getEnumValue() const;
  void setEnumValue(
      NotificationControl_anyOf::eNotificationControl_anyOf value);
  friend void to_json(nlohmann::json& j, const NotificationControl& o);
  friend void from_json(const nlohmann::json& j, NotificationControl& o);
  friend void to_json(nlohmann::json& j, const NotificationControl_anyOf& o);
  friend void from_json(const nlohmann::json& j, NotificationControl_anyOf& o);

 protected:
  NotificationControl_anyOf m_value;
};

}  // namespace ngkore::model::common

