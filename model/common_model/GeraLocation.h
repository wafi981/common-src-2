
#ifndef GeraLocation_H_
#define GeraLocation_H_

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
class GeraLocation {
 public:
  GeraLocation();
  virtual ~GeraLocation() = default;

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

  bool operator==(const GeraLocation& rhs) const;
  bool operator!=(const GeraLocation& rhs) const;

  /////////////////////////////////////////////
  /// GeraLocation members

  /// <summary>
  ///
  /// </summary>
  std::string getLocationNumber() const;
  void setLocationNumber(std::string const& value);
  bool locationNumberIsSet() const;
  void unsetLocationNumber();
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
  ngkore::model::common::RoutingAreaId getRai() const;
  void setRai(ngkore::model::common::RoutingAreaId const& value);
  bool raiIsSet() const;
  void unsetRai();
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
  std::string getVlrNumber() const;
  void setVlrNumber(std::string const& value);
  bool vlrNumberIsSet() const;
  void unsetVlrNumber();
  /// <summary>
  ///
  /// </summary>
  std::string getMscNumber() const;
  void setMscNumber(std::string const& value);
  bool mscNumberIsSet() const;
  void unsetMscNumber();
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

  friend void to_json(nlohmann::json& j, const GeraLocation& o);
  friend void from_json(const nlohmann::json& j, GeraLocation& o);

 protected:
  std::string m_LocationNumber;
  bool m_LocationNumberIsSet;
  ngkore::model::common::CellGlobalId m_Cgi;
  bool m_CgiIsSet;
  ngkore::model::common::RoutingAreaId m_Rai;
  bool m_RaiIsSet;
  ngkore::model::common::ServiceAreaId m_Sai;
  bool m_SaiIsSet;
  ngkore::model::common::LocationAreaId m_Lai;
  bool m_LaiIsSet;
  std::string m_VlrNumber;
  bool m_VlrNumberIsSet;
  std::string m_MscNumber;
  bool m_MscNumberIsSet;
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

