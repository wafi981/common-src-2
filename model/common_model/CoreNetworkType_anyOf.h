
#ifndef CoreNetworkType_anyOf_H_
#define CoreNetworkType_anyOf_H_

#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class CoreNetworkType_anyOf {
 public:
  CoreNetworkType_anyOf();
  virtual ~CoreNetworkType_anyOf() = default;

  enum class eCoreNetworkType_anyOf {
    // To have a valid default value.
    // Avoiding name clashes with user defined
    // enum values
    INVALID_VALUE_OPENAPI_GENERATED = 0,
    _5GC,
    EPC
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

  bool operator==(const CoreNetworkType_anyOf& rhs) const;
  bool operator!=(const CoreNetworkType_anyOf& rhs) const;

  /////////////////////////////////////////////
  /// CoreNetworkType_anyOf members

  CoreNetworkType_anyOf::eCoreNetworkType_anyOf getValue() const;
  void setValue(CoreNetworkType_anyOf::eCoreNetworkType_anyOf value);

  friend void to_json(nlohmann::json& j, const CoreNetworkType_anyOf& o);
  friend void from_json(const nlohmann::json& j, CoreNetworkType_anyOf& o);

 protected:
  CoreNetworkType_anyOf::eCoreNetworkType_anyOf m_value =
      CoreNetworkType_anyOf::eCoreNetworkType_anyOf::
          INVALID_VALUE_OPENAPI_GENERATED;
};

}  // namespace ngkore::model::common

