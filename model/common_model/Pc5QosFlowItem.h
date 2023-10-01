
#ifndef Pc5QosFlowItem_H_
#define Pc5QosFlowItem_H_

#include "Pc5FlowBitRates.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class Pc5QosFlowItem {
 public:
  Pc5QosFlowItem();
  virtual ~Pc5QosFlowItem() = default;

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

  bool operator==(const Pc5QosFlowItem& rhs) const;
  bool operator!=(const Pc5QosFlowItem& rhs) const;

  /////////////////////////////////////////////
  /// Pc5QosFlowItem members

  /// <summary>
  ///
  /// </summary>
  int32_t getPqi() const;
  void setPqi(int32_t const value);
  /// <summary>
  ///
  /// </summary>
  ngkore::model::common::Pc5FlowBitRates getPc5FlowBitRates() const;
  void setPc5FlowBitRates(ngkore::model::common::Pc5FlowBitRates const& value);
  bool pc5FlowBitRatesIsSet() const;
  void unsetPc5FlowBitRates();
  /// <summary>
  ///
  /// </summary>
  int32_t getRange() const;
  void setRange(int32_t const value);
  bool rangeIsSet() const;
  void unsetRange();

  friend void to_json(nlohmann::json& j, const Pc5QosFlowItem& o);
  friend void from_json(const nlohmann::json& j, Pc5QosFlowItem& o);

 protected:
  int32_t m_Pqi;

  ngkore::model::common::Pc5FlowBitRates m_Pc5FlowBitRates;
  bool m_Pc5FlowBitRatesIsSet;
  int32_t m_Range;
  bool m_RangeIsSet;
};

}  // namespace ngkore::model::common

