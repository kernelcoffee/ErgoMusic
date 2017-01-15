#include "coremanager.h"
#include <QDebug>


CoreManager::CoreManager(QObject *parent) :
    AbstractCore(parent)
  , m_media(new MediaCore(this))
  , m_database(new DatabaseCore(this))
  , m_threads(new ThreadsCore(this))
  , m_ui(new UiCore(this))
{
    m_cores << m_media << m_database << m_threads << m_ui;
    qDebug() << "Cores available : " << m_cores;
}

CoreManager::~CoreManager()
{
    qDeleteAll(m_cores);
}

void CoreManager::init()
{
    for (auto core : m_cores)
    {
        qDebug() << core << "\tinitializing";
        core->init();
        qDebug() << core << "\tinitialized";
    }
}

void CoreManager::initSettings()
{
    for (auto core : m_cores)
    {
        qDebug() << "Init settings " << core;
        core->initSettings();
    }
}

void CoreManager::initArguments(QCommandLineParser &cmd)
{
    for (auto core : m_cores)
    {
        core->initArguments(cmd);
    }
}

void CoreManager::processArguments(QCommandLineParser &cmd)
{
    for (auto core : m_cores)
    {
        core->processArguments(cmd);
    }
}

MediaCore *CoreManager::media() const
{
    return m_media;
}

DatabaseCore *CoreManager::database() const
{
    return m_database;
}

ThreadsCore *CoreManager::threads() const
{
    return m_threads;
}

UiCore *CoreManager::ui() const
{
    return m_ui;
}

void CoreManager::addCommand(QUndoCommand *command)
{
    m_historyStack.push(command);
    emit historyCountChanged(historyCount());
}

int CoreManager::historyCount() const
{
    return m_historyStack.index();
}

void CoreManager::delayedInit()
{
    for (auto core : m_cores)
    {
        core->delayedInit();
    }
}

void CoreManager::onAboutToQuit()
{
    for (auto core : m_cores)
    {
        core->onAboutToQuit();
    }
}

void CoreManager::undo()
{
    qDebug() << "undo";
    m_historyStack.undo();
    emit historyCountChanged(historyCount());
}

void CoreManager::redo()
{
    qDebug() << "redo";
    m_historyStack.redo();
    emit historyCountChanged(historyCount());
}

