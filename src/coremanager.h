#ifndef COREMANAGER_H
#define COREMANAGER_H

#include  "Abstracts/abstractcore.h"
#include "Utilities/singleton.h"

#include "Media/mediacore.h"
#include "Database/databasecore.h"
#include "Threads/threadscore.h"
#include "Ui/uicore.h"

#include <QMap>

class CoreManager : public AbstractCore , public Singleton<CoreManager>
{
    friend class Singleton<CoreManager>;

    Q_OBJECT
public:
    explicit CoreManager(QObject *parent = 0);
    ~CoreManager();

    void    init();
    void    initSettings();
    void    initArguments(QCommandLineParser &cmd);
    void    processArguments(QCommandLineParser &cmd);

    MediaCore*      media() const;
    DatabaseCore*   database() const;
    ThreadsCore*    threads() const;
    UiCore*         ui() const;

    void    addCommand(QUndoCommand* command);
    int     historyCount() const;

signals:
    void    historyCountChanged(int count);

public slots:
    void    delayedInit();
    void    aboutToQuit();

    void    undo();
    void    redo();

private:
    QMap<QString, AbstractCore*>   m_cores;
    QUndoStack       m_historyStack;

    MediaCore       *m_media;
    DatabaseCore    *m_database;
    ThreadsCore     *m_threads;
    UiCore          *m_ui;
};

#endif // COREMANAGER_H
