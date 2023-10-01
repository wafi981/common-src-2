
#ifndef PositioningMethodMdt_H_
#define PositioningMethodMdt_H_

#include "PositioningMethodMdt_anyOf.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class PositioningMethodMdt {
 public:
  PositioningMethodMdt();
  virtual ~PositioningMethodMdt() = default;

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

  bool operator==(const PositioningMethodMdt& rhs) const;
  bool operator!=(const PositioningMethodMdt& rhs) const;

  /////////////////////////////////////////////
  /// PositioningMethodMdt members

  PositioningMethodMdt_anyOf getValue() const;
  void setValue(PositioningMethodMdt_anyOf value);
  PositioningMethodMdt_anyOf::ePositioningMethodMdt_anyOf getEnumValue() const;
  void setEnumValue(
      PositioningMethodMdt_anyOf::ePositioningMethodMdt_anyOf value);
  friend void to_json(nlohmann::json& j, const PositioningMethodMdt& o);
  friend void from_json(const nlohmann::json& j, PositioningMethodMdt& o);
  friend void to_json(nlohmann::json& j, const PositioningMethodMdt_anyOf& o);
  friend void from_json(const nlohmann::json& j, PositioningMethodMdt_anyOf& o);

 protected:
  PositioningMethodMdt_anyOf m_value;
};

}  // namespace ngkore::model::common

