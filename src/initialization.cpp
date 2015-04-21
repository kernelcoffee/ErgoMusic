#include "initialization.h"

#include <QCoreApplication>
#include <QTimer>
#include <QTime>
#include <QSettings>
#include <QFile>
#include <QDebug>

#include "coremanager.h"

Initialization::Initialization(QObject *parent) : QObject(parent)
{
    QCoreApplication::setOrganizationName("Kernelcoffee");
    QCoreApplication::setOrganizationDomain("kernelcoffee.org");
    QCoreApplication::setApplicationName("ErgoMusic");

    _translator = new QTranslator;

    QTimer::singleShot(1, this, SLOT(delayedInit()));
    qsrand((uint)QTime::currentTime().msec());
}

Initialization::~Initialization()
{

}

void Initialization::initCores()
{
    CoreManager* cores = CoreManager::instance();
    cores->init();

    QObject::connect(qApp, &QCoreApplication::aboutToQuit,
                     cores, &CoreManager::aboutToQuit);

}

void Initialization::initSettings()
{
    QSettings settings;

    CoreManager::instance()->initSettings();

    QString lang(":/languages/languages/lang_" + settings.value("language", QLocale::system().name()).toString() + ".qm");
    if (QFile::exists(lang))
    {
        _translator->load(lang);
        qApp->installTranslator(_translator);
    }
    else
        qWarning() << "lang file " << lang << "  not found";

    qDebug() << "Settings initilized";
}

void Initialization::delayedInit()
{
    CoreManager::instance()->delayedInit();
}
