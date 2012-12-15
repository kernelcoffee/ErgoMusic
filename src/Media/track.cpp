#include "track.h"
#include "collection.h"

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
//    TagLib::FileRef file(m_file->absoluteFilePath());

//    if (!file.isNull() && file.tag())
//    {
//        TagLib::Tag *tag = file.tag();
//        m_title = tag->title().toCString(true);
//        m_artist = Collection::instance()->getArtist(tag->title().toCString(true));
//        m_album = Collection::instance()->getAlbum(tag->album().toCString(), m_artist);
//        m_year = tag->year();
//        m_track = tag->track();
//        m_genre = Collection::instance()->getGenre(tag->genre().toCString());
//    }
//    if (!file.isNull() && file.audioProperties())
//    {}
}

