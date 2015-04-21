#ifndef COLLECTION_H
#define COLLECTION_H

#include <QObject>
#include "track.h"

class Collection : public QObject
{
    Q_OBJECT
public:
    explicit Collection(QObject *parent = 0);
    ~Collection();

signals:

public slots:

protected:
    QList<Track*>   *m_tracks;
};

#endif // COLLECTION_H
