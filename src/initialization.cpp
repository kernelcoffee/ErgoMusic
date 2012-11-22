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

#include <QtCore/QSettings>
#include <QtCore/QCoreApplication>
#include <QtCore/QStandardPaths>

#include "initialization.h"
#include "Utilities/logger.h"
#include "coremanager.h"
#include "common.h"

Initialization::Initialization(void)
{
    QSettings settings;

    Logger::log("Starting initialization.", LOG_DEBUG);
    _arguments = qApp->arguments();

    Q_INIT_RESOURCE(ErgoMusic);
    Logger::log("Ressources Loaded.", LOG_DEBUG);

    _translator = new QTranslator();

    Logger::log("Language found : " + settings.value("language").toString(), LOG_DEBUG);
    //    _translator->load(QString("lang_" + QSettings.value("language").toStdString());

    Logger::log("intialization done.");
}

Initialization::~Initialization()
{}

void    Initialization::initSettings(void)
{
    QCoreApplication::setApplicationName(APPLICATION_NAME);
    QCoreApplication::setOrganizationName(ORGANIZATION_NAME);
    QCoreApplication::setOrganizationDomain(ORGANIZATION_DOMAIN);

    QSettings settings;

    if (_arguments.contains("--reset-all"))
        settings.clear();

    if (settings.value("initialized").isNull())
        initDefault();

    if (settings.value("version").isNull())
        settings.setValue("version", APPLICATION_VERSION);

    if (settings.value("version") != APPLICATION_VERSION)
    {
        Logger::log("Version doesn't match, pleaze do a migration");
        // do migration
    }
    Logger::log("Settings initilized", LOG_DEBUG);
}

void    Initialization::initDefault(void)
{
    QSettings	settings;

    settings.setValue("musicFolder", QStandardPaths::writableLocation(QStandardPaths::MusicLocation));
    settings.setValue("watchFolder", "");
    settings.setValue("watchFolderActivated", false);
    settings.setValue("dbType", "SQLITE");
    settings.setValue("dbPath", QStandardPaths::writableLocation(QStandardPaths::DataLocation));
    settings.setValue("dbName", "ergomusic");
    settings.setValue("dbLogin", "login");
    settings.setValue("dbPassword", "password");
    settings.setValue("language", QLocale::system().name());
    settings.setValue("initialized", true);
}

void    Initialization::initManagers()
{
   CoreManager::instance()->initManagers(_arguments);
}
