#ifndef MEDIACORE_H
#define MEDIACORE_H

#include "Abstracts/abstractcore.h"

#include "collection.h"
#include "Playlists/watchplaylists.h"
#include "MetaData/metadatahandler.h"

class CoreManager;

class MediaCore : public AbstractCore
{
    Q_OBJECT
public:
    explicit MediaCore(CoreManager *parent = 0);
    ~MediaCore();

    void    init() override;
    void    initSettings() override;

    Collection*         library() const;
    WatchPlaylists*     watchPlaylists() const;

public slots:
    void    delayedInit();
    void    onAboutToQuit() override;

private:
    CoreManager     *m_cores = nullptr;
    Collection      *m_library = nullptr;
    WatchPlaylists  *m_watchPlaylists = nullptr;
};

#endif // MEDIACORE_H
