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

unix:!macx {
    LIBS += -ltag
}


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
    Gui/viewwidget.cpp \
    Gui/settingswidget.cpp \
    Audio/audiomanager.cpp \
    Media/album.cpp \
    Media/track.cpp \
    Media/watchplaylist.cpp \
    Media/genre.cpp \
    Gui/Models/treemodel.cpp \
    Gui/Models/tablemodel.cpp \
    Utilities/Abstract/abstractplaylist.cpp \
    Media/playlist.cpp \
    Gui/Models/sidebarwidgetmodel.cpp \
    Gui/sidebarwidget.cpp \
    Gui/Views/listview.cpp \
    Gui/Models/listviewmodel.cpp \
    Gui/Items/treeitem.cpp \
    Gui/Items/sidebarwidgetitem.cpp \
    Gui/Items/listviewitem.cpp \
    Media/library.cpp \
    Gui/Views/viewheader.cpp

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
    Gui/viewwidget.h \
    Gui/settingswidget.h \
    Audio/audiomanager.h \
    Media/album.h \
    Media/track.h \
    Media/watchplaylist.h \
    Media/genre.h \
    Gui/Models/treemodel.h \
    Gui/Models/tablemodel.h \
    Utilities/Abstract/abstractplaylist.h \
    Media/playlist.h \
    Gui/sidebarwidget.h \
    Gui/Models/sidebarwidgetmodel.h \
    Gui/Views/listview.h \
    Gui/Models/listviewmodel.h \
    Gui/Items/treeitem.h \
    Gui/Items/sidebarwidgetitem.h \
    Gui/Items/listviewitem.h \
    Media/library.h \
    Gui/Views/viewheader.h

FORMS    += mainwindow.ui \
    Gui/settingswidget.ui

RESOURCES += \
    Ressources/ErgoMusic.qrc

TRANSLATIONS += \
    Ressources/languages/lang_en_US.ts \
    Ressources/languages/lang_fr_FR.ts
