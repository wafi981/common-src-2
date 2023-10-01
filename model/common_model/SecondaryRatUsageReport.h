
#ifndef SecondaryRatUsageReport_H_
#define SecondaryRatUsageReport_H_

#include "QosFlowUsageReport.h"
#include "RatType.h"
#include <vector>
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class SecondaryRatUsageReport {
 public:
  SecondaryRatUsageReport();
  virtual ~SecondaryRatUsageReport() = default;

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

  bool operator==(const SecondaryRatUsageReport& rhs) const;
  bool operator!=(const SecondaryRatUsageReport& rhs) const;

  /////////////////////////////////////////////
  /// SecondaryRatUsageReport members

  /// <summary>
  ///
  /// </summary>
  ngkore::model::common::RatType getSecondaryRatType() const;
  void setSecondaryRatType(ngkore::model::common::RatType const& value);
  /// <summary>
  ///
  /// </summary>
  std::vector<ngkore::model::common::QosFlowUsageReport> getQosFlowsUsageData()
      const;
  void setQosFlowsUsageData(
      std::vector<ngkore::model::common::QosFlowUsageReport> const& value);

  friend void to_json(nlohmann::json& j, const SecondaryRatUsageReport& o);
  friend void from_json(const nlohmann::json& j, SecondaryRatUsageReport& o);

 protected:
  ngkore::model::common::RatType m_SecondaryRatType;

  std::vector<ngkore::model::common::QosFlowUsageReport> m_QosFlowsUsageData;
};

}  // namespace ngkore::model::common

