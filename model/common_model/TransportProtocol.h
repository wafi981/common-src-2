
#ifndef TransportProtocol_H_
#define TransportProtocol_H_

#include "TransportProtocol_anyOf.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
/// Possible values are - UDP: User Datagram Protocol. - TCP: Transmission
/// Control Protocol.
/// </summary>
class TransportProtocol {
 public:
  TransportProtocol();
  virtual ~TransportProtocol() = default;

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

  bool operator==(const TransportProtocol& rhs) const;
  bool operator!=(const TransportProtocol& rhs) const;

  /////////////////////////////////////////////
  /// TransportProtocol members

  TransportProtocol_anyOf getValue() const;
  void setValue(TransportProtocol_anyOf value);
  TransportProtocol_anyOf::eTransportProtocol_anyOf getEnumValue() const;
  void setEnumValue(TransportProtocol_anyOf::eTransportProtocol_anyOf value);
  friend void to_json(nlohmann::json& j, const TransportProtocol& o);
  friend void from_json(const nlohmann::json& j, TransportProtocol& o);
  friend void to_json(nlohmann::json& j, const TransportProtocol_anyOf& o);
  friend void from_json(const nlohmann::json& j, TransportProtocol_anyOf& o);

 protected:
  TransportProtocol_anyOf m_value;
};

}  // namespace ngkore::model::common

