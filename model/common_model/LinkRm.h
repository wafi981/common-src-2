
#ifndef LinkRm_H_
#define LinkRm_H_

#include <string>
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class LinkRm {
 public:
  LinkRm();
  virtual ~LinkRm() = default;

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

  bool operator==(const LinkRm& rhs) const;
  bool operator!=(const LinkRm& rhs) const;

  /////////////////////////////////////////////
  /// LinkRm members

  /// <summary>
  ///
  /// </summary>
  std::string getHref() const;
  void setHref(std::string const& value);
  bool hrefIsSet() const;
  void unsetHref();

  friend void to_json(nlohmann::json& j, const LinkRm& o);
  friend void from_json(const nlohmann::json& j, LinkRm& o);

 protected:
  std::string m_Href;
  bool m_HrefIsSet;
};

}  // namespace ngkore::model::common

