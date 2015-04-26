#ifndef UICORE_H
#define UICORE_H

#include "Abstracts/abstractcore.h"
#include "Ui/Media/mediacontroller.h"
#include "Views/viewcontroller.h"

#include <QQmlApplicationEngine>
#include <QUndoStack>

class UiCore : public AbstractCore
{
    Q_OBJECT


public:
    explicit UiCore(QObject *parent = 0);
    ~UiCore();

    void    init();
    void    initSettings();
    void    initArguments(QCommandLineParser &cmd);
    void    processArguments(QCommandLineParser &cmd);

signals:

public slots:
    void    delayedInit();
    void    aboutToQuit();

private:
    QQmlApplicationEngine m_engine;

    MediaController*    m_mediaController;
    ViewController*     m_viewController;
};

#endif // UICORE_H
