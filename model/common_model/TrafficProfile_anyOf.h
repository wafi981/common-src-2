
#ifndef TrafficProfile_anyOf_H_
#define TrafficProfile_anyOf_H_

#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class TrafficProfile_anyOf {
 public:
  TrafficProfile_anyOf();
  virtual ~TrafficProfile_anyOf() = default;

  enum class eTrafficProfile_anyOf {
    // To have a valid default value.
    // Avoiding name clashes with user defined
    // enum values
    INVALID_VALUE_OPENAPI_GENERATED = 0,
    SINGLE_TRANS_UL,
    SINGLE_TRANS_DL,
    DUAL_TRANS_UL_FIRST,
    DUAL_TRANS_DL_FIRST,
    MULTI_TRANS
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

  bool operator==(const TrafficProfile_anyOf& rhs) const;
  bool operator!=(const TrafficProfile_anyOf& rhs) const;

  /////////////////////////////////////////////
  /// TrafficProfile_anyOf members

  TrafficProfile_anyOf::eTrafficProfile_anyOf getValue() const;
  void setValue(TrafficProfile_anyOf::eTrafficProfile_anyOf value);

  friend void to_json(nlohmann::json& j, const TrafficProfile_anyOf& o);
  friend void from_json(const nlohmann::json& j, TrafficProfile_anyOf& o);

 protected:
  TrafficProfile_anyOf::eTrafficProfile_anyOf m_value = TrafficProfile_anyOf::
      eTrafficProfile_anyOf::INVALID_VALUE_OPENAPI_GENERATED;
};

}  // namespace ngkore::model::common

