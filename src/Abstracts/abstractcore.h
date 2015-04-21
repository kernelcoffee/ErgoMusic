#ifndef ABSTRACTCORE_H
#define ABSTRACTCORE_H

#include <QObject>
#include <QCommandLineParser>

class AbstractCore : public QObject
{
    Q_OBJECT
public:
    explicit AbstractCore(QObject *parent = 0);

    virtual void init() = 0;
    // If we need some processing to be done right after the UI shows
    virtual void initSettings() = 0;
    // If the core as arguments to take into account
    virtual void initArguments(QCommandLineParser &cmd) { Q_UNUSED(cmd); }
    // process the arguments
    virtual void processArguments(QCommandLineParser &cmd) { Q_UNUSED(cmd) }

signals:

public slots:
    // If the core as settings to be saved
    virtual void delayedInit() {}
    // called when the current app is going to exit
    virtual void aboutToQuit() = 0;
};

#endif // ABSTRACTCORE_H
