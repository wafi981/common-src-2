
#ifndef PlmnSnssai_H_
#define PlmnSnssai_H_

#include "PlmnId.h"
#include "Snssai.h"
#include <vector>
#include <nlohmann/json.hpp>

namespace ngkore::model::nrf {

/// <summary>
///
/// </summary>
class PlmnSnssai {
 public:
  PlmnSnssai();
  virtual ~PlmnSnssai();

  void validate();

  /////////////////////////////////////////////
  /// PlmnSnssai members

  /// <summary>
  ///
  /// </summary>
  ngkore::model::common::PlmnId getPlmnId() const;
  void setPlmnId(ngkore::model::common::PlmnId const& value);
  /// <summary>
  ///
  /// </summary>
  std::vector<ngkore::model::common::Snssai>& getSNssaiList();
  void setSNssaiList(std::vector<ngkore::model::common::Snssai> const& value);

  friend void to_json(nlohmann::json& j, const PlmnSnssai& o);
  friend void from_json(const nlohmann::json& j, PlmnSnssai& o);

 protected:
  ngkore::model::common::PlmnId m_PlmnId;

  std::vector<ngkore::model::common::Snssai> m_SNssaiList;
};

}  // namespace ngkore::model::nrf

