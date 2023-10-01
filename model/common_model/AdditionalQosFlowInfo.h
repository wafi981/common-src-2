
#ifndef AdditionalQosFlowInfo_H_
#define AdditionalQosFlowInfo_H_

#include "NullValue.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class AdditionalQosFlowInfo {
 public:
  AdditionalQosFlowInfo();
  virtual ~AdditionalQosFlowInfo() = default;

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

  bool operator==(const AdditionalQosFlowInfo& rhs) const;
  bool operator!=(const AdditionalQosFlowInfo& rhs) const;

  /////////////////////////////////////////////
  /// AdditionalQosFlowInfo members

  friend void to_json(nlohmann::json& j, const AdditionalQosFlowInfo& o);
  friend void from_json(const nlohmann::json& j, AdditionalQosFlowInfo& o);

 protected:
};

}  // namespace ngkore::model::common

