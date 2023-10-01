
#ifndef SnssaiSmfInfoItem_H_
#define SnssaiSmfInfoItem_H_

#include "DnnSmfInfoItem.h"
#include "Snssai.h"
#include <vector>
#include <nlohmann/json.hpp>

namespace ngkore::model::nrf {

/// <summary>
/// Set of parameters supported by SMF for a given S-NSSAI
/// </summary>
class SnssaiSmfInfoItem {
 public:
  SnssaiSmfInfoItem();
  virtual ~SnssaiSmfInfoItem() = default;

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

  bool operator==(const SnssaiSmfInfoItem& rhs) const;
  bool operator!=(const SnssaiSmfInfoItem& rhs) const;

  /////////////////////////////////////////////
  /// SnssaiSmfInfoItem members

  /// <summary>
  ///
  /// </summary>
  ngkore::model::common::Snssai getSNssai() const;
  void setSNssai(ngkore::model::common::Snssai const& value);
  /// <summary>
  ///
  /// </summary>
  std::vector<ngkore::model::nrf::DnnSmfInfoItem> getDnnSmfInfoList() const;
  void setDnnSmfInfoList(
      std::vector<ngkore::model::nrf::DnnSmfInfoItem> const& value);

  friend void to_json(nlohmann::json& j, const SnssaiSmfInfoItem& o);
  friend void from_json(const nlohmann::json& j, SnssaiSmfInfoItem& o);

  [[nodiscard]] std::string to_string(int indent_level) const;

 protected:
  ngkore::model::common::Snssai m_SNssai;

  std::vector<ngkore::model::nrf::DnnSmfInfoItem> m_DnnSmfInfoList;
};

}  // namespace ngkore::model::nrf

