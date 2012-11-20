#-------------------------------------------------
#
# Project created by QtCreator 2012-02-08T18:16:30
#
#-------------------------------------------------

QT       += core gui widgets sql network

TARGET = ErgoMusic
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Utilities/logger.cpp \
    initialization.cpp \
    Database/importengine.cpp \
    Media/song.cpp \
    Media/collection.cpp \
    Media/artist.cpp \
    Database/integrityengine.cpp \
    Database/migrationengine.cpp \
    Database/syncengine.cpp \
    Database/databasemanager.cpp \
    Network/networkmanager.cpp \
    Network/gatekeeper.cpp \
    coremanager.cpp \
    Gui/playerwidget.cpp \
    Gui/playlistwidget.cpp \
    Gui/viewwidget.cpp \
    Gui/preferenceswidget.cpp

HEADERS  += \
    Database/databasemanager.h \
    Database/importengine.h \
    Database/integrityengine.h \
    Database/migrationengine.h \
    Database/syncengine.h \
    Media/artist.h \
    Media/collection.h \
    Media/song.h \
    Network/gatekeeper.h \
    Network/networkmanager.h \
    Utilities/logger.h \
    Utilities/singleton.h \
    common.h \
    coremanager.h \
    initialization.h \
    mainwindow.h \
    Gui/playerwidget.h \
    Gui/playlistwidget.h \
    Gui/viewwidget.h \
    Gui/preferenceswidget.h

FORMS    += mainwindow.ui \
    Gui/preferenceswidget.ui

RESOURCES += \
    Ressources/ErgoMusic.qrc












