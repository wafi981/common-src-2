
#ifndef Pc5FlowBitRates_H_
#define Pc5FlowBitRates_H_

#include <string>
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class Pc5FlowBitRates {
 public:
  Pc5FlowBitRates();
  virtual ~Pc5FlowBitRates() = default;

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

  bool operator==(const Pc5FlowBitRates& rhs) const;
  bool operator!=(const Pc5FlowBitRates& rhs) const;

  /////////////////////////////////////////////
  /// Pc5FlowBitRates members

  /// <summary>
  ///
  /// </summary>
  std::string getGuaFbr() const;
  void setGuaFbr(std::string const& value);
  bool guaFbrIsSet() const;
  void unsetGuaFbr();
  /// <summary>
  ///
  /// </summary>
  std::string getMaxFbr() const;
  void setMaxFbr(std::string const& value);
  bool maxFbrIsSet() const;
  void unsetMaxFbr();

  friend void to_json(nlohmann::json& j, const Pc5FlowBitRates& o);
  friend void from_json(const nlohmann::json& j, Pc5FlowBitRates& o);

 protected:
  std::string m_GuaFbr;
  bool m_GuaFbrIsSet;
  std::string m_MaxFbr;
  bool m_MaxFbrIsSet;
};

}  // namespace ngkore::model::common

