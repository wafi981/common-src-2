
#ifndef UserLocation_H_
#define UserLocation_H_

#include "EutraLocation.h"
#include "GeraLocation.h"
#include "NrLocation.h"
#include "UtraLocation.h"
#include "N3gaLocation.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class UserLocation {
 public:
  UserLocation();
  virtual ~UserLocation() = default;

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

  bool operator==(const UserLocation& rhs) const;
  bool operator!=(const UserLocation& rhs) const;

  /////////////////////////////////////////////
  /// UserLocation members

  /// <summary>
  ///
  /// </summary>
  ngkore::model::common::EutraLocation getEutraLocation() const;
  void setEutraLocation(ngkore::model::common::EutraLocation const& value);
  bool eutraLocationIsSet() const;
  void unsetEutraLocation();
  /// <summary>
  ///
  /// </summary>
  ngkore::model::common::NrLocation getNrLocation() const;
  void setNrLocation(ngkore::model::common::NrLocation const& value);
  bool nrLocationIsSet() const;
  void unsetNrLocation();
  /// <summary>
  ///
  /// </summary>
  ngkore::model::common::N3gaLocation getN3gaLocation() const;
  void setN3gaLocation(ngkore::model::common::N3gaLocation const& value);
  bool n3gaLocationIsSet() const;
  void unsetN3gaLocation();
  /// <summary>
  ///
  /// </summary>
  ngkore::model::common::UtraLocation getUtraLocation() const;
  void setUtraLocation(ngkore::model::common::UtraLocation const& value);
  bool utraLocationIsSet() const;
  void unsetUtraLocation();
  /// <summary>
  ///
  /// </summary>
  ngkore::model::common::GeraLocation getGeraLocation() const;
  void setGeraLocation(ngkore::model::common::GeraLocation const& value);
  bool geraLocationIsSet() const;
  void unsetGeraLocation();

  friend void to_json(nlohmann::json& j, const UserLocation& o);
  friend void from_json(const nlohmann::json& j, UserLocation& o);

 protected:
  ngkore::model::common::EutraLocation m_EutraLocation;
  bool m_EutraLocationIsSet;
  ngkore::model::common::NrLocation m_NrLocation;
  bool m_NrLocationIsSet;
  ngkore::model::common::N3gaLocation m_N3gaLocation;
  bool m_N3gaLocationIsSet;
  ngkore::model::common::UtraLocation m_UtraLocation;
  bool m_UtraLocationIsSet;
  ngkore::model::common::GeraLocation m_GeraLocation;
  bool m_GeraLocationIsSet;
};

}  // namespace ngkore::model::common

