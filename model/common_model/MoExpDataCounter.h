
#ifndef MoExpDataCounter_H_
#define MoExpDataCounter_H_

#include <string>
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class MoExpDataCounter {
 public:
  MoExpDataCounter();
  virtual ~MoExpDataCounter() = default;

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

  bool operator==(const MoExpDataCounter& rhs) const;
  bool operator!=(const MoExpDataCounter& rhs) const;

  /////////////////////////////////////////////
  /// MoExpDataCounter members

  /// <summary>
  ///
  /// </summary>
  int32_t getCounter() const;
  void setCounter(int32_t const value);
  /// <summary>
  ///
  /// </summary>
  std::string getTimeStamp() const;
  void setTimeStamp(std::string const& value);
  bool timeStampIsSet() const;
  void unsetTimeStamp();

  friend void to_json(nlohmann::json& j, const MoExpDataCounter& o);
  friend void from_json(const nlohmann::json& j, MoExpDataCounter& o);

 protected:
  int32_t m_Counter;

  std::string m_TimeStamp;
  bool m_TimeStampIsSet;
};

}  // namespace ngkore::model::common

