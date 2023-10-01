
#ifndef StationaryIndicationRm_H_
#define StationaryIndicationRm_H_

#include "NullValue.h"
#include "StationaryIndication.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class StationaryIndicationRm {
 public:
  StationaryIndicationRm();
  virtual ~StationaryIndicationRm() = default;

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

  bool operator==(const StationaryIndicationRm& rhs) const;
  bool operator!=(const StationaryIndicationRm& rhs) const;

  /////////////////////////////////////////////
  /// StationaryIndicationRm members

  friend void to_json(nlohmann::json& j, const StationaryIndicationRm& o);
  friend void from_json(const nlohmann::json& j, StationaryIndicationRm& o);

 protected:
};

}  // namespace ngkore::model::common
