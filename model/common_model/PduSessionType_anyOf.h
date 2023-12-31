
#ifndef PduSessionType_anyOf_H_
#define PduSessionType_anyOf_H_

#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class PduSessionType_anyOf {
 public:
  PduSessionType_anyOf();
  virtual ~PduSessionType_anyOf() = default;

  enum class ePduSessionType_anyOf {
    // To have a valid default value.
    // Avoiding name clashes with user defined
    // enum values
    INVALID_VALUE_OPENAPI_GENERATED = 0,
    IPV4,
    IPV6,
    IPV4V6,
    UNSTRUCTURED,
    ETHERNET
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

  bool operator==(const PduSessionType_anyOf& rhs) const;
  bool operator!=(const PduSessionType_anyOf& rhs) const;

  /////////////////////////////////////////////
  /// PduSessionType_anyOf members

  PduSessionType_anyOf::ePduSessionType_anyOf getValue() const;
  void setValue(PduSessionType_anyOf::ePduSessionType_anyOf value);

  friend void to_json(nlohmann::json& j, const PduSessionType_anyOf& o);
  friend void from_json(const nlohmann::json& j, PduSessionType_anyOf& o);

 protected:
  PduSessionType_anyOf::ePduSessionType_anyOf m_value = PduSessionType_anyOf::
      ePduSessionType_anyOf::INVALID_VALUE_OPENAPI_GENERATED;
};

}  // namespace ngkore::model::common

