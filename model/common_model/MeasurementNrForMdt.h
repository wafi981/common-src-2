
#ifndef MeasurementNrForMdt_H_
#define MeasurementNrForMdt_H_

#include "MeasurementLteForMdt_anyOf.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class MeasurementNrForMdt {
 public:
  MeasurementNrForMdt();
  virtual ~MeasurementNrForMdt() = default;

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

  bool operator==(const MeasurementNrForMdt& rhs) const;
  bool operator!=(const MeasurementNrForMdt& rhs) const;

  /////////////////////////////////////////////
  /// MeasurementNrForMdt members

  MeasurementLteForMdt_anyOf getValue() const;
  void setValue(MeasurementLteForMdt_anyOf value);
  MeasurementLteForMdt_anyOf::eMeasurementLteForMdt_anyOf getEnumValue() const;
  void setEnumValue(
      MeasurementLteForMdt_anyOf::eMeasurementLteForMdt_anyOf value);
  friend void to_json(nlohmann::json& j, const MeasurementNrForMdt& o);
  friend void from_json(const nlohmann::json& j, MeasurementNrForMdt& o);
  friend void to_json(nlohmann::json& j, const MeasurementLteForMdt_anyOf& o);
  friend void from_json(const nlohmann::json& j, MeasurementLteForMdt_anyOf& o);

 protected:
  MeasurementLteForMdt_anyOf m_value;
};

}  // namespace ngkore::model::common

