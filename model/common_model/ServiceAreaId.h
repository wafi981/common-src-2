
#ifndef ServiceAreaId_H_
#define ServiceAreaId_H_

#include <string>
#include "PlmnId.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class ServiceAreaId {
 public:
  ServiceAreaId();
  virtual ~ServiceAreaId() = default;

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

  bool operator==(const ServiceAreaId& rhs) const;
  bool operator!=(const ServiceAreaId& rhs) const;

  /////////////////////////////////////////////
  /// ServiceAreaId members

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
  std::string getSac() const;
  void setSac(std::string const& value);

  friend void to_json(nlohmann::json& j, const ServiceAreaId& o);
  friend void from_json(const nlohmann::json& j, ServiceAreaId& o);

 protected:
  ngkore::model::common::PlmnId m_PlmnId;

  std::string m_Lac;

  std::string m_Sac;
};

}  // namespace ngkore::model::common

