#include "ergoapplication.h"
#include "coremanager.h"
#include "Utilities/singleinstance.h"

#include <QTime>
#include <QTimer>

int main(int argc, char *argv[])
{
    if (SingleInstance::check()) {
        qDebug() << "Session already exist";
//        SingleInstance::sendData(argc, argv);
        return 0;
    }

    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    ErgoApplication app(argc, argv);

    CoreManager *cores = CoreManager::instance();

    QObject::connect(&app, &ErgoApplication::aboutToQuit,
                     cores, &CoreManager::onAboutToQuit);
    QTimer::singleShot(1, cores, &CoreManager::delayedInit);
    qsrand((uint)QTime::currentTime().msec());

    cores->initSettings();
    cores->init();

    return app.exec();
}
