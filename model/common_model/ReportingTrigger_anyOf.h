
#ifndef ReportingTrigger_anyOf_H_
#define ReportingTrigger_anyOf_H_

#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class ReportingTrigger_anyOf {
 public:
  ReportingTrigger_anyOf();
  virtual ~ReportingTrigger_anyOf() = default;

  enum class eReportingTrigger_anyOf {
    // To have a valid default value.
    // Avoiding name clashes with user defined
    // enum values
    INVALID_VALUE_OPENAPI_GENERATED = 0,
    PERIODICAL,
    EVENT_A2,
    EVENT_A2_PERIODIC,
    ALL_RRM_EVENT_TRIGGERS
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

  bool operator==(const ReportingTrigger_anyOf& rhs) const;
  bool operator!=(const ReportingTrigger_anyOf& rhs) const;

  /////////////////////////////////////////////
  /// ReportingTrigger_anyOf members

  ReportingTrigger_anyOf::eReportingTrigger_anyOf getValue() const;
  void setValue(ReportingTrigger_anyOf::eReportingTrigger_anyOf value);

  friend void to_json(nlohmann::json& j, const ReportingTrigger_anyOf& o);
  friend void from_json(const nlohmann::json& j, ReportingTrigger_anyOf& o);

 protected:
  ReportingTrigger_anyOf::eReportingTrigger_anyOf m_value =
      ReportingTrigger_anyOf::eReportingTrigger_anyOf::
          INVALID_VALUE_OPENAPI_GENERATED;
};

}  // namespace ngkore::model::common

