
#ifndef UPInterfaceType_H_
#define UPInterfaceType_H_

#include "UPInterfaceType_anyOf.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::nrf {

/// <summary>
/// Types of User-Plane interfaces of the UPF
/// </summary>
class UPInterfaceType {
 public:
  UPInterfaceType();
  virtual ~UPInterfaceType() = default;

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

  bool operator==(const UPInterfaceType& rhs) const;
  bool operator!=(const UPInterfaceType& rhs) const;

  /////////////////////////////////////////////
  /// UPInterfaceType members

  UPInterfaceType_anyOf getValue() const;
  void setValue(UPInterfaceType_anyOf value);
  UPInterfaceType_anyOf::eUPInterfaceType_anyOf getEnumValue() const;
  std::string getEnumString() const;
  void setEnumValue(UPInterfaceType_anyOf::eUPInterfaceType_anyOf value);
  friend void to_json(nlohmann::json& j, const UPInterfaceType& o);
  friend void from_json(const nlohmann::json& j, UPInterfaceType& o);
  friend void to_json(nlohmann::json& j, const UPInterfaceType_anyOf& o);
  friend void from_json(const nlohmann::json& j, UPInterfaceType_anyOf& o);

 protected:
  UPInterfaceType_anyOf m_value;
};

}  // namespace ngkore::model::nrf

