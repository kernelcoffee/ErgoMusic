#ifndef METADATAHANDLER_H
#define METADATAHANDLER_H

#include <QObject>
#include "track.h"

class MetaDataHandler : public QObject
{
    Q_OBJECT
public:
    explicit MetaDataHandler(QObject *parent = 0);
    ~MetaDataHandler();

    Track*  getTrackFromFile(QString path);
signals:

public slots:
};

#endif // METADATAHANDLER_H
