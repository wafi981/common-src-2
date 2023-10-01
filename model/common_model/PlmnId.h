
#ifndef PlmnId_H_
#define PlmnId_H_

#include <string>
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class PlmnId {
 public:
  PlmnId();
  virtual ~PlmnId() = default;

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

  bool operator==(const PlmnId& rhs) const;
  bool operator!=(const PlmnId& rhs) const;

  /////////////////////////////////////////////
  /// PlmnId members

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

  friend void to_json(nlohmann::json& j, const PlmnId& o);
  friend void from_json(const nlohmann::json& j, PlmnId& o);

 protected:
  std::string m_Mcc;

  std::string m_Mnc;
};

}  // namespace ngkore::model::common

