
#ifndef LineType_H_
#define LineType_H_

#include "LineType_anyOf.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
/// Possible values are - DSL: Identifies a DSL line - PON: Identifies a PON
/// line
/// </summary>
class LineType {
 public:
  LineType();
  virtual ~LineType() = default;

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

  bool operator==(const LineType& rhs) const;
  bool operator!=(const LineType& rhs) const;

  /////////////////////////////////////////////
  /// LineType members

  LineType_anyOf getValue() const;
  void setValue(LineType_anyOf value);
  LineType_anyOf::eLineType_anyOf getEnumValue() const;
  void setEnumValue(LineType_anyOf::eLineType_anyOf value);
  friend void to_json(nlohmann::json& j, const LineType& o);
  friend void from_json(const nlohmann::json& j, LineType& o);
  friend void to_json(nlohmann::json& j, const LineType_anyOf& o);
  friend void from_json(const nlohmann::json& j, LineType_anyOf& o);

 protected:
  LineType_anyOf m_value;
};

}  // namespace ngkore::model::common

