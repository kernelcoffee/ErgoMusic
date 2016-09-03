QT += qml quick widgets sql

TARGET = ErgoMusic
TEMPLATE = app

macx {
    # FIX: issue where cache is not created
    cache()
    #using default path of MacPort
    INCLUDEPATH += /opt/local/include/
    LIBS += -L/opt/local/lib
    #using default path of Homebrew
    INCLUDEPATH += /usr/local/include/
    LIBS += -L/usr/local/lib

    LIBS += -ltag
}

linux {
    LIBS += -ltag
}

INCLUDEPATH += $$PWD

SOURCES += main.cpp \
    coremanager.cpp \
    Utilities/logger.cpp \
    Media/mediacore.cpp \
    Media/track.cpp \
    Database/databasecore.cpp \
    Media/collection.cpp \
    Threads/threadscore.cpp \
    Media/Abstracts/abstractplaylist.cpp \
    Media/Playlists/watchplaylist.cpp \
    Media/Jobs/watchplaylistjob.cpp \
    Ui/uicore.cpp \
    Ui/Media/mediacontroller.cpp \
    Ui/Notifications/notificationcontroller.cpp \
    Media/Playlists/watchplaylists.cpp \
    Database/Migration/migrationengine.cpp \
    Database/Migration/Recipies/watchplaylists_migration.cpp \
    Database/Handlers/watchplaylistdbhandler.cpp \
    Database/Handlers/dbhandlers.cpp \
    Ui/Views/viewcontroller.cpp \
    Ui/Media/Models/trackmodel.cpp \
    Media/Commands/addwatchplaylistcommand.cpp \
    Media/Commands/removewatchplaylistcommand.cpp \
    Ui/Views/Model/tracksortmodel.cpp \
    Media/MetaData/metadatahandler.cpp \
    Media/MetaData/fmpsparser.cpp \
    ergoapplication.cpp \
    Database/Migration/Recipies/initial_migration.cpp \
    Ui/Media/Models/watchplaylistsmodel.cpp

HEADERS += \
    coremanager.h \
    Utilities/logger.h \
    Utilities/singleton.h \
    Abstracts/abstractcore.h \
    Media/mediacore.h \
    Media/track.h \
    Database/databasecore.h \
    Media/collection.h \
    Threads/threadscore.h \
    Media/Abstracts/abstractplaylist.h \
    Media/Playlists/watchplaylist.h \
    Media/Jobs/watchplaylistjob.h \
    Ui/uicore.h \
    Ui/Media/mediacontroller.h \
    Ui/Notifications/notificationcontroller.h \
    Media/Playlists/watchplaylists.h \
    Database/Migration/migrationengine.h \
    Database/Migration/migration_list.h \
    Database/Handlers/watchplaylistdbhandler.h \
    Database/Handlers/dbhandlers.h \
    Ui/Views/viewcontroller.h \
    Ui/uicommon.h \
    Ui/Media/Models/trackmodel.h \
    Media/Commands/addwatchplaylistcommand.h \
    Media/Commands/removewatchplaylistcommand.h \
    Ui/Views/Model/tracksortmodel.h \
    Media/MetaData/metadatahandler.h \
    Media/MetaData/fmpsparser.h \
    ergoapplication.h \
    common.h \
    Ui/Media/Models/watchplaylistsmodel.h


RESOURCES += Ressources/qml.qrc \
    Ressources/misc.qrc

TRANSLATIONS += \
    Ressources/languages/lang_en_US.ts \
    Ressources/languages/lang_fr_FR.ts

DISTFILES += .astylerc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

message(CONFIG=$$CONFIG)
