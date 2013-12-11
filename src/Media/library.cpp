#include "library.h"

Library::Library(Collection* collection, QObject *parent) :
    m_collection(collection), AbstractPlaylist(parent)
{
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
