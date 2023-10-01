
#ifndef UpIntegrityRm_H_
#define UpIntegrityRm_H_

#include "NullValue.h"
#include "UpIntegrity.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class UpIntegrityRm {
 public:
  UpIntegrityRm();
  virtual ~UpIntegrityRm() = default;

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

  bool operator==(const UpIntegrityRm& rhs) const;
  bool operator!=(const UpIntegrityRm& rhs) const;

  /////////////////////////////////////////////
  /// UpIntegrityRm members

  friend void to_json(nlohmann::json& j, const UpIntegrityRm& o);
  friend void from_json(const nlohmann::json& j, UpIntegrityRm& o);

 protected:
};

}  // namespace ngkore::model::common

