
#ifndef LinksValueSchema_H_
#define LinksValueSchema_H_

#include <string>
#include "Link.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class LinksValueSchema {
 public:
  LinksValueSchema();
  virtual ~LinksValueSchema() = default;

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

  bool operator==(const LinksValueSchema& rhs) const;
  bool operator!=(const LinksValueSchema& rhs) const;

  /////////////////////////////////////////////
  /// LinksValueSchema members

  /// <summary>
  ///
  /// </summary>
  std::string getHref() const;
  void setHref(std::string const& value);
  bool hrefIsSet() const;
  void unsetHref();

  friend void to_json(nlohmann::json& j, const LinksValueSchema& o);
  friend void from_json(const nlohmann::json& j, LinksValueSchema& o);

 protected:
  std::string m_Href;
  bool m_HrefIsSet;
};

}  // namespace ngkore::model::common

