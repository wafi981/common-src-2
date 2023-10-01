
#ifndef DnaiChangeType_anyOf_H_
#define DnaiChangeType_anyOf_H_

#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class DnaiChangeType_anyOf {
 public:
  DnaiChangeType_anyOf();
  virtual ~DnaiChangeType_anyOf() = default;

  enum class eDnaiChangeType_anyOf {
    // To have a valid default value.
    // Avoiding name clashes with user defined
    // enum values
    INVALID_VALUE_OPENAPI_GENERATED = 0,
    EARLY,
    EARLY_LATE,
    LATE
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

  bool operator==(const DnaiChangeType_anyOf& rhs) const;
  bool operator!=(const DnaiChangeType_anyOf& rhs) const;

  /////////////////////////////////////////////
  /// DnaiChangeType_anyOf members

  DnaiChangeType_anyOf::eDnaiChangeType_anyOf getValue() const;
  void setValue(DnaiChangeType_anyOf::eDnaiChangeType_anyOf value);

  friend void to_json(nlohmann::json& j, const DnaiChangeType_anyOf& o);
  friend void from_json(const nlohmann::json& j, DnaiChangeType_anyOf& o);

 protected:
  DnaiChangeType_anyOf::eDnaiChangeType_anyOf m_value = DnaiChangeType_anyOf::
      eDnaiChangeType_anyOf::INVALID_VALUE_OPENAPI_GENERATED;
};

}  // namespace ngkore::model::common

