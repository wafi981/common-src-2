
#include "Cnf.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

Cnf::Cnf() {}

void Cnf::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool Cnf::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool Cnf::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success                  = true;
  const std::string _pathPrefix = pathPrefix.empty() ? "Cnf" : pathPrefix;

