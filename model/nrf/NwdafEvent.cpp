
#include "NwdafEvent.h"

namespace ngkore::model::nrf {

NwdafEvent::NwdafEvent() {}

NwdafEvent::~NwdafEvent() {}

void NwdafEvent::validate() {
  // TODO: implement validation
}

void to_json(nlohmann::json& j, const NwdafEvent& o) {
  j = nlohmann::json();
}

void from_json(const nlohmann::json& j, NwdafEvent& o) {}

}  // namespace ngkore::model::nrf
