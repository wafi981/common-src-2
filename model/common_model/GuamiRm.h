
#ifndef GuamiRm_H_
#define GuamiRm_H_

#include "PlmnIdNid.h"
#include <string>
#include "NullValue.h"
#include "Guami.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class GuamiRm {
 public:
  GuamiRm();
  virtual ~GuamiRm() = default;

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

  bool operator==(const GuamiRm& rhs) const;
  bool operator!=(const GuamiRm& rhs) const;

  /////////////////////////////////////////////
  /// GuamiRm members

  /// <summary>
  ///
  /// </summary>
  ngkore::model::common::PlmnIdNid getPlmnId() const;
  void setPlmnId(ngkore::model::common::PlmnIdNid const& value);
  /// <summary>
  ///
  /// </summary>
  std::string getAmfId() const;
  void setAmfId(std::string const& value);

  friend void to_json(nlohmann::json& j, const GuamiRm& o);
  friend void from_json(const nlohmann::json& j, GuamiRm& o);

 protected:
  ngkore::model::common::PlmnIdNid m_PlmnId;

  std::string m_AmfId;
};

}  // namespace ngkore::model::common

