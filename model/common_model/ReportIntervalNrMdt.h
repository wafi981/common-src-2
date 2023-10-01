
#ifndef ReportIntervalNrMdt_H_
#define ReportIntervalNrMdt_H_

#include "ReportIntervalNrMdt_anyOf.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class ReportIntervalNrMdt {
 public:
  ReportIntervalNrMdt();
  virtual ~ReportIntervalNrMdt() = default;

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

  bool operator==(const ReportIntervalNrMdt& rhs) const;
  bool operator!=(const ReportIntervalNrMdt& rhs) const;

  /////////////////////////////////////////////
  /// ReportIntervalNrMdt members

  ReportIntervalNrMdt_anyOf getValue() const;
  void setValue(ReportIntervalNrMdt_anyOf value);
  ReportIntervalNrMdt_anyOf::eReportIntervalNrMdt_anyOf getEnumValue() const;
  void setEnumValue(
      ReportIntervalNrMdt_anyOf::eReportIntervalNrMdt_anyOf value);
  friend void to_json(nlohmann::json& j, const ReportIntervalNrMdt& o);
  friend void from_json(const nlohmann::json& j, ReportIntervalNrMdt& o);
  friend void to_json(nlohmann::json& j, const ReportIntervalNrMdt_anyOf& o);
  friend void from_json(const nlohmann::json& j, ReportIntervalNrMdt_anyOf& o);

 protected:
  ReportIntervalNrMdt_anyOf m_value;
};

}  // namespace ngkore::model::common

