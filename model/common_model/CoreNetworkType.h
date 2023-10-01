
#ifndef CoreNetworkType_H_
#define CoreNetworkType_H_

#include "CoreNetworkType_anyOf.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class CoreNetworkType {
 public:
  CoreNetworkType();
  virtual ~CoreNetworkType() = default;

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

  bool operator==(const CoreNetworkType& rhs) const;
  bool operator!=(const CoreNetworkType& rhs) const;

  /////////////////////////////////////////////
  /// CoreNetworkType members

  CoreNetworkType_anyOf getValue() const;
  void setValue(CoreNetworkType_anyOf value);
  CoreNetworkType_anyOf::eCoreNetworkType_anyOf getEnumValue() const;
  void setEnumValue(CoreNetworkType_anyOf::eCoreNetworkType_anyOf value);
  friend void to_json(nlohmann::json& j, const CoreNetworkType& o);
  friend void from_json(const nlohmann::json& j, CoreNetworkType& o);
  friend void to_json(nlohmann::json& j, const CoreNetworkType_anyOf& o);
  friend void from_json(const nlohmann::json& j, CoreNetworkType_anyOf& o);

 protected:
  CoreNetworkType_anyOf m_value;
};

}  // namespace ngkore::model::common

