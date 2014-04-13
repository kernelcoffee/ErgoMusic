#include "library.h"
#include <QtDebug>

Library::Library(Collection* collection, QObject *parent) :
    AbstractPlaylist(parent)
{
    m_type = LIBRARY;
    m_collection = collection;
    qDebug() << "Library: "<< this <<  " - Collection " << m_collection;
}

void Library::insert(int, const Track *)
{

}

void Library::append(const Track *)
{

}

void Library::remove(int)
{

}

QObject *Library::get(int index)
{
    return m_collection->getTracks()->at(index);
}

void Library::setProperty(int index, const QString &property, const QVariant &value)
{

}
