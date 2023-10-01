
#ifndef Snssai_H_
#define Snssai_H_

#include <string>
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

const std::string SD_VALIDATION_REGEX = "^[A-Fa-f0-9]{6}$";
const std::string SD_DEFAULT_VALUE    = "FFFFFF";

/// <summary>
///
/// </summary>
class Snssai {
 public:
  Snssai();
  Snssai(const int32_t& sst) : m_Sst(sst) {
    m_Sd      = "ffffff";
    m_SdIsSet = true;
  };
  virtual ~Snssai() = default;

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

  bool operator==(const Snssai& rhs) const;
  bool operator!=(const Snssai& rhs) const;

  /////////////////////////////////////////////
  /// Snssai members

  /// <summary>
  ///
  /// </summary>
  int32_t getSst() const;
  void setSst(int32_t const value);
  /// <summary>
  ///
  /// </summary>
  std::string getSd() const;
  int32_t getSdInt() const;
  void setSd(std::string const& value);
  bool sdIsSet() const;
  void unsetSd();

  friend void to_json(nlohmann::json& j, const Snssai& o);
  friend void from_json(const nlohmann::json& j, Snssai& o);

  [[nodiscard]] std::string to_string(int indent_level) const;

 protected:
  int32_t m_Sst;

  std::string m_Sd;
  bool m_SdIsSet;
};

}  // namespace ngkore::model::common

