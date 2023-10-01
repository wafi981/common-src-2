
#include "SmfInfo.h"
#include "Helpers.h"
#include "config.hpp"

#include <sstream>

namespace ngkore::model::nrf {

SmfInfo::SmfInfo() {
  m_TaiListIsSet        = false;
  m_TaiRangeListIsSet   = false;
  m_PgwFqdn             = "";
  m_PgwFqdnIsSet        = false;
  m_AccessTypeIsSet     = false;
  m_Priority            = 0;
  m_PriorityIsSet       = false;
  m_VsmfSupportInd      = false;
  m_VsmfSupportIndIsSet = false;
}

void SmfInfo::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool SmfInfo::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool SmfInfo::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success                  = true;
  const std::string _pathPrefix = pathPrefix.empty() ? "SmfInfo" : pathPrefix;

