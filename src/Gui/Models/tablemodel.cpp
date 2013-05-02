#include "tablemodel.h"
#include "Utilities/logger.h"
#include "Media/track.h"

TableModel::TableModel(QObject *parent) :
    QAbstractTableModel(parent)
{
    Logger::log("TableModel - init instance", LOG_DEBUG);
    _playlist = NULL;
}

TableModel::~TableModel()
{

}

void    TableModel::setPlaylist(AbstractPlaylist* playlist)
{
    if (_playlist != NULL) {
//        if (_playlist == playlist)
//            return;
        disconnect(_playlist, SIGNAL(updated()), this, SIGNAL(layoutChanged()));
    }
    _playlist = playlist;
    connect(_playlist, SIGNAL(updated()), this, SIGNAL(layoutChanged()));
    initHeader();
    layoutAboutToBeChanged();
    layoutChanged();
}

int TableModel::rowCount(const QModelIndex &parent) const
{
    if (!_playlist) {
        return 0;
    }
    return _playlist->getList()->size();
}

int TableModel::columnCount(const QModelIndex &parent) const
{
    if (!_playlist)
        return 0;
    return _header.size();
}

QVariant    TableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole || !_playlist)
        return QVariant();
    Track* item = _playlist->getList()->at(index.row());
    return item->getValue(_header.at(index.column()));
}

bool TableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{

//    dataChanged(index);
    return true;
}

Qt::ItemFlags TableModel::flags(const QModelIndex &index) const
{
    return Qt::ItemIsEditable | Qt::ItemIsEnabled ;
}

QStringList TableModel::getHeader() const
{
    return _header;
}

void    TableModel::initHeader()
{
    _header << "Title" << "Artist" << "Album" << "Duration" << "Track";
}
