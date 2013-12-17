/**
 * ErgoMusic - Simple music player and music library manager.
 * Copyright (C) 2011-2012 Alexandre Moore <alexandre.moore@kernelcoffee.org>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "Utilities/logger.h"
#include "coremanager.h"
#include "importengine.h"

#include <QDirIterator>
#include <QUrl>

class Collection;

ImportEngine::ImportEngine()
{
    Logger::log("ImportEngine - Creating Instance", LOG_DEBUG);
    m_supportedExtension << "mp3" << "wma" << "ogg" << "oga" << "wav" << "flac" << "aac" << "m4a";
}

ImportEngine::~ImportEngine()
{
}

void    ImportEngine::init(QStringList &arguments)
{
    Q_UNUSED(arguments);
    Logger::log("ImportEngine - Inititialization", LOG_DEBUG);
}

void    ImportEngine::setQuery(QSqlQuery *query)
{
    m_query = query;
}

QList<Track*>*   ImportEngine::importPath(QString &path)
{
    return importPath(path, CoreManager::instance()->media()->collection());
}



QList<Track*>*   ImportEngine::importPath(QString &path, Collection* collection)
{
    Track*  track;

    Logger::log("ImportEngine - importPath - " + path, LOG_DEBUG);
    QList<Track*>*  list = new QList<Track*>;
    QDirIterator it(path, QDirIterator::Subdirectories);
    while (it.hasNext())
     {
        it.next();
        //!TODO : improve error catching
         if (it.fileInfo().isFile() == false)
             continue;
         if (it.fileInfo().isReadable() == false)
             continue;
         if (m_supportedExtension.contains(it.fileInfo().suffix().toLower()) == true)
         {
            track = new Track(QUrl(it.fileInfo().absoluteFilePath()));
            track->extractTags(collection);
            list->append(track);
         }
     }
    Logger::log("Returning import list", LOG_DEBUG);
    return list;
}
