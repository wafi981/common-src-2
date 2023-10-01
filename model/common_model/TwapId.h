
#ifndef TwapId_H_
#define TwapId_H_

#include <string>
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class TwapId {
 public:
  TwapId();
  virtual ~TwapId() = default;

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

  bool operator==(const TwapId& rhs) const;
  bool operator!=(const TwapId& rhs) const;

  /////////////////////////////////////////////
  /// TwapId members

  /// <summary>
  ///
  /// </summary>
  std::string getSsId() const;
  void setSsId(std::string const& value);
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

  friend void to_json(nlohmann::json& j, const TwapId& o);
  friend void from_json(const nlohmann::json& j, TwapId& o);

 protected:
  std::string m_SsId;

  std::string m_BssId;
  bool m_BssIdIsSet;
  std::string m_CivicAddress;
  bool m_CivicAddressIsSet;
};

}  // namespace ngkore::model::common

