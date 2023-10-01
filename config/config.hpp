

#pragma once

#include "config_types.hpp"
#include "logger_base.hpp"

#include <string>
#include <map>
#include <memory>
#include <shared_mutex>
#include <unordered_set>

namespace ngkore::config {

const int COLUMN_WIDTH           = 45;
const int INDENT_WIDTH           = 2;
const std::string BASE_FORMATTER = "{} {:.<{}}: {}\n";
const std::string LOGGER_NAME    = "config ";

// common validator REGEX

const std::string LOG_LVL_VALIDATOR_REGEX = "debug|info|warning|error|off";
const std::string IPV4_ADDRESS_VALIDATOR_REGEX =
    "^((25[0-5]|(2[0-4]|1\\d|[1-9]|)\\d)\\.?\\b){4}$";
const std::string IPV6_ADDRESS_VALIDATOR_REGEX = ".*";  // TODO
const std::string HOSTNAME_VALIDATOR_REGEX =
    "^([a-zA-Z0-9]|[a-zA-Z0-9][a-zA-Z0-9\\-]{0,61}[a-zA-Z0-9])(\\.([a-zA-Z0-9]|"
    "[a-zA-Z0-9][a-zA-Z0-9\\-]{0,61}[a-zA-Z0-9]))*$";
const std::string API_VERSION_REGEX = "v1|v2";
const std::string HOST_VALIDATOR_REGEX =
    IPV4_ADDRESS_VALIDATOR_REGEX + "|" + HOSTNAME_VALIDATOR_REGEX;
const std::string PDU_SESSION_TYPE_REGEX = "IPV4|IPV6|IPV4V6";

const uint16_t PORT_MIN_VALUE = 1;
const uint16_t PORT_MAX_VALUE = 65535;

const std::string PCF_CONFIG_NAME  = "pcf";
const std::string NRF_CONFIG_NAME  = "nrf";
const std::string SMF_CONFIG_NAME  = "smf";
const std::string UPF_CONFIG_NAME  = "upf";
const std::string AMF_CONFIG_NAME  = "amf";
const std::string UDM_CONFIG_NAME  = "udm";
const std::string UDR_CONFIG_NAME  = "udr";
const std::string NSSF_CONFIG_NAME = "nssf";
const std::string AUSF_CONFIG_NAME = "ausf";

const std::string LOG_LEVEL_CONFIG_NAME   = "log_level";
const std::string REGISTER_NF_CONFIG_NAME = "register_nf";
const std::string NF_LIST_CONFIG_NAME     = "nfs";

// NF
constexpr auto NF_CONFIG_HOST_NAME       = "host";
constexpr auto NF_CONFIG_HOST_NAME_LABEL = "Host";

// Database (AMF/UDR): should be moved to UDR when we drop minimal deployment
// scenario (only AMF/SMF/UPF)
constexpr auto DATABASE_CONFIG                          = "database";
constexpr auto DATABASE_CONFIG_LABEL                    = "Database";
constexpr auto DATABASE_CONFIG_USER                     = "user";
constexpr auto DATABASE_CONFIG_USER_LABEL               = "User";
constexpr auto DATABASE_CONFIG_PASSWORD                 = "password";
constexpr auto DATABASE_CONFIG_PASSWORD_LABEL           = "Password";
constexpr auto DATABASE_CONFIG_DATABASE_NAME            = "database_name";
constexpr auto DATABASE_CONFIG_DATABASE_NAME_LABEL      = "Database Name";
constexpr auto DATABASE_CONFIG_DATABASE_TYPE            = "type";
constexpr auto DATABASE_CONFIG_DATABASE_TYPE_LABEL      = "Database Type";
constexpr auto DATABASE_CONFIG_RANDOM                   = "generate_random";
constexpr auto DATABASE_CONFIG_RANDOM_LABEL             = "Generate Random";
constexpr auto DATABASE_CONFIG_CONNECTION_TIMEOUT       = "connection_timeout";
constexpr auto DATABASE_CONFIG_CONNECTION_TIMEOUT_LABEL = "Connection Timeout";

// DNN (SMF/UPF)
const std::string DNNS_CONFIG_NAME = "dnns";

// HTTP Version
constexpr auto NF_CONFIG_HTTP_NAME  = "http_version";
constexpr auto NF_CONFIG_HTTP_LABEL = "HTTP Version";

static std::string get_value_formatter(int level) {
  // TODO use this function everywhere, it is much simpler
  int indent_width        = level * INDENT_WIDTH;
  std::string base_indent = fmt::format("{:<{}}", "", indent_width);
  std::string indent_char =
      (level) % 2 == 0 ? INNER_LIST_ELEM : OUTER_LIST_ELEM;

  unsigned int inner_width = COLUMN_WIDTH;
  if (base_indent.length() < COLUMN_WIDTH) {
    inner_width = COLUMN_WIDTH - base_indent.length();
  }
  return base_indent + indent_char + " {:.<" + std::to_string(inner_width) +
         "}: {}\n";
}

static std::string get_title_formatter(int level) {
  int indent_width        = level * INDENT_WIDTH;
  std::string base_indent = fmt::format("{:<{}}", "", indent_width);
  std::string indent_char =
      (level) % 2 == 0 ? INNER_LIST_ELEM : OUTER_LIST_ELEM;
  return base_indent + indent_char + " {}\n";
}

class config_iface {
 public:
  [[nodiscard]] virtual bool validate() = 0;

  [[nodiscard]] virtual std::string to_string() const = 0;

  virtual void display() const = 0;

  virtual ~config_iface() = default;

  [[nodiscard]] virtual bool register_nrf() const = 0;

  [[nodiscard]] virtual const std::string& log_level() const = 0;

  [[nodiscard]] virtual const nf& local() const = 0;

  [[nodiscard]] virtual std::shared_ptr<nf> get_local() const = 0;
  [[nodiscard]] virtual std::shared_ptr<nf> get_nf(
      const std::string& nf_name) const = 0;

  [[nodiscard]] virtual const std::vector<dnn_config>& get_dnns() const = 0;
  [[nodiscard]] virtual database_config& get_database_config()          = 0;
  [[nodiscard]] virtual int get_http_version() const                    = 0;

  virtual bool init() = 0;
};

class config : public config_iface {
  // friend class yaml_file;

 public:
  explicit config(
      const std::string& config_path, const std::string& nf_name,
      bool log_stdout, bool log_rot_file);

  [[nodiscard]] bool validate() override;

  [[nodiscard]] std::string to_string() const override;

  [[nodiscard]] bool register_nrf() const override;

  [[nodiscard]] const std::string& log_level() const override;

  [[nodiscard]] const nf& local() const override;
  [[nodiscard]] std::shared_ptr<nf> get_local() const override;
  [[nodiscard]] std::shared_ptr<nf> get_nf(
      const std::string& nf_name) const override;

  [[nodiscard]] database_config& get_database_config() override;
  [[nodiscard]] const std::vector<dnn_config>& get_dnns() const override;

  [[nodiscard]] int get_http_version() const override;

  bool init() override;

  void display() const override;

  void read_from_file(const std::string& file_path);
  void to_json(nlohmann::json& json_data);
  bool from_json(const nlohmann::json& json_data);

 protected:
  // to define for each NF which values are used
  std::unordered_set<std::string> m_used_config_values;
  std::unordered_set<std::string> m_used_sbi_values;
  std::string m_nf_name;
  std::vector<dnn_config> m_dnns;
  nf_features_config m_register_nrf_feature;

  virtual void update_used_nfs();
  bool add_nf(const std::string& name, const std::shared_ptr<nf>& nf_ptr);

 private:
  std::string m_config_path;

  nf_features_config m_log_level_feature;
  nf_http_version m_http_version;

  std::shared_ptr<nf> m_local_nf;

  database_config m_database;

  std::unordered_map<std::string, std::shared_ptr<nf>> m_nf_map;

  mutable std::shared_mutex m_config_mutex;

  static bool safe_validate_field(config_type& config);
};

}  // namespace ngkore::config
