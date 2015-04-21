#include <QApplication>

#include "Utilities/logger.h"
#include "initialization.h"

int main(int argc, char *argv[])
{
    qInstallMessageHandler(Logger::instance()->log);
    QApplication app(argc, argv);

    Initialization init;

    init.initSettings();
    init.initCores();

    return app.exec();
}
