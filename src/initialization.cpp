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
#include <QPixmap>

#include "initialization.h"
#include "Utilities/logger.h"
#include "coremanager.h"
#include "common.h"
#include "Media/collection.h"

Initialization::Initialization(void)
{

    Logger::log("Starting initialization.", LOG_DEBUG);

    QCoreApplication::setApplicationName(APPLICATION_NAME);
    QCoreApplication::setOrganizationName(ORGANIZATION_NAME);
    QCoreApplication::setOrganizationDomain(ORGANIZATION_DOMAIN);

    Q_INIT_RESOURCE(ErgoMusic);
    Logger::log("Ressources Loaded.", LOG_DEBUG);

    QPixmap splashPixmap(":/images/spashScreen.png");
    _splash = new QSplashScreen(splashPixmap);
    _splash->show();
    _splash->showMessage("Initialization...");
    qApp->processEvents();
    _arguments = qApp->arguments();
    _translator = new QTranslator();
}

Initialization::~Initialization()
{
    delete  _splash;
}

void    Initialization::initSettings(void)
{
    QSettings settings;

    if (_arguments.contains("--reset-all"))
    {
        Logger::log("Reset all settings enabled");
        settings.clear();
    }

    if (settings.contains("initialized") && settings.value("initialized") == false)
        initDefault();

    if (settings.value("version").isNull())
        settings.setValue("version", APPLICATION_VERSION);

    if (settings.value("version") != APPLICATION_VERSION)
    {
        Logger::log("Version doesn't match, pleaze do a migration");
        // do migration
    }

    Logger::log("Language found : " + settings.value("language").toString(), LOG_DEBUG);
    if (QFile::exists(":qm_files/languages/lang_" + settings.value("language").toString()) == false) {
        Logger::log("lang file :/languages/lang_" + settings.value("language").toString() + "  not found");
    } else {
        _translator->load(":/languages/lang_" + settings.value("language").toString());
        qApp->installTranslator(_translator);
    }

    //    _translator->load(QString(":/language/lang_" + settings.value("language").toStdString());

    Logger::log("Settings initilized", LOG_DEBUG);
}

void    Initialization::initDefault(void)
{
    QSettings	settings;

    Logger::log("Initialization - set default values");
    settings.setValue("language", QLocale::system().name());
    settings.setValue("musicFolder", QStandardPaths::writableLocation(QStandardPaths::MusicLocation));
    settings.setValue("watchFolder", "");
    settings.setValue("watchFolderActivated", false);
    settings.setValue("database/type", "SQLITE");
    settings.setValue("database/path", QStandardPaths::writableLocation(QStandardPaths::DataLocation));
    settings.setValue("database/name", "ergomusic");
    settings.setValue("database/login", "login");
    settings.setValue("database/password", "password");
    settings.setValue("initialized", true);

    settings.sync();
    Logger::log("Language found : " + settings.value("language").toString(), LOG_DEBUG);
    settings.sync();
}

void    Initialization::initManagers()
{
   CoreManager::instance()->initManagers(_arguments);
}

void    Initialization::initCollection()
{
    Collection::instance()->init(_arguments, _splash);
}

QSplashScreen*  Initialization::getSplashScreen() const
{
    return _splash;
}
