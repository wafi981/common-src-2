
#include "Pc5QosFlowItem.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

Pc5QosFlowItem::Pc5QosFlowItem() {
  m_Pqi                  = 0;
  m_Pc5FlowBitRatesIsSet = false;
  m_Range                = 0;
  m_RangeIsSet           = false;
}

void Pc5QosFlowItem::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool Pc5QosFlowItem::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool Pc5QosFlowItem::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "Pc5QosFlowItem" : pathPrefix;

