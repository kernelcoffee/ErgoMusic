#include "ergoapplication.h"
#include "coremanager.h"

#include <QTime>
#include <QTimer>

int main(int argc, char *argv[])
{
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

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
