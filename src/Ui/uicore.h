#ifndef UICORE_H
#define UICORE_H

#include "Abstracts/abstractcore.h"
#include "Ui/Media/mediacontroller.h"
#include "Views/viewcontroller.h"

#include <QQmlApplicationEngine>

class UiCore : public AbstractCore
{
    Q_OBJECT


public:
    explicit UiCore(QObject *parent = 0);
    ~UiCore();

    void    init() override;
    void    initSettings() override;

public slots:
    void    delayedInit() override;
    void    onAboutToQuit() override;

private:
    QQmlApplicationEngine m_engine;

    MediaController*    m_mediaController;
    ViewController*     m_viewController;
};

#endif // UICORE_H
