
#ifndef DnaiChangeType_H_
#define DnaiChangeType_H_

#include "DnaiChangeType_anyOf.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
/// Possible values are - EARLY: Early notification of UP path reconfiguration.
/// - EARLY_LATE: Early and late notification of UP path reconfiguration. This
/// value shall only be present in the subscription to the DNAI change event. -
/// LATE: Late notification of UP path reconfiguration.
/// </summary>
class DnaiChangeType {
 public:
  DnaiChangeType();
  virtual ~DnaiChangeType() = default;

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

  bool operator==(const DnaiChangeType& rhs) const;
  bool operator!=(const DnaiChangeType& rhs) const;

  /////////////////////////////////////////////
  /// DnaiChangeType members

  DnaiChangeType_anyOf getValue() const;
  void setValue(DnaiChangeType_anyOf value);
  DnaiChangeType_anyOf::eDnaiChangeType_anyOf getEnumValue() const;
  void setEnumValue(DnaiChangeType_anyOf::eDnaiChangeType_anyOf value);
  friend void to_json(nlohmann::json& j, const DnaiChangeType& o);
  friend void from_json(const nlohmann::json& j, DnaiChangeType& o);
  friend void to_json(nlohmann::json& j, const DnaiChangeType_anyOf& o);
  friend void from_json(const nlohmann::json& j, DnaiChangeType_anyOf& o);

 protected:
  DnaiChangeType_anyOf m_value;
};

}  // namespace ngkore::model::common

