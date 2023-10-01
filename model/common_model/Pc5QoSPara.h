
#ifndef Pc5QoSPara_H_
#define Pc5QoSPara_H_

#include <string>
#include "Pc5QosFlowItem.h"
#include <vector>
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class Pc5QoSPara {
 public:
  Pc5QoSPara();
  virtual ~Pc5QoSPara() = default;

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

  bool operator==(const Pc5QoSPara& rhs) const;
  bool operator!=(const Pc5QoSPara& rhs) const;

  /////////////////////////////////////////////
  /// Pc5QoSPara members

  /// <summary>
  ///
  /// </summary>
  std::vector<ngkore::model::common::Pc5QosFlowItem> getPc5QosFlowList() const;
  void setPc5QosFlowList(
      std::vector<ngkore::model::common::Pc5QosFlowItem> const& value);
  /// <summary>
  ///
  /// </summary>
  std::string getPc5LinkAmbr() const;
  void setPc5LinkAmbr(std::string const& value);
  bool pc5LinkAmbrIsSet() const;
  void unsetPc5LinkAmbr();

  friend void to_json(nlohmann::json& j, const Pc5QoSPara& o);
  friend void from_json(const nlohmann::json& j, Pc5QoSPara& o);

 protected:
  std::vector<ngkore::model::common::Pc5QosFlowItem> m_Pc5QosFlowList;

  std::string m_Pc5LinkAmbr;
  bool m_Pc5LinkAmbrIsSet;
};

}  // namespace ngkore::model::common

