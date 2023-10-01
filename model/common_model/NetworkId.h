
#ifndef NetworkId_H_
#define NetworkId_H_

#include <string>
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class NetworkId {
 public:
  NetworkId();
  virtual ~NetworkId() = default;

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

  bool operator==(const NetworkId& rhs) const;
  bool operator!=(const NetworkId& rhs) const;

  /////////////////////////////////////////////
  /// NetworkId members

  /// <summary>
  ///
  /// </summary>
  std::string getMnc() const;
  void setMnc(std::string const& value);
  bool mncIsSet() const;
  void unsetMnc();
  /// <summary>
  ///
  /// </summary>
  std::string getMcc() const;
  void setMcc(std::string const& value);
  bool mccIsSet() const;
  void unsetMcc();

  friend void to_json(nlohmann::json& j, const NetworkId& o);
  friend void from_json(const nlohmann::json& j, NetworkId& o);

 protected:
  std::string m_Mnc;
  bool m_MncIsSet;
  std::string m_Mcc;
  bool m_MccIsSet;
};

}  // namespace ngkore::model::common

