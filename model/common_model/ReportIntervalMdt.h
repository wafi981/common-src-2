
#ifndef ReportIntervalMdt_H_
#define ReportIntervalMdt_H_

#include "ReportIntervalMdt_anyOf.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class ReportIntervalMdt {
 public:
  ReportIntervalMdt();
  virtual ~ReportIntervalMdt() = default;

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

  bool operator==(const ReportIntervalMdt& rhs) const;
  bool operator!=(const ReportIntervalMdt& rhs) const;

  /////////////////////////////////////////////
  /// ReportIntervalMdt members

  ReportIntervalMdt_anyOf getValue() const;
  void setValue(ReportIntervalMdt_anyOf value);
  ReportIntervalMdt_anyOf::eReportIntervalMdt_anyOf getEnumValue() const;
  void setEnumValue(ReportIntervalMdt_anyOf::eReportIntervalMdt_anyOf value);
  friend void to_json(nlohmann::json& j, const ReportIntervalMdt& o);
  friend void from_json(const nlohmann::json& j, ReportIntervalMdt& o);
  friend void to_json(nlohmann::json& j, const ReportIntervalMdt_anyOf& o);
  friend void from_json(const nlohmann::json& j, ReportIntervalMdt_anyOf& o);

 protected:
  ReportIntervalMdt_anyOf m_value;
};

}  // namespace ngkore::model::common

