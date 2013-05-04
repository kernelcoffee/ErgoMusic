#include "listviewmodel.h"
#include "Utilities/logger.h"
#include "Media/track.h"
#include "Gui/Items/listviewitem.h"

ListViewModel::ListViewModel(QObject *parent) :
    TreeModel(parent)
{
    _initHeader();
}

ListViewModel::~ListViewModel()
{
}

void ListViewModel::setPlaylist(AbstractPlaylist *playlist)
{
    if (m_playlist == playlist)
        return;
    m_playlist = playlist;
    _initHeader();
    setupModelData();
}

void ListViewModel::setupModelData()
{
    if (m_playlist->isLocked())
        return;
    for (int i = 0; i < m_playlist->getList()->size(); i++) {
        Track* t = m_playlist->getList()->at(i);
        ListViewItem* item = new ListViewItem(t, rootItem);
        rootItem->appendChild(item);
    }
}

QVariant ListViewModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
        return m_header.at(section);

    return QVariant();
}

int ListViewModel::columnCount(const QModelIndex &parent) const
{
    return m_header.size();
}

QVariant ListViewModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role != Qt::DisplayRole)
        return QVariant();

    ListViewItem *item = static_cast<ListViewItem*>(index.internalPointer());
    if (index.column() == 0)
        return index.row();
    return item->data(m_header.at(index.column()));
}

void ListViewModel::_initHeader()
{
    m_header.clear();
    m_header << "#" << tr("Title") << "Artist" << "Album";
}
