
#ifndef TraceDepth_H_
#define TraceDepth_H_

#include "TraceDepth_anyOf.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class TraceDepth {
 public:
  TraceDepth();
  virtual ~TraceDepth() = default;

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

  bool operator==(const TraceDepth& rhs) const;
  bool operator!=(const TraceDepth& rhs) const;

  /////////////////////////////////////////////
  /// TraceDepth members

  TraceDepth_anyOf getValue() const;
  void setValue(TraceDepth_anyOf value);
  TraceDepth_anyOf::eTraceDepth_anyOf getEnumValue() const;
  void setEnumValue(TraceDepth_anyOf::eTraceDepth_anyOf value);
  friend void to_json(nlohmann::json& j, const TraceDepth& o);
  friend void from_json(const nlohmann::json& j, TraceDepth& o);
  friend void to_json(nlohmann::json& j, const TraceDepth_anyOf& o);
  friend void from_json(const nlohmann::json& j, TraceDepth_anyOf& o);

 protected:
  TraceDepth_anyOf m_value;
};

}  // namespace ngkore::model::common

