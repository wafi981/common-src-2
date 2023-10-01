
#ifndef CoreNetworkTypeRm_H_
#define CoreNetworkTypeRm_H_

#include "CoreNetworkType.h"
#include "NullValue.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class CoreNetworkTypeRm : public CoreNetworkType {
 public:
  CoreNetworkTypeRm();
  virtual ~CoreNetworkTypeRm() = default;

  bool validate(
      std::stringstream& msg, const std::string& pathPrefix) const override;

  friend void to_json(nlohmann::json& j, const CoreNetworkTypeRm& o);
  friend void from_json(const nlohmann::json& j, CoreNetworkTypeRm& o);

 protected:
};

}  // namespace ngkore::model::common

