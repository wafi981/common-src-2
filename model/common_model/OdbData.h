
#ifndef OdbData_H_
#define OdbData_H_

#include "RoamingOdb.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class OdbData {
 public:
  OdbData();
  virtual ~OdbData() = default;

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

  bool operator==(const OdbData& rhs) const;
  bool operator!=(const OdbData& rhs) const;

  /////////////////////////////////////////////
  /// OdbData members

  /// <summary>
  ///
  /// </summary>
  ngkore::model::common::RoamingOdb getRoamingOdb() const;
  void setRoamingOdb(ngkore::model::common::RoamingOdb const& value);
  bool roamingOdbIsSet() const;
  void unsetRoamingOdb();

  friend void to_json(nlohmann::json& j, const OdbData& o);
  friend void from_json(const nlohmann::json& j, OdbData& o);

 protected:
  ngkore::model::common::RoamingOdb m_RoamingOdb;
  bool m_RoamingOdbIsSet;
};

}  // namespace ngkore::model::common

