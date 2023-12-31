
#ifndef RgWirelineCharacteristicsRm_H_
#define RgWirelineCharacteristicsRm_H_

#include "NullValue.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class RgWirelineCharacteristicsRm {
 public:
  RgWirelineCharacteristicsRm();
  virtual ~RgWirelineCharacteristicsRm() = default;

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

  bool operator==(const RgWirelineCharacteristicsRm& rhs) const;
  bool operator!=(const RgWirelineCharacteristicsRm& rhs) const;

  /////////////////////////////////////////////
  /// RgWirelineCharacteristicsRm members

  NullValue getValue() const;
  void setValue(NullValue value);
  NullValue::eNullValue getEnumValue() const;
  void setEnumValue(NullValue::eNullValue value);
  friend void to_json(nlohmann::json& j, const RgWirelineCharacteristicsRm& o);
  friend void from_json(
      const nlohmann::json& j, RgWirelineCharacteristicsRm& o);
  friend void to_json(nlohmann::json& j, const NullValue& o);
  friend void from_json(const nlohmann::json& j, NullValue& o);

 protected:
  NullValue m_value;
};

}  // namespace ngkore::model::common

