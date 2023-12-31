
#ifndef Property_H_
#define Property_H_

#include <string>
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class Property {
 public:
  Property();
  virtual ~Property() = default;

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

  bool operator==(const Property& rhs) const;
  bool operator!=(const Property& rhs) const;

  /////////////////////////////////////////////
  /// Property members

  /// <summary>
  ///
  /// </summary>
  std::string getName() const;
  void setName(std::string const& value);
  /// <summary>
  ///
  /// </summary>
  bool isRequired() const;
  void setRequired(bool const value);
  bool requiredIsSet() const;
  void unsetRequired();
  /// <summary>
  ///
  /// </summary>
  std::string getRegex() const;
  void setRegex(std::string const& value);
  bool regexIsSet() const;
  void unsetRegex();
  /// <summary>
  ///
  /// </summary>
  std::string getValue() const;
  void setValue(std::string const& value);
  bool valueIsSet() const;
  void unsetValue();

  friend void to_json(nlohmann::json& j, const Property& o);
  friend void from_json(const nlohmann::json& j, Property& o);

 protected:
  std::string m_Name;

  bool m_Required;
  bool m_RequiredIsSet;
  std::string m_Regex;
  bool m_RegexIsSet;
  std::string m_Value;
  bool m_ValueIsSet;
};

}  // namespace ngkore::model::common

