#include "tablemodel.h"
#include "Utilities/logger.h"

TableModel::TableModel(QObject *parent) :
    QAbstractTableModel(parent)
{
    Logger::log("TableModel - init instance", LOG_DEBUG);
}

TableModel::~TableModel()
{

}

int TableModel::rowCount(const QModelIndex &parent) const
{
}

int TableModel::columnCount(const QModelIndex &parent) const
{}

QVariant    TableModel::data(const QModelIndex &index, int role) const
{}
