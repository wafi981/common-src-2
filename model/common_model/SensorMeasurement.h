
#ifndef SensorMeasurement_H_
#define SensorMeasurement_H_

#include "SensorMeasurement_anyOf.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class SensorMeasurement {
 public:
  SensorMeasurement();
  virtual ~SensorMeasurement() = default;

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

  bool operator==(const SensorMeasurement& rhs) const;
  bool operator!=(const SensorMeasurement& rhs) const;

  /////////////////////////////////////////////
  /// SensorMeasurement members

  SensorMeasurement_anyOf getValue() const;
  void setValue(SensorMeasurement_anyOf value);
  SensorMeasurement_anyOf::eSensorMeasurement_anyOf getEnumValue() const;
  void setEnumValue(SensorMeasurement_anyOf::eSensorMeasurement_anyOf value);
  friend void to_json(nlohmann::json& j, const SensorMeasurement& o);
  friend void from_json(const nlohmann::json& j, SensorMeasurement& o);
  friend void to_json(nlohmann::json& j, const SensorMeasurement_anyOf& o);
  friend void from_json(const nlohmann::json& j, SensorMeasurement_anyOf& o);

 protected:
  SensorMeasurement_anyOf m_value;
};

}  // namespace ngkore::model::common

