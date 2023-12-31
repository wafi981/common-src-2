
#ifndef TraceDepth_anyOf_H_
#define TraceDepth_anyOf_H_

#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class TraceDepth_anyOf {
 public:
  TraceDepth_anyOf();
  virtual ~TraceDepth_anyOf() = default;

  enum class eTraceDepth_anyOf {
    // To have a valid default value.
    // Avoiding name clashes with user defined
    // enum values
    INVALID_VALUE_OPENAPI_GENERATED = 0,
    MINIMUM,
    MEDIUM,
    MAXIMUM,
    MINIMUM_WO_VENDOR_EXTENSION,
    MEDIUM_WO_VENDOR_EXTENSION,
    MAXIMUM_WO_VENDOR_EXTENSION
  };

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

  bool operator==(const TraceDepth_anyOf& rhs) const;
  bool operator!=(const TraceDepth_anyOf& rhs) const;

  /////////////////////////////////////////////
  /// TraceDepth_anyOf members

  TraceDepth_anyOf::eTraceDepth_anyOf getValue() const;
  void setValue(TraceDepth_anyOf::eTraceDepth_anyOf value);

  friend void to_json(nlohmann::json& j, const TraceDepth_anyOf& o);
  friend void from_json(const nlohmann::json& j, TraceDepth_anyOf& o);

 protected:
  TraceDepth_anyOf::eTraceDepth_anyOf m_value =
      TraceDepth_anyOf::eTraceDepth_anyOf::INVALID_VALUE_OPENAPI_GENERATED;
};

}  // namespace ngkore::model::common

