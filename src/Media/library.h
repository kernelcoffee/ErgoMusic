#ifndef LIBRARY_H
#define LIBRARY_H

#include "Utilities/Abstract/abstractplaylist.h"

class Library : public AbstractPlaylist
{
    Q_OBJECT
public:
    explicit Library(Collection*, QObject *parent = 0);
signals:
    
public slots:

protected slots:
    virtual void        insert(int, const Track *);
    virtual void        append(const Track *);
    virtual void        remove(int);
    virtual QObject*    get(int);
    virtual void        setProperty(int index, const QString &property, const QVariant &value);

private:
    Collection*         m_collection;

};

#endif // LIBRARY_H
