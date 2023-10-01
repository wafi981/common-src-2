
#ifndef UPInterfaceType_anyOf_H_
#define UPInterfaceType_anyOf_H_

#include <nlohmann/json.hpp>

namespace ngkore::model::nrf {

/// <summary>
///
/// </summary>
class UPInterfaceType_anyOf {
 public:
  UPInterfaceType_anyOf();
  virtual ~UPInterfaceType_anyOf() = default;

  enum class eUPInterfaceType_anyOf {
    // To have a valid default value.
    // Avoiding name clashes with user defined
    // enum values
    INVALID_VALUE_OPENAPI_GENERATED = 0,
    N3,
    N6,
    N9,
    DATA_FORWARDING
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

  bool operator==(const UPInterfaceType_anyOf& rhs) const;
  bool operator!=(const UPInterfaceType_anyOf& rhs) const;

  /////////////////////////////////////////////
  /// UPInterfaceType_anyOf members

  UPInterfaceType_anyOf::eUPInterfaceType_anyOf getValue() const;
  void setValue(UPInterfaceType_anyOf::eUPInterfaceType_anyOf value);

  friend void to_json(nlohmann::json& j, const UPInterfaceType_anyOf& o);
  friend void from_json(const nlohmann::json& j, UPInterfaceType_anyOf& o);

 protected:
  UPInterfaceType_anyOf::eUPInterfaceType_anyOf m_value =
      UPInterfaceType_anyOf::eUPInterfaceType_anyOf::
          INVALID_VALUE_OPENAPI_GENERATED;
};

}  // namespace ngkore::model::nrf

