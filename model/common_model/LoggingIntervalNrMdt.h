
#ifndef LoggingIntervalNrMdt_H_
#define LoggingIntervalNrMdt_H_

#include "LoggingIntervalNrMdt_anyOf.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class LoggingIntervalNrMdt {
 public:
  LoggingIntervalNrMdt();
  virtual ~LoggingIntervalNrMdt() = default;

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

  bool operator==(const LoggingIntervalNrMdt& rhs) const;
  bool operator!=(const LoggingIntervalNrMdt& rhs) const;

  /////////////////////////////////////////////
  /// LoggingIntervalNrMdt members

  LoggingIntervalNrMdt_anyOf getValue() const;
  void setValue(LoggingIntervalNrMdt_anyOf value);
  LoggingIntervalNrMdt_anyOf::eLoggingIntervalNrMdt_anyOf getEnumValue() const;
  void setEnumValue(
      LoggingIntervalNrMdt_anyOf::eLoggingIntervalNrMdt_anyOf value);
  friend void to_json(nlohmann::json& j, const LoggingIntervalNrMdt& o);
  friend void from_json(const nlohmann::json& j, LoggingIntervalNrMdt& o);
  friend void to_json(nlohmann::json& j, const LoggingIntervalNrMdt_anyOf& o);
  friend void from_json(const nlohmann::json& j, LoggingIntervalNrMdt_anyOf& o);

 protected:
  LoggingIntervalNrMdt_anyOf m_value;
};

}  // namespace ngkore::model::common

