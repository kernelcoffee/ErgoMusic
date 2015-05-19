#ifndef METADATAHANDLER_H
#define METADATAHANDLER_H

#include <QObject>
#include "track.h"

#include <taglib/mpegfile.h>
#include <taglib/flacfile.h>
#include <taglib/mp4file.h>
#include <taglib/asffile.h>
#include <taglib/oggfile.h>

// some code may be borrowed from Clementine player
// https://github.com/clementine-player/Clementine/tree/master/ext/libclementine-tagreader

class MetaDataHandler : public QObject
{
    Q_OBJECT
public:
    explicit MetaDataHandler(QObject *parent = 0);
    ~MetaDataHandler();

    Track*  getTrackFromFile(QString path);
signals:

public slots:
private:
    void    _parseMp3Tags(Track* track, TagLib::MPEG::File* file);
    void    _parseFlacTags(Track* track, TagLib::FLAC::File* file);
    void    _parseMp4Tags(Track* track, TagLib::MP4::File* file);
    void    _parseAsfTags(Track* track, TagLib::ASF::File* file);
    void    _parseOggTags(Track* track, TagLib::Ogg::File* file);

};

#endif // METADATAHANDLER_H
