#ifndef GENRE_H
#define GENRE_H

#include "collection.h"

class Genre
{
public:
    Genre();
    Genre(QString&);
    ~Genre();

    QString name() const;
    int     uid() const;

    void    setName(QString);
    void    setUid(int);
private:
    QString m_name;
    int     m_uid;
};

#endif // GENRE_H
