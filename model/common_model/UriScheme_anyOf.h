
#ifndef UriScheme_anyOf_H_
#define UriScheme_anyOf_H_

#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class UriScheme_anyOf {
 public:
  UriScheme_anyOf();
  virtual ~UriScheme_anyOf() = default;

  enum class eUriScheme_anyOf {
    // To have a valid default value.
    // Avoiding name clashes with user defined
    // enum values
    INVALID_VALUE_OPENAPI_GENERATED = 0,
    HTTP,
    HTTPS
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

  bool operator==(const UriScheme_anyOf& rhs) const;
  bool operator!=(const UriScheme_anyOf& rhs) const;

  /////////////////////////////////////////////
  /// UriScheme_anyOf members

  UriScheme_anyOf::eUriScheme_anyOf getValue() const;
  void setValue(UriScheme_anyOf::eUriScheme_anyOf value);

  friend void to_json(nlohmann::json& j, const UriScheme_anyOf& o);
  friend void from_json(const nlohmann::json& j, UriScheme_anyOf& o);

 protected:
  UriScheme_anyOf::eUriScheme_anyOf m_value =
      UriScheme_anyOf::eUriScheme_anyOf::INVALID_VALUE_OPENAPI_GENERATED;
};

}  // namespace ngkore::model::common

