
#ifndef HttpMethod_H_
#define HttpMethod_H_

#include "HttpMethod_anyOf.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class HttpMethod {
 public:
  HttpMethod();
  virtual ~HttpMethod() = default;

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

  bool operator==(const HttpMethod& rhs) const;
  bool operator!=(const HttpMethod& rhs) const;

  /////////////////////////////////////////////
  /// HttpMethod members

  HttpMethod_anyOf getValue() const;
  void setValue(HttpMethod_anyOf value);
  HttpMethod_anyOf::eHttpMethod_anyOf getEnumValue() const;
  void setEnumValue(HttpMethod_anyOf::eHttpMethod_anyOf value);
  friend void to_json(nlohmann::json& j, const HttpMethod& o);
  friend void from_json(const nlohmann::json& j, HttpMethod& o);
  friend void to_json(nlohmann::json& j, const HttpMethod_anyOf& o);
  friend void from_json(const nlohmann::json& j, HttpMethod_anyOf& o);

 protected:
  HttpMethod_anyOf m_value;
};

}  // namespace ngkore::model::common

