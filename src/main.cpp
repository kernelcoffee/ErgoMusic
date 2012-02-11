#include <QtGui/QApplication>
#include "mainwindow.hpp"

#include "Utilities/sharedobject.hpp"
#include "initialization.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Initialization* init = new Initialization();
    delete init;

    MainWindow w;
    w.show();

    return a.exec();
}
