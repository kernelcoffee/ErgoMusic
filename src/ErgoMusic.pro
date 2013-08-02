QT       += core gui widgets sql network multimedia quick qml

TARGET = ErgoMusic
TEMPLATE = app

macx {
	# FIX: issue where cache is not created on 5.1
	cache()
	#using default path of MacPort
    INCLUDEPATH += /opt/local/include/
    LIBS += -L/opt/local/lib -ltag
}

unix:!macx {
    LIBS += -ltag
}


SOURCES += main.cpp\
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
    Audio/audiomanager.cpp \
    Media/album.cpp \
    Media/track.cpp \
    Media/watchplaylist.cpp \
    Media/genre.cpp \
    Utilities/Abstract/abstractplaylist.cpp \
    Media/playlist.cpp \
    Media/library.cpp \
    Models/watchplaylistsmodel.cpp

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
    Audio/audiomanager.h \
    Media/album.h \
    Media/track.h \
    Media/watchplaylist.h \
    Media/genre.h \
    Utilities/Abstract/abstractplaylist.h \
    Media/playlist.h \
    Media/library.h \
    Models/watchplaylistsmodel.h

OTHER_FILES += \
	Ressources/qml/Desktop/main.qml \
    Ressources/qml/Desktop/Mainview/mainListView.qml \
	Ressources/qml/Desktop/MenuBar/MenuWidget.qml \
	Ressources/qml/Desktop/Widgets/CollapsiblePanel.qml \
    Ressources/qml/Desktop/StatusBar/StatusWidget.qml \
    Ressources/qml/Desktop/TopBar/TopWidget.qml \
    Ressources/qml/Desktop/Components/PlayerControlerIcon.qml

RESOURCES += \
    Ressources/ErgoMusic.qrc \
    Ressources/Desktop.qrc

TRANSLATIONS += \
    Ressources/languages/lang_en_US.ts \
    Ressources/languages/lang_fr_FR.ts
