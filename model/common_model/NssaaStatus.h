
#ifndef NssaaStatus_H_
#define NssaaStatus_H_

#include "AuthStatus.h"
#include "Snssai.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class NssaaStatus {
 public:
  NssaaStatus();
  virtual ~NssaaStatus() = default;

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

  bool operator==(const NssaaStatus& rhs) const;
  bool operator!=(const NssaaStatus& rhs) const;

  /////////////////////////////////////////////
  /// NssaaStatus members

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

  friend void to_json(nlohmann::json& j, const NssaaStatus& o);
  friend void from_json(const nlohmann::json& j, NssaaStatus& o);

 protected:
  ngkore::model::common::Snssai m_Snssai;

  ngkore::model::common::AuthStatus m_Status;
};

}  // namespace ngkore::model::common

