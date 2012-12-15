#include "genre.h"

Genre::Genre()
{
}

Genre::Genre(QString &name)
{
    m_uid = -1;
    m_name = name;

}

Genre::~Genre()
{}

QString Genre::name() const
{
    return m_name;
}

int Genre::uid() const
{
    return m_uid;
}

void    Genre::setName(QString name)
{
    m_name = name;
}

void    Genre::setUid(int uid)
{
    m_uid = uid;
}
