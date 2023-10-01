
#ifndef RatType_H_
#define RatType_H_

#include "RatType_anyOf.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class RatType {
 public:
  RatType();
  virtual ~RatType() = default;

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

  bool operator==(const RatType& rhs) const;
  bool operator!=(const RatType& rhs) const;

  /////////////////////////////////////////////
  /// RatType members

  RatType_anyOf getValue() const;
  void setValue(RatType_anyOf value);
  RatType_anyOf::eRatType_anyOf getEnumValue() const;
  void setEnumValue(RatType_anyOf::eRatType_anyOf value);
  friend void to_json(nlohmann::json& j, const RatType& o);
  friend void from_json(const nlohmann::json& j, RatType& o);
  friend void to_json(nlohmann::json& j, const RatType_anyOf& o);
  friend void from_json(const nlohmann::json& j, RatType_anyOf& o);

 protected:
  RatType_anyOf m_value;
};

}  // namespace ngkore::model::common

