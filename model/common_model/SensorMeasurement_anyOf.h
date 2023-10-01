
#ifndef SensorMeasurement_anyOf_H_
#define SensorMeasurement_anyOf_H_

#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class SensorMeasurement_anyOf {
 public:
  SensorMeasurement_anyOf();
  virtual ~SensorMeasurement_anyOf() = default;

  enum class eSensorMeasurement_anyOf {
    // To have a valid default value.
    // Avoiding name clashes with user defined
    // enum values
    INVALID_VALUE_OPENAPI_GENERATED = 0,
    BAROMETRIC_PRESSURE,
    UE_SPEED,
    UE_ORIENTATION
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

  bool operator==(const SensorMeasurement_anyOf& rhs) const;
  bool operator!=(const SensorMeasurement_anyOf& rhs) const;

  /////////////////////////////////////////////
  /// SensorMeasurement_anyOf members

  SensorMeasurement_anyOf::eSensorMeasurement_anyOf getValue() const;
  void setValue(SensorMeasurement_anyOf::eSensorMeasurement_anyOf value);

  friend void to_json(nlohmann::json& j, const SensorMeasurement_anyOf& o);
  friend void from_json(const nlohmann::json& j, SensorMeasurement_anyOf& o);

 protected:
  SensorMeasurement_anyOf::eSensorMeasurement_anyOf m_value =
      SensorMeasurement_anyOf::eSensorMeasurement_anyOf::
          INVALID_VALUE_OPENAPI_GENERATED;
};

}  // namespace ngkore::model::common

