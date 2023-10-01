
#ifndef RestrictionType_H_
#define RestrictionType_H_

#include "RestrictionType_anyOf.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class RestrictionType {
 public:
  RestrictionType();
  virtual ~RestrictionType() = default;

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

  bool operator==(const RestrictionType& rhs) const;
  bool operator!=(const RestrictionType& rhs) const;

  /////////////////////////////////////////////
  /// RestrictionType members

  RestrictionType_anyOf getValue() const;
  void setValue(RestrictionType_anyOf value);
  RestrictionType_anyOf::eRestrictionType_anyOf getEnumValue() const;
  void setEnumValue(RestrictionType_anyOf::eRestrictionType_anyOf value);
  friend void to_json(nlohmann::json& j, const RestrictionType& o);
  friend void from_json(const nlohmann::json& j, RestrictionType& o);
  friend void to_json(nlohmann::json& j, const RestrictionType_anyOf& o);
  friend void from_json(const nlohmann::json& j, RestrictionType_anyOf& o);

 protected:
  RestrictionType_anyOf m_value;
};

}  // namespace ngkore::model::common

