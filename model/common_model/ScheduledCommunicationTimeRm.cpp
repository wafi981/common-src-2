
#include "ScheduledCommunicationTimeRm.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

ScheduledCommunicationTimeRm::ScheduledCommunicationTimeRm() {
  m_DaysOfWeekIsSet     = false;
  m_TimeOfDayStart      = "";
  m_TimeOfDayStartIsSet = false;
  m_TimeOfDayEnd        = "";
  m_TimeOfDayEndIsSet   = false;
}

void ScheduledCommunicationTimeRm::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool ScheduledCommunicationTimeRm::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool ScheduledCommunicationTimeRm::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "ScheduledCommunicationTimeRm" : pathPrefix;

  if (daysOfWeekIsSet()) {
    const std::vector<int32_t>& value  = m_DaysOfWeek;
    const std::string currentValuePath = _pathPrefix + ".daysOfWeek";

    if (value.size() < 1) {
      success = false;
      msg << currentValuePath << ": must have at least 1 elements;";
    }
    if (value.size() > 6) {
      success = false;
      msg << currentValuePath << ": must have at most 6 elements;";
    }
    {  // Recursive validation of array elements
      const std::string oldValuePath = currentValuePath;
      int i                          = 0;
      for (const int32_t& value : value) {
        const std::string currentValuePath =
            oldValuePath + "[" + std::to_string(i) + "]";

        if (value < 1) {
          success = false;
          msg << currentValuePath << ": must be greater than or equal to 1;";
        }
        if (value > 7) {
          success = false;
          msg << currentValuePath << ": must be less than or equal to 7;";
        }

        i++;
      }
    }
  }

  return success;
}

bool ScheduledCommunicationTimeRm::operator==(
    const ScheduledCommunicationTimeRm& rhs) const {
  return

      ((!daysOfWeekIsSet() && !rhs.daysOfWeekIsSet()) ||
       (daysOfWeekIsSet() && rhs.daysOfWeekIsSet() &&
        getDaysOfWeek() == rhs.getDaysOfWeek())) &&

      ((!timeOfDayStartIsSet() && !rhs.timeOfDayStartIsSet()) ||
       (timeOfDayStartIsSet() && rhs.timeOfDayStartIsSet() &&
        getTimeOfDayStart() == rhs.getTimeOfDayStart())) &&

      ((!timeOfDayEndIsSet() && !rhs.timeOfDayEndIsSet()) ||
       (timeOfDayEndIsSet() && rhs.timeOfDayEndIsSet() &&
        getTimeOfDayEnd() == rhs.getTimeOfDayEnd()))

          ;
}

bool ScheduledCommunicationTimeRm::operator!=(
    const ScheduledCommunicationTimeRm& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const ScheduledCommunicationTimeRm& o) {
  j = nlohmann::json();
  if (o.daysOfWeekIsSet() || !o.m_DaysOfWeek.empty())
    j["daysOfWeek"] = o.m_DaysOfWeek;
  if (o.timeOfDayStartIsSet()) j["timeOfDayStart"] = o.m_TimeOfDayStart;
  if (o.timeOfDayEndIsSet()) j["timeOfDayEnd"] = o.m_TimeOfDayEnd;
}

void from_json(const nlohmann::json& j, ScheduledCommunicationTimeRm& o) {
  if (j.find("daysOfWeek") != j.end()) {
    j.at("daysOfWeek").get_to(o.m_DaysOfWeek);
    o.m_DaysOfWeekIsSet = true;
  }
  if (j.find("timeOfDayStart") != j.end()) {
    j.at("timeOfDayStart").get_to(o.m_TimeOfDayStart);
    o.m_TimeOfDayStartIsSet = true;
  }
  if (j.find("timeOfDayEnd") != j.end()) {
    j.at("timeOfDayEnd").get_to(o.m_TimeOfDayEnd);
    o.m_TimeOfDayEndIsSet = true;
  }
}

std::vector<int32_t> ScheduledCommunicationTimeRm::getDaysOfWeek() const {
  return m_DaysOfWeek;
}
void ScheduledCommunicationTimeRm::setDaysOfWeek(
    std::vector<int32_t> const value) {
  m_DaysOfWeek      = value;
  m_DaysOfWeekIsSet = true;
}
bool ScheduledCommunicationTimeRm::daysOfWeekIsSet() const {
  return m_DaysOfWeekIsSet;
}
void ScheduledCommunicationTimeRm::unsetDaysOfWeek() {
  m_DaysOfWeekIsSet = false;
}
std::string ScheduledCommunicationTimeRm::getTimeOfDayStart() const {
  return m_TimeOfDayStart;
}
void ScheduledCommunicationTimeRm::setTimeOfDayStart(std::string const& value) {
  m_TimeOfDayStart      = value;
  m_TimeOfDayStartIsSet = true;
}
bool ScheduledCommunicationTimeRm::timeOfDayStartIsSet() const {
  return m_TimeOfDayStartIsSet;
}
void ScheduledCommunicationTimeRm::unsetTimeOfDayStart() {
  m_TimeOfDayStartIsSet = false;
}
std::string ScheduledCommunicationTimeRm::getTimeOfDayEnd() const {
  return m_TimeOfDayEnd;
}
void ScheduledCommunicationTimeRm::setTimeOfDayEnd(std::string const& value) {
  m_TimeOfDayEnd      = value;
  m_TimeOfDayEndIsSet = true;
}
bool ScheduledCommunicationTimeRm::timeOfDayEndIsSet() const {
  return m_TimeOfDayEndIsSet;
}
void ScheduledCommunicationTimeRm::unsetTimeOfDayEnd() {
  m_TimeOfDayEndIsSet = false;
}

}  // namespace ngkore::model::common
