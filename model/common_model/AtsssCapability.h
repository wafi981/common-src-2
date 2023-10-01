
#ifndef AtsssCapability_H_
#define AtsssCapability_H_

#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class AtsssCapability {
 public:
  AtsssCapability();
  virtual ~AtsssCapability() = default;

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

  bool operator==(const AtsssCapability& rhs) const;
  bool operator!=(const AtsssCapability& rhs) const;

  /////////////////////////////////////////////
  /// AtsssCapability members

  /// <summary>
  ///
  /// </summary>
  bool isAtsssLL() const;
  void setAtsssLL(bool const value);
  bool atsssLLIsSet() const;
  void unsetAtsssLL();
  /// <summary>
  ///
  /// </summary>
  bool isMptcp() const;
  void setMptcp(bool const value);
  bool mptcpIsSet() const;
  void unsetMptcp();
  /// <summary>
  ///
  /// </summary>
  bool isRttWithoutPmf() const;
  void setRttWithoutPmf(bool const value);
  bool rttWithoutPmfIsSet() const;
  void unsetRttWithoutPmf();

  friend void to_json(nlohmann::json& j, const AtsssCapability& o);
  friend void from_json(const nlohmann::json& j, AtsssCapability& o);

 protected:
  bool m_AtsssLL;
  bool m_AtsssLLIsSet;
  bool m_Mptcp;
  bool m_MptcpIsSet;
  bool m_RttWithoutPmf;
  bool m_RttWithoutPmfIsSet;
};

}  // namespace ngkore::model::common

