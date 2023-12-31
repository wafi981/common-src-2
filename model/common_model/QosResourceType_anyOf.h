
#ifndef QosResourceType_anyOf_H_
#define QosResourceType_anyOf_H_

#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class QosResourceType_anyOf {
 public:
  QosResourceType_anyOf();
  virtual ~QosResourceType_anyOf() = default;

  enum class eQosResourceType_anyOf {
    // To have a valid default value.
    // Avoiding name clashes with user defined
    // enum values
    INVALID_VALUE_OPENAPI_GENERATED = 0,
    NON_GBR,
    NON_CRITICAL_GBR,
    CRITICAL_GBR
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

  bool operator==(const QosResourceType_anyOf& rhs) const;
  bool operator!=(const QosResourceType_anyOf& rhs) const;

  /////////////////////////////////////////////
  /// QosResourceType_anyOf members

  QosResourceType_anyOf::eQosResourceType_anyOf getValue() const;
  void setValue(QosResourceType_anyOf::eQosResourceType_anyOf value);

  friend void to_json(nlohmann::json& j, const QosResourceType_anyOf& o);
  friend void from_json(const nlohmann::json& j, QosResourceType_anyOf& o);

 protected:
  QosResourceType_anyOf::eQosResourceType_anyOf m_value =
      QosResourceType_anyOf::eQosResourceType_anyOf::
          INVALID_VALUE_OPENAPI_GENERATED;
};

}  // namespace ngkore::model::common

