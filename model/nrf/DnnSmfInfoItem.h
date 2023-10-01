
#ifndef DnnSmfInfoItem_H_
#define DnnSmfInfoItem_H_

#include <string>
#include <nlohmann/json.hpp>

namespace ngkore::model::nrf {

/// <summary>
/// Set of parameters supported by SMF for a given DNN
/// </summary>
class DnnSmfInfoItem {
 public:
  DnnSmfInfoItem();
  virtual ~DnnSmfInfoItem() = default;

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

  bool operator==(const DnnSmfInfoItem& rhs) const;
  bool operator!=(const DnnSmfInfoItem& rhs) const;

  /////////////////////////////////////////////
  /// DnnSmfInfoItem members

  /// <summary>
  ///
  /// </summary>
  std::string getDnn() const;
  void setDnn(std::string const& value);

  friend void to_json(nlohmann::json& j, const DnnSmfInfoItem& o);
  friend void from_json(const nlohmann::json& j, DnnSmfInfoItem& o);

  [[nodiscard]] std::string to_string(int indent_level) const;

 protected:
  std::string m_Dnn;
};

}  // namespace ngkore::model::nrf

