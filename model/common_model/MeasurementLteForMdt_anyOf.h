
#ifndef MeasurementLteForMdt_anyOf_H_
#define MeasurementLteForMdt_anyOf_H_

#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class MeasurementLteForMdt_anyOf {
 public:
  MeasurementLteForMdt_anyOf();
  virtual ~MeasurementLteForMdt_anyOf() = default;

  enum class eMeasurementLteForMdt_anyOf {
    // To have a valid default value.
    // Avoiding name clashes with user defined
    // enum values
    INVALID_VALUE_OPENAPI_GENERATED = 0,
    M1,
    M2,
    M3,
    M4_DL,
    M4_UL,
    M5_DL,
    M5_UL,
    M6_DL,
    M6_UL,
    M7_DL,
    M7_UL,
    M8,
    M9
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

  bool operator==(const MeasurementLteForMdt_anyOf& rhs) const;
  bool operator!=(const MeasurementLteForMdt_anyOf& rhs) const;

  /////////////////////////////////////////////
  /// MeasurementLteForMdt_anyOf members

  MeasurementLteForMdt_anyOf::eMeasurementLteForMdt_anyOf getValue() const;
  void setValue(MeasurementLteForMdt_anyOf::eMeasurementLteForMdt_anyOf value);

  friend void to_json(nlohmann::json& j, const MeasurementLteForMdt_anyOf& o);
  friend void from_json(const nlohmann::json& j, MeasurementLteForMdt_anyOf& o);

 protected:
  MeasurementLteForMdt_anyOf::eMeasurementLteForMdt_anyOf m_value =
      MeasurementLteForMdt_anyOf::eMeasurementLteForMdt_anyOf::
          INVALID_VALUE_OPENAPI_GENERATED;
};

}  // namespace ngkore::model::common

