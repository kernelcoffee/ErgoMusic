#ifndef WATCHPLAYLISTJOB_H
#define WATCHPLAYLISTJOB_H

#include <QRunnable>
#include "../Playlists/watchplaylist.h"

class WatchPlaylistJob : public QRunnable
{
public:
    WatchPlaylistJob(WatchPlaylist* data);

    void    run();
private:
    WatchPlaylist*  m_data;
};

#endif // WATCHPLAYLISTJOB_H
