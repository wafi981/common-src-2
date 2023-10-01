
#ifndef ServiceAreaRestriction_H_
#define ServiceAreaRestriction_H_

#include "RestrictionType.h"
#include "Area.h"
#include <vector>
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class ServiceAreaRestriction {
 public:
  ServiceAreaRestriction();
  virtual ~ServiceAreaRestriction() = default;

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

  bool operator==(const ServiceAreaRestriction& rhs) const;
  bool operator!=(const ServiceAreaRestriction& rhs) const;

  /////////////////////////////////////////////
  /// ServiceAreaRestriction members

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
  std::vector<ngkore::model::common::Area> getAreas() const;
  void setAreas(std::vector<ngkore::model::common::Area> const& value);
  bool areasIsSet() const;
  void unsetAreas();
  /// <summary>
  ///
  /// </summary>
  int32_t getMaxNumOfTAs() const;
  void setMaxNumOfTAs(int32_t const value);
  bool maxNumOfTAsIsSet() const;
  void unsetMaxNumOfTAs();
  /// <summary>
  ///
  /// </summary>
  int32_t getMaxNumOfTAsForNotAllowedAreas() const;
  void setMaxNumOfTAsForNotAllowedAreas(int32_t const value);
  bool maxNumOfTAsForNotAllowedAreasIsSet() const;
  void unsetMaxNumOfTAsForNotAllowedAreas();

  friend void to_json(nlohmann::json& j, const ServiceAreaRestriction& o);
  friend void from_json(const nlohmann::json& j, ServiceAreaRestriction& o);

 protected:
  ngkore::model::common::RestrictionType m_RestrictionType;
  bool m_RestrictionTypeIsSet;
  std::vector<ngkore::model::common::Area> m_Areas;
  bool m_AreasIsSet;
  int32_t m_MaxNumOfTAs;
  bool m_MaxNumOfTAsIsSet;
  int32_t m_MaxNumOfTAsForNotAllowedAreas;
  bool m_MaxNumOfTAsForNotAllowedAreasIsSet;
};

}  // namespace ngkore::model::common

