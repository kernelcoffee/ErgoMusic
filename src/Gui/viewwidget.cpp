#include "viewwidget.h"
#include "viewwidgetmodel.h"
#include "Media/collection.h"
#include "playlistwidgetitem.h"
#include "Utilities/logger.h"

#include <QHBoxLayout>
#include <QTableView>

ViewWidget::ViewWidget(QWidget *parent) :
    QWidget(parent)
{
    QHBoxLayout* layout = new QHBoxLayout();
    QTableView*  view = new QTableView();
//    ViewWidgetModel* model = new ViewWidgetModel;
    layout->addWidget(view);
    setLayout(layout);

    view->setFocusPolicy(Qt::NoFocus);
  //  view->setModel(model);
}

void    ViewWidget::selected(int type, int index)
{
    Logger::log("ViewWwdget::selected - type : " + QString::number(type) + " index : " + QString::number(index), LOG_DEBUG);

    switch (type)
    {
    case (PlaylistWidgetItem::WATCHPLAYLIST) :
        Logger::log("ViewWidget::selected -WatchPlaylist selected", LOG_DEBUG);
        break;
    case (PlaylistWidgetItem::PLAYLIST):
        Logger::log("ViewWidget::selected - Playlist selected", LOG_DEBUG);
        break;
    case (PlaylistWidgetItem::DPLAYLIST):
        Logger::log("ViewWidget::selected - Dyanmic Playlist selected", LOG_DEBUG);
        break;
    default:
        Logger::log("ViewWidget::selected - Library selected", LOG_DEBUG);
        break;
    }
}
