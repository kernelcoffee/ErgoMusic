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
#include "Gui/playlistwidget.h"
#include "Gui/viewwidget.h"

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
private:
    void    initMenuBar();
    void    initMenuBarActions();

    Ui::MainWindow *ui;

    QSplitter      *splitter;

    // main widgets
    PlayerWidget    *m_playerWidget;
    PlaylistWidget  *m_playlistWidget;
    ViewWidget      *m_viewWidget;

    //menu bar
    QMenu           *m_fileMenu;
    QMenu           *m_editMenu;

    //menu bar actions
    QAction         *m_preferencesAct;

    QAction         *m_newPlaylistAct;
};

#endif // MAINWINDOW_H
