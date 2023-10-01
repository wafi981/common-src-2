
#include "MoExpDataCounter.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

MoExpDataCounter::MoExpDataCounter() {
  m_Counter        = 0;
  m_TimeStamp      = "";
  m_TimeStampIsSet = false;
}

void MoExpDataCounter::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool MoExpDataCounter::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool MoExpDataCounter::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "MoExpDataCounter" : pathPrefix;

  return success;
}

bool MoExpDataCounter::operator==(const MoExpDataCounter& rhs) const {
  return

      (getCounter() == rhs.getCounter()) &&

      ((!timeStampIsSet() && !rhs.timeStampIsSet()) ||
       (timeStampIsSet() && rhs.timeStampIsSet() &&
        getTimeStamp() == rhs.getTimeStamp()))

          ;
}

bool MoExpDataCounter::operator!=(const MoExpDataCounter& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const MoExpDataCounter& o) {
  j            = nlohmann::json();
  j["counter"] = o.m_Counter;
  if (o.timeStampIsSet()) j["timeStamp"] = o.m_TimeStamp;
}

void from_json(const nlohmann::json& j, MoExpDataCounter& o) {
  j.at("counter").get_to(o.m_Counter);
  if (j.find("timeStamp") != j.end()) {
    j.at("timeStamp").get_to(o.m_TimeStamp);
    o.m_TimeStampIsSet = true;
  }
}

int32_t MoExpDataCounter::getCounter() const {
  return m_Counter;
}
void MoExpDataCounter::setCounter(int32_t const value) {
  m_Counter = value;
}
std::string MoExpDataCounter::getTimeStamp() const {
  return m_TimeStamp;
}
void MoExpDataCounter::setTimeStamp(std::string const& value) {
  m_TimeStamp      = value;
  m_TimeStampIsSet = true;
}
bool MoExpDataCounter::timeStampIsSet() const {
  return m_TimeStampIsSet;
}
void MoExpDataCounter::unsetTimeStamp() {
  m_TimeStampIsSet = false;
}

}  // namespace ngkore::model::common
