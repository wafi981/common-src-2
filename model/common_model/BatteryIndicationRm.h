
#ifndef BatteryIndicationRm_H_
#define BatteryIndicationRm_H_

#include "BatteryIndication.h"
#include "NullValue.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class BatteryIndicationRm {
 public:
  BatteryIndicationRm();
  virtual ~BatteryIndicationRm() = default;

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

  bool operator==(const BatteryIndicationRm& rhs) const;
  bool operator!=(const BatteryIndicationRm& rhs) const;

  /////////////////////////////////////////////
  /// BatteryIndicationRm members

  /// <summary>
  ///
  /// </summary>
  bool isBatteryInd() const;
  void setBatteryInd(bool const value);
  bool batteryIndIsSet() const;
  void unsetBatteryInd();
  /// <summary>
  ///
  /// </summary>
  bool isReplaceableInd() const;
  void setReplaceableInd(bool const value);
  bool replaceableIndIsSet() const;
  void unsetReplaceableInd();
  /// <summary>
  ///
  /// </summary>
  bool isRechargeableInd() const;
  void setRechargeableInd(bool const value);
  bool rechargeableIndIsSet() const;
  void unsetRechargeableInd();

  friend void to_json(nlohmann::json& j, const BatteryIndicationRm& o);
  friend void from_json(const nlohmann::json& j, BatteryIndicationRm& o);

 protected:
  bool m_BatteryInd;
  bool m_BatteryIndIsSet;
  bool m_ReplaceableInd;
  bool m_ReplaceableIndIsSet;
  bool m_RechargeableInd;
  bool m_RechargeableIndIsSet;
};

}  // namespace ngkore::model::common

