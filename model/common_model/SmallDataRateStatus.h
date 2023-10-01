
#ifndef SmallDataRateStatus_H_
#define SmallDataRateStatus_H_

#include <string>
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class SmallDataRateStatus {
 public:
  SmallDataRateStatus();
  virtual ~SmallDataRateStatus() = default;

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

  bool operator==(const SmallDataRateStatus& rhs) const;
  bool operator!=(const SmallDataRateStatus& rhs) const;

  /////////////////////////////////////////////
  /// SmallDataRateStatus members

  /// <summary>
  ///
  /// </summary>
  int32_t getRemainPacketsUl() const;
  void setRemainPacketsUl(int32_t const value);
  bool remainPacketsUlIsSet() const;
  void unsetRemainPacketsUl();
  /// <summary>
  ///
  /// </summary>
  int32_t getRemainPacketsDl() const;
  void setRemainPacketsDl(int32_t const value);
  bool remainPacketsDlIsSet() const;
  void unsetRemainPacketsDl();
  /// <summary>
  ///
  /// </summary>
  std::string getValidityTime() const;
  void setValidityTime(std::string const& value);
  bool validityTimeIsSet() const;
  void unsetValidityTime();
  /// <summary>
  ///
  /// </summary>
  int32_t getRemainExReportsUl() const;
  void setRemainExReportsUl(int32_t const value);
  bool remainExReportsUlIsSet() const;
  void unsetRemainExReportsUl();
  /// <summary>
  ///
  /// </summary>
  int32_t getRemainExReportsDl() const;
  void setRemainExReportsDl(int32_t const value);
  bool remainExReportsDlIsSet() const;
  void unsetRemainExReportsDl();

  friend void to_json(nlohmann::json& j, const SmallDataRateStatus& o);
  friend void from_json(const nlohmann::json& j, SmallDataRateStatus& o);

 protected:
  int32_t m_RemainPacketsUl;
  bool m_RemainPacketsUlIsSet;
  int32_t m_RemainPacketsDl;
  bool m_RemainPacketsDlIsSet;
  std::string m_ValidityTime;
  bool m_ValidityTimeIsSet;
  int32_t m_RemainExReportsUl;
  bool m_RemainExReportsUlIsSet;
  int32_t m_RemainExReportsDl;
  bool m_RemainExReportsDlIsSet;
};

}  // namespace ngkore::model::common

