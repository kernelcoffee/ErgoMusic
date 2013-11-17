import QtQuick 2.1
import QtQuick.Controls 1.0
import "qrc:/qml/Desktop/Windows/"

MenuBar {
    id: menuWidget

    // File Menu
//    m_newPlaylistAct = new QAction(tr("&newPlaylist"), this);
//    m_newPlaylistAct->setShortcuts(QKeySequence::New);
//    m_newPlaylistAct->setStatusTip(tr("Create a new playlist"));
//    connect(m_newPlaylistAct, SIGNAL(triggered()), this, SLOT(newPlaylist()));

//    m_openAct = new QAction(tr("&open"), this);
//    m_openAct->setShortcut(QKeySequence::Open);
//    m_openAct->setStatusTip(tr(""));
//    connect(m_openAct, SIGNAL(triggered()), this, SLOT(open()));

//    m_saveAct = new QAction(tr("&save"), this);
//    m_saveAct->setShortcut(QKeySequence::Save);
//    m_saveAct->setStatusTip(tr(""));
//    connect(m_saveAct, SIGNAL(triggered()), this, SLOT(save()));

//    m_importAct = new QAction(tr("&import"), this);
//    m_importAct->setStatusTip(tr("Import files"));
//    connect(m_importAct, SIGNAL(triggered()), this, SLOT(import()));

//    m_exportAct = new QAction(tr("&export"), this);
//    m_exportAct->setStatusTip(tr("Export files"));
//    connect(m_openAct, SIGNAL(triggered()), this, SLOT(exportf()));

//    m_exitAct = new QAction(tr("&exit"), this);
//    m_exitAct->setShortcut(QKeySequence::Quit);
//    m_exitAct->setStatusTip(tr("Exit ErgoMusic"));
//    connect(m_exitAct, SIGNAL(triggered()), this, SLOT(close()));

    Menu {
        title: "File"
        MenuItem { text: "Open..." }
        MenuItem { text: "Close" }
    }


//    m_undoAct = new QAction(tr("&undo"), this);
//    m_undoAct->setShortcut(QKeySequence::Undo);
//    m_undoAct->setStatusTip(tr(""));
//    connect(m_undoAct, SIGNAL(triggered()), this, SLOT(undo()));

//    m_copyAct = new QAction(tr("&copy"), this);
//    m_copyAct->setShortcut(QKeySequence::Copy);
//    m_copyAct->setStatusTip(tr(""));
//    connect(m_copyAct, SIGNAL(triggered()), this, SLOT(copy()));

//    m_cutAct = new QAction(tr("&cut"), this);
//    m_cutAct->setShortcut(QKeySequence::Cut);
//    m_cutAct->setStatusTip(tr(""));
//    connect(m_cutAct, SIGNAL(triggered()), this, SLOT(cut()));

//    m_pasteAct = new QAction(tr("&paste"), this);
//    m_pasteAct->setShortcut(QKeySequence::Paste);
//    m_pasteAct->setStatusTip(tr(""));
//    connect(m_pasteAct, SIGNAL(triggered()), this, SLOT(paste()));

//    m_settingsAct = new QAction(tr("&settings"), this);
//    m_settingsAct->setShortcut(QKeySequence::Preferences);
//    m_settingsAct->setStatusTip(tr("Edit ErgoMusic settings"));
//    connect(m_settingsAct, SIGNAL(triggered()), this, SLOT(showSettings()));

    Menu {
        title: "Edit"
        MenuItem { text: "Cut" }
        MenuItem { text: "Copy" }
        MenuItem { text: "Paste" }
        MenuItem { text: "Settings"
            onTriggered: settingsWindow.show()
        }
    }
    //Presentation Menu

    //Commands Menu

    //Help Menu
//    m_aboutQt = new QAction(tr("&about Qt"), this);
//    m_aboutQt->setStatusTip(tr("Display informations about Qt"));
//    connect(m_aboutQt, SIGNAL(triggered()), this, SLOT(aboutQt()));

//    m_aboutErgoMusic = new QAction(tr("&about ErgoMusic"), this);
//    m_aboutErgoMusic->setStatusTip(tr("Display informations about ErgoMusic"));
//    connect(m_aboutErgoMusic, SIGNAL(triggered()), this, SLOT(aboutErgoMusic()));
//    Logger::log("init menuBar Action - END", LOG_DEBUG);

}
