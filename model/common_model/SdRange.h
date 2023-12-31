
#ifndef SdRange_H_
#define SdRange_H_

#include <string>
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
/// A range of SDs (Slice Differentiators)
/// </summary>
class SdRange {
 public:
  SdRange();
  virtual ~SdRange() = default;

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

  bool operator==(const SdRange& rhs) const;
  bool operator!=(const SdRange& rhs) const;

  /////////////////////////////////////////////
  /// SdRange members

  /// <summary>
  ///
  /// </summary>
  std::string getStart() const;
  void setStart(std::string const& value);
  bool startIsSet() const;
  void unsetStart();
  /// <summary>
  ///
  /// </summary>
  std::string getEnd() const;
  void setEnd(std::string const& value);
  bool endIsSet() const;
  void unsetEnd();

  friend void to_json(nlohmann::json& j, const SdRange& o);
  friend void from_json(const nlohmann::json& j, SdRange& o);

 protected:
  std::string m_Start;
  bool m_StartIsSet;
  std::string m_End;
  bool m_EndIsSet;
};

}  // namespace ngkore::model::common

