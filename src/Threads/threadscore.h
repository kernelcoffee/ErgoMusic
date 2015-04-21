#ifndef THREADSCORE_H
#define THREADSCORE_H

#include "Abstracts/abstractcore.h"
#include <QRunnable>

class ThreadsCore : public AbstractCore
{
    Q_OBJECT
public:
    explicit ThreadsCore(QObject *parent = 0);
    ~ThreadsCore();

    void    init();
    void    initSettings();
    void    initArguments(QCommandLineParser &cmd);
    void    processArguments(QCommandLineParser &cmd);


    void    AddJob(QRunnable* job);
signals:

public slots:
    void    delayedInit();
    void    aboutToQuit();

};

#endif // THREADSCORE_H
