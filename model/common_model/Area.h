
#ifndef Area_H_
#define Area_H_

#include <string>
#include <vector>
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class Area {
 public:
  Area();
  virtual ~Area() = default;

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

  bool operator==(const Area& rhs) const;
  bool operator!=(const Area& rhs) const;

  /////////////////////////////////////////////
  /// Area members

  /// <summary>
  ///
  /// </summary>
  std::vector<std::string> getTacs() const;
  void setTacs(std::vector<std::string> const& value);
  bool tacsIsSet() const;
  void unsetTacs();
  /// <summary>
  ///
  /// </summary>
  std::string getAreaCode() const;
  void setAreaCode(std::string const& value);
  bool areaCodeIsSet() const;
  void unsetAreaCode();

  friend void to_json(nlohmann::json& j, const Area& o);
  friend void from_json(const nlohmann::json& j, Area& o);

 protected:
  std::vector<std::string> m_Tacs;
  bool m_TacsIsSet;
  std::string m_AreaCode;
  bool m_AreaCodeIsSet;
};

}  // namespace ngkore::model::common

