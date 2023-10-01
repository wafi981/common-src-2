
#ifndef HfcNodeIdRm_H_
#define HfcNodeIdRm_H_

#include <string>
#include "NullValue.h"
#include "HfcNodeId.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class HfcNodeIdRm {
 public:
  HfcNodeIdRm();
  virtual ~HfcNodeIdRm() = default;

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

  bool operator==(const HfcNodeIdRm& rhs) const;
  bool operator!=(const HfcNodeIdRm& rhs) const;

  /////////////////////////////////////////////
  /// HfcNodeIdRm members

  /// <summary>
  ///
  /// </summary>
  std::string getHfcNId() const;
  void setHfcNId(std::string const& value);

  friend void to_json(nlohmann::json& j, const HfcNodeIdRm& o);
  friend void from_json(const nlohmann::json& j, HfcNodeIdRm& o);

 protected:
  std::string m_HfcNId;
};

}  // namespace ngkore::model::common

