
#ifndef CnfUnit_H_
#define CnfUnit_H_

#include "Atom.h"
#include <vector>
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class CnfUnit {
 public:
  CnfUnit();
  virtual ~CnfUnit() = default;

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

  bool operator==(const CnfUnit& rhs) const;
  bool operator!=(const CnfUnit& rhs) const;

  /////////////////////////////////////////////
  /// CnfUnit members

  /// <summary>
  ///
  /// </summary>
  std::vector<ngkore::model::common::Atom> getCnfUnit() const;
  void setCnfUnit(std::vector<ngkore::model::common::Atom> const& value);

  friend void to_json(nlohmann::json& j, const CnfUnit& o);
  friend void from_json(const nlohmann::json& j, CnfUnit& o);

 protected:
  std::vector<ngkore::model::common::Atom> m_CnfUnit;
};

}  // namespace ngkore::model::common

