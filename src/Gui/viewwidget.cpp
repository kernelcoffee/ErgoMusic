#include "viewwidget.h"
#include "Utilities/logger.h"
#include "Media/collection.h"
#include "Gui/Items/sidebarwidgetitem.h"

#include "Views/listview.h"
#include "Models/listviewmodel.h"
#include "Models/tablemodel.h"

#include <QHBoxLayout>

ViewWidget::ViewWidget(QWidget *parent) :
    QWidget(parent)
{
    m_layout = new QHBoxLayout(this);


//    QTableView*  view = new QTableView();
//    _model = new TableModel;

//    view->horizontalHeader()->setSortIndicatorShown(true);

//    m_layout->addWidget(view);
    setLayout(m_layout);

//    view->setModel(_model);
//    view->setFocusPolicy(Qt::NoFocus);
//    view->setAlternatingRowColors(true);
//    view->setHorizontalHeader(_model->getHeader());
//    view->setSelectionBehavior(QAbstractItemView::SelectRows);
//    view->setSelectionMode(QAbstractItemView::SingleSelection);
}

void    ViewWidget::selected(int type, int index)
{
    Logger::log("ViewWidget::selected - type : " + QString::number(type) + " index : " + QString::number(index), LOG_DEBUG);

    switch (type)
    {
    case (SidebarWidgetItem::WATCHPLAYLIST) :
        Logger::log("ViewWidget::selected - WatchPlaylist selected", LOG_DEBUG);
        _selectView(Collection::instance()->getWatchPlaylist());
//        _model->setPlaylist(Collection::instance()->getWatchPlaylist());
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

void ViewWidget::_selectView(AbstractPlaylist* playlist)
{
    QLayoutItem *item;
    delete m_layout->takeAt(0);

    switch (playlist->getViewType()) {
    default:
        ListView* view = new ListView;
        m_layout->addWidget(view);
        ListViewModel*  model = new ListViewModel;
        model->setPlaylist(playlist);
        view->setModel(model);
        view->header()->setSortIndicatorShown(true);
        view->setAlternatingRowColors(true);
        view->setAnimated(true);
        connect(playlist, SIGNAL(updated()), this, SLOT(update()));
        break;
    }
}
