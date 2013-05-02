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
#include "Gui/settingswidget.h"
#include "Media/collection.h"

#include <QVBoxLayout>
#include <QAction>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    QSettings settings;
    QList<int> splitterSize;

    m_playerWidget = new PlayerWidget(this);
    m_sidebarWidget = new SidebarWidget();
    m_viewWidget = new ViewWidget();
    m_settingsWidget = NULL;
    ui->setupUi(this);

    splitter = new QSplitter();
    splitter->setOrientation(Qt::Horizontal);

    splitter->addWidget(m_sidebarWidget);
    splitter->addWidget(m_viewWidget);

    splitter->setCollapsible(0, false);
    splitter->setCollapsible(1, false);
    splitterSize << 250 << m_viewWidget->width();
    splitter->setSizes(splitterSize);
    if (!settings.value("splitterSizes").isNull())
        splitter->restoreState(settings.value("splitterSizes").toByteArray());
    splitter->setContentsMargins(0, 0 , 0, 0);

    m_sidebarWidget->setContentsMargins(0, 0, 0, 0);
    m_viewWidget->setContentsMargins(0, 0, 0, 0);

    ui->verticalLayout->setSpacing(0);
    ui->verticalLayout->addWidget(m_playerWidget, 1);
    ui->verticalLayout->addWidget(splitter, 1);
    ui->verticalLayout->setContentsMargins(0,0,0,0);

    initMenuBarActions();
    initMenuBar();
    initSignals();
 }

MainWindow::~MainWindow()
{
    QSettings settings;

    Logger::log("Destroying MainWindow", LOG_DEBUG);
    settings.setValue("splitterSizes", splitter->saveState());

    delete m_playerWidget;
    delete m_sidebarWidget;
    delete m_viewWidget;
    delete m_settingsWidget;
    delete ui;
}

void    MainWindow::refreshWindow()
{

}

void    MainWindow::initMenuBar()
{
    Logger::log("init menuBar - START", LOG_DEBUG);

    // File menu
    m_fileMenu = menuBar()->addMenu(tr("&file"));
    m_fileMenu->addAction(m_newPlaylistAct);
    m_fileMenu->addAction(m_openAct);
    m_fileMenu->addAction(m_saveAct);
    m_fileMenu->addSeparator();
    m_fileMenu->addAction(m_exitAct);

    // Edit menu
    m_editMenu = menuBar()->addMenu(tr("&edit"));
    m_editMenu->addAction(m_undoAct);
    m_editMenu->addSeparator();
    m_editMenu->addAction(m_cutAct);
    m_editMenu->addAction(m_copyAct);
    m_editMenu->addAction(m_pasteAct);
    m_editMenu->addSeparator();
    m_editMenu->addAction(m_settingsAct);

    m_presentationMenu = menuBar()->addMenu(tr("&presentation"));
    m_commandsMenu = menuBar()->addMenu(tr("&commands"));
    m_advancedMenu = menuBar()->addMenu(tr("&advanced"));
    m_helpMenu = menuBar()->addMenu(tr("&help"));
    m_helpMenu->addAction(m_aboutQt);
    m_helpMenu->addAction(m_aboutErgoMusic);


    Logger::log("init menuBar - END", LOG_DEBUG);

}

void    MainWindow::initMenuBarActions()
{
    Logger::log("init menuBar Action - START", LOG_DEBUG);

    // File Menu
    m_newPlaylistAct = new QAction(tr("&newPlaylist"), this);
    m_newPlaylistAct->setShortcuts(QKeySequence::New);
    m_newPlaylistAct->setStatusTip(tr("Create a new playlist"));
    connect(m_newPlaylistAct, SIGNAL(triggered()), this, SLOT(newPlaylist()));

    m_openAct = new QAction(tr("&open"), this);
    m_openAct->setShortcut(QKeySequence::Open);
    m_openAct->setStatusTip(tr(""));
    connect(m_openAct, SIGNAL(triggered()), this, SLOT(open()));

    m_saveAct = new QAction(tr("&save"), this);
    m_saveAct->setShortcut(QKeySequence::Save);
    m_saveAct->setStatusTip(tr(""));
    connect(m_saveAct, SIGNAL(triggered()), this, SLOT(save()));

    m_importAct = new QAction(tr("&import"), this);
    m_importAct->setStatusTip(tr("Import files"));
    connect(m_importAct, SIGNAL(triggered()), this, SLOT(import()));

    m_exportAct = new QAction(tr("&export"), this);
    m_exportAct->setStatusTip(tr("Export files"));
    connect(m_openAct, SIGNAL(triggered()), this, SLOT(exportf()));

    m_exitAct = new QAction(tr("&exit"), this);
    m_exitAct->setShortcut(QKeySequence::Quit);
    m_exitAct->setStatusTip(tr("Exit ErgoMusic"));
    connect(m_exitAct, SIGNAL(triggered()), this, SLOT(close()));


    // Edit Menu
    m_undoAct = new QAction(tr("&undo"), this);
    m_undoAct->setShortcut(QKeySequence::Undo);
    m_undoAct->setStatusTip(tr(""));
    connect(m_undoAct, SIGNAL(triggered()), this, SLOT(undo()));

    m_copyAct = new QAction(tr("&copy"), this);
    m_copyAct->setShortcut(QKeySequence::Copy);
    m_copyAct->setStatusTip(tr(""));
    connect(m_copyAct, SIGNAL(triggered()), this, SLOT(copy()));

    m_cutAct = new QAction(tr("&cut"), this);
    m_cutAct->setShortcut(QKeySequence::Cut);
    m_cutAct->setStatusTip(tr(""));
    connect(m_cutAct, SIGNAL(triggered()), this, SLOT(cut()));

    m_pasteAct = new QAction(tr("&paste"), this);
    m_pasteAct->setShortcut(QKeySequence::Paste);
    m_pasteAct->setStatusTip(tr(""));
    connect(m_pasteAct, SIGNAL(triggered()), this, SLOT(paste()));

    m_settingsAct = new QAction(tr("&settings"), this);
    m_settingsAct->setShortcut(QKeySequence::Preferences);
    m_settingsAct->setStatusTip(tr("Edit ErgoMusic settings"));
    connect(m_settingsAct, SIGNAL(triggered()), this, SLOT(showSettings()));

    //Presentation Menu

    //Commands Menu

    //Help Menu
    m_aboutQt = new QAction(tr("&about Qt"), this);
    m_aboutQt->setStatusTip(tr("Display informations about Qt"));
    connect(m_aboutQt, SIGNAL(triggered()), this, SLOT(aboutQt()));

    m_aboutErgoMusic = new QAction(tr("&about ErgoMusic"), this);
    m_aboutErgoMusic->setStatusTip(tr("Display informations about ErgoMusic"));
    connect(m_aboutErgoMusic, SIGNAL(triggered()), this, SLOT(aboutErgoMusic()));
    Logger::log("init menuBar Action - END", LOG_DEBUG);
}

void    MainWindow::initSignals()
{
    connect(m_sidebarWidget, SIGNAL(selected(int,int)), m_viewWidget, SLOT(selected(int,int)));
}

// SLOTS
void    MainWindow::newPlaylist()
{}

void    MainWindow::open()
{}

void    MainWindow::save()
{}

void    MainWindow::import()
{}

void    MainWindow::exportf()
{}

void    MainWindow::undo()
{}

void    MainWindow::copy()
{}

void    MainWindow::paste()
{}

void    MainWindow::cut()
{}

void    MainWindow::showSettings()
{
    if (!m_settingsWidget) {
        m_settingsWidget = new SettingsWidget();

        connect(m_settingsWidget, SIGNAL(watchFolderPath_updated()), Collection::instance()->getWatchPlaylist(), SLOT(update()));
        Logger::log("MainWindow - show setting - settingsWidget creation - end of creating signals connections.", LOG_DEBUG);
    }
    m_settingsWidget->show();
}

void    MainWindow::aboutQt()
{
    QApplication::aboutQt();
}

void    MainWindow::aboutErgoMusic()
{

}
