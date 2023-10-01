#include "Helpers.h"
#include <regex>

namespace ngkore::model::common::helpers {

const std::regex regexRfc3339_date(R"(^(\d{4})\-(\d{2})\-(\d{2})$)");
const std::regex regexRfc3339_date_time(
    R"(^(\d{4})\-(\d{2})\-(\d{2})[Tt](\d{2}):(\d{2}):(\d{2})(\.\d+)?([Zz]|([\+\-])(\d{2}):(\d{2}))$)");

namespace {
// Determine if given year is a leap year
// See RFC 3339, Appendix C https://tools.ietf.org/html/rfc3339#appendix-C
bool isLeapYear(const uint16_t year) {
  return (year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0));
}

bool validateDateValues(
    const uint16_t year, const uint16_t month, const uint16_t day) {
  return !(
      (month == 0 || month > 12) || (day == 0) ||
      (month == 2 && day > (28 + (isLeapYear(year) ? 1 : 0))) ||
      (month <= 7 && day > (30 + month % 2)) ||
      (month >= 8 && day > (31 - month % 2)));
}

bool validateTimeValues(
    const uint16_t hours, const uint16_t minutes, const uint16_t seconds) {
  return (hours <= 23) && (minutes <= 59) && (seconds <= 60);
}
}  // namespace

bool validateRfc3339_date(const std::string& str) {
  std::smatch match;
  const bool found = std::regex_search(str, match, regexRfc3339_date);
  return found && validateDateValues(
                      static_cast<uint16_t>(std::stoi(match[1])),
                      static_cast<uint16_t>(std::stoi(match[2])),
                      static_cast<uint16_t>(std::stoi(match[3])));
}

bool validateRfc3339_date_time(const std::string& str) {
  std::smatch match;
  const bool found = std::regex_search(str, match, regexRfc3339_date_time);
  return found &&
         validateDateValues(
             static_cast<uint16_t>(std::stoi(match[1])),
             static_cast<uint16_t>(std::stoi(match[2])),
             static_cast<uint16_t>(std::stoi(match[3]))) &&
         validateTimeValues(
             static_cast<uint16_t>(std::stoi(match[4])),
             static_cast<uint16_t>(std::stoi(match[5])),
             static_cast<uint16_t>(std::stoi(match[6])));
}

std::string toStringValue(const std::string& value) {
  return std::string(value);
}

std::string toStringValue(const int32_t value) {
  return std::to_string(value);
}

std::string toStringValue(const int64_t value) {
  return std::to_string(value);
}

std::string toStringValue(const bool value) {
  return value ? std::string("true") : std::string("false");
}

std::string toStringValue(const float value) {
  return std::to_string(value);
}

std::string toStringValue(const double value) {
  return std::to_string(value);
}

bool fromStringValue(const std::string& inStr, std::string& value) {
  value = std::string(inStr);
  return true;
}

bool fromStringValue(const std::string& inStr, int32_t& value) {
  try {
    value = std::stoi(inStr);
  } catch (const std::invalid_argument&) {
    return false;
  }
  return true;
}

bool fromStringValue(const std::string& inStr, int64_t& value) {
  try {
    value = std::stol(inStr);
  } catch (const std::invalid_argument&) {
    return false;
  }
  return true;
}

bool fromStringValue(const std::string& inStr, bool& value) {
  if (inStr == "true") {
    value = true;
    return true;
  }
  if (inStr == "false") {
    value = false;
    return true;
  }
  return false;
}

bool fromStringValue(const std::string& inStr, float& value) {
  try {
    value = std::stof(inStr);
  } catch (const std::invalid_argument&) {
    return false;
  }
  return true;
}

bool fromStringValue(const std::string& inStr, double& value) {
  try {
    value = std::stod(inStr);
  } catch (const std::invalid_argument&) {
    return false;
  }
  return true;
}

bool validate_regex(
    const std::string& regex, const std::string& value, std::stringstream& msg,
    const std::string& pathPrefix) {
  std::regex re(regex);
  if (!std::regex_match(value, re)) {
    msg << pathPrefix << " must follow regex specification: " << regex;
    return false;
  }
  return true;
}

}  // namespace ngkore::model::common::helpers
