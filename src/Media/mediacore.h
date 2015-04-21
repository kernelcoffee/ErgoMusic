#ifndef MEDIACORE_H
#define MEDIACORE_H

#include "Abstracts/abstractcore.h"

#include "collection.h"
#include "Playlists/watchplaylists.h"
#include "metadatahandler.h"

class MediaCore : public AbstractCore
{
    Q_OBJECT
public:
    explicit MediaCore(QObject *parent = 0);
    ~MediaCore();

    void    init();
    void    initSettings();
    void    initArguments(QCommandLineParser &cmd);
    void    processArguments(QCommandLineParser &cmd);

    Collection*         library() const;
    WatchPlaylists*     watchPlaylists() const;
    MetaDataHandler*    metaDataHandler() const;
signals:

public slots:
    void    delayedInit();
    void    aboutToQuit();

private:
    Collection      *m_library;
    WatchPlaylists  *m_watchPlaylists;
    MetaDataHandler *m_metaData;
};

#endif // MEDIACORE_H
