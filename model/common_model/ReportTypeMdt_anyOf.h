
#ifndef ReportTypeMdt_anyOf_H_
#define ReportTypeMdt_anyOf_H_

#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class ReportTypeMdt_anyOf {
 public:
  ReportTypeMdt_anyOf();
  virtual ~ReportTypeMdt_anyOf() = default;

  enum class eReportTypeMdt_anyOf {
    // To have a valid default value.
    // Avoiding name clashes with user defined
    // enum values
    INVALID_VALUE_OPENAPI_GENERATED = 0,
    PERIODICAL,
    EVENT_TRIGGED
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

  bool operator==(const ReportTypeMdt_anyOf& rhs) const;
  bool operator!=(const ReportTypeMdt_anyOf& rhs) const;

  /////////////////////////////////////////////
  /// ReportTypeMdt_anyOf members

  ReportTypeMdt_anyOf::eReportTypeMdt_anyOf getValue() const;
  void setValue(ReportTypeMdt_anyOf::eReportTypeMdt_anyOf value);

  friend void to_json(nlohmann::json& j, const ReportTypeMdt_anyOf& o);
  friend void from_json(const nlohmann::json& j, ReportTypeMdt_anyOf& o);

 protected:
  ReportTypeMdt_anyOf::eReportTypeMdt_anyOf m_value = ReportTypeMdt_anyOf::
      eReportTypeMdt_anyOf::INVALID_VALUE_OPENAPI_GENERATED;
};

}  // namespace ngkore::model::common

