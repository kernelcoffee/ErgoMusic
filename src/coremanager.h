#ifndef COREMANAGER_H
#define COREMANAGER_H

#include  "Abstracts/abstractcore.h"
#include "Utilities/singleton.h"

#include "Media/mediacore.h"
#include "Database/databasecore.h"
#include "Threads/threadscore.h"
#include "Ui/uicore.h"

#include <QMap>
#include <QUndoCommand>

class CoreManager : public AbstractCore , public Singleton<CoreManager>
{
    friend class Singleton<CoreManager>;

    Q_OBJECT
public:
    explicit CoreManager(QObject *parent = 0);
    ~CoreManager();

    void    init() override;
    void    initSettings() override;
    void    initArguments(QCommandLineParser &cmd) override;
    void    processArguments(QCommandLineParser &cmd) override;

    MediaCore*      media() const;
    DatabaseCore*   database() const;
    ThreadsCore*    threads() const;
    UiCore*         ui() const;

    void    addCommand(QUndoCommand* command);
    int     historyCount() const;

signals:
    void    historyCountChanged(int count);

public slots:
    void    delayedInit() override;
    void    onAboutToQuit() override;

    void    undo();
    void    redo();

private:
    QList<AbstractCore*>   m_cores;
    QUndoStack       m_historyStack;

    MediaCore       *m_media = nullptr;
    DatabaseCore    *m_database = nullptr;
    ThreadsCore     *m_threads = nullptr;
    UiCore          *m_ui = nullptr;
};

#endif // COREMANAGER_H
