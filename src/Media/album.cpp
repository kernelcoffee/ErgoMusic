#include "album.h"

Album::Album()
{
}

Album::Album(QString title, Artist *artist)
{
    m_name = title;
    m_albumArtist = artist;
}

Album::~Album()
{}

Artist* Album::albumArtist() const
{
    return m_albumArtist;
}
