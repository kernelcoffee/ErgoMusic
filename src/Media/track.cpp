#include "track.h"
#include "collection.h"
#include "Utilities/logger.h"

// LibTag
//#include <audioproperties.h>
//#include <mpegfile.h>
#include <taglib/fileref.h>
//#include <id3v2tag.h>
//#include <id3v2frame.h>
//#include <id3v2header.h>
//#include <id3v1tag.h>
//#include <apetag.h>
//#include <attachedpictureframe.h>

Track::Track()
{
}

Track::Track(QString path)
{
    m_file = new QFileInfo(path);
    _extractTags();
}

Track::~Track()
{
    delete m_file;
}

int Track::uid()
{
    return m_uid;
}

QString Track::title()
{
    return m_title;
}

Artist *Track::artist()
{
    return m_artist;
}

void Track::setUid(int uid)
{
    m_uid = uid;
}

void Track::setTitle(QString title)
{
    m_title = title;
}

void Track::setArtist(QString artist)
{
    m_artist->setName(artist);
}

void Track::_extractTags()
{
    TagLib::FileRef file(m_file->absoluteFilePath().toLocal8Bit().data());

    if (!file.isNull() && file.tag())
    {
        TagLib::Tag *tag = file.tag();
        m_title = tag->title().toCString(true);
        m_artist = Collection::instance()->getArtist(QString(tag->artist().toCString(true)));
        m_album = Collection::instance()->getAlbum(QString(tag->album().toCString(true)), m_artist);
        m_year = (int)tag->year();
        m_track = tag->track();
        m_genre = Collection::instance()->getGenre(QString(tag->genre().toCString(true)));
        Logger::log("Album " + m_album->name() + " Artist " + m_artist->name() + " Title " + m_title + " file " + m_file->fileName(), LOG_DEBUG);
    }
    if (!file.isNull() && file.audioProperties())
    {
        TagLib::AudioProperties *properties = file.audioProperties();
        m_bitrate = properties->bitrate();
        m_sampleRate = properties->sampleRate();
        m_channels = properties->channels();
        m_duration = properties->length();
        Logger::log("bitrate " + QString::number(m_bitrate) + " samplerate " + QString::number(m_sampleRate) + " Channels " + QString::number(m_channels) + " duration " + QString::number(m_duration), LOG_DEBUG);
    }

    if (m_album->illustration()->isNull())
    {

    }
}

