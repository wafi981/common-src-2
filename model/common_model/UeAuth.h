
#ifndef UeAuth_H_
#define UeAuth_H_

#include "UeAuth_anyOf.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class UeAuth {
 public:
  UeAuth();
  virtual ~UeAuth() = default;

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

  bool operator==(const UeAuth& rhs) const;
  bool operator!=(const UeAuth& rhs) const;

  /////////////////////////////////////////////
  /// UeAuth members

  UeAuth_anyOf getValue() const;
  void setValue(UeAuth_anyOf value);
  UeAuth_anyOf::eUeAuth_anyOf getEnumValue() const;
  void setEnumValue(UeAuth_anyOf::eUeAuth_anyOf value);
  friend void to_json(nlohmann::json& j, const UeAuth& o);
  friend void from_json(const nlohmann::json& j, UeAuth& o);
  friend void to_json(nlohmann::json& j, const UeAuth_anyOf& o);
  friend void from_json(const nlohmann::json& j, UeAuth_anyOf& o);

 protected:
  UeAuth_anyOf m_value;
};

}  // namespace ngkore::model::common

