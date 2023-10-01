
#ifndef RefToBinaryDataRm_H_
#define RefToBinaryDataRm_H_

#include "RefToBinaryData.h"
#include <string>
#include "NullValue.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class RefToBinaryDataRm {
 public:
  RefToBinaryDataRm();
  virtual ~RefToBinaryDataRm() = default;

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

  bool operator==(const RefToBinaryDataRm& rhs) const;
  bool operator!=(const RefToBinaryDataRm& rhs) const;

  /////////////////////////////////////////////
  /// RefToBinaryDataRm members

  /// <summary>
  ///
  /// </summary>
  std::string getContentId() const;
  void setContentId(std::string const& value);

  friend void to_json(nlohmann::json& j, const RefToBinaryDataRm& o);
  friend void from_json(const nlohmann::json& j, RefToBinaryDataRm& o);

 protected:
  std::string m_ContentId;
};

}  // namespace ngkore::model::common

