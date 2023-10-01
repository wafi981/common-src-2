
#ifndef ChangeItem_H_
#define ChangeItem_H_

#include <nlohmann/json.hpp>
#include "ChangeType.h"
#include <string>
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class ChangeItem {
 public:
  ChangeItem();
  virtual ~ChangeItem() = default;

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

  bool operator==(const ChangeItem& rhs) const;
  bool operator!=(const ChangeItem& rhs) const;

  /////////////////////////////////////////////
  /// ChangeItem members

  /// <summary>
  ///
  /// </summary>
  ngkore::model::common::ChangeType getOp() const;
  void setOp(ngkore::model::common::ChangeType const& value);
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
  nlohmann::json getOrigValue() const;
  void setOrigValue(nlohmann::json const& value);
  bool origValueIsSet() const;
  void unsetOrigValue();
  /// <summary>
  ///
  /// </summary>
  nlohmann::json getNewValue() const;
  void setNewValue(nlohmann::json const& value);
  bool newValueIsSet() const;
  void unsetNewValue();

  friend void to_json(nlohmann::json& j, const ChangeItem& o);
  friend void from_json(const nlohmann::json& j, ChangeItem& o);

 protected:
  ngkore::model::common::ChangeType m_Op;

  std::string m_Path;

  std::string m_From;
  bool m_FromIsSet;
  nlohmann::json m_OrigValue;
  bool m_OrigValueIsSet;
  nlohmann::json m_NewValue;
  bool m_NewValueIsSet;
};

}  // namespace ngkore::model::common

