
#ifndef LcsServiceAuth_H_
#define LcsServiceAuth_H_

#include "LcsServiceAuth_anyOf.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
/// Possible values are - \&quot;LOCATION_ALLOWED_WITH_NOTIFICATION\&quot;:
/// Location allowed with notification -
/// \&quot;LOCATION_ALLOWED_WITHOUT_NOTIFICATION\&quot;: Location allowed
/// without notification - \&quot;LOCATION_ALLOWED_WITHOUT_RESPONSE\&quot;:
/// Location with notification and privacy verification; location allowed if no
/// response - \&quot;LOCATION_RESTRICTED_WITHOUT_RESPONSE\&quot;: Location with
/// notification and privacy verification; location restricted if no response -
/// \&quot;NOTIFICATION_ONLY\&quot;: Notification only -
/// \&quot;NOTIFICATION_AND_VERIFICATION_ONLY\&quot;: Notification and privacy
/// verification only
/// </summary>
class LcsServiceAuth {
 public:
  LcsServiceAuth();
  virtual ~LcsServiceAuth() = default;

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

  bool operator==(const LcsServiceAuth& rhs) const;
  bool operator!=(const LcsServiceAuth& rhs) const;

  /////////////////////////////////////////////
  /// LcsServiceAuth members

  LcsServiceAuth_anyOf getValue() const;
  void setValue(LcsServiceAuth_anyOf value);
  LcsServiceAuth_anyOf::eLcsServiceAuth_anyOf getEnumValue() const;
  void setEnumValue(LcsServiceAuth_anyOf::eLcsServiceAuth_anyOf value);
  friend void to_json(nlohmann::json& j, const LcsServiceAuth& o);
  friend void from_json(const nlohmann::json& j, LcsServiceAuth& o);
  friend void to_json(nlohmann::json& j, const LcsServiceAuth_anyOf& o);
  friend void from_json(const nlohmann::json& j, LcsServiceAuth_anyOf& o);

 protected:
  LcsServiceAuth_anyOf m_value;
};

}  // namespace ngkore::model::common

