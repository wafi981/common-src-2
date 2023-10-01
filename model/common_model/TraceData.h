
#ifndef TraceData_H_
#define TraceData_H_

#include "TraceDepth.h"
#include <string>
#include "Ipv6Addr.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class TraceData {
 public:
  TraceData();
  virtual ~TraceData() = default;

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

  bool operator==(const TraceData& rhs) const;
  bool operator!=(const TraceData& rhs) const;

  /////////////////////////////////////////////
  /// TraceData members

  /// <summary>
  ///
  /// </summary>
  std::string getTraceRef() const;
  void setTraceRef(std::string const& value);
  /// <summary>
  ///
  /// </summary>
  ngkore::model::common::TraceDepth getTraceDepth() const;
  void setTraceDepth(ngkore::model::common::TraceDepth const& value);
  /// <summary>
  ///
  /// </summary>
  std::string getNeTypeList() const;
  void setNeTypeList(std::string const& value);
  /// <summary>
  ///
  /// </summary>
  std::string getEventList() const;
  void setEventList(std::string const& value);
  /// <summary>
  ///
  /// </summary>
  std::string getCollectionEntityIpv4Addr() const;
  void setCollectionEntityIpv4Addr(std::string const& value);
  bool collectionEntityIpv4AddrIsSet() const;
  void unsetCollectionEntityIpv4Addr();
  /// <summary>
  ///
  /// </summary>
  ngkore::model::common::Ipv6Addr getCollectionEntityIpv6Addr() const;
  void setCollectionEntityIpv6Addr(ngkore::model::common::Ipv6Addr const& value);
  bool collectionEntityIpv6AddrIsSet() const;
  void unsetCollectionEntityIpv6Addr();
  /// <summary>
  ///
  /// </summary>
  std::string getInterfaceList() const;
  void setInterfaceList(std::string const& value);
  bool interfaceListIsSet() const;
  void unsetInterfaceList();

  friend void to_json(nlohmann::json& j, const TraceData& o);
  friend void from_json(const nlohmann::json& j, TraceData& o);

 protected:
  std::string m_TraceRef;

  ngkore::model::common::TraceDepth m_TraceDepth;

  std::string m_NeTypeList;

  std::string m_EventList;

  std::string m_CollectionEntityIpv4Addr;
  bool m_CollectionEntityIpv4AddrIsSet;
  ngkore::model::common::Ipv6Addr m_CollectionEntityIpv6Addr;
  bool m_CollectionEntityIpv6AddrIsSet;
  std::string m_InterfaceList;
  bool m_InterfaceListIsSet;
};

}  // namespace ngkore::model::common

