
#ifndef HalTemplate_H_
#define HalTemplate_H_

#include <string>
#include "HttpMethod.h"
#include <vector>
#include "Property.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class HalTemplate {
 public:
  HalTemplate();
  virtual ~HalTemplate() = default;

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

  bool operator==(const HalTemplate& rhs) const;
  bool operator!=(const HalTemplate& rhs) const;

  /////////////////////////////////////////////
  /// HalTemplate members

  /// <summary>
  ///
  /// </summary>
  std::string getTitle() const;
  void setTitle(std::string const& value);
  bool titleIsSet() const;
  void unsetTitle();
  /// <summary>
  ///
  /// </summary>
  ngkore::model::common::HttpMethod getMethod() const;
  void setMethod(ngkore::model::common::HttpMethod const& value);
  /// <summary>
  ///
  /// </summary>
  std::string getContentType() const;
  void setContentType(std::string const& value);
  bool contentTypeIsSet() const;
  void unsetContentType();
  /// <summary>
  ///
  /// </summary>
  std::vector<ngkore::model::common::Property> getProperties() const;
  void setProperties(std::vector<ngkore::model::common::Property> const& value);
  bool propertiesIsSet() const;
  void unsetProperties();

  friend void to_json(nlohmann::json& j, const HalTemplate& o);
  friend void from_json(const nlohmann::json& j, HalTemplate& o);

 protected:
  std::string m_Title;
  bool m_TitleIsSet;
  ngkore::model::common::HttpMethod m_Method;

  std::string m_ContentType;
  bool m_ContentTypeIsSet;
  std::vector<ngkore::model::common::Property> m_Properties;
  bool m_PropertiesIsSet;
};

}  // namespace ngkore::model::common

