#include "metadatahandler.h"

#include <taglib/taglib.h>
#include <taglib/fileref.h>
#include <taglib/id3v2tag.h>
#include <taglib/commentsframe.h>
#include <taglib/textidentificationframe.h>

#include <taglib/oggflacfile.h>

//#include <taglib/aifffile.h>
//#include <taglib/attachedpictureframe.h>
//#include <taglib/commentsframe.h>
//#include <taglib/mp4file.h>
//#include <taglib/mpcfile.h>
//#include <taglib/opusfile.h>
//#include <taglib/popularimeterframe.h>
//#include <taglib/speexfile.h>
//#include <taglib/tag.h>
//#include <taglib/textidentificationframe.h>
//#include <taglib/trueaudiofile.h>
//#include <taglib/tstring.h>
//#include <taglib/vorbisfile.h>
//#include <taglib/wavfile.h>

#include "fmpsparser.h"

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
    }

    if (TagLib::Ogg::XiphComment* tag =
            dynamic_cast<TagLib::Ogg::XiphComment*>(fileref.file()->tag())) {
//      _parseOggTags(tag->fieldListMap(), track);
//            qDebug() << TStringToQString(tag->comment());
    }

    if (TagLib::MPEG::File* file =
            dynamic_cast<TagLib::MPEG::File*>(fileref.file())) {
        _parseMp3Tags(track, file);
    } else if (TagLib::FLAC::File* file =
               dynamic_cast<TagLib::FLAC::File*>(fileref.file())) {
        _parseFlacTags(track, file);
    } else if (TagLib::MP4::File* file =
               dynamic_cast<TagLib::MP4::File*>(fileref.file())) {
        _parseMp4Tags(track, file);
    }  else if (TagLib::ASF::File* file =
                dynamic_cast<TagLib::ASF::File*>(fileref.file())) {
        _parseAsfTags(track, file);
    } else if (TagLib::Ogg::File* file =
               dynamic_cast<TagLib::Ogg::File*>(fileref.file())) {
        _parseOggTags(track, file);
    }
    return track;
}


// http://id3.org/id3v2.3.0
void MetaDataHandler::_parseMp3Tags(Track *track, TagLib::MPEG::File *file)
{
    if (!file->ID3v2Tag())
        return;

    QString debug;
    const TagLib::ID3v2::FrameListMap& map = file->ID3v2Tag()->frameListMap();

    // [#TPOS Part of a set]
    if (!map["TPOS"].isEmpty())
        debug.append(" TPOS " + TStringToQString(map["TPOS"].front()->toString()).trimmed());

    // [#TBPM BPM (beats per minute)]
    if (!map["TBPM"].isEmpty())
        debug.append(debug + " TBPM " + TStringToQString(map["TBPM"].front()->toString()).trimmed().toFloat());

    // [#TCOM Composer]
    if (!map["TCOM"].isEmpty())
        debug.append(" TCOM " + TStringToQString(map["TCOM"].front()->toString()));

    // [#TIT1 Content group description]
    if (!map["TIT1"].isEmpty())
        debug.append(" TIT1 " + TStringToQString(map["TIT1"].front()->toString()));

    // [#TOPE Original artist(s)/performer(s)]
    if (!map["TOPE"].isEmpty())
        debug.append(" TOPE " + TStringToQString(map["TOPE"].front()->toString()));

    // Skip TPE1 (which is the artist) here because we already fetched it

    // [#TPE2 Band/orchestra/accompaniment]
    if (!map["TPE2"].isEmpty())  // non-standard: Apple, Microsoft
        debug.append(" TPE2 " +  TStringToQString(map["TPE2"].front()->toString()));

    // TCMP - iTunes Compilation Flag (class 4)
    if (!map["TCMP"].isEmpty())
        debug.append(" TCMP " + TStringToQString(map["TCMP"].front()->toString()).trimmed());

    // [#sec4.9 Unsychronized lyric/text transcription]
    if (!map["USLT"].isEmpty())
        debug.append(" USLT " + TStringToQString((map["USLT"].front())->toString()).trimmed());
    // [#sec4.10 Synchronized lyric/text]
    else if (!map["SYLT"].isEmpty())
        debug.append(" SYLT " + TStringToQString((map["SYLT"].front())->toString()).trimmed());

    // [#sec4.15 Attached picture]
    if (!map["APIC"].isEmpty())
        debug.append(" APIC Album art present");

    // Find a suitable comment tag.  For now we ignore iTunNORM comments.
    for (uint i = 0; i < map["COMM"].size(); ++i) {
        const TagLib::ID3v2::CommentsFrame* frame =
                dynamic_cast<const TagLib::ID3v2::CommentsFrame*>(map["COMM"][i]);

        if (frame && TStringToQString(frame->description()) != "iTunNORM") {
            debug.append(" COMM " + TStringToQString(frame->text()));
            break;
        }
    }
    // Parse FMPS frames
    for (uint i = 0; i < map["TXXX"].size(); ++i) {
        const TagLib::ID3v2::UserTextIdentificationFrame* frame =
                dynamic_cast<const TagLib::ID3v2::UserTextIdentificationFrame*>(map["TXXX"][i]);

        if (frame && frame->description().startsWith("FMPS_")) {
            _parseFMPSFrame(TStringToQString(frame->description()),
                            TStringToQString(frame->fieldList()[1]), track);
        }
    }

    //    if (!debug.isEmpty())
    //        qDebug() << debug;
}

void MetaDataHandler::_parseFlacTags(Track *track, TagLib::FLAC::File *file)
{
    TagLib::Ogg::FieldListMap map = file->xiphComment()->fieldListMap();
    QString debug;


    if (!map["COMPOSER"].isEmpty())
        debug.append(TStringToQString(map["COMPOSER"].front()));

    if (!map["PERFORMER"].isEmpty())
        debug.append(TStringToQString(map["PERFORMER"].front()));

    if (!map["CONTENT GROUP"].isEmpty())
        debug.append(TStringToQString(map["CONTENT GROUP"].front()));

    if (!map["ALBUMARTIST"].isEmpty()) {
        debug.append(TStringToQString(map["ALBUMARTIST"].front()));
    } else if (!map["ALBUM ARTIST"].isEmpty()) {
        debug.append(TStringToQString(map["ALBUM ARTIST"].front()));
    }

    if (!map["BPM"].isEmpty())
        debug.append(QString::number(TStringToQString(map["BPM"].front()).trimmed().toFloat()));

    if (!map["DISCNUMBER"].isEmpty())
        debug.append(TStringToQString(map["DISCNUMBER"].front()).trimmed());

    if (!map["COMPILATION"].isEmpty())
        debug.append(TStringToQString(map["COMPILATION"].front()).trimmed());

    if (!map["COVERART"].isEmpty())
        debug.append("has a picture");
    if (!map["METADATA_BLOCK_PICTURE"].isEmpty())
        debug.append("has a picture");
    if (!file->pictureList().isEmpty()) {
        debug.append("has a picture");
    }

    if (!map["FMPS_RATING"].isEmpty())
        debug.append(QString::number(TStringToQString(map["FMPS_RATING"].front()).trimmed().toFloat()));

    if (!map["FMPS_PLAYCOUNT"].isEmpty())
        debug.append(QString::number(TStringToQString(map["FMPS_PLAYCOUNT"].front()).trimmed().toFloat()));

    if (!map["FMPS_RATING_AMAROK_SCORE"].isEmpty())
        debug.append(QString::number(TStringToQString(map["FMPS_RATING_AMAROK_SCORE"].front()).trimmed().toFloat() * 100));

//    if (!debug.isEmpty())
//        qDebug() << debug;
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

void MetaDataHandler::_parseFMPSFrame(const QString &name, const QString &value, Track *track)
{
    QString debug = "Parsing FMPSFrame" + name + ", " + value;
    FMPSParser parser;
    if (!parser.Parse(value) || parser.is_empty()) return;

    QVariant var;
    if (name == "FMPS_Rating") {
        var = parser.result()[0][0];
        if (var.type() == QVariant::Double) {
            debug.append(" FMPS_Rating " + QString::number(var.toDouble()));
        }
    } else if (name == "FMPS_Rating_User") {
        // Take a user rating only if there's no rating already set
        if (parser.result()[0].count() >= 2) {
            var = parser.result()[0][1];
            if (var.type() == QVariant::Double) {
                debug.append(" FMPS_Rating_User " + QString::number(var.toDouble()));
            }
        }
    } else if (name == "FMPS_PlayCount") {
        var = parser.result()[0][0];
        if (var.type() == QVariant::Double) {
            debug.append(" FMPS_PlayCount " + QString::number(var.toDouble()));
        }
    } else if (name == "FMPS_PlayCount_User") {
        // Take a user playcount only if there's no playcount already set
        if (parser.result()[0].count() >= 2) {
            var = parser.result()[0][1];
            if (var.type() == QVariant::Double) {
                debug.append(" FMPS_PlayCount_User " + QString::number(var.toDouble()));
            }
        }
    } else if (name == "FMPS_Rating_Amarok_Score") {
        var = parser.result()[0][0];
        if (var.type() == QVariant::Double) {
            debug.append("FMPS_Rating_Amarok_Score " + QString::number(var.toFloat() * 100));
        }
    }

    //    qDebug() << debug;
}

