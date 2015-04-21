#include "uicore.h"
#include "uicommon.h"

#include <QApplication>
#include <QQmlContext>
#include <QFontMetrics>

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
  context->setContextProperty("uiCore", this);
  context->setContextProperty("mediaController", m_mediaController);
  context->setContextProperty("watchPlaylistsMenuModel", &m_mediaController->watchPlaylistsModel());
  context->setContextProperty("viewController", m_viewController);

  QFontMetrics fm(qApp->font());
  context->setContextProperty("fontHeight", fm.height());
}

void UiCore::initSettings()
{

}

void UiCore::initArguments(QCommandLineParser &cmd)
{
    Q_UNUSED(cmd)
}

void UiCore::processArguments(QCommandLineParser &cmd)
{
    Q_UNUSED(cmd)
}

void UiCore::delayedInit()
{
    m_engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));
}

void UiCore::aboutToQuit()
{
}
