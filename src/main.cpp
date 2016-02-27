#include "ergoapplication.h"
#include "Utilities/logger.h"
#include "coremanager.h"

#include <QLoggingCategory>
#include <QTime>
#include <QTimer>

int main(int argc, char *argv[])
{
#ifndef QT_NO_DEBUG_OUTPUT
    QLoggingCategory::defaultCategory()->setEnabled(QtDebugMsg, true);
#endif
    qInstallMessageHandler(Logger::instance()->log);

    ErgoApplication app(argc, argv);
    CoreManager* cores = CoreManager::instance();

    QObject::connect(&app, &ErgoApplication::aboutToQuit,
                     cores, &CoreManager::onAboutToQuit);
    QTimer::singleShot(1, cores, SLOT(delayedInit()));
    qsrand((uint)QTime::currentTime().msec());

    cores->init();
    cores->initSettings();

    return app.exec();
}
