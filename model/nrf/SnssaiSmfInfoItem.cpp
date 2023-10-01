
#include "SnssaiSmfInfoItem.h"
#include "Helpers.h"
#include "config.hpp"

#include <sstream>

namespace ngkore::model::nrf {

SnssaiSmfInfoItem::SnssaiSmfInfoItem() {}

void SnssaiSmfInfoItem::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool SnssaiSmfInfoItem::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool SnssaiSmfInfoItem::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "SnssaiSmfInfoItem" : pathPrefix;

  if (!m_SNssai.validate(msg)) {
    msg << _pathPrefix << ": SNssai is invalid;";
    success = false;
  }

