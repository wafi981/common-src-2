
#ifndef NwdafEvent_H_
#define NwdafEvent_H_

#include <nlohmann/json.hpp>

namespace ngkore::model::nrf {

/// <summary>
/// Possible values are - SLICE_LOAD_LEVEL: Indicates that the event subscribed
/// is load level information of Network Slice - NETWORK_PERFORMANCE: Indicates
/// that the event subscribed is network performance information. - NF_LOAD:
/// Indicates that the event subscribed is load level and status of one or
/// several Network Functions. - SERVICE_EXPERIENCE: Indicates that the event
/// subscribed is service experience. - UE_MOBILITY: Indicates that the event
/// subscribed is UE mobility information. - UE_COMMUNICATION: Indicates that
/// the event subscribed is UE communication information. - QOS_SUSTAINABILITY:
/// Indicates that the event subscribed is QoS sustainability. -
/// ABNORMAL_BEHAVIOUR: Indicates that the event subscribed is abnormal
/// behaviour. - USER_DATA_CONGESTION: Indicates that the event subscribed is
/// user data congestion information. - NSI_LOAD_LEVEL: Indicates that the event
/// subscribed is load level information of Network Slice and the optionally
/// associated Network Slice Instance
/// </summary>
class NwdafEvent {
 public:
  NwdafEvent();
  virtual ~NwdafEvent();

  void validate();

  /////////////////////////////////////////////
  /// NwdafEvent members

  friend void to_json(nlohmann::json& j, const NwdafEvent& o);
  friend void from_json(const nlohmann::json& j, NwdafEvent& o);

 protected:
};

}  // namespace ngkore::model::nrf

