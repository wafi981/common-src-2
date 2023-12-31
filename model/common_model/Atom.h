
#ifndef Atom_H_
#define Atom_H_

#include <nlohmann/json.hpp>
#include <string>
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class Atom {
 public:
  Atom();
  virtual ~Atom() = default;

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

  bool operator==(const Atom& rhs) const;
  bool operator!=(const Atom& rhs) const;

  /////////////////////////////////////////////
  /// Atom members

  /// <summary>
  ///
  /// </summary>
  std::string getAttr() const;
  void setAttr(std::string const& value);
  /// <summary>
  ///
  /// </summary>
  nlohmann::json getValue() const;
  void setValue(nlohmann::json const& value);
  /// <summary>
  ///
  /// </summary>
  bool isNegative() const;
  void setNegative(bool const value);
  bool negativeIsSet() const;
  void unsetNegative();

  friend void to_json(nlohmann::json& j, const Atom& o);
  friend void from_json(const nlohmann::json& j, Atom& o);

 protected:
  std::string m_Attr;

  nlohmann::json m_Value;

  bool m_Negative;
  bool m_NegativeIsSet;
};

}  // namespace ngkore::model::common

