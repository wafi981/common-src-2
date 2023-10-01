
#ifndef InvalidParam_H_
#define InvalidParam_H_

#include <string>
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class InvalidParam {
 public:
  InvalidParam();
  virtual ~InvalidParam() = default;

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

  bool operator==(const InvalidParam& rhs) const;
  bool operator!=(const InvalidParam& rhs) const;

  /////////////////////////////////////////////
  /// InvalidParam members

  /// <summary>
  ///
  /// </summary>
  std::string getParam() const;
  void setParam(std::string const& value);
  /// <summary>
  ///
  /// </summary>
  std::string getReason() const;
  void setReason(std::string const& value);
  bool reasonIsSet() const;
  void unsetReason();

  friend void to_json(nlohmann::json& j, const InvalidParam& o);
  friend void from_json(const nlohmann::json& j, InvalidParam& o);

 protected:
  std::string m_Param;

  std::string m_Reason;
  bool m_ReasonIsSet;
};

}  // namespace ngkore::model::common

