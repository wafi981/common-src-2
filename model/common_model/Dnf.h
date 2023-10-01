
#ifndef Dnf_H_
#define Dnf_H_

#include <vector>
#include "DnfUnit.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class Dnf {
 public:
  Dnf();
  virtual ~Dnf() = default;

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

  bool operator==(const Dnf& rhs) const;
  bool operator!=(const Dnf& rhs) const;

  /////////////////////////////////////////////
  /// Dnf members

  /// <summary>
  ///
  /// </summary>
  std::vector<ngkore::model::common::DnfUnit> getDnfUnits() const;
  void setDnfUnits(std::vector<ngkore::model::common::DnfUnit> const& value);

  friend void to_json(nlohmann::json& j, const Dnf& o);
  friend void from_json(const nlohmann::json& j, Dnf& o);

 protected:
  std::vector<ngkore::model::common::DnfUnit> m_DnfUnits;
};

}  // namespace ngkore::model::common

