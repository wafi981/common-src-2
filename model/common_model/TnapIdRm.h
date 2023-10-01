
#ifndef TnapIdRm_H_
#define TnapIdRm_H_

#include <string>
#include "TnapId.h"
#include "NullValue.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class TnapIdRm {
 public:
  TnapIdRm();
  virtual ~TnapIdRm() = default;

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

  bool operator==(const TnapIdRm& rhs) const;
  bool operator!=(const TnapIdRm& rhs) const;

  /////////////////////////////////////////////
  /// TnapIdRm members

  /// <summary>
  ///
  /// </summary>
  std::string getSsId() const;
  void setSsId(std::string const& value);
  bool ssIdIsSet() const;
  void unsetSsId();
  /// <summary>
  ///
  /// </summary>
  std::string getBssId() const;
  void setBssId(std::string const& value);
  bool bssIdIsSet() const;
  void unsetBssId();
  /// <summary>
  ///
  /// </summary>
  std::string getCivicAddress() const;
  void setCivicAddress(std::string const& value);
  bool civicAddressIsSet() const;
  void unsetCivicAddress();

  friend void to_json(nlohmann::json& j, const TnapIdRm& o);
  friend void from_json(const nlohmann::json& j, TnapIdRm& o);

 protected:
  std::string m_SsId;
  bool m_SsIdIsSet;
  std::string m_BssId;
  bool m_BssIdIsSet;
  std::string m_CivicAddress;
  bool m_CivicAddressIsSet;
};

}  // namespace ngkore::model::common

