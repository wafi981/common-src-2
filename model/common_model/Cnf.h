
#ifndef Cnf_H_
#define Cnf_H_

#include "CnfUnit.h"
#include <vector>
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class Cnf {
 public:
  Cnf();
  virtual ~Cnf() = default;

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

  bool operator==(const Cnf& rhs) const;
  bool operator!=(const Cnf& rhs) const;

  /////////////////////////////////////////////
  /// Cnf members

  /// <summary>
  ///
  /// </summary>
  std::vector<ngkore::model::common::CnfUnit> getCnfUnits() const;
  void setCnfUnits(std::vector<ngkore::model::common::CnfUnit> const& value);

  friend void to_json(nlohmann::json& j, const Cnf& o);
  friend void from_json(const nlohmann::json& j, Cnf& o);

 protected:
  std::vector<ngkore::model::common::CnfUnit> m_CnfUnits;
};

}  // namespace ngkore::model::common

