
#ifndef NgApCause_H_
#define NgApCause_H_

#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class NgApCause {
 public:
  NgApCause();
  virtual ~NgApCause() = default;

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

  bool operator==(const NgApCause& rhs) const;
  bool operator!=(const NgApCause& rhs) const;

  /////////////////////////////////////////////
  /// NgApCause members

  /// <summary>
  ///
  /// </summary>
  int32_t getGroup() const;
  void setGroup(int32_t const value);
  /// <summary>
  ///
  /// </summary>
  int32_t getValue() const;
  void setValue(int32_t const value);

  friend void to_json(nlohmann::json& j, const NgApCause& o);
  friend void from_json(const nlohmann::json& j, NgApCause& o);

 protected:
  int32_t m_Group;

  int32_t m_Value;
};

}  // namespace ngkore::model::common

