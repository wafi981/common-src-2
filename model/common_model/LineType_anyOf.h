
#ifndef LineType_anyOf_H_
#define LineType_anyOf_H_

#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class LineType_anyOf {
 public:
  LineType_anyOf();
  virtual ~LineType_anyOf() = default;

  enum class eLineType_anyOf {
    // To have a valid default value.
    // Avoiding name clashes with user defined
    // enum values
    INVALID_VALUE_OPENAPI_GENERATED = 0,
    DSL,
    PON
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

  bool operator==(const LineType_anyOf& rhs) const;
  bool operator!=(const LineType_anyOf& rhs) const;

  /////////////////////////////////////////////
  /// LineType_anyOf members

  LineType_anyOf::eLineType_anyOf getValue() const;
  void setValue(LineType_anyOf::eLineType_anyOf value);

  friend void to_json(nlohmann::json& j, const LineType_anyOf& o);
  friend void from_json(const nlohmann::json& j, LineType_anyOf& o);

 protected:
  LineType_anyOf::eLineType_anyOf m_value =
      LineType_anyOf::eLineType_anyOf::INVALID_VALUE_OPENAPI_GENERATED;
};

}  // namespace ngkore::model::common

