
#ifndef PatchOperation_H_
#define PatchOperation_H_

#include "PatchOperation_anyOf.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class PatchOperation {
 public:
  PatchOperation();

  virtual ~PatchOperation() = default;

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

  bool operator==(const PatchOperation& rhs) const;
  bool operator!=(const PatchOperation& rhs) const;

  /////////////////////////////////////////////
  /// PatchOperation members

  PatchOperation_anyOf getValue() const;
  void setValue(PatchOperation_anyOf value);
  PatchOperation_anyOf::ePatchOperation_anyOf getEnumValue() const;
  std::string getEnumString() const;
  void setEnumValue(PatchOperation_anyOf::ePatchOperation_anyOf value);
  friend void to_json(nlohmann::json& j, const PatchOperation& o);
  friend void from_json(const nlohmann::json& j, PatchOperation& o);
  friend void to_json(nlohmann::json& j, const PatchOperation_anyOf& o);
  friend void from_json(const nlohmann::json& j, PatchOperation_anyOf& o);

 protected:
  PatchOperation_anyOf m_value;
};

}  // namespace ngkore::model::common

