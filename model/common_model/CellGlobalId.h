
#ifndef CellGlobalId_H_
#define CellGlobalId_H_

#include <string>
#include "PlmnId.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class CellGlobalId {
 public:
  CellGlobalId();
  virtual ~CellGlobalId() = default;

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

  bool operator==(const CellGlobalId& rhs) const;
  bool operator!=(const CellGlobalId& rhs) const;

  /////////////////////////////////////////////
  /// CellGlobalId members

  /// <summary>
  ///
  /// </summary>
  ngkore::model::common::PlmnId getPlmnId() const;
  void setPlmnId(ngkore::model::common::PlmnId const& value);
  /// <summary>
  ///
  /// </summary>
  std::string getLac() const;
  void setLac(std::string const& value);
  /// <summary>
  ///
  /// </summary>
  std::string getCellId() const;
  void setCellId(std::string const& value);

  friend void to_json(nlohmann::json& j, const CellGlobalId& o);
  friend void from_json(const nlohmann::json& j, CellGlobalId& o);

 protected:
  ngkore::model::common::PlmnId m_PlmnId;

  std::string m_Lac;

  std::string m_CellId;
};

}  // namespace ngkore::model::common

