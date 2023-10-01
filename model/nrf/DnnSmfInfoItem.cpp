
#include "DnnSmfInfoItem.h"
#include "Helpers.h"
#include "config.hpp"

#include <sstream>

namespace ngkore::model::nrf {

DnnSmfInfoItem::DnnSmfInfoItem() {
  m_Dnn = "";
}

void DnnSmfInfoItem::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool DnnSmfInfoItem::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool DnnSmfInfoItem::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "DnnSmfInfoItem" : pathPrefix;

  return success;
}

bool DnnSmfInfoItem::operator==(const DnnSmfInfoItem& rhs) const {
  return

      (getDnn() == rhs.getDnn())

          ;
}

bool DnnSmfInfoItem::operator!=(const DnnSmfInfoItem& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const DnnSmfInfoItem& o) {
  j        = nlohmann::json::object();
  j["dnn"] = o.m_Dnn;
}

void from_json(const nlohmann::json& j, DnnSmfInfoItem& o) {
  j.at("dnn").get_to(o.m_Dnn);
}

std::string DnnSmfInfoItem::getDnn() const {
  return m_Dnn;
}
void DnnSmfInfoItem::setDnn(std::string const& value) {
  m_Dnn = value;
}

std::string DnnSmfInfoItem::to_string(int indent_level) const {
  std::string out;
  std::string fmt_value = ngkore::config::get_value_formatter(indent_level);
  out.append(fmt::format(fmt_value, "dnn", m_Dnn));
  return out;
}

}  // namespace ngkore::model::nrf
