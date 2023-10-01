
#ifndef MeasurementPeriodLteMdt_H_
#define MeasurementPeriodLteMdt_H_

#include "CollectionPeriodRmmLteMdt_anyOf.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class MeasurementPeriodLteMdt {
 public:
  MeasurementPeriodLteMdt();
  virtual ~MeasurementPeriodLteMdt() = default;

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

  bool operator==(const MeasurementPeriodLteMdt& rhs) const;
  bool operator!=(const MeasurementPeriodLteMdt& rhs) const;

  /////////////////////////////////////////////
  /// MeasurementPeriodLteMdt members

  CollectionPeriodRmmLteMdt_anyOf getValue() const;
  void setValue(CollectionPeriodRmmLteMdt_anyOf value);
  CollectionPeriodRmmLteMdt_anyOf::eCollectionPeriodRmmLteMdt_anyOf
  getEnumValue() const;
  void setEnumValue(
      CollectionPeriodRmmLteMdt_anyOf::eCollectionPeriodRmmLteMdt_anyOf value);
  friend void to_json(nlohmann::json& j, const MeasurementPeriodLteMdt& o);
  friend void from_json(const nlohmann::json& j, MeasurementPeriodLteMdt& o);
  friend void to_json(
      nlohmann::json& j, const CollectionPeriodRmmLteMdt_anyOf& o);
  friend void from_json(
      const nlohmann::json& j, CollectionPeriodRmmLteMdt_anyOf& o);

 protected:
  CollectionPeriodRmmLteMdt_anyOf m_value;
};

}  // namespace ngkore::model::common

