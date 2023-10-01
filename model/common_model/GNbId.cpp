
#include "GNbId.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

GNbId::GNbId() {
  m_BitLength = 0;
  m_GNBValue  = "";
}

void GNbId::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool GNbId::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool GNbId::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success                  = true;
  const std::string _pathPrefix = pathPrefix.empty() ? "GNbId" : pathPrefix;

  return success;
}

bool GNbId::operator==(const GNbId& rhs) const {
  return

      (getBitLength() == rhs.getBitLength()) &&

      (getGNBValue() == rhs.getGNBValue())

          ;
}

bool GNbId::operator!=(const GNbId& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const GNbId& o) {
  j              = nlohmann::json();
  j["bitLength"] = o.m_BitLength;
  j["gNBValue"]  = o.m_GNBValue;
}

void from_json(const nlohmann::json& j, GNbId& o) {
  j.at("bitLength").get_to(o.m_BitLength);
  j.at("gNBValue").get_to(o.m_GNBValue);
}

int32_t GNbId::getBitLength() const {
  return m_BitLength;
}
void GNbId::setBitLength(int32_t const value) {
  m_BitLength = value;
}
std::string GNbId::getGNBValue() const {
  return m_GNBValue;
}
void GNbId::setGNBValue(std::string const& value) {
  m_GNBValue = value;
}

}  // namespace ngkore::model::common
