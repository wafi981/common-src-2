
#ifndef PlmnIdNid_H_
#define PlmnIdNid_H_

#include <string>
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class PlmnIdNid {
 public:
  PlmnIdNid();
  virtual ~PlmnIdNid() = default;

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

  bool operator==(const PlmnIdNid& rhs) const;
  bool operator!=(const PlmnIdNid& rhs) const;

  /////////////////////////////////////////////
  /// PlmnIdNid members

  /// <summary>
  ///
  /// </summary>
  std::string getMcc() const;
  void setMcc(std::string const& value);
  /// <summary>
  ///
  /// </summary>
  std::string getMnc() const;
  void setMnc(std::string const& value);
  /// <summary>
  ///
  /// </summary>
  std::string getNid() const;
  void setNid(std::string const& value);
  bool nidIsSet() const;
  void unsetNid();

  friend void to_json(nlohmann::json& j, const PlmnIdNid& o);
  friend void from_json(const nlohmann::json& j, PlmnIdNid& o);

 protected:
  std::string m_Mcc;

  std::string m_Mnc;

  std::string m_Nid;
  bool m_NidIsSet;
};

}  // namespace ngkore::model::common

