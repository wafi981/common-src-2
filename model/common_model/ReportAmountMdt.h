
#ifndef ReportAmountMdt_H_
#define ReportAmountMdt_H_

#include "ReportAmountMdt_anyOf.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class ReportAmountMdt {
 public:
  ReportAmountMdt();
  virtual ~ReportAmountMdt() = default;

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

  bool operator==(const ReportAmountMdt& rhs) const;
  bool operator!=(const ReportAmountMdt& rhs) const;

  /////////////////////////////////////////////
  /// ReportAmountMdt members

  ReportAmountMdt_anyOf getValue() const;
  void setValue(ReportAmountMdt_anyOf value);
  ReportAmountMdt_anyOf::eReportAmountMdt_anyOf getEnumValue() const;
  void setEnumValue(ReportAmountMdt_anyOf::eReportAmountMdt_anyOf value);
  friend void to_json(nlohmann::json& j, const ReportAmountMdt& o);
  friend void from_json(const nlohmann::json& j, ReportAmountMdt& o);
  friend void to_json(nlohmann::json& j, const ReportAmountMdt_anyOf& o);
  friend void from_json(const nlohmann::json& j, ReportAmountMdt_anyOf& o);

 protected:
  ReportAmountMdt_anyOf m_value;
};

}  // namespace ngkore::model::common

