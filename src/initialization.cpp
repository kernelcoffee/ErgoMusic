#include <QSettings>
#include <QCoreApplication>
#include <QDesktopServices>

#include "initialization.hpp"
#include "Utilities/logger.hpp"

Initialization::Initialization(void)
{
    QSettings settings;

    Logger::log("Starting initialization.", LOG_DEBUG);

    _arguments = qApp->arguments();

    Q_INIT_RESOURCE(ErgoMusic);
    Logger::log("Ressources Loaded.", LOG_DEBUG);

    initSettings();
    Logger::log("Settings initilized", LOG_DEBUG);

    _translator = new QTranslator();
    Logger::log("Language found : " + settings.value("language").toString());
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
    {
        settings.clear();
    }

    if (settings.value("initialized").isNull())
    {
        initDefault();
    }

    if (settings.value("version").isNull())
        settings.setValue("version", APPLICATION_VERSION);

    if (settings.value("version") != APPLICATION_VERSION)
    {
        Logger::log("Version doesn't match, pleaze do a migration");
        // do migration
        return;
    }
}

void    Initialization::initDefault(void)
{
    QSettings	settings;

    settings.setValue("musicFolder", QDesktopServices::storageLocation(QDesktopServices::MusicLocation));
    settings.setValue("watchFolder", "");
    settings.setValue("watchFolderActivated", false);
    settings.setValue("dbType", "SQLITE");
    settings.setValue("dbPath", QDesktopServices::storageLocation(QDesktopServices::DataLocation));
    settings.setValue("dbName", "ergomusic");
    settings.setValue("dbLogin", "login");
    settings.setValue("dbPassword", "password");
    settings.setValue("language", QLocale::system().name());
}
