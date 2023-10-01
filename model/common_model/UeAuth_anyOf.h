
#ifndef UeAuth_anyOf_H_
#define UeAuth_anyOf_H_

#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class UeAuth_anyOf {
 public:
  UeAuth_anyOf();
  virtual ~UeAuth_anyOf() = default;

  enum class eUeAuth_anyOf {
    // To have a valid default value.
    // Avoiding name clashes with user defined
    // enum values
    INVALID_VALUE_OPENAPI_GENERATED = 0,
    AUTHORIZED,
    NOT_AUTHORIZED
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

  bool operator==(const UeAuth_anyOf& rhs) const;
  bool operator!=(const UeAuth_anyOf& rhs) const;

  /////////////////////////////////////////////
  /// UeAuth_anyOf members

  UeAuth_anyOf::eUeAuth_anyOf getValue() const;
  void setValue(UeAuth_anyOf::eUeAuth_anyOf value);

  friend void to_json(nlohmann::json& j, const UeAuth_anyOf& o);
  friend void from_json(const nlohmann::json& j, UeAuth_anyOf& o);

 protected:
  UeAuth_anyOf::eUeAuth_anyOf m_value =
      UeAuth_anyOf::eUeAuth_anyOf::INVALID_VALUE_OPENAPI_GENERATED;
};

}  // namespace ngkore::model::common

