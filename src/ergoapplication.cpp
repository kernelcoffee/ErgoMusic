#include "ergoapplication.h"
#include "Utilities/logger.h"

#include <QSettings>
#include <QFile>
#include <QLoggingCategory>
#include <QDebug>


ErgoApplication::ErgoApplication(int &argc, char **argv) :
    QApplication(argc, argv),
    m_translator(new QTranslator)
{

#ifndef QT_NO_DEBUG_OUTPUT
    QLoggingCategory::defaultCategory()->setEnabled(QtDebugMsg, true);
#endif
    qInstallMessageHandler(Logger::instance()->log);

    QCoreApplication::setOrganizationName("Kernelcoffee");
    QCoreApplication::setOrganizationDomain("kernelcoffee.org");
    QCoreApplication::setApplicationName("ErgoMusic");

    QSettings settings;

    updateLanguage(settings.value("language", QLocale::system().name()).toString());
}

bool ErgoApplication::updateLanguage(const QString &language)
{
    QString path(":/languages/languages/lang_" + language  + ".qm");
    if (QFile::exists(path))
    {
        m_translator->load(path);
        installTranslator(m_translator);
    }
    else {
        return false;
    }
    return true;
}

