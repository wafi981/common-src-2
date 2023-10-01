
#ifndef SnssaiUpfInfoItem_H_
#define SnssaiUpfInfoItem_H_

#include "DnnUpfInfoItem.h"
#include "Snssai.h"
#include <vector>
#include <nlohmann/json.hpp>

namespace ngkore::model::nrf {

/// <summary>
/// Set of parameters supported by UPF for a given S-NSSAI
/// </summary>
class SnssaiUpfInfoItem {
 public:
  SnssaiUpfInfoItem();
  virtual ~SnssaiUpfInfoItem() = default;

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

  bool operator==(const SnssaiUpfInfoItem& rhs) const;
  bool operator!=(const SnssaiUpfInfoItem& rhs) const;

  /////////////////////////////////////////////
  /// SnssaiUpfInfoItem members

  /// <summary>
  ///
  /// </summary>
  ngkore::model::common::Snssai getSNssai() const;
  void setSNssai(ngkore::model::common::Snssai const& value);
  /// <summary>
  ///
  /// </summary>
  std::vector<ngkore::model::nrf::DnnUpfInfoItem> getDnnUpfInfoList() const;
  void setDnnUpfInfoList(
      std::vector<ngkore::model::nrf::DnnUpfInfoItem> const& value);
  /// <summary>
  ///
  /// </summary>
  bool isRedundantTransport() const;
  void setRedundantTransport(bool const value);
  bool redundantTransportIsSet() const;
  void unsetRedundantTransport();

  friend void to_json(nlohmann::json& j, const SnssaiUpfInfoItem& o);
  friend void from_json(const nlohmann::json& j, SnssaiUpfInfoItem& o);

  [[nodiscard]] std::string to_string(int indent_level) const;

 protected:
  ngkore::model::common::Snssai m_SNssai;

  std::vector<ngkore::model::nrf::DnnUpfInfoItem> m_DnnUpfInfoList;

  bool m_RedundantTransport;
  bool m_RedundantTransportIsSet;
};

}  // namespace ngkore::model::nrf

