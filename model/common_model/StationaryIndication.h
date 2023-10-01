
#ifndef StationaryIndication_H_
#define StationaryIndication_H_

#include "StationaryIndication_anyOf.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
/// Possible values are - STATIONARY: Identifies the UE is stationary - MOBILE:
/// Identifies the UE is mobile
/// </summary>
class StationaryIndication {
 public:
  StationaryIndication();
  virtual ~StationaryIndication() = default;

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

  bool operator==(const StationaryIndication& rhs) const;
  bool operator!=(const StationaryIndication& rhs) const;

  /////////////////////////////////////////////
  /// StationaryIndication members

  StationaryIndication_anyOf getValue() const;
  void setValue(StationaryIndication_anyOf value);
  StationaryIndication_anyOf::eStationaryIndication_anyOf getEnumValue() const;
  void setEnumValue(
      StationaryIndication_anyOf::eStationaryIndication_anyOf value);
  friend void to_json(nlohmann::json& j, const StationaryIndication& o);
  friend void from_json(const nlohmann::json& j, StationaryIndication& o);
  friend void to_json(nlohmann::json& j, const StationaryIndication_anyOf& o);
  friend void from_json(const nlohmann::json& j, StationaryIndication_anyOf& o);

 protected:
  StationaryIndication_anyOf m_value;
};

}  // namespace ngkore::model::common

