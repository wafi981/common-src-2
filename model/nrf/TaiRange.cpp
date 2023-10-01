
#include "TaiRange.h"
#include "Helpers.h"

#include <sstream>
#include <Helpers.h>

namespace ngkore::model::nrf {

TaiRange::TaiRange() {
  m_Nid      = "";
  m_NidIsSet = false;
}

void TaiRange::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool TaiRange::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool TaiRange::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success                  = true;
  const std::string _pathPrefix = pathPrefix.empty() ? "TaiRange" : pathPrefix;

  if (!m_PlmnId.validate(msg)) {
    msg << _pathPrefix << ": PlmnId is invalid;";
    success = false;
  }

