
#ifndef UpIntegrity_anyOf_H_
#define UpIntegrity_anyOf_H_

#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class UpIntegrity_anyOf {
 public:
  UpIntegrity_anyOf();
  virtual ~UpIntegrity_anyOf() = default;

  enum class eUpIntegrity_anyOf {
    // To have a valid default value.
    // Avoiding name clashes with user defined
    // enum values
    INVALID_VALUE_OPENAPI_GENERATED = 0,
    REQUIRED,
    PREFERRED,
    NOT_NEEDED
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

  bool operator==(const UpIntegrity_anyOf& rhs) const;
  bool operator!=(const UpIntegrity_anyOf& rhs) const;

  /////////////////////////////////////////////
  /// UpIntegrity_anyOf members

  UpIntegrity_anyOf::eUpIntegrity_anyOf getValue() const;
  void setValue(UpIntegrity_anyOf::eUpIntegrity_anyOf value);

  friend void to_json(nlohmann::json& j, const UpIntegrity_anyOf& o);
  friend void from_json(const nlohmann::json& j, UpIntegrity_anyOf& o);

 protected:
  UpIntegrity_anyOf::eUpIntegrity_anyOf m_value =
      UpIntegrity_anyOf::eUpIntegrity_anyOf::INVALID_VALUE_OPENAPI_GENERATED;
};

}  // namespace ngkore::model::common

