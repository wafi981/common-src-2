
#ifndef ReportTypeMdt_H_
#define ReportTypeMdt_H_

#include "ReportTypeMdt_anyOf.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class ReportTypeMdt {
 public:
  ReportTypeMdt();
  virtual ~ReportTypeMdt() = default;

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

  bool operator==(const ReportTypeMdt& rhs) const;
  bool operator!=(const ReportTypeMdt& rhs) const;

  /////////////////////////////////////////////
  /// ReportTypeMdt members

  ReportTypeMdt_anyOf getValue() const;
  void setValue(ReportTypeMdt_anyOf value);
  ReportTypeMdt_anyOf::eReportTypeMdt_anyOf getEnumValue() const;
  void setEnumValue(ReportTypeMdt_anyOf::eReportTypeMdt_anyOf value);
  friend void to_json(nlohmann::json& j, const ReportTypeMdt& o);
  friend void from_json(const nlohmann::json& j, ReportTypeMdt& o);
  friend void to_json(nlohmann::json& j, const ReportTypeMdt_anyOf& o);
  friend void from_json(const nlohmann::json& j, ReportTypeMdt_anyOf& o);

 protected:
  ReportTypeMdt_anyOf m_value;
};

}  // namespace ngkore::model::common

