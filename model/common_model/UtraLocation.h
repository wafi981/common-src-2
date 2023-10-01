
#ifndef UtraLocation_H_
#define UtraLocation_H_

#include "CellGlobalId.h"
#include <string>
#include "RoutingAreaId.h"
#include "LocationAreaId.h"
#include "ServiceAreaId.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class UtraLocation {
 public:
  UtraLocation();
  virtual ~UtraLocation() = default;

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

  bool operator==(const UtraLocation& rhs) const;
  bool operator!=(const UtraLocation& rhs) const;

  /////////////////////////////////////////////
  /// UtraLocation members

  /// <summary>
  ///
  /// </summary>
  ngkore::model::common::CellGlobalId getCgi() const;
  void setCgi(ngkore::model::common::CellGlobalId const& value);
  bool cgiIsSet() const;
  void unsetCgi();
  /// <summary>
  ///
  /// </summary>
  ngkore::model::common::ServiceAreaId getSai() const;
  void setSai(ngkore::model::common::ServiceAreaId const& value);
  bool saiIsSet() const;
  void unsetSai();
  /// <summary>
  ///
  /// </summary>
  ngkore::model::common::LocationAreaId getLai() const;
  void setLai(ngkore::model::common::LocationAreaId const& value);
  bool laiIsSet() const;
  void unsetLai();
  /// <summary>
  ///
  /// </summary>
  ngkore::model::common::RoutingAreaId getRai() const;
  void setRai(ngkore::model::common::RoutingAreaId const& value);
  bool raiIsSet() const;
  void unsetRai();
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

  friend void to_json(nlohmann::json& j, const UtraLocation& o);
  friend void from_json(const nlohmann::json& j, UtraLocation& o);

 protected:
  ngkore::model::common::CellGlobalId m_Cgi;
  bool m_CgiIsSet;
  ngkore::model::common::ServiceAreaId m_Sai;
  bool m_SaiIsSet;
  ngkore::model::common::LocationAreaId m_Lai;
  bool m_LaiIsSet;
  ngkore::model::common::RoutingAreaId m_Rai;
  bool m_RaiIsSet;
  int32_t m_AgeOfLocationInformation;
  bool m_AgeOfLocationInformationIsSet;
  std::string m_UeLocationTimestamp;
  bool m_UeLocationTimestampIsSet;
  std::string m_GeographicalInformation;
  bool m_GeographicalInformationIsSet;
  std::string m_GeodeticInformation;
  bool m_GeodeticInformationIsSet;
};

}  // namespace ngkore::model::common

