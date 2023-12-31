
#ifndef PatchOperation_anyOf_H_
#define PatchOperation_anyOf_H_

#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class PatchOperation_anyOf {
 public:
  PatchOperation_anyOf();
  virtual ~PatchOperation_anyOf() = default;

  enum class ePatchOperation_anyOf {
    // To have a valid default value.
    // Avoiding name clashes with user defined
    // enum values
    INVALID_VALUE_OPENAPI_GENERATED = 0,
    ADD,
    COPY,
    MOVE,
    REMOVE,
    REPLACE,
    TEST
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

  bool operator==(const PatchOperation_anyOf& rhs) const;
  bool operator!=(const PatchOperation_anyOf& rhs) const;

  /////////////////////////////////////////////
  /// PatchOperation_anyOf members

  PatchOperation_anyOf::ePatchOperation_anyOf getValue() const;
  void setValue(PatchOperation_anyOf::ePatchOperation_anyOf value);

  friend void to_json(nlohmann::json& j, const PatchOperation_anyOf& o);
  friend void from_json(const nlohmann::json& j, PatchOperation_anyOf& o);

 protected:
  PatchOperation_anyOf::ePatchOperation_anyOf m_value = PatchOperation_anyOf::
      ePatchOperation_anyOf::INVALID_VALUE_OPENAPI_GENERATED;
};

}  // namespace ngkore::model::common

