#include "watchplaylistjob.h"
#include <QDirIterator>
#include <QUrl>
#include <QDebug>
#include <coremanager.h>

WatchPlaylistJob::WatchPlaylistJob(WatchPlaylist* data) :
    m_data(data)
{

}

void WatchPlaylistJob::run()
{
    // get list from audio player
    QStringList supportedExtension {"mp3","wma","ogg", "wav", "flac", "aac", "m4a"};

    qDebug() << "watchplaylist job running";
    m_data->setStatus(WatchPlaylist::Busy);
    QDirIterator it(m_data->path(), QDirIterator::Subdirectories);
    while (it.hasNext())
    {
        it.next();
        //!TODO : improve error catching
        if (it.fileInfo().isFile() &&
                it.fileInfo().isReadable() &&
                supportedExtension.contains(it.fileInfo().suffix().toLower()))
        {
            m_data->addTrack(CoreManager::instance()->media()->metaDataHandler()->getTrackFromFile(it.fileInfo().absoluteFilePath()));
        }
    }
    m_data->setStatus(WatchPlaylist::Idle);
    emit m_data->refreshed();
    qDebug() << "watchplaylist job done";
}
