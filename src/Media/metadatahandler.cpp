#include "metadatahandler.h"
#include <taglib/taglib.h>
#include <taglib/fileref.h>
#include <QDebug>

MetaDataHandler::MetaDataHandler(QObject *parent) : QObject(parent)
{

}

MetaDataHandler::~MetaDataHandler()
{

}

Track *MetaDataHandler::getTrackFromFile(QString path)
{
    TagLib::FileRef file(path.toLocal8Bit());
    Track* track = new Track;

    if (!file.isNull() && file.tag())
    {
        TagLib::Tag *tag = file.tag();
        //qDebug() << tag->title().toCString(true);
        track->setTitle(tag->title().toCString(true));
        track->setArtist(QString(tag->artist().toCString(true)));
        track->setAlbum(QString(tag->album().toCString(true)));
//        setYear(tag->year());
//        setTrack(tag->track());
//        setGenre(collection->getGenre(QString(tag->genre().toCString(true))));
//        qDebug() << "Album :" + track->album() + ", Artist " + track->artist() + ", Title " + track->title();
    }
    if (!file.isNull() && file.audioProperties())
    {
//        TagLib::AudioProperties *properties = file.audioProperties();
//        m_bitrate = properties->bitrate();
//        _setValue("bitrate", m_bitrate);
//        m_sampleRate = properties->sampleRate();
//        _setValue("samplerate", m_sampleRate);
//        m_channels = properties->channels();
//        _setValue("channels", m_channels);
//        m_duration = properties->length();
//        _setValue("duration", m_duration);
//        Logger::log("bitrate " + QString::number(m_bitrate) + " samplerate " + QString::number(m_sampleRate) + " Channels " + QString::number(m_channels) + " duration " + QString::number(m_duration), LOG_DEBUG);
    }

    /// TODO Illustration
    return track;
}

