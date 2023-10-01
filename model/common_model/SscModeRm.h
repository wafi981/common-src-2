
#ifndef SscModeRm_H_
#define SscModeRm_H_

#include "NullValue.h"
#include "SscMode.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class SscModeRm {
 public:
  SscModeRm();
  virtual ~SscModeRm() = default;

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

  bool operator==(const SscModeRm& rhs) const;
  bool operator!=(const SscModeRm& rhs) const;

  /////////////////////////////////////////////
  /// SscModeRm members

  friend void to_json(nlohmann::json& j, const SscModeRm& o);
  friend void from_json(const nlohmann::json& j, SscModeRm& o);

 protected:
};

}  // namespace ngkore::model::common

