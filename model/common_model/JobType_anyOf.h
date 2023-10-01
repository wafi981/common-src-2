
#ifndef JobType_anyOf_H_
#define JobType_anyOf_H_

#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class JobType_anyOf {
 public:
  JobType_anyOf();
  virtual ~JobType_anyOf() = default;

  enum class eJobType_anyOf {
    // To have a valid default value.
    // Avoiding name clashes with user defined
    // enum values
    INVALID_VALUE_OPENAPI_GENERATED = 0,
    IMMEDIATE_MDT_ONLY,
    LOGGED_MDT_ONLY,
    TRACE_ONLY,
    IMMEDIATE_MDT_AND_TRACE,
    RLF_REPORTS_ONLY,
    RCEF_REPORTS_ONLY,
    LOGGED_MBSFN_MDT
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

  bool operator==(const JobType_anyOf& rhs) const;
  bool operator!=(const JobType_anyOf& rhs) const;

  /////////////////////////////////////////////
  /// JobType_anyOf members

  JobType_anyOf::eJobType_anyOf getValue() const;
  void setValue(JobType_anyOf::eJobType_anyOf value);

  friend void to_json(nlohmann::json& j, const JobType_anyOf& o);
  friend void from_json(const nlohmann::json& j, JobType_anyOf& o);

 protected:
  JobType_anyOf::eJobType_anyOf m_value =
      JobType_anyOf::eJobType_anyOf::INVALID_VALUE_OPENAPI_GENERATED;
};

}  // namespace ngkore::model::common

