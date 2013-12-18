#include "album.h"

Album::Album()
{
}

Album::Album(QString title, Artist *artist)
{
    m_name = title;
    m_albumArtist = artist;
    m_illustration = NULL;
}

Album::~Album()
{
    while (!m_tracks->empty()) {
        delete  m_tracks->takeFirst();
    }
}

Artist* Album::albumArtist() const
{
    return m_albumArtist;
}

QImage* Album::illustration() const
{
    return m_illustration;
}

QString Album::name() const
{
    return m_name;
}

QString Album::description() const
{
    return m_description;
}

