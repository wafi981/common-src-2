
#ifndef PatchResult_H_
#define PatchResult_H_

#include "ReportItem.h"
#include <vector>
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class PatchResult {
 public:
  PatchResult();
  virtual ~PatchResult() = default;

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

  bool operator==(const PatchResult& rhs) const;
  bool operator!=(const PatchResult& rhs) const;

  /////////////////////////////////////////////
  /// PatchResult members

  /// <summary>
  ///
  /// </summary>
  std::vector<ngkore::model::common::ReportItem> getReport() const;
  void setReport(std::vector<ngkore::model::common::ReportItem> const& value);

  friend void to_json(nlohmann::json& j, const PatchResult& o);
  friend void from_json(const nlohmann::json& j, PatchResult& o);

 protected:
  std::vector<ngkore::model::common::ReportItem> m_Report;
};

}  // namespace ngkore::model::common

