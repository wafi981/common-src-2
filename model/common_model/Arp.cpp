
#include "Arp.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

Arp::Arp() {
  m_PriorityLevel = 0;
}

void Arp::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool Arp::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool Arp::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success                  = true;
  const std::string _pathPrefix = pathPrefix.empty() ? "Arp" : pathPrefix;

