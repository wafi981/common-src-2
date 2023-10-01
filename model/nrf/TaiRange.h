
#ifndef TaiRange_H_
#define TaiRange_H_

#include "TacRange.h"
#include <string>
#include "PlmnId.h"
#include <vector>
#include <nlohmann/json.hpp>

namespace ngkore::model::nrf {

/// <summary>
/// Range of TAIs (Tracking Area Identities)
/// </summary>
class TaiRange {
 public:
  TaiRange();
  virtual ~TaiRange() = default;

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

  bool operator==(const TaiRange& rhs) const;
  bool operator!=(const TaiRange& rhs) const;

  /////////////////////////////////////////////
  /// TaiRange members

  /// <summary>
  ///
  /// </summary>
  ngkore::model::common::PlmnId getPlmnId() const;
  void setPlmnId(ngkore::model::common::PlmnId const& value);
  /// <summary>
  ///
  /// </summary>
  std::vector<ngkore::model::nrf::TacRange> getTacRangeList() const;
  void setTacRangeList(std::vector<ngkore::model::nrf::TacRange> const& value);
  /// <summary>
  ///
  /// </summary>
  std::string getNid() const;
  void setNid(std::string const& value);
  bool nidIsSet() const;
  void unsetNid();

  friend void to_json(nlohmann::json& j, const TaiRange& o);
  friend void from_json(const nlohmann::json& j, TaiRange& o);

 protected:
  ngkore::model::common::PlmnId m_PlmnId;

  std::vector<ngkore::model::nrf::TacRange> m_TacRangeList;

  std::string m_Nid;
  bool m_NidIsSet;
};

}  // namespace ngkore::model::nrf

