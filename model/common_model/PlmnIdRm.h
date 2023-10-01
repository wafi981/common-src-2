
#ifndef PlmnIdRm_H_
#define PlmnIdRm_H_

#include <string>
#include "PlmnId.h"
#include "NullValue.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class PlmnIdRm {
 public:
  PlmnIdRm();
  virtual ~PlmnIdRm() = default;

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

  bool operator==(const PlmnIdRm& rhs) const;
  bool operator!=(const PlmnIdRm& rhs) const;

  /////////////////////////////////////////////
  /// PlmnIdRm members

  /// <summary>
  ///
  /// </summary>
  std::string getMcc() const;
  void setMcc(std::string const& value);
  /// <summary>
  ///
  /// </summary>
  std::string getMnc() const;
  void setMnc(std::string const& value);

  friend void to_json(nlohmann::json& j, const PlmnIdRm& o);
  friend void from_json(const nlohmann::json& j, PlmnIdRm& o);

 protected:
  std::string m_Mcc;

  std::string m_Mnc;
};

}  // namespace ngkore::model::common

