#include "viewwidget.h"
#include "Views/tableviewwidget.h"
#include "Media/collection.h"
#include "sidebarwidgetitem.h"
#include "Models/tablemodel.h"
#include "Utilities/logger.h"
#include "Media/collection.h"

#include <QHBoxLayout>
#include <QTableView>

ViewWidget::ViewWidget(QWidget *parent) :
    QWidget(parent)
{
    QHBoxLayout* layout = new QHBoxLayout(this);
    QTableView*  view = new QTableView();
//    QTreeView*  view = new QTreeView();
    _model = new TableModel;
//view->setHorizontalHeader(_model->getHeader());

    view->horizontalHeader()->setSortIndicatorShown(true);

    layout->addWidget(view);
    setLayout(layout);

    view->setModel(_model);
//    view->setFocusPolicy(Qt::NoFocus);
    view->setAlternatingRowColors(true);
//    view->setHorizontalHeader(_model->getHeader());
    view->setSelectionBehavior(QAbstractItemView::SelectRows);
    view->setSelectionMode(QAbstractItemView::SingleSelection);
}

void    ViewWidget::selected(int type, int index)
{
    Logger::log("ViewWwdget::selected - type : " + QString::number(type) + " index : " + QString::number(index), LOG_DEBUG);

    switch (type)
    {
    case (SidebarWidgetItem::WATCHPLAYLIST) :
        Logger::log("ViewWidget::selected - WatchPlaylist selected", LOG_DEBUG);
        _model->setPlaylist(Collection::instance()->getWatchPlaylist());
        break;
    case (SidebarWidgetItem::PLAYLIST):
        Logger::log("ViewWidget::selected - Playlist selected", LOG_DEBUG);
        break;
    case (SidebarWidgetItem::DPLAYLIST):
        Logger::log("ViewWidget::selected - Dyanmic Playlist selected", LOG_DEBUG);
        break;
    default:
        Logger::log("ViewWidget::selected - Library selected", LOG_DEBUG);
        break;
    }
    update();
}
