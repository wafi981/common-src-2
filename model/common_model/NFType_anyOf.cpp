
#include "NFType_anyOf.h"
#include "Helpers.h"
#include <stdexcept>
#include <sstream>

namespace ngkore::model::common {

NFType_anyOf::NFType_anyOf() {}

void NFType_anyOf::validate() const {
  std::stringstream msg;
  if (!validate(msg)) {
    throw ngkore::model::common::helpers::ValidationException(msg.str());
  }
}

bool NFType_anyOf::validate(std::stringstream& msg) const {
  return validate(msg, "");
}

bool NFType_anyOf::validate(
    std::stringstream& msg, const std::string& pathPrefix) const {
  bool success = true;
  const std::string _pathPrefix =
      pathPrefix.empty() ? "NFType_anyOf" : pathPrefix;

  if (m_value == NFType_anyOf::eNFType_anyOf::INVALID_VALUE_OPENAPI_GENERATED) {
    success = false;
    msg << _pathPrefix << ": has no value;";
  }

  return success;
}

bool NFType_anyOf::operator==(const NFType_anyOf& rhs) const {
  return getValue() == rhs.getValue()

      ;
}

bool NFType_anyOf::operator!=(const NFType_anyOf& rhs) const {
  return !(*this == rhs);
}

void to_json(nlohmann::json& j, const NFType_anyOf& o) {
  j = nlohmann::json();

  switch (o.getValue()) {
    case NFType_anyOf::eNFType_anyOf::INVALID_VALUE_OPENAPI_GENERATED:
      j = "INVALID_VALUE_OPENAPI_GENERATED";
      break;
    case NFType_anyOf::eNFType_anyOf::NRF:
      j = "NRF";
      break;
    case NFType_anyOf::eNFType_anyOf::UDM:
      j = "UDM";
      break;
    case NFType_anyOf::eNFType_anyOf::AMF:
      j = "AMF";
      break;
    case NFType_anyOf::eNFType_anyOf::SMF:
      j = "SMF";
      break;
    case NFType_anyOf::eNFType_anyOf::AUSF:
      j = "AUSF";
      break;
    case NFType_anyOf::eNFType_anyOf::NEF:
      j = "NEF";
      break;
    case NFType_anyOf::eNFType_anyOf::PCF:
      j = "PCF";
      break;
    case NFType_anyOf::eNFType_anyOf::SMSF:
      j = "SMSF";
      break;
    case NFType_anyOf::eNFType_anyOf::NSSF:
      j = "NSSF";
      break;
    case NFType_anyOf::eNFType_anyOf::UDR:
      j = "UDR";
      break;
    case NFType_anyOf::eNFType_anyOf::LMF:
      j = "LMF";
      break;
    case NFType_anyOf::eNFType_anyOf::GMLC:
      j = "GMLC";
      break;
    case NFType_anyOf::eNFType_anyOf::_5G_EIR:
      j = "5G_EIR";
      break;
    case NFType_anyOf::eNFType_anyOf::SEPP:
      j = "SEPP";
      break;
    case NFType_anyOf::eNFType_anyOf::UPF:
      j = "UPF";
      break;
    case NFType_anyOf::eNFType_anyOf::N3IWF:
      j = "N3IWF";
      break;
    case NFType_anyOf::eNFType_anyOf::AF:
      j = "AF";
      break;
    case NFType_anyOf::eNFType_anyOf::UDSF:
      j = "UDSF";
      break;
    case NFType_anyOf::eNFType_anyOf::BSF:
      j = "BSF";
      break;
    case NFType_anyOf::eNFType_anyOf::CHF:
      j = "CHF";
      break;
    case NFType_anyOf::eNFType_anyOf::NWDAF:
      j = "NWDAF";
      break;
    case NFType_anyOf::eNFType_anyOf::PCSCF:
      j = "PCSCF";
      break;
    case NFType_anyOf::eNFType_anyOf::CBCF:
      j = "CBCF";
      break;
    case NFType_anyOf::eNFType_anyOf::HSS:
      j = "HSS";
      break;
    case NFType_anyOf::eNFType_anyOf::UCMF:
      j = "UCMF";
      break;
    case NFType_anyOf::eNFType_anyOf::SOR_AF:
      j = "SOR_AF";
      break;
    case NFType_anyOf::eNFType_anyOf::SPAF:
      j = "SPAF";
      break;
    case NFType_anyOf::eNFType_anyOf::MME:
      j = "MME";
      break;
    case NFType_anyOf::eNFType_anyOf::SCSAS:
      j = "SCSAS";
      break;
    case NFType_anyOf::eNFType_anyOf::SCEF:
      j = "SCEF";
      break;
    case NFType_anyOf::eNFType_anyOf::SCP:
      j = "SCP";
      break;
    case NFType_anyOf::eNFType_anyOf::NSSAAF:
      j = "NSSAAF";
      break;
    case NFType_anyOf::eNFType_anyOf::ICSCF:
      j = "ICSCF";
      break;
    case NFType_anyOf::eNFType_anyOf::SCSCF:
      j = "SCSCF";
      break;
    case NFType_anyOf::eNFType_anyOf::DRA:
      j = "DRA";
      break;
    case NFType_anyOf::eNFType_anyOf::IMS_AS:
      j = "IMS_AS";
      break;
    case NFType_anyOf::eNFType_anyOf::CEF:
      j = "CEF";
      break;
  }
}

void from_json(const nlohmann::json& j, NFType_anyOf& o) {
  auto s = j.get<std::string>();
  if (s == "NRF") {
    o.setValue(NFType_anyOf::eNFType_anyOf::NRF);
  } else if (s == "UDM") {
    o.setValue(NFType_anyOf::eNFType_anyOf::UDM);
  } else if (s == "AMF") {
    o.setValue(NFType_anyOf::eNFType_anyOf::AMF);
  } else if (s == "SMF") {
    o.setValue(NFType_anyOf::eNFType_anyOf::SMF);
  } else if (s == "AUSF") {
    o.setValue(NFType_anyOf::eNFType_anyOf::AUSF);
  } else if (s == "NEF") {
    o.setValue(NFType_anyOf::eNFType_anyOf::NEF);
  } else if (s == "PCF") {
    o.setValue(NFType_anyOf::eNFType_anyOf::PCF);
  } else if (s == "SMSF") {
    o.setValue(NFType_anyOf::eNFType_anyOf::SMSF);
  } else if (s == "NSSF") {
    o.setValue(NFType_anyOf::eNFType_anyOf::NSSF);
  } else if (s == "UDR") {
    o.setValue(NFType_anyOf::eNFType_anyOf::UDR);
  } else if (s == "LMF") {
    o.setValue(NFType_anyOf::eNFType_anyOf::LMF);
  } else if (s == "GMLC") {
    o.setValue(NFType_anyOf::eNFType_anyOf::GMLC);
  } else if (s == "5G_EIR") {
    o.setValue(NFType_anyOf::eNFType_anyOf::_5G_EIR);
  } else if (s == "SEPP") {
    o.setValue(NFType_anyOf::eNFType_anyOf::SEPP);
  } else if (s == "UPF") {
    o.setValue(NFType_anyOf::eNFType_anyOf::UPF);
  } else if (s == "N3IWF") {
    o.setValue(NFType_anyOf::eNFType_anyOf::N3IWF);
  } else if (s == "AF") {
    o.setValue(NFType_anyOf::eNFType_anyOf::AF);
  } else if (s == "UDSF") {
    o.setValue(NFType_anyOf::eNFType_anyOf::UDSF);
  } else if (s == "BSF") {
    o.setValue(NFType_anyOf::eNFType_anyOf::BSF);
  } else if (s == "CHF") {
    o.setValue(NFType_anyOf::eNFType_anyOf::CHF);
  } else if (s == "NWDAF") {
    o.setValue(NFType_anyOf::eNFType_anyOf::NWDAF);
  } else if (s == "PCSCF") {
    o.setValue(NFType_anyOf::eNFType_anyOf::PCSCF);
  } else if (s == "CBCF") {
    o.setValue(NFType_anyOf::eNFType_anyOf::CBCF);
  } else if (s == "HSS") {
    o.setValue(NFType_anyOf::eNFType_anyOf::HSS);
  } else if (s == "UCMF") {
    o.setValue(NFType_anyOf::eNFType_anyOf::UCMF);
  } else if (s == "SOR_AF") {
    o.setValue(NFType_anyOf::eNFType_anyOf::SOR_AF);
  } else if (s == "SPAF") {
    o.setValue(NFType_anyOf::eNFType_anyOf::SPAF);
  } else if (s == "MME") {
    o.setValue(NFType_anyOf::eNFType_anyOf::MME);
  } else if (s == "SCSAS") {
    o.setValue(NFType_anyOf::eNFType_anyOf::SCSAS);
  } else if (s == "SCEF") {
    o.setValue(NFType_anyOf::eNFType_anyOf::SCEF);
  } else if (s == "SCP") {
    o.setValue(NFType_anyOf::eNFType_anyOf::SCP);
  } else if (s == "NSSAAF") {
    o.setValue(NFType_anyOf::eNFType_anyOf::NSSAAF);
  } else if (s == "ICSCF") {
    o.setValue(NFType_anyOf::eNFType_anyOf::ICSCF);
  } else if (s == "SCSCF") {
    o.setValue(NFType_anyOf::eNFType_anyOf::SCSCF);
  } else if (s == "DRA") {
    o.setValue(NFType_anyOf::eNFType_anyOf::DRA);
  } else if (s == "IMS_AS") {
    o.setValue(NFType_anyOf::eNFType_anyOf::IMS_AS);
  } else if (s == "CEF") {
    o.setValue(NFType_anyOf::eNFType_anyOf::CEF);
  } else {
    std::stringstream ss;
    ss << "Unexpected value " << s << " in json"
       << " cannot be converted to enum of type"
       << " NFType_anyOf::eNFType_anyOf";
    throw std::invalid_argument(ss.str());
  }
}

NFType_anyOf::eNFType_anyOf NFType_anyOf::getValue() const {
  return m_value;
}
void NFType_anyOf::setValue(NFType_anyOf::eNFType_anyOf value) {
  m_value = value;
}

}  // namespace ngkore::model::common
