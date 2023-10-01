
#ifndef CollectionPeriodRmmLteMdt_anyOf_H_
#define CollectionPeriodRmmLteMdt_anyOf_H_

#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class CollectionPeriodRmmLteMdt_anyOf {
 public:
  CollectionPeriodRmmLteMdt_anyOf();
  virtual ~CollectionPeriodRmmLteMdt_anyOf() = default;

  enum class eCollectionPeriodRmmLteMdt_anyOf {
    // To have a valid default value.
    // Avoiding name clashes with user defined
    // enum values
    INVALID_VALUE_OPENAPI_GENERATED = 0,
    _1024,
    _1280,
    _2048,
    _2560,
    _5120,
    _10240,
    _60000
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

  bool operator==(const CollectionPeriodRmmLteMdt_anyOf& rhs) const;
  bool operator!=(const CollectionPeriodRmmLteMdt_anyOf& rhs) const;

  /////////////////////////////////////////////
  /// CollectionPeriodRmmLteMdt_anyOf members

  CollectionPeriodRmmLteMdt_anyOf::eCollectionPeriodRmmLteMdt_anyOf getValue()
      const;
  void setValue(
      CollectionPeriodRmmLteMdt_anyOf::eCollectionPeriodRmmLteMdt_anyOf value);

  friend void to_json(
      nlohmann::json& j, const CollectionPeriodRmmLteMdt_anyOf& o);
  friend void from_json(
      const nlohmann::json& j, CollectionPeriodRmmLteMdt_anyOf& o);

 protected:
  CollectionPeriodRmmLteMdt_anyOf::eCollectionPeriodRmmLteMdt_anyOf m_value =
      CollectionPeriodRmmLteMdt_anyOf::eCollectionPeriodRmmLteMdt_anyOf::
          INVALID_VALUE_OPENAPI_GENERATED;
};

}  // namespace ngkore::model::common

