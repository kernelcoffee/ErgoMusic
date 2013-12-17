#include "track.h"
#include "coremanager.h"
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


Track::Track(QUrl path) :
    QMediaContent(path)
{
    m_file = new QFileInfo(path.path());
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
    m_data["title"] = m_title;
}

void Track::setArtist(QString artist)
{
//    m_artist->setName(artist);
}

void Track::setArtist(Artist *artist)
{
    m_artist = artist;
}


void Track::setAlbum(QString)
{
    //
}

void Track::setAlbum(Album *album)
{
    m_album = album;
}

void Track::setYear(int year)
{
    m_year = year;
    m_data["year"] = m_year;
}

void Track::setGenre(Genre *genre)
{
    m_genre = genre;
}

void Track::setTrack(int track)
{
    m_track = track;
    m_data["track"] = QString::number(track);
}

void Track::_setValue(QString key, QString value)
{
    m_data[key] = value;
}

void Track::_setValue(QString key, int value)
{
    _setValue(key, QString::number(value));
}

void Track::extractTags()
{
    extractTags(CoreManager::instance()->media()->collection());
}

void Track::extractTags(Collection* collection)
{
    TagLib::FileRef file(m_file->absoluteFilePath().toLocal8Bit().data());

    if (!file.isNull() && file.tag())
    {
        TagLib::Tag *tag = file.tag();
        setTitle(tag->title().toCString(true));
        setArtist(collection->getArtist(QString(tag->artist().toCString(true))));
        setAlbum(collection->getAlbum(QString(tag->album().toCString(true)), m_artist));
        setYear(tag->year());
        setTrack(tag->track());
        setGenre(collection->getGenre(QString(tag->genre().toCString(true))));
        //Logger::log("Album " + m_album->name() + " Artist " + m_artist->name() + " Title " + m_title + " file " + m_file->fileName(), LOG_DEBUG);
    }
    if (!file.isNull() && file.audioProperties())
    {
        TagLib::AudioProperties *properties = file.audioProperties();
        m_bitrate = properties->bitrate();
        _setValue("bitrate", m_bitrate);
        m_sampleRate = properties->sampleRate();
        _setValue("samplerate", m_sampleRate);
        m_channels = properties->channels();
        _setValue("channels", m_channels);
        m_duration = properties->length();
        _setValue("duration", m_duration);
//        Logger::log("bitrate " + QString::number(m_bitrate) + " samplerate " + QString::number(m_sampleRate) + " Channels " + QString::number(m_channels) + " duration " + QString::number(m_duration), LOG_DEBUG);
    }

    /// TODO Illustration
}


QString Track::getValue(QString value) const
{
    if (value.toLower() == "artist")
        return m_artist->name();
    if (value.toLower() == "album")
        return m_album->name();
    if (value.toLower() == "genre")
        return m_genre->name();
    if (m_data.contains(value.toLower()))
        return m_data[value.toLower()];
    return "unavalable";
}
