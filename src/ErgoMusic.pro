#-------------------------------------------------
#
# Project created by QtCreator 2012-02-08T18:16:30
#
#-------------------------------------------------

QT       += core gui sql network

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
    coremanager.cpp

HEADERS  += mainwindow.hpp \
    Utilities/singleton.hpp \
    Utilities/logger.hpp \
    initialization.hpp \
    Database/importengine.hpp \
    Media/song.hpp \
    Media/collection.hpp \
    Media/artist.hpp \
    Database/integrityengine.hpp \
    Database/migrationengine.hpp \
    Database/syncengine.hpp \
    Database/databasemanager.hpp \
    Network/networkmanager.hpp \
    Network/gatekeeper.hpp \
    common.hpp \
    coremanager.hpp

FORMS    += mainwindow.ui

RESOURCES += \
    Ressources/ErgoMusic.qrc












