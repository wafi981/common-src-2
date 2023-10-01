
#ifndef DnaiChangeTypeRm_H_
#define DnaiChangeTypeRm_H_

#include "DnaiChangeType.h"
#include "NullValue.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class DnaiChangeTypeRm : DnaiChangeType {
 public:
  DnaiChangeTypeRm();
  virtual ~DnaiChangeTypeRm() = default;

  bool validate(
      std::stringstream& msg, const std::string& pathPrefix) const override;

  friend void to_json(nlohmann::json& j, const DnaiChangeTypeRm& o);
  friend void from_json(const nlohmann::json& j, DnaiChangeTypeRm& o);

 protected:
};

}  // namespace ngkore::model::common

