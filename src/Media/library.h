#ifndef LIBRARY_H
#define LIBRARY_H

#include "Utilities/Abstract/abstractplaylist.h"

class Library : public AbstractPlaylist
{
    Q_OBJECT
public:
    explicit Library(QObject *parent = 0);
    explicit Library(QList<Track*>*, QObject*parent = 0);
signals:
    
public slots:
    
};

#endif // LIBRARY_H
