
#ifndef RatTypeRm_H_
#define RatTypeRm_H_

#include "RatType.h"
#include "NullValue.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class RatTypeRm {
 public:
  RatTypeRm();
  virtual ~RatTypeRm() = default;

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

  bool operator==(const RatTypeRm& rhs) const;
  bool operator!=(const RatTypeRm& rhs) const;

  /////////////////////////////////////////////
  /// RatTypeRm members

  friend void to_json(nlohmann::json& j, const RatTypeRm& o);
  friend void from_json(const nlohmann::json& j, RatTypeRm& o);

 protected:
};

}  // namespace ngkore::model::common

