
#ifndef EcgiRm_H_
#define EcgiRm_H_

#include "Ecgi.h"
#include <string>
#include "PlmnId.h"
#include "NullValue.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class EcgiRm {
 public:
  EcgiRm();
  virtual ~EcgiRm() = default;

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

  bool operator==(const EcgiRm& rhs) const;
  bool operator!=(const EcgiRm& rhs) const;

  /////////////////////////////////////////////
  /// EcgiRm members

  /// <summary>
  ///
  /// </summary>
  ngkore::model::common::PlmnId getPlmnId() const;
  void setPlmnId(ngkore::model::common::PlmnId const& value);
  /// <summary>
  ///
  /// </summary>
  std::string getEutraCellId() const;
  void setEutraCellId(std::string const& value);
  /// <summary>
  ///
  /// </summary>
  std::string getNid() const;
  void setNid(std::string const& value);
  bool nidIsSet() const;
  void unsetNid();

  friend void to_json(nlohmann::json& j, const EcgiRm& o);
  friend void from_json(const nlohmann::json& j, EcgiRm& o);

 protected:
  ngkore::model::common::PlmnId m_PlmnId;

  std::string m_EutraCellId;

  std::string m_Nid;
  bool m_NidIsSet;
};

}  // namespace ngkore::model::common

