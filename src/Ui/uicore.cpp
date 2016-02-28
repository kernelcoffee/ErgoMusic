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
  context->setContextProperty("uiCore", this);
  context->setContextProperty("mediaController", m_mediaController);
  context->setContextProperty("watchPlaylistsMenuModel", &m_mediaController->watchPlaylistsModel());
  context->setContextProperty("viewController", m_viewController);

  QFontMetrics fm(qApp->font());
  context->setContextProperty("fontHeight", fm.height());


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

void UiCore::delayedInit()
{
    m_engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));
}

void UiCore::onAboutToQuit()
{
}
