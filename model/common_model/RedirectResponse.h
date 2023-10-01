
#ifndef RedirectResponse_H_
#define RedirectResponse_H_

#include <string>
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class RedirectResponse {
 public:
  RedirectResponse();
  virtual ~RedirectResponse() = default;

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

  bool operator==(const RedirectResponse& rhs) const;
  bool operator!=(const RedirectResponse& rhs) const;

  /////////////////////////////////////////////
  /// RedirectResponse members

  /// <summary>
  ///
  /// </summary>
  std::string getCause() const;
  void setCause(std::string const& value);
  bool causeIsSet() const;
  void unsetCause();
  /// <summary>
  ///
  /// </summary>
  std::string getTargetScp() const;
  void setTargetScp(std::string const& value);
  bool targetScpIsSet() const;
  void unsetTargetScp();
  /// <summary>
  ///
  /// </summary>
  std::string getTargetSepp() const;
  void setTargetSepp(std::string const& value);
  bool targetSeppIsSet() const;
  void unsetTargetSepp();

  friend void to_json(nlohmann::json& j, const RedirectResponse& o);
  friend void from_json(const nlohmann::json& j, RedirectResponse& o);

 protected:
  std::string m_Cause;
  bool m_CauseIsSet;
  std::string m_TargetScp;
  bool m_TargetScpIsSet;
  std::string m_TargetSepp;
  bool m_TargetSeppIsSet;
};

}  // namespace ngkore::model::common

