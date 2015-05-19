#include "metadatahandler.h"
#include <taglib/taglib.h>
#include <taglib/fileref.h>
#include <taglib/id3v2tag.h>
#include <taglib/commentsframe.h>

#include <QDebug>

// some code may be borrowed from Clementine player
// https://github.com/clementine-player/Clementine/tree/master/ext/libclementine-tagreader

MetaDataHandler::MetaDataHandler(QObject *parent) : QObject(parent)
{

}

MetaDataHandler::~MetaDataHandler()
{

}

Track *MetaDataHandler::getTrackFromFile(QString path)
{
    TagLib::FileRef fileref(path.toLocal8Bit());
    Track* track = new Track(path);

    if (!fileref.isNull() && fileref.tag())
    {
        TagLib::Tag *tag = fileref.tag();
        track->setTitle(tag->title().toCString(true));
        track->setArtist(QString(tag->artist().toCString(true)));
        track->setAlbum(QString(tag->album().toCString(true)));
        track->setYear(tag->year());
        track->setTrack(tag->track());
        track->setGenre(tag->genre().toCString(true));
    }
    if (!fileref.isNull() && fileref.audioProperties())
    {
        TagLib::AudioProperties *properties = fileref.audioProperties();
        track->setLength(properties->length());
//        m_bitrate = properties->bitrate();
//        _setValue("bitrate", m_bitrate);
//        m_sampleRate = properties->sampleRate();
//        _setValue("samplerate", m_sampleRate);
//        m_channels = properties->channels();
//        _setValue("channels", m_channels);
//        Logger::log("bitrate " + QString::number(m_bitrate) + " samplerate " + QString::number(m_sampleRate) + " Channels " + QString::number(m_channels) + " duration " + QString::number(m_duration), LOG_DEBUG);
    }

    if (TagLib::MPEG::File* file =
            dynamic_cast<TagLib::MPEG::File*>(fileref.file()))
    {
        _parseMp3Tags(track, file);
    }
    else if (TagLib::FLAC::File* file =
             dynamic_cast<TagLib::FLAC::File*>(fileref.file()))
    {
        _parseFlacTags(track, file);
    }
    else if (TagLib::MP4::File* file =
             dynamic_cast<TagLib::MP4::File*>(fileref.file()))
    {
        _parseMp4Tags(track, file);
    }
    else if (TagLib::ASF::File* file =
             dynamic_cast<TagLib::ASF::File*>(fileref.file()))
    {
        _parseAsfTags(track, file);
    }
    else if (TagLib::Ogg::File* file =
             dynamic_cast<TagLib::Ogg::File*>(fileref.file()))
    {
        _parseOggTags(track, file);
    }
    return track;
}


// http://id3.org/id3v2.3.0
void MetaDataHandler::_parseMp3Tags(Track *track, TagLib::MPEG::File *file)
{
    if (!file->ID3v2Tag())
        return;

    QString disc;
    const TagLib::ID3v2::FrameListMap& map = file->ID3v2Tag()->frameListMap();

    // [#TPOS Part of a set]
    if (!map["TPOS"].isEmpty())
        disc = TStringToQString(map["TPOS"].front()->toString()).trimmed();

    // [#TBPM BPM (beats per minute)]
    if (!map["TBPM"].isEmpty())
        qDebug() << "TBPM " << TStringToQString(map["TBPM"].front()->toString()).trimmed().toFloat();

    // [#TCOM Composer]
    if (!map["TCOM"].isEmpty())
        qDebug() << "TCOM "<< TStringToQString(map["TCOM"].front()->toString());

    // [#TIT1 Content group description]
    if (!map["TIT1"].isEmpty())
        qDebug() << "TIT1 " << TStringToQString(map["TIT1"].front()->toString());

    // [#TOPE Original artist(s)/performer(s)]
    if (!map["TOPE"].isEmpty())
        qDebug() << "TOPE " << TStringToQString(map["TOPE"].front()->toString());

    // Skip TPE1 (which is the artist) here because we already fetched it

    // [#TPE2 Band/orchestra/accompaniment]
    if (!map["TPE2"].isEmpty())  // non-standard: Apple, Microsoft
        qDebug() << "TPE2 " <<  TStringToQString(map["TPE2"].front()->toString());

    // TCMP - iTunes Compilation Flag (class 4)
    if (!map["TCMP"].isEmpty())
        qDebug() << "TCMP " << TStringToQString(map["TCMP"].front()->toString()).trimmed();

    // [#sec4.9 Unsychronized lyric/text transcription]
    if (!map["USLT"].isEmpty())
        qDebug() << "USLT " << TStringToQString((map["USLT"].front())->toString()).trimmed();
    // [#sec4.10 Synchronized lyric/text]
    else if (!map["SYLT"].isEmpty())
        qDebug() << "SYLT " << TStringToQString((map["SYLT"].front())->toString()).trimmed();

    // [#sec4.15 Attached picture]
    if (!map["APIC"].isEmpty())
        qDebug() << "APIC " << "Album art present";

    // Find a suitable comment tag.  For now we ignore iTunNORM comments.
    for (uint i = 0; i < map["COMM"].size(); ++i) {
        const TagLib::ID3v2::CommentsFrame* frame =  dynamic_cast<const TagLib::ID3v2::CommentsFrame*>(map["COMM"][i]);

        if (frame && TStringToQString(frame->description()) != "iTunNORM") {
            qDebug() << "COMM " << TStringToQString(frame->text());
            break;
        }
    }

}

void MetaDataHandler::_parseFlacTags(Track *track, TagLib::FLAC::File *file)
{

}

void MetaDataHandler::_parseMp4Tags(Track *track, TagLib::MP4::File *file)
{

}

void MetaDataHandler::_parseAsfTags(Track *track, TagLib::ASF::File *file)
{

}

void MetaDataHandler::_parseOggTags(Track *track, TagLib::Ogg::File *file)
{

}

