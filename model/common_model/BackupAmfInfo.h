
#ifndef BackupAmfInfo_H_
#define BackupAmfInfo_H_

#include <string>
#include <vector>
#include "Guami.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class BackupAmfInfo {
 public:
  BackupAmfInfo();
  virtual ~BackupAmfInfo() = default;

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

  bool operator==(const BackupAmfInfo& rhs) const;
  bool operator!=(const BackupAmfInfo& rhs) const;

  /////////////////////////////////////////////
  /// BackupAmfInfo members

  /// <summary>
  ///
  /// </summary>
  std::string getBackupAmf() const;
  void setBackupAmf(std::string const& value);
  /// <summary>
  ///
  /// </summary>
  std::vector<ngkore::model::common::Guami> getGuamiList() const;
  void setGuamiList(std::vector<ngkore::model::common::Guami> const& value);
  bool guamiListIsSet() const;
  void unsetGuamiList();

  friend void to_json(nlohmann::json& j, const BackupAmfInfo& o);
  friend void from_json(const nlohmann::json& j, BackupAmfInfo& o);

 protected:
  std::string m_BackupAmf;

  std::vector<ngkore::model::common::Guami> m_GuamiList;
  bool m_GuamiListIsSet;
};

}  // namespace ngkore::model::common

