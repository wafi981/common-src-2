
#ifndef PatchItem_H_
#define PatchItem_H_

#include <nlohmann/json.hpp>
#include <string>
#include "PatchOperation.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class PatchItem {
 public:
  PatchItem();
  virtual ~PatchItem() = default;

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

  bool operator==(const PatchItem& rhs) const;
  bool operator!=(const PatchItem& rhs) const;

  /////////////////////////////////////////////
  /// PatchItem members

  /// <summary>
  ///
  /// </summary>
  ngkore::model::common::PatchOperation getOp() const;
  void setOp(ngkore::model::common::PatchOperation const& value);
  /// <summary>
  ///
  /// </summary>
  std::string getPath() const;
  void setPath(std::string const& value);
  /// <summary>
  ///
  /// </summary>
  std::string getFrom() const;
  void setFrom(std::string const& value);
  bool fromIsSet() const;
  void unsetFrom();
  /// <summary>
  ///
  /// </summary>
  nlohmann::json getValue() const;
  void setValue(nlohmann::json const& value);
  bool valueIsSet() const;
  void unsetValue();

  friend void to_json(nlohmann::json& j, const PatchItem& o);
  friend void from_json(const nlohmann::json& j, PatchItem& o);

 protected:
  ngkore::model::common::PatchOperation m_Op;

  std::string m_Path;

  std::string m_From;
  bool m_FromIsSet;
  nlohmann::json m_Value;
  bool m_ValueIsSet;
};

}  // namespace ngkore::model::common

