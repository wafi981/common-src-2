
#ifndef ExtSnssai_H_
#define ExtSnssai_H_

#include "SdRange.h"
#include "SnssaiExtension.h"
#include <string>
#include "Snssai.h"
#include <vector>
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class ExtSnssai {
 public:
  ExtSnssai();
  virtual ~ExtSnssai() = default;

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

  bool operator==(const ExtSnssai& rhs) const;
  bool operator!=(const ExtSnssai& rhs) const;

  /////////////////////////////////////////////
  /// ExtSnssai members

  /// <summary>
  ///
  /// </summary>
  int32_t getSst() const;
  void setSst(int32_t const value);
  /// <summary>
  ///
  /// </summary>
  std::string getSd() const;
  void setSd(std::string const& value);
  bool sdIsSet() const;
  void unsetSd();
  /// <summary>
  /// When present, it shall contain the range(s) of Slice Differentiator values
  /// supported for the Slice/Service Type value indicated in the sst attribute
  /// of the Snssai data type
  /// </summary>
  std::vector<ngkore::model::common::SdRange> getSdRanges() const;
  void setSdRanges(std::vector<ngkore::model::common::SdRange> const& value);
  bool sdRangesIsSet() const;
  void unsetSdRanges();
  /// <summary>
  /// When present, it shall be set to true, to indicate that all SD values are
  /// supported for the Slice/Service Type value indicated in the sst attribute
  /// of the Snssai data type
  /// </summary>
  bool isWildcardSd() const;
  void setWildcardSd(bool const value);
  bool wildcardSdIsSet() const;
  void unsetWildcardSd();

  friend void to_json(nlohmann::json& j, const ExtSnssai& o);
  friend void from_json(const nlohmann::json& j, ExtSnssai& o);

 protected:
  int32_t m_Sst;

  std::string m_Sd;
  bool m_SdIsSet;
  std::vector<ngkore::model::common::SdRange> m_SdRanges;
  bool m_SdRangesIsSet;
  bool m_WildcardSd;
  bool m_WildcardSdIsSet;
};

}  // namespace ngkore::model::common

