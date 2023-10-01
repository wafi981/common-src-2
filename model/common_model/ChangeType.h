
#ifndef ChangeType_H_
#define ChangeType_H_

#include "ChangeType_anyOf.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class ChangeType {
 public:
  ChangeType();
  virtual ~ChangeType() = default;

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

  bool operator==(const ChangeType& rhs) const;
  bool operator!=(const ChangeType& rhs) const;

  /////////////////////////////////////////////
  /// ChangeType members

  ChangeType_anyOf getValue() const;
  void setValue(ChangeType_anyOf value);
  ChangeType_anyOf::eChangeType_anyOf getEnumValue() const;
  void setEnumValue(ChangeType_anyOf::eChangeType_anyOf value);
  friend void to_json(nlohmann::json& j, const ChangeType& o);
  friend void from_json(const nlohmann::json& j, ChangeType& o);
  friend void to_json(nlohmann::json& j, const ChangeType_anyOf& o);
  friend void from_json(const nlohmann::json& j, ChangeType_anyOf& o);

 protected:
  ChangeType_anyOf m_value;
};

}  // namespace ngkore::model::common
