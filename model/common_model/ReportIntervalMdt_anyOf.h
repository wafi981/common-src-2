
#ifndef ReportIntervalMdt_anyOf_H_
#define ReportIntervalMdt_anyOf_H_

#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class ReportIntervalMdt_anyOf {
 public:
  ReportIntervalMdt_anyOf();
  virtual ~ReportIntervalMdt_anyOf() = default;

  enum class eReportIntervalMdt_anyOf {
    // To have a valid default value.
    // Avoiding name clashes with user defined
    // enum values
    INVALID_VALUE_OPENAPI_GENERATED = 0,
    _120,
    _240,
    _480,
    _640,
    _1024,
    _2048,
    _5120,
    _10240,
    _60000,
    _360000,
    _720000,
    _1800000,
    _3600000
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

  bool operator==(const ReportIntervalMdt_anyOf& rhs) const;
  bool operator!=(const ReportIntervalMdt_anyOf& rhs) const;

  /////////////////////////////////////////////
  /// ReportIntervalMdt_anyOf members

  ReportIntervalMdt_anyOf::eReportIntervalMdt_anyOf getValue() const;
  void setValue(ReportIntervalMdt_anyOf::eReportIntervalMdt_anyOf value);

  friend void to_json(nlohmann::json& j, const ReportIntervalMdt_anyOf& o);
  friend void from_json(const nlohmann::json& j, ReportIntervalMdt_anyOf& o);

 protected:
  ReportIntervalMdt_anyOf::eReportIntervalMdt_anyOf m_value =
      ReportIntervalMdt_anyOf::eReportIntervalMdt_anyOf::
          INVALID_VALUE_OPENAPI_GENERATED;
};

}  // namespace ngkore::model::common

