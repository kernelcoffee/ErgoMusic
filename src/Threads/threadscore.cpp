#include "threadscore.h"
#include <QSettings>
#include <QThreadPool>

ThreadsCore::ThreadsCore(QObject *parent) :
    AbstractCore(parent)
{

}

ThreadsCore::~ThreadsCore()
{

}

void ThreadsCore::init()
{

}

void ThreadsCore::initSettings()
{
    QSettings settings;

    settings.setValue("Threads/nbThreads", 10);
}

void ThreadsCore::initArguments(QCommandLineParser &cmd)
{
    Q_UNUSED(cmd)
}

void ThreadsCore::processArguments(QCommandLineParser &cmd)
{
    Q_UNUSED(cmd)
}

void ThreadsCore::AddJob(QRunnable *job)
{
    QThreadPool::globalInstance()->start(job);
}

void ThreadsCore::delayedInit()
{

}

void ThreadsCore::onAboutToQuit()
{

}

