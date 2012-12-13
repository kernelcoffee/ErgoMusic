#include "artist.h"

Artist::Artist()
{
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
