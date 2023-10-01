
#include "RouteInformation.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

RouteInformation::RouteInformation() {
  m_Ipv4Addr      = "";
  m_Ipv4AddrIsSet = false;
  m_Ipv6AddrIsSet = false;
  m_PortNumber    = 0;
}

void RouteInformation::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool RouteInformation::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool RouteInformation::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "RouteInformation" : pathPrefix;
