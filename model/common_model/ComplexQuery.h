
#ifndef ComplexQuery_H_
#define ComplexQuery_H_

#include "CnfUnit.h"
#include "Dnf.h"
#include <vector>
#include "Cnf.h"
#include "DnfUnit.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class ComplexQuery {
 public:
  ComplexQuery();
  virtual ~ComplexQuery() = default;

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

  bool operator==(const ComplexQuery& rhs) const;
  bool operator!=(const ComplexQuery& rhs) const;

  /////////////////////////////////////////////
  /// ComplexQuery members

  /// <summary>
  ///
  /// </summary>
  std::vector<ngkore::model::common::CnfUnit> getCnfUnits() const;
  void setCnfUnits(std::vector<ngkore::model::common::CnfUnit> const& value);
  /// <summary>
  ///
  /// </summary>
  std::vector<ngkore::model::common::DnfUnit> getDnfUnits() const;
  void setDnfUnits(std::vector<ngkore::model::common::DnfUnit> const& value);

  friend void to_json(nlohmann::json& j, const ComplexQuery& o);
  friend void from_json(const nlohmann::json& j, ComplexQuery& o);

 protected:
  std::vector<ngkore::model::common::CnfUnit> m_CnfUnits;

  std::vector<ngkore::model::common::DnfUnit> m_DnfUnits;
};

}  // namespace ngkore::model::common

