
#ifndef LineTypeRm_H_
#define LineTypeRm_H_

#include "LineType.h"
#include "NullValue.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class LineTypeRm : public LineType {
 public:
  LineTypeRm();
  virtual ~LineTypeRm() = default;

  /// <summary>
  /// Helper overload for validate. Used when one model stores another model and
  /// calls it's validate. Not meant to be called outside that case.
  /// </summary>
  bool validate(
      std::stringstream& msg, const std::string& pathPrefix) const override;
  /////////////////////////////////////////////
  /// LineTypeRm members

  friend void to_json(nlohmann::json& j, const LineTypeRm& o);
  friend void from_json(const nlohmann::json& j, LineTypeRm& o);

 protected:
};

}  // namespace ngkore::model::common

