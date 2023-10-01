
#ifndef EventId_H_
#define EventId_H_

#include <nlohmann/json.hpp>

namespace ngkore::model::nrf {

/// <summary>
/// Possible values are - LOAD_LEVEL_INFORMATION: Represent the analytics of
/// load level information of corresponding network slice. -
/// NETWORK_PERFORMANCE: Represent the analytics of network performance
/// information. - NF_LOAD: Indicates that the event subscribed is NF Load. -
/// SERVICE_EXPERIENCE: Represent the analytics of service experience
/// information of the specific applications. - UE_MOBILITY: Represent the
/// analytics of UE mobility. - UE_COMMUNICATION: Represent the analytics of UE
/// communication. - QOS_SUSTAINABILITY: Represent the analytics of QoS
/// sustainability information in the certain area.  - ABNORMAL_BEHAVIOUR:
/// Indicates that the event subscribed is abnormal behaviour information. -
/// USER_DATA_CONGESTION: Represent the analytics of the user data congestion in
/// the certain area. - NSI_LOAD_LEVEL: Represent the analytics of Network Slice
/// and the optionally associated Network Slice Instance.
/// </summary>
class EventId {
 public:
  EventId();
  virtual ~EventId();

  void validate();

  /////////////////////////////////////////////
  /// EventId members

  friend void to_json(nlohmann::json& j, const EventId& o);
  friend void from_json(const nlohmann::json& j, EventId& o);

 protected:
};

}  // namespace ngkore::model::nrf

