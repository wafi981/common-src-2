
#include "Pc5FlowBitRates.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

Pc5FlowBitRates::Pc5FlowBitRates() {
  m_GuaFbr      = "";
  m_GuaFbrIsSet = false;
  m_MaxFbr      = "";
  m_MaxFbrIsSet = false;
}

void Pc5FlowBitRates::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool Pc5FlowBitRates::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool Pc5FlowBitRates::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "Pc5FlowBitRates" : pathPrefix;

  if (guaFbrIsSet()) {
    const std::string& value           = m_GuaFbr;
    const std::string currentValuePath = _pathPrefix + ".guaFbr";
  }

  if (maxFbrIsSet()) {
    const std::string& value           = m_MaxFbr;
    const std::string currentValuePath = _pathPrefix + ".maxFbr";
  }

  return success;
}

bool Pc5FlowBitRates::operator==(const Pc5FlowBitRates& rhs) const {
  return

      ((!guaFbrIsSet() && !rhs.guaFbrIsSet()) ||
       (guaFbrIsSet() && rhs.guaFbrIsSet() &&
        getGuaFbr() == rhs.getGuaFbr())) &&

      ((!maxFbrIsSet() && !rhs.maxFbrIsSet()) ||
       (maxFbrIsSet() && rhs.maxFbrIsSet() && getMaxFbr() == rhs.getMaxFbr()))

          ;
}

bool Pc5FlowBitRates::operator!=(const Pc5FlowBitRates& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const Pc5FlowBitRates& o) {
  j = nlohmann::json();
  if (o.guaFbrIsSet()) j["guaFbr"] = o.m_GuaFbr;
  if (o.maxFbrIsSet()) j["maxFbr"] = o.m_MaxFbr;
}

void from_json(const nlohmann::json& j, Pc5FlowBitRates& o) {
  if (j.find("guaFbr") != j.end()) {
    j.at("guaFbr").get_to(o.m_GuaFbr);
    o.m_GuaFbrIsSet = true;
  }
  if (j.find("maxFbr") != j.end()) {
    j.at("maxFbr").get_to(o.m_MaxFbr);
    o.m_MaxFbrIsSet = true;
  }
}

std::string Pc5FlowBitRates::getGuaFbr() const {
  return m_GuaFbr;
}
void Pc5FlowBitRates::setGuaFbr(std::string const& value) {
  m_GuaFbr      = value;
  m_GuaFbrIsSet = true;
}
bool Pc5FlowBitRates::guaFbrIsSet() const {
  return m_GuaFbrIsSet;
}
void Pc5FlowBitRates::unsetGuaFbr() {
  m_GuaFbrIsSet = false;
}
std::string Pc5FlowBitRates::getMaxFbr() const {
  return m_MaxFbr;
}
void Pc5FlowBitRates::setMaxFbr(std::string const& value) {
  m_MaxFbr      = value;
  m_MaxFbrIsSet = true;
}
bool Pc5FlowBitRates::maxFbrIsSet() const {
  return m_MaxFbrIsSet;
}
void Pc5FlowBitRates::unsetMaxFbr() {
  m_MaxFbrIsSet = false;
}

}  // namespace ngkore::model::common
