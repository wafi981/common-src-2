
#ifndef SelfLink_H_
#define SelfLink_H_

#include "Link.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class SelfLink {
 public:
  SelfLink();
  virtual ~SelfLink() = default;

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

  bool operator==(const SelfLink& rhs) const;
  bool operator!=(const SelfLink& rhs) const;

  /////////////////////////////////////////////
  /// SelfLink members

  /// <summary>
  ///
  /// </summary>
  ngkore::model::common::Link getSelf() const;
  void setSelf(ngkore::model::common::Link const& value);

  friend void to_json(nlohmann::json& j, const SelfLink& o);
  friend void from_json(const nlohmann::json& j, SelfLink& o);

 protected:
  ngkore::model::common::Link m_Self;
};

}  // namespace ngkore::model::common

