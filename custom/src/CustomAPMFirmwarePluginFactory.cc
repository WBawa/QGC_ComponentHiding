// #pragma once
#include "CustomAPMFirmwarePluginFactory.h"
#include "CustomAPMFirmwarePlugin.h"
#include "APM/ArduCopterFirmwarePlugin.h"
#include "APM/ArduPlaneFirmwarePlugin.h"
#include "APM/ArduRoverFirmwarePlugin.h"
#include "APM/ArduSubFirmwarePlugin.h"

CustomAPMFirmwarePluginFactory CustomFirmwarePluginFactoryImp1;

CustomAPMFirmwarePluginFactory::CustomAPMFirmwarePluginFactory(void)
    : _arduCopterPluginInstance(nullptr)
    , _arduPlanePluginInstance(nullptr)
    , _arduRoverPluginInstance(nullptr)
    , _arduSubPluginInstance(nullptr)
{

}

QList<QGCMAVLink::FirmwareClass_t> CustomAPMFirmwarePluginFactory::supportedFirmwareClasses(void) const
{
    QList<QGCMAVLink::FirmwareClass_t> list;

    list.append(QGCMAVLink::FirmwareClassArduPilot);
    return list;
}

FirmwarePlugin* CustomAPMFirmwarePluginFactory::firmwarePluginForAutopilot(MAV_AUTOPILOT autopilotType, MAV_TYPE vehicleType)
{
    if (autopilotType == MAV_AUTOPILOT_ARDUPILOTMEGA) {
        switch (vehicleType) {
        case MAV_TYPE_QUADROTOR:
        case MAV_TYPE_HEXAROTOR:
        case MAV_TYPE_OCTOROTOR:
        case MAV_TYPE_TRICOPTER:
        case MAV_TYPE_COAXIAL:
        case MAV_TYPE_HELICOPTER:
            if (!_arduCopterPluginInstance) {
                _arduCopterPluginInstance = new ArduCopterFirmwarePlugin;
            }
            return _arduCopterPluginInstance;
        case MAV_TYPE_FIXED_WING:
            if (!_arduPlanePluginInstance) {
                _arduPlanePluginInstance = new ArduPlaneFirmwarePlugin;
            }
            return _arduPlanePluginInstance;
        case MAV_TYPE_GROUND_ROVER:
        case MAV_TYPE_SURFACE_BOAT:
            if (!_arduRoverPluginInstance) {
                _arduRoverPluginInstance = new ArduRoverFirmwarePlugin;
            }
            return _arduRoverPluginInstance;
        case MAV_TYPE_SUBMARINE:
            if (!_arduSubPluginInstance) {
                _arduSubPluginInstance = new ArduSubFirmwarePlugin;
            }
            return _arduSubPluginInstance;
        default:
            break;
        }
    }

    return nullptr;
}
