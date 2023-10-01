
#ifndef RatType_anyOf_H_
#define RatType_anyOf_H_

#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class RatType_anyOf {
 public:
  RatType_anyOf();
  virtual ~RatType_anyOf() = default;

  enum class eRatType_anyOf {
    // To have a valid default value.
    // Avoiding name clashes with user defined
    // enum values
    INVALID_VALUE_OPENAPI_GENERATED = 0,
    NR,
    EUTRA,
    WLAN,
    VIRTUAL,
    NBIOT,
    WIRELINE,
    WIRELINE_CABLE,
    WIRELINE_BBF,
    LTE_M,
    NR_U,
    EUTRA_U,
    TRUSTED_N3GA,
    TRUSTED_WLAN,
    UTRA,
    GERA
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

  bool operator==(const RatType_anyOf& rhs) const;
  bool operator!=(const RatType_anyOf& rhs) const;

  /////////////////////////////////////////////
  /// RatType_anyOf members

  RatType_anyOf::eRatType_anyOf getValue() const;
  void setValue(RatType_anyOf::eRatType_anyOf value);

  friend void to_json(nlohmann::json& j, const RatType_anyOf& o);
  friend void from_json(const nlohmann::json& j, RatType_anyOf& o);

 protected:
  RatType_anyOf::eRatType_anyOf m_value =
      RatType_anyOf::eRatType_anyOf::INVALID_VALUE_OPENAPI_GENERATED;
};

}  // namespace ngkore::model::common

