
#ifndef CollectionPeriodRmmNrMdt_anyOf_H_
#define CollectionPeriodRmmNrMdt_anyOf_H_

#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class CollectionPeriodRmmNrMdt_anyOf {
 public:
  CollectionPeriodRmmNrMdt_anyOf();
  virtual ~CollectionPeriodRmmNrMdt_anyOf() = default;

  enum class eCollectionPeriodRmmNrMdt_anyOf {
    // To have a valid default value.
    // Avoiding name clashes with user defined
    // enum values
    INVALID_VALUE_OPENAPI_GENERATED = 0,
    _1024,
    _2048,
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

  bool operator==(const CollectionPeriodRmmNrMdt_anyOf& rhs) const;
  bool operator!=(const CollectionPeriodRmmNrMdt_anyOf& rhs) const;

  /////////////////////////////////////////////
  /// CollectionPeriodRmmNrMdt_anyOf members

  CollectionPeriodRmmNrMdt_anyOf::eCollectionPeriodRmmNrMdt_anyOf getValue()
      const;
  void setValue(
      CollectionPeriodRmmNrMdt_anyOf::eCollectionPeriodRmmNrMdt_anyOf value);

  friend void to_json(
      nlohmann::json& j, const CollectionPeriodRmmNrMdt_anyOf& o);
  friend void from_json(
      const nlohmann::json& j, CollectionPeriodRmmNrMdt_anyOf& o);

 protected:
  CollectionPeriodRmmNrMdt_anyOf::eCollectionPeriodRmmNrMdt_anyOf m_value =
      CollectionPeriodRmmNrMdt_anyOf::eCollectionPeriodRmmNrMdt_anyOf::
          INVALID_VALUE_OPENAPI_GENERATED;
};

}  // namespace ngkore::model::common

