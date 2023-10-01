
#ifndef EventForMdt_anyOf_H_
#define EventForMdt_anyOf_H_

#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class EventForMdt_anyOf {
 public:
  EventForMdt_anyOf();
  virtual ~EventForMdt_anyOf() = default;

  enum class eEventForMdt_anyOf {
    // To have a valid default value.
    // Avoiding name clashes with user defined
    // enum values
    INVALID_VALUE_OPENAPI_GENERATED = 0,
    OUT_OF_COVERAG,
    A2_EVENT
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

  bool operator==(const EventForMdt_anyOf& rhs) const;
  bool operator!=(const EventForMdt_anyOf& rhs) const;

  /////////////////////////////////////////////
  /// EventForMdt_anyOf members

  EventForMdt_anyOf::eEventForMdt_anyOf getValue() const;
  void setValue(EventForMdt_anyOf::eEventForMdt_anyOf value);

  friend void to_json(nlohmann::json& j, const EventForMdt_anyOf& o);
  friend void from_json(const nlohmann::json& j, EventForMdt_anyOf& o);

 protected:
  EventForMdt_anyOf::eEventForMdt_anyOf m_value =
      EventForMdt_anyOf::eEventForMdt_anyOf::INVALID_VALUE_OPENAPI_GENERATED;
};

}  // namespace ngkore::model::common

