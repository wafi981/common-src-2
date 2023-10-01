
#include "EventId.h"

namespace ngkore::model::nrf {

EventId::EventId() {}

EventId::~EventId() {}

void EventId::validate() {
  // TODO: implement validation
}

void to_json(nlohmann::json& j, const EventId& o) {
  j = nlohmann::json();
}

void from_json(const nlohmann::json& j, EventId& o) {}

}  // namespace ngkore::model::nrf
