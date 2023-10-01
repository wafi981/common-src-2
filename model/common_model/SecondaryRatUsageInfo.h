
#ifndef SecondaryRatUsageInfo_H_
#define SecondaryRatUsageInfo_H_

#include "VolumeTimedReport.h"
#include "QosFlowUsageReport.h"
#include "RatType.h"
#include <vector>
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class SecondaryRatUsageInfo {
 public:
  SecondaryRatUsageInfo();
  virtual ~SecondaryRatUsageInfo() = default;

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

  bool operator==(const SecondaryRatUsageInfo& rhs) const;
  bool operator!=(const SecondaryRatUsageInfo& rhs) const;

  /////////////////////////////////////////////
  /// SecondaryRatUsageInfo members

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
  bool qosFlowsUsageDataIsSet() const;
  void unsetQosFlowsUsageData();
  /// <summary>
  ///
  /// </summary>
  std::vector<ngkore::model::common::VolumeTimedReport> getPduSessionUsageData()
      const;
  void setPduSessionUsageData(
      std::vector<ngkore::model::common::VolumeTimedReport> const& value);
  bool pduSessionUsageDataIsSet() const;
  void unsetPduSessionUsageData();

  friend void to_json(nlohmann::json& j, const SecondaryRatUsageInfo& o);
  friend void from_json(const nlohmann::json& j, SecondaryRatUsageInfo& o);

 protected:
  ngkore::model::common::RatType m_SecondaryRatType;

  std::vector<ngkore::model::common::QosFlowUsageReport> m_QosFlowsUsageData;
  bool m_QosFlowsUsageDataIsSet;
  std::vector<ngkore::model::common::VolumeTimedReport> m_PduSessionUsageData;
  bool m_PduSessionUsageDataIsSet;
};

}  // namespace ngkore::model::common

