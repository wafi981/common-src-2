
#ifndef WirelineServiceAreaRestriction_H_
#define WirelineServiceAreaRestriction_H_

#include "RestrictionType.h"
#include "WirelineArea.h"
#include <vector>
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class WirelineServiceAreaRestriction {
 public:
  WirelineServiceAreaRestriction();
  virtual ~WirelineServiceAreaRestriction() = default;

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

  bool operator==(const WirelineServiceAreaRestriction& rhs) const;
  bool operator!=(const WirelineServiceAreaRestriction& rhs) const;

  /////////////////////////////////////////////
  /// WirelineServiceAreaRestriction members

  /// <summary>
  ///
  /// </summary>
  ngkore::model::common::RestrictionType getRestrictionType() const;
  void setRestrictionType(ngkore::model::common::RestrictionType const& value);
  bool restrictionTypeIsSet() const;
  void unsetRestrictionType();
  /// <summary>
  ///
  /// </summary>
  std::vector<ngkore::model::common::WirelineArea> getAreas() const;
  void setAreas(std::vector<ngkore::model::common::WirelineArea> const& value);
  bool areasIsSet() const;
  void unsetAreas();

  friend void to_json(
      nlohmann::json& j, const WirelineServiceAreaRestriction& o);
  friend void from_json(
      const nlohmann::json& j, WirelineServiceAreaRestriction& o);

 protected:
  ngkore::model::common::RestrictionType m_RestrictionType;
  bool m_RestrictionTypeIsSet;
  std::vector<ngkore::model::common::WirelineArea> m_Areas;
  bool m_AreasIsSet;
};

}  // namespace ngkore::model::common

