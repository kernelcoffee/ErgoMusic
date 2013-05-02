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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSplitter>
#include "Gui/playerwidget.h"
#include "Gui/sidebarwidget.h"
#include "Gui/viewwidget.h"
#include "Gui/settingswidget.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void    refreshWindow();
    void    createLayout();

public slots:
    void    newPlaylist();
    void    open();
    void    save();
    void    import();
    void    exportf();


    void    undo();
    void    copy();
    void    paste();
    void    cut();
    void    showSettings();

    void    aboutQt();
    void    aboutErgoMusic();

private:
    void    initMenuBar();
    void    initMenuBarActions();
    void    initSignals();

    Ui::MainWindow *ui;

    QSplitter      *splitter;

    // main widgets
    PlayerWidget    *m_playerWidget;
    SidebarWidget   *m_sidebarWidget;
    ViewWidget      *m_viewWidget;
    SettingsWidget  *m_settingsWidget;

    //menu bar
    QMenu           *m_fileMenu;
    QMenu           *m_editMenu;
    QMenu           *m_presentationMenu;
    QMenu           *m_commandsMenu;
    QMenu           *m_advancedMenu;
    QMenu           *m_helpMenu;

    //menu bar actions
    QAction         *m_settingsAct;

    QAction         *m_undoAct;
    QAction         *m_copyAct;
    QAction         *m_cutAct;
    QAction         *m_pasteAct;

    QAction         *m_newPlaylistAct;
    QAction         *m_openAct;
    QAction         *m_importAct;
    QAction         *m_exportAct;
    QAction         *m_saveAct;
    QAction         *m_exitAct;

    // Help
    QAction         *m_aboutQt;
    QAction         *m_aboutErgoMusic;
};

#endif // MAINWINDOW_H
