#include "uicore.h"
#include "uicommon.h"

#include <QApplication>
#include <QQmlContext>
#include <QFontMetrics>
#include <QSystemTrayIcon>

#include <QDebug>

UiCore::UiCore(QObject *parent) :
    AbstractCore(parent)
  , m_viewController(new ViewController)
{
}

UiCore::~UiCore()
{
}

void UiCore::init()
{
  QQmlContext* context = m_engine.rootContext();
  m_mediaController = new MediaController(this);

  qRegisterMetaType<ModelType>("ModelType");
  qRegisterMetaType<TrackSortModel*>("trackSortModel");

  qmlRegisterType<MediaController>("ErgoMusic", 1, 0, "MediaController");

  context->setContextProperty("uiCore", this);
  context->setContextProperty("viewController", m_viewController);

  if (!QSystemTrayIcon::isSystemTrayAvailable())
  {
      qDebug() << "no system tray available";
//      QMessageBox::critical(0, QObject::tr("Systray"),
//                               QObject::tr("I couldn't detect any system tray "
//                                           "on this system."));
//      return 1;
  }
  else
  {
      qDebug() << "system tray available";
  }
}

void UiCore::initSettings()
{

}

MediaController* UiCore::mediaController() const
{
    return m_mediaController;
}

void UiCore::delayedInit()
{
    m_engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));
}

void UiCore::onAboutToQuit()
{
}
