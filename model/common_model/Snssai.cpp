
#include "Snssai.h"
#include "Helpers.h"
#include "config.hpp"

#include <sstream>
#include <fmt/format.h>

namespace ngkore::model::common {

Snssai::Snssai() {
  m_Sst     = 0;
  m_Sd      = "";
  m_SdIsSet = false;
}

void Snssai::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool Snssai::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool Snssai::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success                  = true;
  const std::string _pathPrefix = pathPrefix.empty() ? "Snssai" : pathPrefix;

