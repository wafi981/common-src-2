
#ifndef Arp_H_
#define Arp_H_

#include "PreemptionCapability.h"
#include "PreemptionVulnerability.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class Arp {
 public:
  Arp();
  virtual ~Arp() = default;

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

  bool operator==(const Arp& rhs) const;
  bool operator!=(const Arp& rhs) const;

  /////////////////////////////////////////////
  /// Arp members

  /// <summary>
  /// nullable true shall not be used for this attribute
  /// </summary>
  int32_t getPriorityLevel() const;
  void setPriorityLevel(int32_t const value);
  /// <summary>
  ///
  /// </summary>
  ngkore::model::common::PreemptionCapability getPreemptCap() const;
  void setPreemptCap(ngkore::model::common::PreemptionCapability const& value);
  /// <summary>
  ///
  /// </summary>
  ngkore::model::common::PreemptionVulnerability getPreemptVuln() const;
  void setPreemptVuln(ngkore::model::common::PreemptionVulnerability const& value);

  friend void to_json(nlohmann::json& j, const Arp& o);
  friend void from_json(const nlohmann::json& j, Arp& o);

 protected:
  int32_t m_PriorityLevel;

  ngkore::model::common::PreemptionCapability m_PreemptCap;

  ngkore::model::common::PreemptionVulnerability m_PreemptVuln;
};

}  // namespace ngkore::model::common

