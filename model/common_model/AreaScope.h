
#ifndef AreaScope_H_
#define AreaScope_H_

#include <string>
#include <map>
#include <vector>
#include "TacInfo.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class AreaScope {
 public:
  AreaScope();
  virtual ~AreaScope() = default;

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

  bool operator==(const AreaScope& rhs) const;
  bool operator!=(const AreaScope& rhs) const;

  /////////////////////////////////////////////
  /// AreaScope members

  /// <summary>
  ///
  /// </summary>
  std::vector<std::string> getEutraCellIdList() const;
  void setEutraCellIdList(std::vector<std::string> const& value);
  bool eutraCellIdListIsSet() const;
  void unsetEutraCellIdList();
  /// <summary>
  ///
  /// </summary>
  std::vector<std::string> getNrCellIdList() const;
  void setNrCellIdList(std::vector<std::string> const& value);
  bool nrCellIdListIsSet() const;
  void unsetNrCellIdList();
  /// <summary>
  ///
  /// </summary>
  std::vector<std::string> getTacList() const;
  void setTacList(std::vector<std::string> const& value);
  bool tacListIsSet() const;
  void unsetTacList();
  /// <summary>
  ///
  /// </summary>
  std::map<std::string, ngkore::model::common::TacInfo> getTacInfoPerPlmn() const;
  void setTacInfoPerPlmn(
      std::map<std::string, ngkore::model::common::TacInfo> const& value);
  bool tacInfoPerPlmnIsSet() const;
  void unsetTacInfoPerPlmn();

  friend void to_json(nlohmann::json& j, const AreaScope& o);
  friend void from_json(const nlohmann::json& j, AreaScope& o);

 protected:
  std::vector<std::string> m_EutraCellIdList;
  bool m_EutraCellIdListIsSet;
  std::vector<std::string> m_NrCellIdList;
  bool m_NrCellIdListIsSet;
  std::vector<std::string> m_TacList;
  bool m_TacListIsSet;
  std::map<std::string, ngkore::model::common::TacInfo> m_TacInfoPerPlmn;
  bool m_TacInfoPerPlmnIsSet;
};

}  // namespace ngkore::model::common

