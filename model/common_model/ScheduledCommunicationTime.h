
#ifndef ScheduledCommunicationTime_H_
#define ScheduledCommunicationTime_H_

#include <string>
#include <vector>
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class ScheduledCommunicationTime {
 public:
  ScheduledCommunicationTime();
  virtual ~ScheduledCommunicationTime() = default;

  /// <summary>
  /// Validate the current data in the model. Throws a ValidationException on
  /// failure.
  /// </summary>
  void validate() const;

  /// <summary>
  /// Validate the current data in the model. Returns false on error and writes
  /// an error message into the given stringstream.
  /// </summary>
  bool validate(std::stringstream& msg) const;

  /// <summary>
  /// Helper overload for validate. Used when one model stores another model and
  /// calls it's validate. Not meant to be called outside that case.
  /// </summary>
  bool validate(std::stringstream& msg, const std::string& pathPrefix) const;

  bool operator==(const ScheduledCommunicationTime& rhs) const;
  bool operator!=(const ScheduledCommunicationTime& rhs) const;

  /////////////////////////////////////////////
  /// ScheduledCommunicationTime members

  /// <summary>
  /// Identifies the day(s) of the week. If absent, it indicates every day of
  /// the week.
  /// </summary>
  std::vector<int32_t> getDaysOfWeek() const;
  void setDaysOfWeek(std::vector<int32_t> const value);
  bool daysOfWeekIsSet() const;
  void unsetDaysOfWeek();
  /// <summary>
  /// String with format partial-time or full-time as defined in clause 5.6 of
  /// IETF RFC 3339. Examples, 20:15:00, 20:15:00-08:00 (for 8 hours behind
  /// UTC).
  /// </summary>
  std::string getTimeOfDayStart() const;
  void setTimeOfDayStart(std::string const& value);
  bool timeOfDayStartIsSet() const;
  void unsetTimeOfDayStart();
  /// <summary>
  /// String with format partial-time or full-time as defined in clause 5.6 of
  /// IETF RFC 3339. Examples, 20:15:00, 20:15:00-08:00 (for 8 hours behind
  /// UTC).
  /// </summary>
  std::string getTimeOfDayEnd() const;
  void setTimeOfDayEnd(std::string const& value);
  bool timeOfDayEndIsSet() const;
  void unsetTimeOfDayEnd();

  friend void to_json(nlohmann::json& j, const ScheduledCommunicationTime& o);
  friend void from_json(const nlohmann::json& j, ScheduledCommunicationTime& o);

 protected:
  std::vector<int32_t> m_DaysOfWeek;
  bool m_DaysOfWeekIsSet;
  std::string m_TimeOfDayStart;
  bool m_TimeOfDayStartIsSet;
  std::string m_TimeOfDayEnd;
  bool m_TimeOfDayEndIsSet;
};

}  // namespace ngkore::model::common

