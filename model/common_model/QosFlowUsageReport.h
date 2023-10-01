
#ifndef QosFlowUsageReport_H_
#define QosFlowUsageReport_H_

#include <string>
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class QosFlowUsageReport {
 public:
  QosFlowUsageReport();
  virtual ~QosFlowUsageReport() = default;

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

  bool operator==(const QosFlowUsageReport& rhs) const;
  bool operator!=(const QosFlowUsageReport& rhs) const;

  /////////////////////////////////////////////
  /// QosFlowUsageReport members

  /// <summary>
  ///
  /// </summary>
  int32_t getQfi() const;
  void setQfi(int32_t const value);
  /// <summary>
  ///
  /// </summary>
  std::string getStartTimeStamp() const;
  void setStartTimeStamp(std::string const& value);
  /// <summary>
  ///
  /// </summary>
  std::string getEndTimeStamp() const;
  void setEndTimeStamp(std::string const& value);
  /// <summary>
  ///
  /// </summary>
  int64_t getDownlinkVolume() const;
  void setDownlinkVolume(int64_t const value);
  /// <summary>
  ///
  /// </summary>
  int64_t getUplinkVolume() const;
  void setUplinkVolume(int64_t const value);

  friend void to_json(nlohmann::json& j, const QosFlowUsageReport& o);
  friend void from_json(const nlohmann::json& j, QosFlowUsageReport& o);

 protected:
  int32_t m_Qfi;

  std::string m_StartTimeStamp;

  std::string m_EndTimeStamp;

  int64_t m_DownlinkVolume;

  int64_t m_UplinkVolume;
};

}  // namespace ngkore::model::common

