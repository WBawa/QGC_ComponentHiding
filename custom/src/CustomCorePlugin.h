#pragma once

#ifndef CUSTOMCOREPLUGIN_H
#define CUSTOMCOREPLUGIN_H

#include "AccessType.h"
#include "QGCCorePlugin.h"
#include <string>
#include <CustomPX4FirmwarePlugin.h>

class CustomCorePlugin : public QGCCorePlugin {
    Q_OBJECT

  public:
    CustomCorePlugin(QGCApplication *app, QGCToolbox *toolbox);
    ~CustomCorePlugin();
    Q_PROPERTY(QString accessType READ accessType WRITE setAccessType NOTIFY accessTypeChanged);
    Q_INVOKABLE void setAccessType(QString qAccessType);
    QString accessType() {
        return QString::fromStdString(accessTypeString(_accessType));
    };
    Q_INVOKABLE void updateFlightModes();
    AccessType getAccessType() {
        return _accessType;
    };
    QVariantList &settingsPages(void) final;
    void paletteOverride(QString colorName, QGCPalette::PaletteColorInfo_t& colorInfo) final;
    QQmlApplicationEngine *createQmlApplicationEngine(QObject *parent) final;
    CustomPX4FirmwarePlugin *px4FirmwarePlugin;

  private:
    void _addSettingsEntry(const QString &title, const char *qmlFile,
                           const char *iconFile = nullptr);
    QVariantList _customSettingsList;

  protected:
    AccessType _accessType;

  signals:
    void accessTypeChanged();
};

#endif // CUSTOMCOREPLUGIN_H
