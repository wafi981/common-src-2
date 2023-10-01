
#ifndef ServiceName_H_
#define ServiceName_H_

#include <nlohmann/json.hpp>

namespace ngkore::model::nrf {

/// <summary>
///
/// </summary>
class ServiceName {
 public:
  ServiceName();
  virtual ~ServiceName();

  void validate();

  /////////////////////////////////////////////
  /// ServiceName members

  friend void to_json(nlohmann::json& j, const ServiceName& o);
  friend void from_json(const nlohmann::json& j, ServiceName& o);

 protected:
};

}  // namespace ngkore::model::nrf

