
#ifndef LoggingDurationNrMdt_H_
#define LoggingDurationNrMdt_H_

#include "LoggingDurationMdt_anyOf.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class LoggingDurationNrMdt {
 public:
  LoggingDurationNrMdt();
  virtual ~LoggingDurationNrMdt() = default;

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

  bool operator==(const LoggingDurationNrMdt& rhs) const;
  bool operator!=(const LoggingDurationNrMdt& rhs) const;

  /////////////////////////////////////////////
  /// LoggingDurationNrMdt members

  LoggingDurationMdt_anyOf getValue() const;
  void setValue(LoggingDurationMdt_anyOf value);
  LoggingDurationMdt_anyOf::eLoggingDurationMdt_anyOf getEnumValue() const;
  void setEnumValue(LoggingDurationMdt_anyOf::eLoggingDurationMdt_anyOf value);
  friend void to_json(nlohmann::json& j, const LoggingDurationNrMdt& o);
  friend void from_json(const nlohmann::json& j, LoggingDurationNrMdt& o);
  friend void to_json(nlohmann::json& j, const LoggingDurationMdt_anyOf& o);
  friend void from_json(const nlohmann::json& j, LoggingDurationMdt_anyOf& o);

 protected:
  LoggingDurationMdt_anyOf m_value;
};

}  // namespace ngkore::model::common

