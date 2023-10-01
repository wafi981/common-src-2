
#ifndef SscMode_H_
#define SscMode_H_

#include "SscMode_anyOf.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class SscMode {
 public:
  SscMode();
  virtual ~SscMode() = default;

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

  bool operator==(const SscMode& rhs) const;
  bool operator!=(const SscMode& rhs) const;

  /////////////////////////////////////////////
  /// SscMode members

  SscMode_anyOf getValue() const;
  void setValue(SscMode_anyOf value);
  SscMode_anyOf::eSscMode_anyOf getEnumValue() const;
  void setEnumValue(SscMode_anyOf::eSscMode_anyOf value);
  friend void to_json(nlohmann::json& j, const SscMode& o);
  friend void from_json(const nlohmann::json& j, SscMode& o);
  friend void to_json(nlohmann::json& j, const SscMode_anyOf& o);
  friend void from_json(const nlohmann::json& j, SscMode_anyOf& o);

 protected:
  SscMode_anyOf m_value;
};

}  // namespace ngkore::model::common

