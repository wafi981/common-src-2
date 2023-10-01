
#ifndef HttpMethod_anyOf_H_
#define HttpMethod_anyOf_H_

#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class HttpMethod_anyOf {
 public:
  HttpMethod_anyOf();
  virtual ~HttpMethod_anyOf() = default;

  enum class eHttpMethod_anyOf {
    // To have a valid default value.
    // Avoiding name clashes with user defined
    // enum values
    INVALID_VALUE_OPENAPI_GENERATED = 0,
    GET,
    POST,
    PUT,
    DELETE,
    PATCH,
    OPTIONS,
    HEAD,
    CONNECT,
    TRACE
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

  bool operator==(const HttpMethod_anyOf& rhs) const;
  bool operator!=(const HttpMethod_anyOf& rhs) const;

  /////////////////////////////////////////////
  /// HttpMethod_anyOf members

  HttpMethod_anyOf::eHttpMethod_anyOf getValue() const;
  void setValue(HttpMethod_anyOf::eHttpMethod_anyOf value);

  friend void to_json(nlohmann::json& j, const HttpMethod_anyOf& o);
  friend void from_json(const nlohmann::json& j, HttpMethod_anyOf& o);

 protected:
  HttpMethod_anyOf::eHttpMethod_anyOf m_value =
      HttpMethod_anyOf::eHttpMethod_anyOf::INVALID_VALUE_OPENAPI_GENERATED;
};

}  // namespace ngkore::model::common

