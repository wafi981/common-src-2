
#include "PatchItem.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

PatchItem::PatchItem() {
  m_Path       = "";
  m_From       = "";
  m_FromIsSet  = false;
  m_ValueIsSet = false;
}

void PatchItem::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool PatchItem::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool PatchItem::validate(
