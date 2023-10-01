
#ifndef OdbPacketServices_H_
#define OdbPacketServices_H_

#include "NullValue.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class OdbPacketServices {
 public:
  OdbPacketServices();
  virtual ~OdbPacketServices() = default;

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

  bool operator==(const OdbPacketServices& rhs) const;
  bool operator!=(const OdbPacketServices& rhs) const;

  /////////////////////////////////////////////
  /// OdbPacketServices members

  friend void to_json(nlohmann::json& j, const OdbPacketServices& o);
  friend void from_json(const nlohmann::json& j, OdbPacketServices& o);

 protected:
};

}  // namespace ngkore::model::common

