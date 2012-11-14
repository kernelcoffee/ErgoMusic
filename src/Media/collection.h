#ifndef COLLECTION_H
#define COLLECTION_H

#include <QVector>
#include "song.h"

class Collection
{
public:
    Collection();
protected:
    QVector<Song*>  m_collection;
};

#endif // COLLECTION_H
