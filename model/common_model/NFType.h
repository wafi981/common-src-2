
#ifndef NFType_H_
#define NFType_H_

#include "NFType_anyOf.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
/// NF types known to NRF
/// </summary>
class NFType {
 public:
  NFType();
  virtual ~NFType() = default;

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

  bool operator==(const NFType& rhs) const;
  bool operator!=(const NFType& rhs) const;

  /////////////////////////////////////////////
  /// NFType members

  NFType_anyOf getValue() const;
  void setValue(NFType_anyOf value);
  NFType_anyOf::eNFType_anyOf getEnumValue() const;
  std::string getEnumString() const;
  void setEnumValue(NFType_anyOf::eNFType_anyOf value);
  friend void to_json(nlohmann::json& j, const NFType& o);
  friend void from_json(const nlohmann::json& j, NFType& o);
  friend void to_json(nlohmann::json& j, const NFType_anyOf& o);
  friend void from_json(const nlohmann::json& j, NFType_anyOf& o);

 protected:
  NFType_anyOf m_value;
};

}  // namespace ngkore::model::common

