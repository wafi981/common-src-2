
#ifndef NssaaStatusRm_H_
#define NssaaStatusRm_H_

#include "AuthStatus.h"
#include "NssaaStatus.h"
#include "NullValue.h"
#include "Snssai.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class NssaaStatusRm {
 public:
  NssaaStatusRm();
  virtual ~NssaaStatusRm() = default;

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

  bool operator==(const NssaaStatusRm& rhs) const;
  bool operator!=(const NssaaStatusRm& rhs) const;

  /////////////////////////////////////////////
  /// NssaaStatusRm members

  /// <summary>
  ///
  /// </summary>
  ngkore::model::common::Snssai getSnssai() const;
  void setSnssai(ngkore::model::common::Snssai const& value);
  /// <summary>
  ///
  /// </summary>
  ngkore::model::common::AuthStatus getStatus() const;
  void setStatus(ngkore::model::common::AuthStatus const& value);

  friend void to_json(nlohmann::json& j, const NssaaStatusRm& o);
  friend void from_json(const nlohmann::json& j, NssaaStatusRm& o);

 protected:
  ngkore::model::common::Snssai m_Snssai;

  ngkore::model::common::AuthStatus m_Status;
};

}  // namespace ngkore::model::common

