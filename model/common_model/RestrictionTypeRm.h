
#ifndef RestrictionTypeRm_H_
#define RestrictionTypeRm_H_

#include "RestrictionType.h"
#include "NullValue.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class RestrictionTypeRm {
 public:
  RestrictionTypeRm();
  virtual ~RestrictionTypeRm() = default;

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

  bool operator==(const RestrictionTypeRm& rhs) const;
  bool operator!=(const RestrictionTypeRm& rhs) const;

  /////////////////////////////////////////////
  /// RestrictionTypeRm members

  friend void to_json(nlohmann::json& j, const RestrictionTypeRm& o);
  friend void from_json(const nlohmann::json& j, RestrictionTypeRm& o);

 protected:
};

}  // namespace ngkore::model::common

