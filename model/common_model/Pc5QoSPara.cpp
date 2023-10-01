
#include "Pc5QoSPara.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

Pc5QoSPara::Pc5QoSPara() {
  m_Pc5LinkAmbr      = "";
  m_Pc5LinkAmbrIsSet = false;
}

void Pc5QoSPara::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool Pc5QoSPara::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool Pc5QoSPara::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "Pc5QoSPara" : pathPrefix;

