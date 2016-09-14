#include "uicore.h"
#include "uicommon.h"

#include <QApplication>
#include <QQmlContext>
#include <QFontMetrics>
#include <QSystemTrayIcon>

#include <QDebug>

UiCore::UiCore(QObject *parent) :
    AbstractCore(parent)
{
}

UiCore::~UiCore()
{
}

void UiCore::init()
{
    m_mediaController = new MediaController(this);
    m_viewController = new ViewController(this);

    QQmlContext *context = m_engine.rootContext();

    qRegisterMetaType<ModelType>("ModelType");
    qRegisterMetaType<TrackSortModel *>("trackSortModel");

    qmlRegisterType<MediaController>("ErgoMusic", 1, 0, "MediaController");
    qmlRegisterType<ViewController>("ErgoMusic", 1, 0, "ViewController");

    context->setContextProperty("uiCore", this);

    if (!QSystemTrayIcon::isSystemTrayAvailable()) {
        qDebug() << "no system tray available";
        //      QMessageBox::critical(0, QObject::tr("Systray"),
        //                               QObject::tr("I couldn't detect any system tray "
        //                                           "on this system."));
        //      return 1;
    } else {
        qDebug() << "system tray available";
    }
}

void UiCore::initSettings()
{

}

MediaController *UiCore::mediaController() const
{
    return m_mediaController;
}

ViewController *UiCore::viewController() const
{
    return m_viewController;
}

void UiCore::delayedInit()
{
    m_engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));
}

void UiCore::onAboutToQuit()
{
}
