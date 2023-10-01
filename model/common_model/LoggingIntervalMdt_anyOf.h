
#ifndef LoggingIntervalMdt_anyOf_H_
#define LoggingIntervalMdt_anyOf_H_

#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class LoggingIntervalMdt_anyOf {
 public:
  LoggingIntervalMdt_anyOf();
  virtual ~LoggingIntervalMdt_anyOf() = default;

  enum class eLoggingIntervalMdt_anyOf {
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
    _6144
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

  bool operator==(const LoggingIntervalMdt_anyOf& rhs) const;
  bool operator!=(const LoggingIntervalMdt_anyOf& rhs) const;

  /////////////////////////////////////////////
  /// LoggingIntervalMdt_anyOf members

  LoggingIntervalMdt_anyOf::eLoggingIntervalMdt_anyOf getValue() const;
  void setValue(LoggingIntervalMdt_anyOf::eLoggingIntervalMdt_anyOf value);

  friend void to_json(nlohmann::json& j, const LoggingIntervalMdt_anyOf& o);
  friend void from_json(const nlohmann::json& j, LoggingIntervalMdt_anyOf& o);

 protected:
  LoggingIntervalMdt_anyOf::eLoggingIntervalMdt_anyOf m_value =
      LoggingIntervalMdt_anyOf::eLoggingIntervalMdt_anyOf::
          INVALID_VALUE_OPENAPI_GENERATED;
};

}  // namespace ngkore::model::common

