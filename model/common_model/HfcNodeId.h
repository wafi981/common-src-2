
#ifndef HfcNodeId_H_
#define HfcNodeId_H_

#include <string>
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class HfcNodeId {
 public:
  HfcNodeId();
  virtual ~HfcNodeId() = default;

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

  bool operator==(const HfcNodeId& rhs) const;
  bool operator!=(const HfcNodeId& rhs) const;

  /////////////////////////////////////////////
  /// HfcNodeId members

  /// <summary>
  ///
  /// </summary>
  std::string getHfcNId() const;
  void setHfcNId(std::string const& value);

  friend void to_json(nlohmann::json& j, const HfcNodeId& o);
  friend void from_json(const nlohmann::json& j, HfcNodeId& o);

 protected:
  std::string m_HfcNId;
};

}  // namespace ngkore::model::common

