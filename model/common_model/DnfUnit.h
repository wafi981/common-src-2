
#ifndef DnfUnit_H_
#define DnfUnit_H_

#include "Atom.h"
#include <vector>
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class DnfUnit {
 public:
  DnfUnit();
  virtual ~DnfUnit() = default;

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

  bool operator==(const DnfUnit& rhs) const;
  bool operator!=(const DnfUnit& rhs) const;

  /////////////////////////////////////////////
  /// DnfUnit members

  /// <summary>
  ///
  /// </summary>
  std::vector<ngkore::model::common::Atom> getDnfUnit() const;
  void setDnfUnit(std::vector<ngkore::model::common::Atom> const& value);

  friend void to_json(nlohmann::json& j, const DnfUnit& o);
  friend void from_json(const nlohmann::json& j, DnfUnit& o);

 protected:
  std::vector<ngkore::model::common::Atom> m_DnfUnit;
};

}  // namespace ngkore::model::common

