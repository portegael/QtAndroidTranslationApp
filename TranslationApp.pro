TEMPLATE = app

QT += qml quick
CONFIG += c++11

SOURCES += main.cpp \
    translation.cpp

RESOURCES += qml.qrc \
    translations/translations.qrc

# Default rules for deployment.
include(deployment.pri)

TRANSLATIONS += \
    translations/language_fr.ts \
    translations/language_en.ts \
    translations/language_de.ts

HEADERS += \
    translation.h
