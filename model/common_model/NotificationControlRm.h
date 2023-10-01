
#ifndef NotificationControlRm_H_
#define NotificationControlRm_H_

#include "NotificationControl.h"
#include "NullValue.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class NotificationControlRm : public NotificationControl {
 public:
  NotificationControlRm();
  virtual ~NotificationControlRm() = default;

  /// <summary>
  /// Helper overload for validate. Used when one model stores another model and
  /// calls it's validate. Not meant to be called outside that case.
  /// </summary>
  bool validate(
      std::stringstream& msg, const std::string& pathPrefix) const override;

  /////////////////////////////////////////////
  /// NotificationControlRm members

  friend void to_json(nlohmann::json& j, const NotificationControlRm& o);
  friend void from_json(const nlohmann::json& j, NotificationControlRm& o);

 protected:
};

}  // namespace ngkore::model::common

