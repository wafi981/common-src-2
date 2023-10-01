
#ifndef TransportProtocol_anyOf_H_
#define TransportProtocol_anyOf_H_

#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class TransportProtocol_anyOf {
 public:
  TransportProtocol_anyOf();
  virtual ~TransportProtocol_anyOf() = default;

  enum class eTransportProtocol_anyOf {
    // To have a valid default value.
    // Avoiding name clashes with user defined
    // enum values
    INVALID_VALUE_OPENAPI_GENERATED = 0,
    UDP,
    TCP
  };

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

  bool operator==(const TransportProtocol_anyOf& rhs) const;
  bool operator!=(const TransportProtocol_anyOf& rhs) const;

  /////////////////////////////////////////////
  /// TransportProtocol_anyOf members

  TransportProtocol_anyOf::eTransportProtocol_anyOf getValue() const;
  void setValue(TransportProtocol_anyOf::eTransportProtocol_anyOf value);

  friend void to_json(nlohmann::json& j, const TransportProtocol_anyOf& o);
  friend void from_json(const nlohmann::json& j, TransportProtocol_anyOf& o);

 protected:
  TransportProtocol_anyOf::eTransportProtocol_anyOf m_value =
      TransportProtocol_anyOf::eTransportProtocol_anyOf::
          INVALID_VALUE_OPENAPI_GENERATED;
};

}  // namespace ngkore::model::common
