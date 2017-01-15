#include "ergoapplication.h"
#include "Utilities/logger.h"
#include "Utilities/singleinstance.h"
#include "common.h"

#include <QSettings>
#include <QFile>
#include <QLoggingCategory>
#include <QDebug>


ErgoApplication::ErgoApplication(int &argc, char **argv) :
    QApplication(argc, argv),
    m_translator(new QTranslator),
    m_instance(new SingleInstance(this))
{
#ifndef QT_NO_DEBUG_OUTPUT
    QLoggingCategory::defaultCategory()->setEnabled(QtDebugMsg, true);
#endif
    qInstallMessageHandler(Logger::instance()->log);

    QCoreApplication::setApplicationName(APPLICATION_NAME);
    QCoreApplication::setOrganizationName(ORGANISATION_NAME);
    QCoreApplication::setOrganizationDomain(ORGANISATION_DOMAIN);

    QSettings settings;

    updateLanguage(settings.value("language", QLocale::system().name()).toString());

    m_instance->lock();
}

ErgoApplication::~ErgoApplication()
{
    m_instance->unlock();
}

bool ErgoApplication::updateLanguage(const QString &language)
{
    QString path(":/languages/languages/lang_" + language  + ".qm");
    if (!QFile::exists(path))
        return false;

    m_translator->load(path);
    installTranslator(m_translator);

    return true;
}

