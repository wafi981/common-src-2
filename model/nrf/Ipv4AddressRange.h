
#ifndef Ipv4AddressRange_H_
#define Ipv4AddressRange_H_

#include <string>
#include <nlohmann/json.hpp>

namespace ngkore::model::nrf {

/// <summary>
/// Range of IPv4 addresses
/// </summary>
class Ipv4AddressRange {
 public:
  Ipv4AddressRange();
  virtual ~Ipv4AddressRange() = default;

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

  bool operator==(const Ipv4AddressRange& rhs) const;
  bool operator!=(const Ipv4AddressRange& rhs) const;

  /////////////////////////////////////////////
  /// Ipv4AddressRange members

  /// <summary>
  ///
  /// </summary>
  std::string getStart() const;
  void setStart(std::string const& value);
  bool startIsSet() const;
  void unsetStart();
  /// <summary>
  ///
  /// </summary>
  std::string getEnd() const;
  void setEnd(std::string const& value);
  bool endIsSet() const;
  void unsetEnd();

  friend void to_json(nlohmann::json& j, const Ipv4AddressRange& o);
  friend void from_json(const nlohmann::json& j, Ipv4AddressRange& o);

 protected:
  std::string m_Start;
  bool m_StartIsSet;
  std::string m_End;
  bool m_EndIsSet;
};

}  // namespace ngkore::model::nrf

