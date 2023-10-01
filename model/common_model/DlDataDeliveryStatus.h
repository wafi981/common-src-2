
#ifndef DlDataDeliveryStatus_H_
#define DlDataDeliveryStatus_H_

#include "DlDataDeliveryStatus_anyOf.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
/// Possible values are - BUFFERED: The first downlink data is buffered with
/// extended buffering matching the source of the downlink traffic. -
/// TRANSMITTED: The first downlink data matching the source of the downlink
/// traffic is transmitted after previous buffering or discarding of
/// corresponding packet(s) because the UE of the PDU Session becomes ACTIVE,
/// and buffered data can be delivered to UE. - DISCARDED: The first downlink
/// data matching the source of the downlink traffic is discarded because the
/// Extended Buffering time, as determined by the SMF, expires or the amount of
/// downlink data to be buffered is exceeded.
/// </summary>
class DlDataDeliveryStatus {
 public:
  DlDataDeliveryStatus();
  virtual ~DlDataDeliveryStatus() = default;

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
  virtual bool validate(
      std::stringstream& msg, const std::string& pathPrefix) const;

  bool operator==(const DlDataDeliveryStatus& rhs) const;
  bool operator!=(const DlDataDeliveryStatus& rhs) const;

  /////////////////////////////////////////////
  /// DlDataDeliveryStatus members

  DlDataDeliveryStatus_anyOf getValue() const;
  void setValue(DlDataDeliveryStatus_anyOf value);
  DlDataDeliveryStatus_anyOf::eDlDataDeliveryStatus_anyOf getEnumValue() const;
  void setEnumValue(
      DlDataDeliveryStatus_anyOf::eDlDataDeliveryStatus_anyOf value);
  friend void to_json(nlohmann::json& j, const DlDataDeliveryStatus& o);
  friend void from_json(const nlohmann::json& j, DlDataDeliveryStatus& o);
  friend void to_json(nlohmann::json& j, const DlDataDeliveryStatus_anyOf& o);
  friend void from_json(const nlohmann::json& j, DlDataDeliveryStatus_anyOf& o);

 protected:
  DlDataDeliveryStatus_anyOf m_value;
};

}  // namespace ngkore::model::common

