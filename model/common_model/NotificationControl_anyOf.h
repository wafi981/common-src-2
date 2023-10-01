
#ifndef NotificationControl_anyOf_H_
#define NotificationControl_anyOf_H_

#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class NotificationControl_anyOf {
 public:
  NotificationControl_anyOf();
  virtual ~NotificationControl_anyOf() = default;

  enum class eNotificationControl_anyOf {
    // To have a valid default value.
    // Avoiding name clashes with user defined
    // enum values
    INVALID_VALUE_OPENAPI_GENERATED = 0,
    REQUESTED,
    NOT_REQUESTED
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

  bool operator==(const NotificationControl_anyOf& rhs) const;
  bool operator!=(const NotificationControl_anyOf& rhs) const;

  /////////////////////////////////////////////
  /// NotificationControl_anyOf members

  NotificationControl_anyOf::eNotificationControl_anyOf getValue() const;
  void setValue(NotificationControl_anyOf::eNotificationControl_anyOf value);

  friend void to_json(nlohmann::json& j, const NotificationControl_anyOf& o);
  friend void from_json(const nlohmann::json& j, NotificationControl_anyOf& o);

 protected:
  NotificationControl_anyOf::eNotificationControl_anyOf m_value =
      NotificationControl_anyOf::eNotificationControl_anyOf::
          INVALID_VALUE_OPENAPI_GENERATED;
};

}  // namespace ngkore::model::common

