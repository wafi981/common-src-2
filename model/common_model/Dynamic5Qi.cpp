
#include "Dynamic5Qi.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

Dynamic5Qi::Dynamic5Qi() {
  m_PriorityLevel              = 0;
  m_PacketDelayBudget          = 0;
  m_PacketErrRate              = "";
  m_AverWindow                 = 2000;
  m_AverWindowIsSet            = false;
  m_MaxDataBurstVol            = 0;
  m_MaxDataBurstVolIsSet       = false;
  m_ExtMaxDataBurstVol         = 0;
  m_ExtMaxDataBurstVolIsSet    = false;
  m_ExtPacketDelBudget         = 0;
  m_ExtPacketDelBudgetIsSet    = false;
  m_CnPacketDelayBudgetDl      = 0;
  m_CnPacketDelayBudgetDlIsSet = false;
  m_CnPacketDelayBudgetUl      = 0;
  m_CnPacketDelayBudgetUlIsSet = false;
}

void Dynamic5Qi::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool Dynamic5Qi::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool Dynamic5Qi::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "Dynamic5Qi" : pathPrefix;

    const int32_t& value               = m_PacketDelayBudget;
    const std::string currentValuePath = _pathPrefix + ".packetDelayBudget";

    if (value < 1) {
      success = false;
      msg << currentValuePath << ": must be greater than or equal to 1;";
    }
  }

