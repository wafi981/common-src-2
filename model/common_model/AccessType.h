
#ifndef AccessType_H_
#define AccessType_H_

#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class AccessType {
 public:
  AccessType();
  virtual ~AccessType() = default;

  enum class eAccessType {
    // To have a valid default value.
    // Avoiding name clashes with user defined
    // enum values
    INVALID_VALUE_OPENAPI_GENERATED = 0,
    _3GPP_ACCESS,
    NON_3GPP_ACCESS
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
  virtual bool validate(
      std::stringstream& msg, const std::string& pathPrefix) const;

  bool operator==(const AccessType& rhs) const;
  bool operator!=(const AccessType& rhs) const;

  /////////////////////////////////////////////
  /// AccessType members

  AccessType::eAccessType getValue() const;
  void setValue(AccessType::eAccessType value);

  friend void to_json(nlohmann::json& j, const AccessType& o);
  friend void from_json(const nlohmann::json& j, AccessType& o);

 protected:
  AccessType::eAccessType m_value =
      AccessType::eAccessType::INVALID_VALUE_OPENAPI_GENERATED;
};

}  // namespace ngkore::model::common

