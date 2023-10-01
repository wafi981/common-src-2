
#ifndef Ncgi_H_
#define Ncgi_H_

#include <string>
#include "PlmnId.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class Ncgi {
 public:
  Ncgi();
  virtual ~Ncgi() = default;

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

  bool operator==(const Ncgi& rhs) const;
  bool operator!=(const Ncgi& rhs) const;

  /////////////////////////////////////////////
  /// Ncgi members

  /// <summary>
  ///
  /// </summary>
  ngkore::model::common::PlmnId getPlmnId() const;
  void setPlmnId(ngkore::model::common::PlmnId const& value);
  /// <summary>
  ///
  /// </summary>
  std::string getNrCellId() const;
  void setNrCellId(std::string const& value);
  /// <summary>
  ///
  /// </summary>
  std::string getNid() const;
  void setNid(std::string const& value);
  bool nidIsSet() const;
  void unsetNid();

  friend void to_json(nlohmann::json& j, const Ncgi& o);
  friend void from_json(const nlohmann::json& j, Ncgi& o);

 protected:
  ngkore::model::common::PlmnId m_PlmnId;

  std::string m_NrCellId;

  std::string m_Nid;
  bool m_NidIsSet;
};

}  // namespace ngkore::model::common

