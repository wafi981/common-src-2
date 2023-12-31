
#ifndef ReflectiveQoSAttribute_anyOf_H_
#define ReflectiveQoSAttribute_anyOf_H_

#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class ReflectiveQoSAttribute_anyOf {
 public:
  ReflectiveQoSAttribute_anyOf();
  virtual ~ReflectiveQoSAttribute_anyOf() = default;

  enum class eReflectiveQoSAttribute_anyOf {
    // To have a valid default value.
    // Avoiding name clashes with user defined
    // enum values
    INVALID_VALUE_OPENAPI_GENERATED = 0,
    RQOS,
    NO_RQOS
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

  bool operator==(const ReflectiveQoSAttribute_anyOf& rhs) const;
  bool operator!=(const ReflectiveQoSAttribute_anyOf& rhs) const;

  /////////////////////////////////////////////
  /// ReflectiveQoSAttribute_anyOf members

  ReflectiveQoSAttribute_anyOf::eReflectiveQoSAttribute_anyOf getValue() const;
  void setValue(
      ReflectiveQoSAttribute_anyOf::eReflectiveQoSAttribute_anyOf value);

  friend void to_json(nlohmann::json& j, const ReflectiveQoSAttribute_anyOf& o);
  friend void from_json(
      const nlohmann::json& j, ReflectiveQoSAttribute_anyOf& o);

 protected:
  ReflectiveQoSAttribute_anyOf::eReflectiveQoSAttribute_anyOf m_value =
      ReflectiveQoSAttribute_anyOf::eReflectiveQoSAttribute_anyOf::
          INVALID_VALUE_OPENAPI_GENERATED;
};

}  // namespace ngkore::model::common

