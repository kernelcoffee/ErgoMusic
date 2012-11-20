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

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Utilities/logger.h"

#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    QSettings settings;
    QList<int> splitterSize;

    m_playerWidget = new PlayerWidget(this);
    m_playlistWidget = new PlaylistWidget();
    m_viewWidget = new ViewWidget();
    ui->setupUi(this);

    splitter = new QSplitter();
    splitter->setOrientation(Qt::Horizontal);


    splitter->addWidget(m_playlistWidget);
    splitter->addWidget(m_viewWidget);

    splitter->setCollapsible(0, false);
    splitter->setCollapsible(1, false);
    splitterSize << 250 << m_viewWidget->width();
    splitter->setSizes(splitterSize);
    if (!settings.value("splitterSizes").isNull())
        splitter->restoreState(settings.value("splitterSizes").toByteArray());
    splitter->setContentsMargins(0, 0 , 0, 0);
    splitter->setHandleWidth(2);

    m_playlistWidget->setContentsMargins(0, 0, 0, 0);
    m_viewWidget->setContentsMargins(0, 0, 0, 0);

    ui->verticalLayout->setSpacing(0);
    ui->verticalLayout->addWidget(m_playerWidget, 1);
    ui->verticalLayout->addWidget(splitter, 1);
    ui->verticalLayout->setContentsMargins(0,0,0,0);
 }

MainWindow::~MainWindow()
{
    QSettings settings;

    Logger::log("Destroying MainWindow", LOG_DEBUG);
    settings.setValue("splitterSizes", splitter->saveState());

    delete m_playerWidget;
    delete m_playlistWidget;
    delete m_viewWidget;
    delete ui;
}

void    MainWindow::refreshWindow()
{

}
