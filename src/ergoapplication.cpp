#include "ergoapplication.h"

#include <QSettings>
#include <QFile>

ErgoApplication::ErgoApplication(int &argc, char **argv) :
    QApplication(argc, argv),
    m_translator(new QTranslator)
{
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

