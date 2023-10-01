
#ifndef PduSessionType_H_
#define PduSessionType_H_

#include "PduSessionType_anyOf.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class PduSessionType {
 public:
  PduSessionType();
  virtual ~PduSessionType() = default;

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

  bool operator==(const PduSessionType& rhs) const;
  bool operator!=(const PduSessionType& rhs) const;

  /////////////////////////////////////////////
  /// PduSessionType members

  PduSessionType_anyOf getValue() const;
  void setValue(PduSessionType_anyOf value);
  PduSessionType_anyOf::ePduSessionType_anyOf getEnumValue() const;
  void setEnumValue(PduSessionType_anyOf::ePduSessionType_anyOf value);
  friend void to_json(nlohmann::json& j, const PduSessionType& o);
  friend void from_json(const nlohmann::json& j, PduSessionType& o);
  friend void to_json(nlohmann::json& j, const PduSessionType_anyOf& o);
  friend void from_json(const nlohmann::json& j, PduSessionType_anyOf& o);

 protected:
  PduSessionType_anyOf m_value;
};

}  // namespace ngkore::model::common

