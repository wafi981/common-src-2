
#ifndef AccessTypeRm_H_
#define AccessTypeRm_H_

#include "NullValue.h"
#include "AccessType.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///  The same as access type, but it is nullable
/// </summary>
class AccessTypeRm : public AccessType {
 public:
  AccessTypeRm();
  virtual ~AccessTypeRm() = default;

  bool validate(
      std::stringstream& msg, const std::string& pathPrefix) const override;

  friend void to_json(nlohmann::json& j, const AccessTypeRm& o);
  friend void from_json(const nlohmann::json& j, AccessTypeRm& o);

 protected:
};

}  // namespace ngkore::model::common

