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
    m_selectedPlaylist = NULL;
    m_layout = new QHBoxLayout(this);
    setLayout(m_layout);
}

void    ViewWidget::selected(int type, int index)
{
    Q_UNUSED(index);

    switch (type)
    {
    case (SidebarWidgetItem::WATCHPLAYLIST) :
        Logger::log("ViewWidget::selected - WatchPlaylist selected", LOG_DEBUG);
        _selectView(Collection::instance()->getWatchPlaylist());
        break;
    case (SidebarWidgetItem::PLAYLIST):
        Logger::log("ViewWidget::selected - Playlist selected", LOG_DEBUG);
        break;
    case (SidebarWidgetItem::DPLAYLIST):
        Logger::log("ViewWidget::selected - Dyanmic Playlist selected", LOG_DEBUG);
        break;
    default:
        _selectView(Collection::instance()->getLibrary());
        Logger::log("ViewWidget::selected - Library selected", LOG_DEBUG);
        break;
    }
    Logger::log("update view with " + QString::number(m_layout->children().size()), LOG_DEBUG);
    update();
}

void ViewWidget::_clean()
{
    QLayoutItem* item;

    while ( ( item = m_layout->takeAt( 0 ) ) != NULL )
    {
        delete item->widget();
        delete item;
    }
}

void ViewWidget::_selectView(AbstractPlaylist* playlist)
{
    if (m_selectedPlaylist == playlist)
        return;
    m_selectedPlaylist = playlist;
    _clean();
    switch (playlist->getViewType()) {
    case INVALID:
        Logger::log("ViewWidget - Invalide", LOG_DEBUG);
        break;
    case LIST:
    default:
        Logger::log("ViewWidget - new ListView", LOG_DEBUG);
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
