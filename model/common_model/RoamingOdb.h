
#ifndef RoamingOdb_H_
#define RoamingOdb_H_

#include "RoamingOdb_anyOf.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class RoamingOdb {
 public:
  RoamingOdb();
  virtual ~RoamingOdb() = default;

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

  bool operator==(const RoamingOdb& rhs) const;
  bool operator!=(const RoamingOdb& rhs) const;

  /////////////////////////////////////////////
  /// RoamingOdb members

  RoamingOdb_anyOf getValue() const;
  void setValue(RoamingOdb_anyOf value);
  RoamingOdb_anyOf::eRoamingOdb_anyOf getEnumValue() const;
  void setEnumValue(RoamingOdb_anyOf::eRoamingOdb_anyOf value);
  friend void to_json(nlohmann::json& j, const RoamingOdb& o);
  friend void from_json(const nlohmann::json& j, RoamingOdb& o);
  friend void to_json(nlohmann::json& j, const RoamingOdb_anyOf& o);
  friend void from_json(const nlohmann::json& j, RoamingOdb_anyOf& o);

 protected:
  RoamingOdb_anyOf m_value;
};

}  // namespace ngkore::model::common

