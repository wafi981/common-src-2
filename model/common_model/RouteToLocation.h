
#ifndef RouteToLocation_H_
#define RouteToLocation_H_

#include <string>
#include "RouteInformation.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class RouteToLocation {
 public:
  RouteToLocation();
  virtual ~RouteToLocation() = default;

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

  bool operator==(const RouteToLocation& rhs) const;
  bool operator!=(const RouteToLocation& rhs) const;

  /////////////////////////////////////////////
  /// RouteToLocation members

  /// <summary>
  ///
  /// </summary>
  std::string getDnai() const;
  void setDnai(std::string const& value);
  /// <summary>
  ///
  /// </summary>
  ngkore::model::common::RouteInformation getRouteInfo() const;
  void setRouteInfo(ngkore::model::common::RouteInformation const& value);
  bool routeInfoIsSet() const;
  void unsetRouteInfo();
  /// <summary>
  ///
  /// </summary>
  std::string getRouteProfId() const;
  void setRouteProfId(std::string const& value);
  bool routeProfIdIsSet() const;
  void unsetRouteProfId();

  friend void to_json(nlohmann::json& j, const RouteToLocation& o);
  friend void from_json(const nlohmann::json& j, RouteToLocation& o);

 protected:
  std::string m_Dnai;

  ngkore::model::common::RouteInformation m_RouteInfo;
  bool m_RouteInfoIsSet;
  std::string m_RouteProfId;
  bool m_RouteProfIdIsSet;
};

}  // namespace ngkore::model::common

