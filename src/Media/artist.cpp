#include "artist.h"
#include "Utilities/logger.h"

Artist::Artist()
{
}

Artist::Artist(QString name)
{
    Logger::log("Creating artist instance for " + name, LOG_DEBUG);
    uid = -1;
    m_name = name;
    m_photo = NULL;
}

Artist::~Artist()
{
}

QString Artist::name()
{
    if (m_name.isEmpty())
        return "";
    return m_name;
}

void Artist::setName(QString name)
{
    m_name = name;
}
