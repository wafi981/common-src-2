
#ifndef SubscribedDefaultQos_H_
#define SubscribedDefaultQos_H_

#include "Arp.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class SubscribedDefaultQos {
 public:
  SubscribedDefaultQos();
  virtual ~SubscribedDefaultQos() = default;

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

  bool operator==(const SubscribedDefaultQos& rhs) const;
  bool operator!=(const SubscribedDefaultQos& rhs) const;

  /////////////////////////////////////////////
  /// SubscribedDefaultQos members

  /// <summary>
  ///
  /// </summary>
  int32_t getR5qi() const;
  void setR5qi(int32_t const value);
  /// <summary>
  ///
  /// </summary>
  ngkore::model::common::Arp getArp() const;
  void setArp(ngkore::model::common::Arp const& value);
  /// <summary>
  ///
  /// </summary>
  int32_t getPriorityLevel() const;
  void setPriorityLevel(int32_t const value);
  bool priorityLevelIsSet() const;
  void unsetPriorityLevel();

  friend void to_json(nlohmann::json& j, const SubscribedDefaultQos& o);
  friend void from_json(const nlohmann::json& j, SubscribedDefaultQos& o);

 protected:
  int32_t m_r_5qi;

  ngkore::model::common::Arp m_Arp;

  int32_t m_PriorityLevel;
  bool m_PriorityLevelIsSet;
};

}  // namespace ngkore::model::common

