
#ifndef LoggingIntervalMdt_H_
#define LoggingIntervalMdt_H_

#include "LoggingIntervalMdt_anyOf.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class LoggingIntervalMdt {
 public:
  LoggingIntervalMdt();
  virtual ~LoggingIntervalMdt() = default;

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

  bool operator==(const LoggingIntervalMdt& rhs) const;
  bool operator!=(const LoggingIntervalMdt& rhs) const;

  /////////////////////////////////////////////
  /// LoggingIntervalMdt members

  LoggingIntervalMdt_anyOf getValue() const;
  void setValue(LoggingIntervalMdt_anyOf value);
  LoggingIntervalMdt_anyOf::eLoggingIntervalMdt_anyOf getEnumValue() const;
  void setEnumValue(LoggingIntervalMdt_anyOf::eLoggingIntervalMdt_anyOf value);
  friend void to_json(nlohmann::json& j, const LoggingIntervalMdt& o);
  friend void from_json(const nlohmann::json& j, LoggingIntervalMdt& o);
  friend void to_json(nlohmann::json& j, const LoggingIntervalMdt_anyOf& o);
  friend void from_json(const nlohmann::json& j, LoggingIntervalMdt_anyOf& o);

 protected:
  LoggingIntervalMdt_anyOf m_value;
};

}  // namespace ngkore::model::common

