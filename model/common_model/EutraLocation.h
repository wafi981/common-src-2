
#ifndef EutraLocation_H_
#define EutraLocation_H_

#include "Ecgi.h"
#include "Tai.h"
#include <string>
#include "GlobalRanNodeId.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class EutraLocation {
 public:
  EutraLocation();
  virtual ~EutraLocation() = default;

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

  bool operator==(const EutraLocation& rhs) const;
  bool operator!=(const EutraLocation& rhs) const;

  /////////////////////////////////////////////
  /// EutraLocation members

  /// <summary>
  ///
  /// </summary>
  ngkore::model::common::Tai getTai() const;
  void setTai(ngkore::model::common::Tai const& value);
  /// <summary>
  ///
  /// </summary>
  bool isIgnoreTai() const;
  void setIgnoreTai(bool const value);
  bool ignoreTaiIsSet() const;
  void unsetIgnoreTai();
  /// <summary>
  ///
  /// </summary>
  ngkore::model::common::Ecgi getEcgi() const;
  void setEcgi(ngkore::model::common::Ecgi const& value);
  /// <summary>
  ///
  /// </summary>
  bool isIgnoreEcgi() const;
  void setIgnoreEcgi(bool const value);
  bool ignoreEcgiIsSet() const;
  void unsetIgnoreEcgi();
  /// <summary>
  ///
  /// </summary>
  int32_t getAgeOfLocationInformation() const;
  void setAgeOfLocationInformation(int32_t const value);
  bool ageOfLocationInformationIsSet() const;
  void unsetAgeOfLocationInformation();
  /// <summary>
  ///
  /// </summary>
  std::string getUeLocationTimestamp() const;
  void setUeLocationTimestamp(std::string const& value);
  bool ueLocationTimestampIsSet() const;
  void unsetUeLocationTimestamp();
  /// <summary>
  ///
  /// </summary>
  std::string getGeographicalInformation() const;
  void setGeographicalInformation(std::string const& value);
  bool geographicalInformationIsSet() const;
  void unsetGeographicalInformation();
  /// <summary>
  ///
  /// </summary>
  std::string getGeodeticInformation() const;
  void setGeodeticInformation(std::string const& value);
  bool geodeticInformationIsSet() const;
  void unsetGeodeticInformation();
  /// <summary>
  ///
  /// </summary>
  ngkore::model::common::GlobalRanNodeId getGlobalNgenbId() const;
  void setGlobalNgenbId(ngkore::model::common::GlobalRanNodeId const& value);
  bool globalNgenbIdIsSet() const;
  void unsetGlobalNgenbId();
  /// <summary>
  ///
  /// </summary>
  ngkore::model::common::GlobalRanNodeId getGlobalENbId() const;
  void setGlobalENbId(ngkore::model::common::GlobalRanNodeId const& value);
  bool globalENbIdIsSet() const;
  void unsetGlobalENbId();

  friend void to_json(nlohmann::json& j, const EutraLocation& o);
  friend void from_json(const nlohmann::json& j, EutraLocation& o);

 protected:
  ngkore::model::common::Tai m_Tai;

  bool m_IgnoreTai;
  bool m_IgnoreTaiIsSet;
  ngkore::model::common::Ecgi m_Ecgi;

  bool m_IgnoreEcgi;
  bool m_IgnoreEcgiIsSet;
  int32_t m_AgeOfLocationInformation;
  bool m_AgeOfLocationInformationIsSet;
  std::string m_UeLocationTimestamp;
  bool m_UeLocationTimestampIsSet;
  std::string m_GeographicalInformation;
  bool m_GeographicalInformationIsSet;
  std::string m_GeodeticInformation;
  bool m_GeodeticInformationIsSet;
  ngkore::model::common::GlobalRanNodeId m_GlobalNgenbId;
  bool m_GlobalNgenbIdIsSet;
  ngkore::model::common::GlobalRanNodeId m_GlobalENbId;
  bool m_GlobalENbIdIsSet;
};

}  // namespace ngkore::model::common

