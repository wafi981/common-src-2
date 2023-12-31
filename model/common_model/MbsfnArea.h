
#ifndef MbsfnArea_H_
#define MbsfnArea_H_

#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class MbsfnArea {
 public:
  MbsfnArea();
  virtual ~MbsfnArea() = default;

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

  bool operator==(const MbsfnArea& rhs) const;
  bool operator!=(const MbsfnArea& rhs) const;

  /////////////////////////////////////////////
  /// MbsfnArea members

  /// <summary>
  ///
  /// </summary>
  int32_t getMbsfnAreaId() const;
  void setMbsfnAreaId(int32_t const value);
  bool mbsfnAreaIdIsSet() const;
  void unsetMbsfnAreaId();
  /// <summary>
  ///
  /// </summary>
  int32_t getCarrierFrequency() const;
  void setCarrierFrequency(int32_t const value);
  bool carrierFrequencyIsSet() const;
  void unsetCarrierFrequency();

  friend void to_json(nlohmann::json& j, const MbsfnArea& o);
  friend void from_json(const nlohmann::json& j, MbsfnArea& o);

 protected:
  int32_t m_MbsfnAreaId;
  bool m_MbsfnAreaIdIsSet;
  int32_t m_CarrierFrequency;
  bool m_CarrierFrequencyIsSet;
};

}  // namespace ngkore::model::common

