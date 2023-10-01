
#include "AtsssCapability.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

AtsssCapability::AtsssCapability() {
  m_AtsssLL            = false;
  m_AtsssLLIsSet       = false;
  m_Mptcp              = false;
  m_MptcpIsSet         = false;
  m_RttWithoutPmf      = false;
  m_RttWithoutPmfIsSet = false;
}

void AtsssCapability::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool AtsssCapability::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool AtsssCapability::validate(
