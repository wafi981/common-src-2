
#ifndef DlDataDeliveryStatus_anyOf_H_
#define DlDataDeliveryStatus_anyOf_H_

#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class DlDataDeliveryStatus_anyOf {
 public:
  DlDataDeliveryStatus_anyOf();
  virtual ~DlDataDeliveryStatus_anyOf() = default;

  enum class eDlDataDeliveryStatus_anyOf {
    // To have a valid default value.
    // Avoiding name clashes with user defined
    // enum values
    INVALID_VALUE_OPENAPI_GENERATED = 0,
    BUFFERED,
    TRANSMITTED,
    DISCARDED
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

  bool operator==(const DlDataDeliveryStatus_anyOf& rhs) const;
  bool operator!=(const DlDataDeliveryStatus_anyOf& rhs) const;

  /////////////////////////////////////////////
  /// DlDataDeliveryStatus_anyOf members

  DlDataDeliveryStatus_anyOf::eDlDataDeliveryStatus_anyOf getValue() const;
  void setValue(DlDataDeliveryStatus_anyOf::eDlDataDeliveryStatus_anyOf value);

  friend void to_json(nlohmann::json& j, const DlDataDeliveryStatus_anyOf& o);
  friend void from_json(const nlohmann::json& j, DlDataDeliveryStatus_anyOf& o);

 protected:
  DlDataDeliveryStatus_anyOf::eDlDataDeliveryStatus_anyOf m_value =
      DlDataDeliveryStatus_anyOf::eDlDataDeliveryStatus_anyOf::
          INVALID_VALUE_OPENAPI_GENERATED;
};

}  // namespace ngkore::model::common
