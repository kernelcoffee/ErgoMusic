#ifndef MEDIACORE_H
#define MEDIACORE_H

#include "Abstracts/abstractcore.h"

#include "collection.h"
#include "Playlists/watchplaylists.h"
#include "MetaData/metadatahandler.h"

class MediaCore : public AbstractCore
{
    Q_OBJECT
public:
    explicit MediaCore(QObject *parent = 0);
    ~MediaCore();

    void    init() override;
    void    initSettings() override;

    Collection*         library() const;
    WatchPlaylists*     watchPlaylists() const;

public slots:
    void    delayedInit();
    void    onAboutToQuit() override;

private:
    Collection      *m_library;
    WatchPlaylists  *m_watchPlaylists;
};

#endif // MEDIACORE_H
