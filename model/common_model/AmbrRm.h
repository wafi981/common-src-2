
#ifndef AmbrRm_H_
#define AmbrRm_H_

#include "Ambr.h"
#include <string>
#include "NullValue.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class AmbrRm {
 public:
  AmbrRm();
  virtual ~AmbrRm() = default;

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

  bool operator==(const AmbrRm& rhs) const;
  bool operator!=(const AmbrRm& rhs) const;

  /////////////////////////////////////////////
  /// AmbrRm members

  /// <summary>
  ///
  /// </summary>
  std::string getUplink() const;
  void setUplink(std::string const& value);
  /// <summary>
  ///
  /// </summary>
  std::string getDownlink() const;
  void setDownlink(std::string const& value);

  friend void to_json(nlohmann::json& j, const AmbrRm& o);
  friend void from_json(const nlohmann::json& j, AmbrRm& o);

 protected:
  std::string m_Uplink;

  std::string m_Downlink;
};

}  // namespace ngkore::model::common

