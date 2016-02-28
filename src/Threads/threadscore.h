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

    void    init() override;
    void    initSettings() override;

    void    AddJob(QRunnable* job);

public slots:
    void    delayedInit() override;
    void    onAboutToQuit() override;

};

#endif // THREADSCORE_H
