
#ifndef SscMode_anyOf_H_
#define SscMode_anyOf_H_

#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class SscMode_anyOf {
 public:
  SscMode_anyOf();
  virtual ~SscMode_anyOf() = default;

  enum class eSscMode_anyOf {
    // To have a valid default value.
    // Avoiding name clashes with user defined
    // enum values
    INVALID_VALUE_OPENAPI_GENERATED = 0,
    _1,
    _2,
    _3
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

  bool operator==(const SscMode_anyOf& rhs) const;
  bool operator!=(const SscMode_anyOf& rhs) const;

  /////////////////////////////////////////////
  /// SscMode_anyOf members

  SscMode_anyOf::eSscMode_anyOf getValue() const;
  void setValue(SscMode_anyOf::eSscMode_anyOf value);

  friend void to_json(nlohmann::json& j, const SscMode_anyOf& o);
  friend void from_json(const nlohmann::json& j, SscMode_anyOf& o);

 protected:
  SscMode_anyOf::eSscMode_anyOf m_value =
      SscMode_anyOf::eSscMode_anyOf::INVALID_VALUE_OPENAPI_GENERATED;
};

}  // namespace ngkore::model::common

