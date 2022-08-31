// #pragma once
#include "CustomPX4FirmwarePlugin.h"
#include "AccessTypeConfig.cpp"
#include "FirmwarePlugin.h"
#include <iostream>
#include <string>

CustomPX4FirmwarePlugin::CustomPX4FirmwarePlugin() {
    std::cout << "This is being called btw" << std::endl;
    for (int i = 0; i < _flightModeInfoList.count(); i++) {
        FlightModeInfo_t &info = _flightModeInfoList[i];
        if (CURRENT_USER_ACCESS_TYPE == AccessType::Basic || CURRENT_USER_ACCESS_TYPE == AccessType::Expert) {
            if (info.name != _acroFlightMode) {
                info.canBeSet = false;
            }
        }
    }
}

void CustomPX4FirmwarePlugin::updateFlightModes() {
    std::cout << "This is being called btw" << std::endl;
    for (int i = 0; i < _flightModeInfoList.count(); i++) {
        FlightModeInfo_t &info = _flightModeInfoList[i];
        std::cout << info.name->toStdString() << std::endl;
        std::cout << info.canBeSet << std::endl;
        if (CURRENT_USER_ACCESS_TYPE == AccessType::Basic || CURRENT_USER_ACCESS_TYPE == AccessType::Expert) {
//            info.canBeSet = 0;
            if (info.name->compare("Acro")) {
                info.canBeSet = 0;
            }
        }
    }

    modeIndicatorsChanged();
    toolIndicatorsChanged();
}

const QVariantList &
CustomPX4FirmwarePlugin::toolIndicators(const Vehicle *vehicle) {
    std::cout << "is this doing anything at all?" << std::endl;
    if (_toolIndicatorList.size() == 0) {
        _toolIndicatorList = FirmwarePlugin::toolIndicators(vehicle);
        // Then specifically remove the RC RSSI indicator.
        //        _toolIndicatorList.removeOne(QVariant::fromValue(QUrl::fromUserInput("qrc:/toolbar/RCRSSIIndicator.qml")));
    }
    return _toolIndicatorList;
}
