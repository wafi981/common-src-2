
#ifndef CollectionPeriodRmmNrMdt_H_
#define CollectionPeriodRmmNrMdt_H_

#include "CollectionPeriodRmmNrMdt_anyOf.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class CollectionPeriodRmmNrMdt {
 public:
  CollectionPeriodRmmNrMdt();
  virtual ~CollectionPeriodRmmNrMdt() = default;

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

  bool operator==(const CollectionPeriodRmmNrMdt& rhs) const;
  bool operator!=(const CollectionPeriodRmmNrMdt& rhs) const;

  /////////////////////////////////////////////
  /// CollectionPeriodRmmNrMdt members

  CollectionPeriodRmmNrMdt_anyOf getValue() const;
  void setValue(CollectionPeriodRmmNrMdt_anyOf value);
  CollectionPeriodRmmNrMdt_anyOf::eCollectionPeriodRmmNrMdt_anyOf getEnumValue()
      const;
  void setEnumValue(
      CollectionPeriodRmmNrMdt_anyOf::eCollectionPeriodRmmNrMdt_anyOf value);
  friend void to_json(nlohmann::json& j, const CollectionPeriodRmmNrMdt& o);
  friend void from_json(const nlohmann::json& j, CollectionPeriodRmmNrMdt& o);
  friend void to_json(
      nlohmann::json& j, const CollectionPeriodRmmNrMdt_anyOf& o);
  friend void from_json(
      const nlohmann::json& j, CollectionPeriodRmmNrMdt_anyOf& o);

 protected:
  CollectionPeriodRmmNrMdt_anyOf m_value;
};

}  // namespace ngkore::model::common

