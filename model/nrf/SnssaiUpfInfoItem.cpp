
#include "SnssaiUpfInfoItem.h"
#include "Helpers.h"
#include "config.hpp"

#include <sstream>

namespace ngkore::model::nrf {

SnssaiUpfInfoItem::SnssaiUpfInfoItem() {
  m_RedundantTransport      = false;
  m_RedundantTransportIsSet = false;
}

void SnssaiUpfInfoItem::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool SnssaiUpfInfoItem::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool SnssaiUpfInfoItem::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "SnssaiUpfInfoItem" : pathPrefix;

  if (!m_SNssai.validate(msg)) {
    msg << _pathPrefix << ": SNssai is invalid;";
    success = false;
  }

