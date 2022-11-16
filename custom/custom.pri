message("Adding Custom AUVSI Plugin")

#-- Version control
#   Major and minor versions are defined here (manually)

CUSTOM_QGC_VER_MAJOR = 1
CUSTOM_QGC_VER_MINOR = 0
CUSTOM_QGC_VER_FIRST_BUILD = 0

# Build number is automatic
# Uses the current branch. This way it works on any branch including build-server's PR branches
CUSTOM_QGC_VER_BUILD = $$system(git --git-dir ../.git rev-list $$GIT_BRANCH --first-parent --count)
win32 {
    CUSTOM_QGC_VER_BUILD = $$system("set /a $$CUSTOM_QGC_VER_BUILD - $$CUSTOM_QGC_VER_FIRST_BUILD")
} else {
    CUSTOM_QGC_VER_BUILD = $$system("echo $(($$CUSTOM_QGC_VER_BUILD - $$CUSTOM_QGC_VER_FIRST_BUILD))")
}
CUSTOM_QGC_VERSION = $${CUSTOM_QGC_VER_MAJOR}.$${CUSTOM_QGC_VER_MINOR}.$${CUSTOM_QGC_VER_BUILD}

DEFINES -= GIT_VERSION=\"\\\"$$GIT_VERSION\\\"\"
DEFINES += GIT_VERSION=\"\\\"$$CUSTOM_QGC_VERSION\\\"\"

message(AUVSI QGC Version: $${CUSTOM_QGC_VERSION})

# We implement our own PX4/APM plugin factory
CONFIG  += QGC_DISABLE_PX4_PLUGIN_FACTORY
CONFIG  += QGC_DISABLE_APM_PLUGIN_FACTORY

# Branding
DEFINES += CUSTOMHEADER=\"\\\"CustomCorePlugin.h\\\"\"
DEFINES += CUSTOMCLASS=CustomCorePlugin

TARGET   = AUVSIQGroundControl
DEFINES += QGC_APPLICATION_NAME='"\\\"Deez Nuts Drone App\\\""'

DEFINES += QGC_ORG_NAME=\"\\\"qgroundcontrol.org\\\"\"
DEFINES += QGC_ORG_DOMAIN=\"\\\"org.qgroundcontrol\\\"\"

QGC_APP_NAME        = "Deez Nuts Drone App"
QGC_BINARY_NAME     = "DeezNutsQGC"
QGC_ORG_NAME        = "Deez Nuts"
QGC_ORG_DOMAIN      = "org.deez"
QGC_ANDROID_PACKAGE = "org.deez.nuts"
QGC_APP_DESCRIPTION = "Deez Nuts in your mouth"
QGC_APP_COPYRIGHT   = "Copyright (C) 2020 QGroundControl Development Team. All rights reserved."

# Our own, custom resources
RESOURCES += \
    $$PWD/custom.qrc

QML_IMPORT_PATH += \
    $$PWD/res

# Our own, custom sources
SOURCES += \
    $$PWD/src/AccessType.cpp \
    $$PWD/src/AccessTypeConfig.cpp \
    $$PWD/src/CustomCorePlugin.cc \
    $$PWD/src/PasscodeMenu/PasscodeManager.cc


HEADERS += \
    $$PWD/src/AccessType.h \
    $$PWD/src/AccessTypeConfig.h \
    $$PWD/src/CustomCorePlugin.h \
    $$PWD/src/PasscodeMenu/PasscodeManager.h

INCLUDEPATH += \
    $$PWD/src \
