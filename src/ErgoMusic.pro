#-------------------------------------------------
#
# Project created by QtCreator 2012-02-08T18:16:30
#
#-------------------------------------------------

QT       += core gui

TARGET = ErgoMusic
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Utilities/logger.cpp \
    Utilities/sharedobject.cpp \
    initialization.cpp \
    Database/importengine.cpp \
    Media/song.cpp \
    Media/collection.cpp \
    Media/artist.cpp

HEADERS  += mainwindow.hpp \
    Utilities/singleton.hpp \
    Utilities/logger.hpp \
    Utilities/sharedobject.hpp \
    initialization.hpp \
    Database/importengine.hpp \
    Media/song.hpp \
    Media/collection.hpp \
    Media/artist.hpp

FORMS    += mainwindow.ui

RESOURCES += \
    Ressources/ErgoMusic.qrc












