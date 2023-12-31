
#include "TraceData.h"
#include "Helpers.h"

#include <sstream>

namespace ngkore::model::common {

TraceData::TraceData() {
  m_TraceRef                      = "";
  m_NeTypeList                    = "";
  m_EventList                     = "";
  m_CollectionEntityIpv4Addr      = "";
  m_CollectionEntityIpv4AddrIsSet = false;
  m_CollectionEntityIpv6AddrIsSet = false;
  m_InterfaceList                 = "";
  m_InterfaceListIsSet            = false;
}

void TraceData::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool TraceData::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool TraceData::validate(
  return success;
}

bool TraceData::operator==(const TraceData& rhs) const {
  return

      (getTraceRef() == rhs.getTraceRef()) &&

      (getTraceDepth() == rhs.getTraceDepth()) &&

      (getNeTypeList() == rhs.getNeTypeList()) &&

      (getEventList() == rhs.getEventList()) &&

      ((!collectionEntityIpv4AddrIsSet() &&
        !rhs.collectionEntityIpv4AddrIsSet()) ||
       (collectionEntityIpv4AddrIsSet() &&
        rhs.collectionEntityIpv4AddrIsSet() &&
        getCollectionEntityIpv4Addr() == rhs.getCollectionEntityIpv4Addr())) &&

      ((!collectionEntityIpv6AddrIsSet() &&
        !rhs.collectionEntityIpv6AddrIsSet()) ||
       (collectionEntityIpv6AddrIsSet() &&
        rhs.collectionEntityIpv6AddrIsSet() &&
        getCollectionEntityIpv6Addr() == rhs.getCollectionEntityIpv6Addr())) &&

      ((!interfaceListIsSet() && !rhs.interfaceListIsSet()) ||
       (interfaceListIsSet() && rhs.interfaceListIsSet() &&
        getInterfaceList() == rhs.getInterfaceList()))

          ;
}

bool TraceData::operator!=(const TraceData& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const TraceData& o) {
  j               = nlohmann::json();
  j["traceRef"]   = o.m_TraceRef;
  j["traceDepth"] = o.m_TraceDepth;
  j["neTypeList"] = o.m_NeTypeList;
  j["eventList"]  = o.m_EventList;
  if (o.collectionEntityIpv4AddrIsSet())
    j["collectionEntityIpv4Addr"] = o.m_CollectionEntityIpv4Addr;
  if (o.collectionEntityIpv6AddrIsSet())
    j["collectionEntityIpv6Addr"] = o.m_CollectionEntityIpv6Addr;
  if (o.interfaceListIsSet()) j["interfaceList"] = o.m_InterfaceList;
}

void from_json(const nlohmann::json& j, TraceData& o) {
  j.at("traceRef").get_to(o.m_TraceRef);
  j.at("traceDepth").get_to(o.m_TraceDepth);
  j.at("neTypeList").get_to(o.m_NeTypeList);
  j.at("eventList").get_to(o.m_EventList);
  if (j.find("collectionEntityIpv4Addr") != j.end()) {
    j.at("collectionEntityIpv4Addr").get_to(o.m_CollectionEntityIpv4Addr);
    o.m_CollectionEntityIpv4AddrIsSet = true;
  }
  if (j.find("collectionEntityIpv6Addr") != j.end()) {
    j.at("collectionEntityIpv6Addr").get_to(o.m_CollectionEntityIpv6Addr);
    o.m_CollectionEntityIpv6AddrIsSet = true;
  }
  if (j.find("interfaceList") != j.end()) {
    j.at("interfaceList").get_to(o.m_InterfaceList);
    o.m_InterfaceListIsSet = true;
  }
}

std::string TraceData::getTraceRef() const {
  return m_TraceRef;
}
void TraceData::setTraceRef(std::string const& value) {
  m_TraceRef = value;
}
ngkore::model::common::TraceDepth TraceData::getTraceDepth() const {
  return m_TraceDepth;
}
void TraceData::setTraceDepth(ngkore::model::common::TraceDepth const& value) {
  m_TraceDepth = value;
}
std::string TraceData::getNeTypeList() const {
  return m_NeTypeList;
}
void TraceData::setNeTypeList(std::string const& value) {
  m_NeTypeList = value;
}
std::string TraceData::getEventList() const {
  return m_EventList;
}
void TraceData::setEventList(std::string const& value) {
  m_EventList = value;
}
std::string TraceData::getCollectionEntityIpv4Addr() const {
  return m_CollectionEntityIpv4Addr;
}
void TraceData::setCollectionEntityIpv4Addr(std::string const& value) {
  m_CollectionEntityIpv4Addr      = value;
  m_CollectionEntityIpv4AddrIsSet = true;
}
bool TraceData::collectionEntityIpv4AddrIsSet() const {
  return m_CollectionEntityIpv4AddrIsSet;
}
void TraceData::unsetCollectionEntityIpv4Addr() {
  m_CollectionEntityIpv4AddrIsSet = false;
}
ngkore::model::common::Ipv6Addr TraceData::getCollectionEntityIpv6Addr() const {
  return m_CollectionEntityIpv6Addr;
}
void TraceData::setCollectionEntityIpv6Addr(
    ngkore::model::common::Ipv6Addr const& value) {
  m_CollectionEntityIpv6Addr      = value;
  m_CollectionEntityIpv6AddrIsSet = true;
}
bool TraceData::collectionEntityIpv6AddrIsSet() const {
  return m_CollectionEntityIpv6AddrIsSet;
}
void TraceData::unsetCollectionEntityIpv6Addr() {
  m_CollectionEntityIpv6AddrIsSet = false;
}
std::string TraceData::getInterfaceList() const {
  return m_InterfaceList;
}
void TraceData::setInterfaceList(std::string const& value) {
  m_InterfaceList      = value;
  m_InterfaceListIsSet = true;
}
bool TraceData::interfaceListIsSet() const {
  return m_InterfaceListIsSet;
}
void TraceData::unsetInterfaceList() {
  m_InterfaceListIsSet = false;
}

}  // namespace ngkore::model::common
