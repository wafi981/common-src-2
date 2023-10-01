
#ifndef NrV2xAuth_H_
#define NrV2xAuth_H_

#include "UeAuth.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class NrV2xAuth {
 public:
  NrV2xAuth();
  virtual ~NrV2xAuth() = default;

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

  bool operator==(const NrV2xAuth& rhs) const;
  bool operator!=(const NrV2xAuth& rhs) const;

  /////////////////////////////////////////////
  /// NrV2xAuth members

  /// <summary>
  ///
  /// </summary>
  ngkore::model::common::UeAuth getVehicleUeAuth() const;
  void setVehicleUeAuth(ngkore::model::common::UeAuth const& value);
  bool vehicleUeAuthIsSet() const;
  void unsetVehicleUeAuth();
  /// <summary>
  ///
  /// </summary>
  ngkore::model::common::UeAuth getPedestrianUeAuth() const;
  void setPedestrianUeAuth(ngkore::model::common::UeAuth const& value);
  bool pedestrianUeAuthIsSet() const;
  void unsetPedestrianUeAuth();

  friend void to_json(nlohmann::json& j, const NrV2xAuth& o);
  friend void from_json(const nlohmann::json& j, NrV2xAuth& o);

 protected:
  ngkore::model::common::UeAuth m_VehicleUeAuth;
  bool m_VehicleUeAuthIsSet;
  ngkore::model::common::UeAuth m_PedestrianUeAuth;
  bool m_PedestrianUeAuthIsSet;
};

}  // namespace ngkore::model::common

