
#ifndef LoggingIntervalNrMdt_anyOf_H_
#define LoggingIntervalNrMdt_anyOf_H_

#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class LoggingIntervalNrMdt_anyOf {
 public:
  LoggingIntervalNrMdt_anyOf();
  virtual ~LoggingIntervalNrMdt_anyOf() = default;

  enum class eLoggingIntervalNrMdt_anyOf {
    // To have a valid default value.
    // Avoiding name clashes with user defined
    // enum values
    INVALID_VALUE_OPENAPI_GENERATED = 0,
    _128,
    _256,
    _512,
    _1024,
    _2048,
    _3072,
    _4096,
    _6144,
    _320,
    _640,
    INFINITY
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

  bool operator==(const LoggingIntervalNrMdt_anyOf& rhs) const;
  bool operator!=(const LoggingIntervalNrMdt_anyOf& rhs) const;

  /////////////////////////////////////////////
  /// LoggingIntervalNrMdt_anyOf members

  LoggingIntervalNrMdt_anyOf::eLoggingIntervalNrMdt_anyOf getValue() const;
  void setValue(LoggingIntervalNrMdt_anyOf::eLoggingIntervalNrMdt_anyOf value);

  friend void to_json(nlohmann::json& j, const LoggingIntervalNrMdt_anyOf& o);
  friend void from_json(const nlohmann::json& j, LoggingIntervalNrMdt_anyOf& o);

 protected:
  LoggingIntervalNrMdt_anyOf::eLoggingIntervalNrMdt_anyOf m_value =
      LoggingIntervalNrMdt_anyOf::eLoggingIntervalNrMdt_anyOf::
          INVALID_VALUE_OPENAPI_GENERATED;
};

}  // namespace ngkore::model::common
