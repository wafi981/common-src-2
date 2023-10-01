
#include "ServiceName.h"

namespace ngkore::model::nrf {

ServiceName::ServiceName() {}

ServiceName::~ServiceName() {}

void ServiceName::validate() {
  // TODO: implement validation
}

void to_json(nlohmann::json& j, const ServiceName& o) {
  j = nlohmann::json();
}

void from_json(const nlohmann::json& j, ServiceName& o) {}

}  // namespace ngkore::model::nrf
