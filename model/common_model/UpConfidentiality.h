
#ifndef UpConfidentiality_H_
#define UpConfidentiality_H_

#include "UpIntegrity_anyOf.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class UpConfidentiality {
 public:
  UpConfidentiality();
  virtual ~UpConfidentiality() = default;

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

  bool operator==(const UpConfidentiality& rhs) const;
  bool operator!=(const UpConfidentiality& rhs) const;

  /////////////////////////////////////////////
  /// UpConfidentiality members

  UpIntegrity_anyOf getValue() const;
  void setValue(UpIntegrity_anyOf value);
  UpIntegrity_anyOf::eUpIntegrity_anyOf getEnumValue() const;
  void setEnumValue(UpIntegrity_anyOf::eUpIntegrity_anyOf value);
  friend void to_json(nlohmann::json& j, const UpConfidentiality& o);
  friend void from_json(const nlohmann::json& j, UpConfidentiality& o);
  friend void to_json(nlohmann::json& j, const UpIntegrity_anyOf& o);
  friend void from_json(const nlohmann::json& j, UpIntegrity_anyOf& o);

 protected:
  UpIntegrity_anyOf m_value;
};

}  // namespace ngkore::model::common

