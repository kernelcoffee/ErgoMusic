/**
 * ErgoMusic - Simple music player and music library manager.
 * Copyright (C) 2011-2012 Alexandre Moore <alexandre.moore@kernelcoffee.org>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQuickWindow>
#include <QQmlContext>
#include <QDebug>

#include "initialization.h"
#include "coremanager.h"
#include "common.h"

#include "UI/centralview.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Initialization* init = new Initialization();
    init->initSettings();
    init->initManagers();

    QQmlApplicationEngine engine;
    QQmlContext *context = engine.rootContext();


    CoreManager* cores = CoreManager::instance();
    cores->media()->initDummyData();

    qmlRegisterType<CentralView>("ErgoMusic", 1, 0, "CentralView");

    context->setContextProperty("watchPlaylistsModel",cores->media()->watchPlaylists());
    context->setContextProperty("cores", cores);
    context->setContextProperty("library", cores->media()->library());

    // replace the visible: true in main.qml
    engine.load(QUrl("qrc:///main.qml"));

    QObject *topLevel = engine.rootObjects().value(0);
    QQuickWindow *window = qobject_cast<QQuickWindow *>(topLevel);
    if ( !window ) {
        qWarning("Error: Your root item has to be a Window.");
        return -1;
    }

    window->show();
    return app.exec();
}
