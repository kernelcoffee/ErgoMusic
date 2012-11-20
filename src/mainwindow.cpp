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
#include <QAction>

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
//    splitter->setHandleWidth(2);

    m_playlistWidget->setContentsMargins(0, 0, 0, 0);
    m_viewWidget->setContentsMargins(0, 0, 0, 0);

    ui->verticalLayout->setSpacing(0);
    ui->verticalLayout->addWidget(m_playerWidget, 1);
    ui->verticalLayout->addWidget(splitter, 1);
    ui->verticalLayout->setContentsMargins(0,0,0,0);

    initMenuBarActions();
    initMenuBar();
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

void    MainWindow::initMenuBar()
{


#ifdef Q_WS_MAC
#endif

    m_fileMenu = menuBar()->addMenu(tr("&File"));
    m_fileMenu->addAction(m_newPlaylistAct);
//    fileMenu->addAction(openAct);
//    fileMenu->addAction(saveAct);
//    fileMenu->addAction(printAct);
    m_fileMenu->addSeparator();
    m_fileMenu->addAction(m_exitAct);

    m_editMenu = menuBar()->addMenu(tr("&Edit"));
//    editMenu->addAction(undoAct);
//    editMenu->addAction(redoAct);
//    m_editMenu->addSeparator();
//    editMenu->addAction(cutAct);
//    editMenu->addAction(copyAct);
//    editMenu->addAction(pasteAct);
    m_editMenu->addSeparator();

}

void    MainWindow::initMenuBarActions()
{
    m_newPlaylistAct = new QAction(tr("&newPlaylist"), this);
    m_newPlaylistAct->setShortcuts(QKeySequence::New);
    m_newPlaylistAct->setStatusTip(tr("Create a new playlist"));
    connect(m_newPlaylistAct, SIGNAL(triggered()), this, SLOT(newPlaylist()));

    m_preferencesAct = new QAction(tr("&preferences"), this);
    m_preferencesAct->setShortcut(QKeySequence::Preferences);
    m_preferencesAct->setStatusTip(tr("Edit ErgoMusic preferences"));
    connect(m_preferencesAct, SIGNAL(triggered(), this, SLOT(showPreferences()));

    m_exitAct = new QAction(tr("&exit"), 0);
    m_exitAct->setShortcut(QKeySequence::Quit);
    m_exitAct->setStatusTip(tr("Exit ErgoMusic"));
    connect(m_exitAct, SIGNAL(triggered()), this, SLOT(close()));
}

// SLOTS
void    MainWindow::newPlaylist()
{

}

void    MainWindow::showPreferences()
{

}
