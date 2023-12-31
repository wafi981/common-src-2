
#ifndef RoamingOdb_anyOf_H_
#define RoamingOdb_anyOf_H_

#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class RoamingOdb_anyOf {
 public:
  RoamingOdb_anyOf();
  virtual ~RoamingOdb_anyOf() = default;

  enum class eRoamingOdb_anyOf {
    // To have a valid default value.
    // Avoiding name clashes with user defined
    // enum values
    INVALID_VALUE_OPENAPI_GENERATED = 0,
    PLMN,
    PLMN_COUNTRY
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

  bool operator==(const RoamingOdb_anyOf& rhs) const;
  bool operator!=(const RoamingOdb_anyOf& rhs) const;

  /////////////////////////////////////////////
  /// RoamingOdb_anyOf members

  RoamingOdb_anyOf::eRoamingOdb_anyOf getValue() const;
  void setValue(RoamingOdb_anyOf::eRoamingOdb_anyOf value);

  friend void to_json(nlohmann::json& j, const RoamingOdb_anyOf& o);
  friend void from_json(const nlohmann::json& j, RoamingOdb_anyOf& o);

 protected:
  RoamingOdb_anyOf::eRoamingOdb_anyOf m_value =
      RoamingOdb_anyOf::eRoamingOdb_anyOf::INVALID_VALUE_OPENAPI_GENERATED;
};

}  // namespace ngkore::model::common

