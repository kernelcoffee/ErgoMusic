#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QAbstractTableModel>

class TableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    ~TableModel();

    int         rowCount(const QModelIndex &parent) const;
    int         columnCount(const QModelIndex &parent) const;
    QVariant    data(const QModelIndex &index, int role) const;

protected:
    TableModel(QObject* parent = 0);
};

#endif // TABLEMODEL_H
