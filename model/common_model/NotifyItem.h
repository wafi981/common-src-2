
#ifndef NotifyItem_H_
#define NotifyItem_H_

#include "ChangeItem.h"
#include <string>
#include <vector>
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class NotifyItem {
 public:
  NotifyItem();
  virtual ~NotifyItem() = default;

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

  bool operator==(const NotifyItem& rhs) const;
  bool operator!=(const NotifyItem& rhs) const;

  /////////////////////////////////////////////
  /// NotifyItem members

  /// <summary>
  ///
  /// </summary>
  std::string getResourceId() const;
  void setResourceId(std::string const& value);
  /// <summary>
  ///
  /// </summary>
  std::vector<ngkore::model::common::ChangeItem> getChanges() const;
  void setChanges(std::vector<ngkore::model::common::ChangeItem> const& value);

  friend void to_json(nlohmann::json& j, const NotifyItem& o);
  friend void from_json(const nlohmann::json& j, NotifyItem& o);

 protected:
  std::string m_ResourceId;

  std::vector<ngkore::model::common::ChangeItem> m_Changes;
};

}  // namespace ngkore::model::common

