
#ifndef PositioningMethodMdt_anyOf_H_
#define PositioningMethodMdt_anyOf_H_

#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class PositioningMethodMdt_anyOf {
 public:
  PositioningMethodMdt_anyOf();
  virtual ~PositioningMethodMdt_anyOf() = default;

  enum class ePositioningMethodMdt_anyOf {
    // To have a valid default value.
    // Avoiding name clashes with user defined
    // enum values
    INVALID_VALUE_OPENAPI_GENERATED = 0,
    GNSS,
    E_CELL_ID
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

  bool operator==(const PositioningMethodMdt_anyOf& rhs) const;
  bool operator!=(const PositioningMethodMdt_anyOf& rhs) const;

  /////////////////////////////////////////////
  /// PositioningMethodMdt_anyOf members

  PositioningMethodMdt_anyOf::ePositioningMethodMdt_anyOf getValue() const;
  void setValue(PositioningMethodMdt_anyOf::ePositioningMethodMdt_anyOf value);

  friend void to_json(nlohmann::json& j, const PositioningMethodMdt_anyOf& o);
  friend void from_json(const nlohmann::json& j, PositioningMethodMdt_anyOf& o);

 protected:
  PositioningMethodMdt_anyOf::ePositioningMethodMdt_anyOf m_value =
      PositioningMethodMdt_anyOf::ePositioningMethodMdt_anyOf::
          INVALID_VALUE_OPENAPI_GENERATED;
};

}  // namespace ngkore::model::common

