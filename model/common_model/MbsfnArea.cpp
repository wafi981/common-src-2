
#include "MbsfnArea.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

MbsfnArea::MbsfnArea() {
  m_MbsfnAreaId           = 0;
  m_MbsfnAreaIdIsSet      = false;
  m_CarrierFrequency      = 0;
  m_CarrierFrequencyIsSet = false;
}

void MbsfnArea::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool MbsfnArea::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool MbsfnArea::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success                  = true;
  const std::string _pathPrefix = pathPrefix.empty() ? "MbsfnArea" : pathPrefix;

  if (mbsfnAreaIdIsSet()) {
    const int32_t& value               = m_MbsfnAreaId;
    const std::string currentValuePath = _pathPrefix + ".mbsfnAreaId";

    if (value < 0) {
      success = false;
      msg << currentValuePath << ": must be greater than or equal to 0;";
    }
    if (value > 255) {
      success = false;
      msg << currentValuePath << ": must be less than or equal to 255;";
    }
  }

  if (carrierFrequencyIsSet()) {
    const int32_t& value               = m_CarrierFrequency;
    const std::string currentValuePath = _pathPrefix + ".carrierFrequency";

    if (value < 0) {
      success = false;
      msg << currentValuePath << ": must be greater than or equal to 0;";
    }
    if (value > 262143) {
      success = false;
      msg << currentValuePath << ": must be less than or equal to 262143;";
    }
  }

  return success;
}

bool MbsfnArea::operator==(const MbsfnArea& rhs) const {
  return

      ((!mbsfnAreaIdIsSet() && !rhs.mbsfnAreaIdIsSet()) ||
       (mbsfnAreaIdIsSet() && rhs.mbsfnAreaIdIsSet() &&
        getMbsfnAreaId() == rhs.getMbsfnAreaId())) &&

      ((!carrierFrequencyIsSet() && !rhs.carrierFrequencyIsSet()) ||
       (carrierFrequencyIsSet() && rhs.carrierFrequencyIsSet() &&
        getCarrierFrequency() == rhs.getCarrierFrequency()))

          ;
}

bool MbsfnArea::operator!=(const MbsfnArea& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const MbsfnArea& o) {
  j = nlohmann::json();
  if (o.mbsfnAreaIdIsSet()) j["mbsfnAreaId"] = o.m_MbsfnAreaId;
  if (o.carrierFrequencyIsSet()) j["carrierFrequency"] = o.m_CarrierFrequency;
}

void from_json(const nlohmann::json& j, MbsfnArea& o) {
  if (j.find("mbsfnAreaId") != j.end()) {
    j.at("mbsfnAreaId").get_to(o.m_MbsfnAreaId);
    o.m_MbsfnAreaIdIsSet = true;
  }
  if (j.find("carrierFrequency") != j.end()) {
    j.at("carrierFrequency").get_to(o.m_CarrierFrequency);
    o.m_CarrierFrequencyIsSet = true;
  }
}

int32_t MbsfnArea::getMbsfnAreaId() const {
  return m_MbsfnAreaId;
}
void MbsfnArea::setMbsfnAreaId(int32_t const value) {
  m_MbsfnAreaId      = value;
  m_MbsfnAreaIdIsSet = true;
}
bool MbsfnArea::mbsfnAreaIdIsSet() const {
  return m_MbsfnAreaIdIsSet;
}
void MbsfnArea::unsetMbsfnAreaId() {
  m_MbsfnAreaIdIsSet = false;
}
int32_t MbsfnArea::getCarrierFrequency() const {
  return m_CarrierFrequency;
}
void MbsfnArea::setCarrierFrequency(int32_t const value) {
  m_CarrierFrequency      = value;
  m_CarrierFrequencyIsSet = true;
}
bool MbsfnArea::carrierFrequencyIsSet() const {
  return m_CarrierFrequencyIsSet;
}
void MbsfnArea::unsetCarrierFrequency() {
  m_CarrierFrequencyIsSet = false;
}

}  // namespace ngkore::model::common
