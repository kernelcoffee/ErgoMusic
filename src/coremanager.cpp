#include "coremanager.h"
#include <QDebug>


CoreManager::CoreManager(QObject *parent) :
    AbstractCore(parent)
  , m_media(new MediaCore(this))
  , m_database(new DatabaseCore(this))
  , m_threads(new ThreadsCore(this))
  , m_ui(new UiCore(this))
{
    m_cores["media"] = m_media;
    m_cores["database"] = m_database;
    m_cores["threasds"] = m_threads;
    m_cores["ui"] = m_ui;
}

CoreManager::~CoreManager()
{
    qDeleteAll(m_cores);
}

void CoreManager::init()
{
    for (auto core : m_cores)
    {
        core->init();
        qDebug() << core << "\tInitialized";
    }
}

void CoreManager::initSettings()
{
    for (auto core : m_cores)
    {
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

void CoreManager::delayedInit()
{
    for (auto core : m_cores)
    {
        core->delayedInit();
    }
}

void CoreManager::aboutToQuit()
{
    for (auto core : m_cores)
    {
        core->aboutToQuit();
    }

}

