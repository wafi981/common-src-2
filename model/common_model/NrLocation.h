
#ifndef NrLocation_H_
#define NrLocation_H_

#include "Ncgi.h"
#include "Tai.h"
#include <string>
#include "GlobalRanNodeId.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class NrLocation {
 public:
  NrLocation();
  virtual ~NrLocation() = default;

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

  bool operator==(const NrLocation& rhs) const;
  bool operator!=(const NrLocation& rhs) const;

  /////////////////////////////////////////////
  /// NrLocation members

  /// <summary>
  ///
  /// </summary>
  ngkore::model::common::Tai getTai() const;
  void setTai(ngkore::model::common::Tai const& value);
  /// <summary>
  ///
  /// </summary>
  ngkore::model::common::Ncgi getNcgi() const;
  void setNcgi(ngkore::model::common::Ncgi const& value);
  /// <summary>
  ///
  /// </summary>
  bool isIgnoreNcgi() const;
  void setIgnoreNcgi(bool const value);
  bool ignoreNcgiIsSet() const;
  void unsetIgnoreNcgi();
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
  ngkore::model::common::GlobalRanNodeId getGlobalGnbId() const;
  void setGlobalGnbId(ngkore::model::common::GlobalRanNodeId const& value);
  bool globalGnbIdIsSet() const;
  void unsetGlobalGnbId();

  friend void to_json(nlohmann::json& j, const NrLocation& o);
  friend void from_json(const nlohmann::json& j, NrLocation& o);

 protected:
  ngkore::model::common::Tai m_Tai;

  ngkore::model::common::Ncgi m_Ncgi;

  bool m_IgnoreNcgi;
  bool m_IgnoreNcgiIsSet;
  int32_t m_AgeOfLocationInformation;
  bool m_AgeOfLocationInformationIsSet;
  std::string m_UeLocationTimestamp;
  bool m_UeLocationTimestampIsSet;
  std::string m_GeographicalInformation;
  bool m_GeographicalInformationIsSet;
  std::string m_GeodeticInformation;
  bool m_GeodeticInformationIsSet;
  ngkore::model::common::GlobalRanNodeId m_GlobalGnbId;
  bool m_GlobalGnbIdIsSet;
};

}  // namespace ngkore::model::common

