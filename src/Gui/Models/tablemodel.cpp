#include "tablemodel.h"
#include "Utilities/logger.h"

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
    return 10;
}

QVariant    TableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole || !_playlist)
        return QVariant();
    _playlist->getList()->at(index.row());
    return QString("test");
}

bool TableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
//    dataChanged(index);
    true;
}

Qt::ItemFlags TableModel::flags(const QModelIndex &index) const
{
    return Qt::ItemIsEditable | Qt::ItemIsEnabled ;
}

void    TableModel::initHeader()
{
//    if (_header == NULL)
//        _header = new QHeaderView;
//    _header->setStretchLastSection(true);
}
