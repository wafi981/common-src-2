
#ifndef MdtConfiguration_H_
#define MdtConfiguration_H_

#include "LoggingDurationNrMdt.h"
#include "MeasurementPeriodLteMdt.h"
#include "ReportingTrigger.h"
#include "PositioningMethodMdt.h"
#include "LoggingIntervalMdt.h"
#include "LoggingIntervalNrMdt.h"
#include "PlmnId.h"
#include "CollectionPeriodRmmNrMdt.h"
#include "JobType.h"
#include <vector>
#include "ReportTypeMdt.h"
#include "SensorMeasurement.h"
#include "ReportIntervalMdt.h"
#include "CollectionPeriodRmmLteMdt.h"
#include "LoggingDurationMdt.h"
#include "MbsfnArea.h"
#include "MeasurementNrForMdt.h"
#include "InterFreqTargetInfo.h"
#include "ReportAmountMdt.h"
#include "EventForMdt.h"
#include "ReportIntervalNrMdt.h"
#include "AreaScope.h"
#include "MeasurementLteForMdt.h"
#include <nlohmann/json.hpp>

namespace ngkore::model::common {

/// <summary>
///
/// </summary>
class MdtConfiguration {
 public:
  MdtConfiguration();
  virtual ~MdtConfiguration() = default;

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

  bool operator==(const MdtConfiguration& rhs) const;
  bool operator!=(const MdtConfiguration& rhs) const;

  /////////////////////////////////////////////
  /// MdtConfiguration members

  /// <summary>
  ///
  /// </summary>
  ngkore::model::common::JobType getJobType() const;
  void setJobType(ngkore::model::common::JobType const& value);
  /// <summary>
  ///
  /// </summary>
  ngkore::model::common::ReportTypeMdt getReportType() const;
  void setReportType(ngkore::model::common::ReportTypeMdt const& value);
  bool reportTypeIsSet() const;
  void unsetReportType();
  /// <summary>
  ///
  /// </summary>
  ngkore::model::common::AreaScope getAreaScope() const;
  void setAreaScope(ngkore::model::common::AreaScope const& value);
  bool areaScopeIsSet() const;
  void unsetAreaScope();
  /// <summary>
  ///
  /// </summary>
  std::vector<ngkore::model::common::MeasurementLteForMdt> getMeasurementLteList()
      const;
  void setMeasurementLteList(
      std::vector<ngkore::model::common::MeasurementLteForMdt> const& value);
  bool measurementLteListIsSet() const;
  void unsetMeasurementLteList();
  /// <summary>
  ///
  /// </summary>
  std::vector<ngkore::model::common::MeasurementNrForMdt> getMeasurementNrList()
      const;
  void setMeasurementNrList(
      std::vector<ngkore::model::common::MeasurementNrForMdt> const& value);
  bool measurementNrListIsSet() const;
  void unsetMeasurementNrList();
  /// <summary>
  ///
  /// </summary>
  std::vector<ngkore::model::common::SensorMeasurement> getSensorMeasurementList()
      const;
  void setSensorMeasurementList(
      std::vector<ngkore::model::common::SensorMeasurement> const& value);
  bool sensorMeasurementListIsSet() const;
  void unsetSensorMeasurementList();
  /// <summary>
  ///
  /// </summary>
  std::vector<ngkore::model::common::ReportingTrigger> getReportingTriggerList()
      const;
  void setReportingTriggerList(
      std::vector<ngkore::model::common::ReportingTrigger> const& value);
  bool reportingTriggerListIsSet() const;
  void unsetReportingTriggerList();
  /// <summary>
  ///
  /// </summary>
  ngkore::model::common::ReportIntervalMdt getReportInterval() const;
  void setReportInterval(ngkore::model::common::ReportIntervalMdt const& value);
  bool reportIntervalIsSet() const;
  void unsetReportInterval();
  /// <summary>
  ///
  /// </summary>
  ngkore::model::common::ReportIntervalNrMdt getReportIntervalNr() const;
  void setReportIntervalNr(
      ngkore::model::common::ReportIntervalNrMdt const& value);
  bool reportIntervalNrIsSet() const;
  void unsetReportIntervalNr();
  /// <summary>
  ///
  /// </summary>
  ngkore::model::common::ReportAmountMdt getReportAmount() const;
  void setReportAmount(ngkore::model::common::ReportAmountMdt const& value);
  bool reportAmountIsSet() const;
  void unsetReportAmount();
  /// <summary>
  ///
  /// </summary>
  int32_t getEventThresholdRsrp() const;
  void setEventThresholdRsrp(int32_t const value);
  bool eventThresholdRsrpIsSet() const;
  void unsetEventThresholdRsrp();
  /// <summary>
  ///
  /// </summary>
  int32_t getEventThresholdRsrpNr() const;
  void setEventThresholdRsrpNr(int32_t const value);
  bool eventThresholdRsrpNrIsSet() const;
  void unsetEventThresholdRsrpNr();
  /// <summary>
  ///
  /// </summary>
  int32_t getEventThresholdRsrq() const;
  void setEventThresholdRsrq(int32_t const value);
  bool eventThresholdRsrqIsSet() const;
  void unsetEventThresholdRsrq();
  /// <summary>
  ///
  /// </summary>
  int32_t getEventThresholdRsrqNr() const;
  void setEventThresholdRsrqNr(int32_t const value);
  bool eventThresholdRsrqNrIsSet() const;
  void unsetEventThresholdRsrqNr();
  /// <summary>
  ///
  /// </summary>
  std::vector<ngkore::model::common::EventForMdt> getEventList() const;
  void setEventList(std::vector<ngkore::model::common::EventForMdt> const& value);
  bool eventListIsSet() const;
  void unsetEventList();
  /// <summary>
  ///
  /// </summary>
  ngkore::model::common::LoggingIntervalMdt getLoggingInterval() const;
  void setLoggingInterval(ngkore::model::common::LoggingIntervalMdt const& value);
  bool loggingIntervalIsSet() const;
  void unsetLoggingInterval();
  /// <summary>
  ///
  /// </summary>
  ngkore::model::common::LoggingIntervalNrMdt getLoggingIntervalNr() const;
  void setLoggingIntervalNr(
      ngkore::model::common::LoggingIntervalNrMdt const& value);
  bool loggingIntervalNrIsSet() const;
  void unsetLoggingIntervalNr();
  /// <summary>
  ///
  /// </summary>
  ngkore::model::common::LoggingDurationMdt getLoggingDuration() const;
  void setLoggingDuration(ngkore::model::common::LoggingDurationMdt const& value);
  bool loggingDurationIsSet() const;
  void unsetLoggingDuration();
  /// <summary>
  ///
  /// </summary>
  ngkore::model::common::LoggingDurationNrMdt getLoggingDurationNr() const;
  void setLoggingDurationNr(
      ngkore::model::common::LoggingDurationNrMdt const& value);
  bool loggingDurationNrIsSet() const;
  void unsetLoggingDurationNr();
  /// <summary>
  ///
  /// </summary>
  ngkore::model::common::PositioningMethodMdt getPositioningMethod() const;
  void setPositioningMethod(
      ngkore::model::common::PositioningMethodMdt const& value);
  bool positioningMethodIsSet() const;
  void unsetPositioningMethod();
  /// <summary>
  ///
  /// </summary>
  std::vector<ngkore::model::common::PositioningMethodMdt>
  getAddPositioningMethodList() const;
  void setAddPositioningMethodList(
      std::vector<ngkore::model::common::PositioningMethodMdt> const& value);
  bool addPositioningMethodListIsSet() const;
  void unsetAddPositioningMethodList();
  /// <summary>
  ///
  /// </summary>
  ngkore::model::common::CollectionPeriodRmmLteMdt getCollectionPeriodRmmLte()
      const;
  void setCollectionPeriodRmmLte(
      ngkore::model::common::CollectionPeriodRmmLteMdt const& value);
  bool collectionPeriodRmmLteIsSet() const;
  void unsetCollectionPeriodRmmLte();
  /// <summary>
  ///
  /// </summary>
  ngkore::model::common::CollectionPeriodRmmNrMdt getCollectionPeriodRmmNr() const;
  void setCollectionPeriodRmmNr(
      ngkore::model::common::CollectionPeriodRmmNrMdt const& value);
  bool collectionPeriodRmmNrIsSet() const;
  void unsetCollectionPeriodRmmNr();
  /// <summary>
  ///
  /// </summary>
  ngkore::model::common::MeasurementPeriodLteMdt getMeasurementPeriodLte() const;
  void setMeasurementPeriodLte(
      ngkore::model::common::MeasurementPeriodLteMdt const& value);
  bool measurementPeriodLteIsSet() const;
  void unsetMeasurementPeriodLte();
  /// <summary>
  ///
  /// </summary>
  std::vector<ngkore::model::common::PlmnId> getMdtAllowedPlmnIdList() const;
  void setMdtAllowedPlmnIdList(
      std::vector<ngkore::model::common::PlmnId> const& value);
  bool mdtAllowedPlmnIdListIsSet() const;
  void unsetMdtAllowedPlmnIdList();
  /// <summary>
  ///
  /// </summary>
  std::vector<ngkore::model::common::MbsfnArea> getMbsfnAreaList() const;
  void setMbsfnAreaList(
      std::vector<ngkore::model::common::MbsfnArea> const& value);
  bool mbsfnAreaListIsSet() const;
  void unsetMbsfnAreaList();
  /// <summary>
  ///
  /// </summary>
  std::vector<ngkore::model::common::InterFreqTargetInfo> getInterFreqTargetList()
      const;
  void setInterFreqTargetList(
      std::vector<ngkore::model::common::InterFreqTargetInfo> const& value);
  bool interFreqTargetListIsSet() const;
  void unsetInterFreqTargetList();

  friend void to_json(nlohmann::json& j, const MdtConfiguration& o);
  friend void from_json(const nlohmann::json& j, MdtConfiguration& o);

 protected:
  ngkore::model::common::JobType m_JobType;

  ngkore::model::common::ReportTypeMdt m_ReportType;
  bool m_ReportTypeIsSet;
  ngkore::model::common::AreaScope m_AreaScope;
  bool m_AreaScopeIsSet;
  std::vector<ngkore::model::common::MeasurementLteForMdt> m_MeasurementLteList;
  bool m_MeasurementLteListIsSet;
  std::vector<ngkore::model::common::MeasurementNrForMdt> m_MeasurementNrList;
  bool m_MeasurementNrListIsSet;
  std::vector<ngkore::model::common::SensorMeasurement> m_SensorMeasurementList;
  bool m_SensorMeasurementListIsSet;
  std::vector<ngkore::model::common::ReportingTrigger> m_ReportingTriggerList;
  bool m_ReportingTriggerListIsSet;
  ngkore::model::common::ReportIntervalMdt m_ReportInterval;
  bool m_ReportIntervalIsSet;
  ngkore::model::common::ReportIntervalNrMdt m_ReportIntervalNr;
  bool m_ReportIntervalNrIsSet;
  ngkore::model::common::ReportAmountMdt m_ReportAmount;
  bool m_ReportAmountIsSet;
  int32_t m_EventThresholdRsrp;
  bool m_EventThresholdRsrpIsSet;
  int32_t m_EventThresholdRsrpNr;
  bool m_EventThresholdRsrpNrIsSet;
  int32_t m_EventThresholdRsrq;
  bool m_EventThresholdRsrqIsSet;
  int32_t m_EventThresholdRsrqNr;
  bool m_EventThresholdRsrqNrIsSet;
  std::vector<ngkore::model::common::EventForMdt> m_EventList;
  bool m_EventListIsSet;
  ngkore::model::common::LoggingIntervalMdt m_LoggingInterval;
  bool m_LoggingIntervalIsSet;
  ngkore::model::common::LoggingIntervalNrMdt m_LoggingIntervalNr;
  bool m_LoggingIntervalNrIsSet;
  ngkore::model::common::LoggingDurationMdt m_LoggingDuration;
  bool m_LoggingDurationIsSet;
  ngkore::model::common::LoggingDurationNrMdt m_LoggingDurationNr;
  bool m_LoggingDurationNrIsSet;
  ngkore::model::common::PositioningMethodMdt m_PositioningMethod;
  bool m_PositioningMethodIsSet;
  std::vector<ngkore::model::common::PositioningMethodMdt>
      m_AddPositioningMethodList;
  bool m_AddPositioningMethodListIsSet;
  ngkore::model::common::CollectionPeriodRmmLteMdt m_CollectionPeriodRmmLte;
  bool m_CollectionPeriodRmmLteIsSet;
  ngkore::model::common::CollectionPeriodRmmNrMdt m_CollectionPeriodRmmNr;
  bool m_CollectionPeriodRmmNrIsSet;
  ngkore::model::common::MeasurementPeriodLteMdt m_MeasurementPeriodLte;
  bool m_MeasurementPeriodLteIsSet;
  std::vector<ngkore::model::common::PlmnId> m_MdtAllowedPlmnIdList;
  bool m_MdtAllowedPlmnIdListIsSet;
  std::vector<ngkore::model::common::MbsfnArea> m_MbsfnAreaList;
  bool m_MbsfnAreaListIsSet;
  std::vector<ngkore::model::common::InterFreqTargetInfo> m_InterFreqTargetList;
  bool m_InterFreqTargetListIsSet;
};

}  // namespace ngkore::model::common

