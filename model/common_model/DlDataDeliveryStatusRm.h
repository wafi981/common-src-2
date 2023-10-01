
#ifndef DlDataDeliveryStatusRm_H_
#define DlDataDeliveryStatusRm_H_

#include "DlDataDeliveryStatus.h"
#include "NullValue.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class DlDataDeliveryStatusRm : public DlDataDeliveryStatus {
 public:
  DlDataDeliveryStatusRm();
  virtual ~DlDataDeliveryStatusRm() = default;

  virtual bool validate(
      std::stringstream& msg, const std::string& pathPrefix) const override;

  friend void to_json(nlohmann::json& j, const DlDataDeliveryStatusRm& o);
  friend void from_json(const nlohmann::json& j, DlDataDeliveryStatusRm& o);

 protected:
};

}  // namespace ngkore::model::common

