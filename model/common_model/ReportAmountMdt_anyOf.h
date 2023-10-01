
#ifndef ReportAmountMdt_anyOf_H_
#define ReportAmountMdt_anyOf_H_

#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class ReportAmountMdt_anyOf {
 public:
  ReportAmountMdt_anyOf();
  virtual ~ReportAmountMdt_anyOf() = default;

  enum class eReportAmountMdt_anyOf {
    // To have a valid default value.
    // Avoiding name clashes with user defined
    // enum values
    INVALID_VALUE_OPENAPI_GENERATED = 0,
    _1,
    _2,
    _4,
    _8,
    _16,
    _32,
    _64,
    _INFINITY
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

  bool operator==(const ReportAmountMdt_anyOf& rhs) const;
  bool operator!=(const ReportAmountMdt_anyOf& rhs) const;

  /////////////////////////////////////////////
  /// ReportAmountMdt_anyOf members

  ReportAmountMdt_anyOf::eReportAmountMdt_anyOf getValue() const;
  void setValue(ReportAmountMdt_anyOf::eReportAmountMdt_anyOf value);

  friend void to_json(nlohmann::json& j, const ReportAmountMdt_anyOf& o);
  friend void from_json(const nlohmann::json& j, ReportAmountMdt_anyOf& o);

 protected:
  ReportAmountMdt_anyOf::eReportAmountMdt_anyOf m_value =
      ReportAmountMdt_anyOf::eReportAmountMdt_anyOf::
          INVALID_VALUE_OPENAPI_GENERATED;
};

}  // namespace ngkore::model::common

