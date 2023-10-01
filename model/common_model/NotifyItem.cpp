
#include "NotifyItem.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

NotifyItem::NotifyItem() {
  m_ResourceId = "";
}

void NotifyItem::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool NotifyItem::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool NotifyItem::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "NotifyItem" : pathPrefix;

