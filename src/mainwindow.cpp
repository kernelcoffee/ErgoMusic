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

    m_playerWidget = new PlayerWidget();
    m_playlistWidget = new PlaylistWidget();
    m_viewWidget = new ViewWidget();

    ui->setupUi(this);

    QSplitter*   splitter = new QSplitter();
    splitter->addWidget(m_playlistWidget);
    splitter->addWidget(m_viewWidget);

    ui->verticalLayout->addWidget(m_playerWidget);
    ui->verticalLayout->addWidget(splitter);
}

MainWindow::~MainWindow()
{
    delete m_playerWidget;
    delete m_playlistWidget;
    delete m_viewWidget;
    delete ui;
}

void    MainWindow::refreshWindow()
{

}
