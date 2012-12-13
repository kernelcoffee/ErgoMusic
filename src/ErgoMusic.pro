#-------------------------------------------------
#
# Project created by QtCreator 2012-02-08T18:16:30
#
#-------------------------------------------------

QT       += core gui widgets sql network multimedia

TARGET = ErgoMusic
TEMPLATE = app

macx {
	#using default path of MacPort
	INCLUDEPATH += /opt/local/include/
	LIBS += -L/opt/local/lib -ltag
}

LIBS += -ltag


SOURCES += main.cpp\
        mainwindow.cpp \
    Utilities/logger.cpp \
    initialization.cpp \
    Database/importengine.cpp \
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
    Gui/settingswidget.cpp \
    Audio/audiomanager.cpp \
    Media/album.cpp \
    Media/track.cpp \
    Media/playlist.cpp \
    Media/watchplaylist.cpp

HEADERS  += \
    Database/databasemanager.h \
    Database/importengine.h \
    Database/integrityengine.h \
    Database/migrationengine.h \
    Database/syncengine.h \
    Media/artist.h \
    Media/collection.h \
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
    Gui/settingswidget.h \
    Audio/audiomanager.h \
    Media/album.h \
    Media/track.h \
    Media/playlist.h \
    Media/watchplaylist.h

FORMS    += mainwindow.ui \
    Gui/settingswidget.ui

RESOURCES += \
    Ressources/ErgoMusic.qrc

TRANSLATIONS += \
    Ressources/languages/lang_en_US.ts \
    Ressources/languages/lang_fr_FR.ts











