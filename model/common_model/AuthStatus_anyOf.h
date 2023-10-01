
#ifndef AuthStatus_anyOf_H_
#define AuthStatus_anyOf_H_

#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class AuthStatus_anyOf {
 public:
  AuthStatus_anyOf();
  virtual ~AuthStatus_anyOf() = default;

  enum class eAuthStatus_anyOf {
    // To have a valid default value.
    // Avoiding name clashes with user defined
    // enum values
    INVALID_VALUE_OPENAPI_GENERATED = 0,
    EAP_SUCCESS,
    EAP_FAILURE,
    PENDING
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

  bool operator==(const AuthStatus_anyOf& rhs) const;
  bool operator!=(const AuthStatus_anyOf& rhs) const;

  /////////////////////////////////////////////
  /// AuthStatus_anyOf members

  AuthStatus_anyOf::eAuthStatus_anyOf getValue() const;
  void setValue(AuthStatus_anyOf::eAuthStatus_anyOf value);

  friend void to_json(nlohmann::json& j, const AuthStatus_anyOf& o);
  friend void from_json(const nlohmann::json& j, AuthStatus_anyOf& o);

 protected:
  AuthStatus_anyOf::eAuthStatus_anyOf m_value =
      AuthStatus_anyOf::eAuthStatus_anyOf::INVALID_VALUE_OPENAPI_GENERATED;
};

}  // namespace ngkore::model::common

