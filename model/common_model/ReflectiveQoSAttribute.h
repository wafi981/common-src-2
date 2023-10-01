
#ifndef ReflectiveQoSAttribute_H_
#define ReflectiveQoSAttribute_H_

#include "ReflectiveQoSAttribute_anyOf.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class ReflectiveQoSAttribute {
 public:
  ReflectiveQoSAttribute();
  virtual ~ReflectiveQoSAttribute() = default;

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

  bool operator==(const ReflectiveQoSAttribute& rhs) const;
  bool operator!=(const ReflectiveQoSAttribute& rhs) const;

  /////////////////////////////////////////////
  /// ReflectiveQoSAttribute members

  ReflectiveQoSAttribute_anyOf getValue() const;
  void setValue(ReflectiveQoSAttribute_anyOf value);
  ReflectiveQoSAttribute_anyOf::eReflectiveQoSAttribute_anyOf getEnumValue()
      const;
  void setEnumValue(
      ReflectiveQoSAttribute_anyOf::eReflectiveQoSAttribute_anyOf value);
  friend void to_json(nlohmann::json& j, const ReflectiveQoSAttribute& o);
  friend void from_json(const nlohmann::json& j, ReflectiveQoSAttribute& o);
  friend void to_json(nlohmann::json& j, const ReflectiveQoSAttribute_anyOf& o);
  friend void from_json(
      const nlohmann::json& j, ReflectiveQoSAttribute_anyOf& o);

 protected:
  ReflectiveQoSAttribute_anyOf m_value;
};

}  // namespace ngkore::model::common

