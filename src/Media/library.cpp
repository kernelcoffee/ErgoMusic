#include "library.h"

Library::Library(Collection* collection, QObject *parent) :
    AbstractPlaylist(parent)
{
    m_collection = collection;
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

QObject *Library::get(int)
{

}

void Library::setProperty(int index, const QString &property, const QVariant &value)
{

}
