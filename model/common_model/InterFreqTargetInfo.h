
#ifndef InterFreqTargetInfo_H_
#define InterFreqTargetInfo_H_

#include <vector>
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class InterFreqTargetInfo {
 public:
  InterFreqTargetInfo();
  virtual ~InterFreqTargetInfo() = default;

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

  bool operator==(const InterFreqTargetInfo& rhs) const;
  bool operator!=(const InterFreqTargetInfo& rhs) const;

  /////////////////////////////////////////////
  /// InterFreqTargetInfo members

  /// <summary>
  ///
  /// </summary>
  int32_t getDlCarrierFreq() const;
  void setDlCarrierFreq(int32_t const value);
  /// <summary>
  ///
  /// </summary>
  std::vector<int32_t> getCellIdList() const;
  void setCellIdList(std::vector<int32_t> const value);
  bool cellIdListIsSet() const;
  void unsetCellIdList();

  friend void to_json(nlohmann::json& j, const InterFreqTargetInfo& o);
  friend void from_json(const nlohmann::json& j, InterFreqTargetInfo& o);

 protected:
  int32_t m_DlCarrierFreq;

  std::vector<int32_t> m_CellIdList;
  bool m_CellIdListIsSet;
};

}  // namespace ngkore::model::common

