
#include "Dnf.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

Dnf::Dnf() {}

void Dnf::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool Dnf::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool Dnf::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success                  = true;
  const std::string _pathPrefix = pathPrefix.empty() ? "Dnf" : pathPrefix;

