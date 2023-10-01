
#ifndef NullValue_H_
#define NullValue_H_

#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class NullValue {
 public:
  NullValue();
  virtual ~NullValue() = default;

  enum class eNullValue {
    // To have a valid default value.
    // Avoiding name clashes with user defined
    // enum values
    INVALID_VALUE_OPENAPI_GENERATED = 0,
    _NULL
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

  bool operator==(const NullValue& rhs) const;
  bool operator!=(const NullValue& rhs) const;

  /////////////////////////////////////////////
  /// NullValue members

  NullValue::eNullValue getValue() const;
  void setValue(NullValue::eNullValue value);

  friend void to_json(nlohmann::json& j, const NullValue& o);
  friend void from_json(const nlohmann::json& j, NullValue& o);

 protected:
  NullValue::eNullValue m_value =
      NullValue::eNullValue::INVALID_VALUE_OPENAPI_GENERATED;
};

}  // namespace ngkore::model::common

