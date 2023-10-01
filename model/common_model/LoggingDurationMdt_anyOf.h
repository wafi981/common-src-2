
#ifndef LoggingDurationMdt_anyOf_H_
#define LoggingDurationMdt_anyOf_H_

#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class LoggingDurationMdt_anyOf {
 public:
  LoggingDurationMdt_anyOf();
  virtual ~LoggingDurationMdt_anyOf() = default;

  enum class eLoggingDurationMdt_anyOf {
    // To have a valid default value.
    // Avoiding name clashes with user defined
    // enum values
    INVALID_VALUE_OPENAPI_GENERATED = 0,
    _600,
    _1200,
    _2400,
    _3600,
    _5400,
    _7200
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

  bool operator==(const LoggingDurationMdt_anyOf& rhs) const;
  bool operator!=(const LoggingDurationMdt_anyOf& rhs) const;

  /////////////////////////////////////////////
  /// LoggingDurationMdt_anyOf members

  LoggingDurationMdt_anyOf::eLoggingDurationMdt_anyOf getValue() const;
  void setValue(LoggingDurationMdt_anyOf::eLoggingDurationMdt_anyOf value);

  friend void to_json(nlohmann::json& j, const LoggingDurationMdt_anyOf& o);
  friend void from_json(const nlohmann::json& j, LoggingDurationMdt_anyOf& o);

 protected:
  LoggingDurationMdt_anyOf::eLoggingDurationMdt_anyOf m_value =
      LoggingDurationMdt_anyOf::eLoggingDurationMdt_anyOf::
          INVALID_VALUE_OPENAPI_GENERATED;
};

}  // namespace ngkore::model::common

