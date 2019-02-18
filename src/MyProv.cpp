// -*- C++ -*-
/*!
 * @file  MyProv.cpp
 * @brief ModuleDescription
 * @date $Date$
 *
 * $Id$
 */

#include "MyProv.h"

// Module specification
// <rtc-template block="module_spec">
static const char* myprov_spec[] =
  {
    "implementation_id", "MyProv",
    "type_name",         "MyProv",
    "description",       "ModuleDescription",
    "version",           "1.0.0",
    "vendor",            "VenderName",
    "category",          "Category",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
MyProv::MyProv(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_sv01Port("sv01")

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
MyProv::~MyProv()
{
}



RTC::ReturnCode_t MyProv::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  
  // Set OutPort buffer
  
  // Set service provider to Ports
  m_sv01Port.registerProvider("ssr_ServiceExample", "ssr::ServiceExample", m_service);
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  addPort(m_sv01Port);
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t MyProv::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t MyProv::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t MyProv::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t MyProv::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t MyProv::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t MyProv::onExecute(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t MyProv::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t MyProv::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t MyProv::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t MyProv::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t MyProv::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void MyProvInit(RTC::Manager* manager)
  {
    coil::Properties profile(myprov_spec);
    manager->registerFactory(profile,
                             RTC::Create<MyProv>,
                             RTC::Delete<MyProv>);
  }
  
};


