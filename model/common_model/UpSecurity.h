
#ifndef UpSecurity_H_
#define UpSecurity_H_

#include "UpConfidentiality.h"
#include "UpIntegrity.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class UpSecurity {
 public:
  UpSecurity();
  virtual ~UpSecurity() = default;

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

  bool operator==(const UpSecurity& rhs) const;
  bool operator!=(const UpSecurity& rhs) const;

  /////////////////////////////////////////////
  /// UpSecurity members

  /// <summary>
  ///
  /// </summary>
  ngkore::model::common::UpIntegrity getUpIntegr() const;
  void setUpIntegr(ngkore::model::common::UpIntegrity const& value);
  /// <summary>
  ///
  /// </summary>
  ngkore::model::common::UpConfidentiality getUpConfid() const;
  void setUpConfid(ngkore::model::common::UpConfidentiality const& value);

  friend void to_json(nlohmann::json& j, const UpSecurity& o);
  friend void from_json(const nlohmann::json& j, UpSecurity& o);

 protected:
  ngkore::model::common::UpIntegrity m_UpIntegr;

  ngkore::model::common::UpConfidentiality m_UpConfid;
};

}  // namespace ngkore::model::common

