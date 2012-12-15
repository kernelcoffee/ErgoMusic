#include "artist.h"

Artist::Artist()
{
}

Artist::Artist(QString name)
{
    uid = -1;
    m_name = name;
    m_photo = NULL;
}

Artist::~Artist()
{
}

QString Artist::name()
{
    return m_name;
}

void Artist::setName(QString name)
{
    m_name = name;
}
