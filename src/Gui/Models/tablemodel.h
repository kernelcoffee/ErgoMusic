#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QAbstractTableModel>
#include "Utilities/Abstract/abstractplaylist.h"
#include <QHeaderView>

class TableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    ~TableModel();

    void        setPlaylist(AbstractPlaylist*);
    int         rowCount(const QModelIndex &parent) const;
    int         columnCount(const QModelIndex &parent) const;
    QVariant    data(const QModelIndex &index, int role) const;
    bool        setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole);
    Qt::ItemFlags flags(const QModelIndex & index) const ;

    QHeaderView*    getHeader(void) const;
protected:
    TableModel(QObject* parent = 0);
    void         initHeader(void);
private:
    AbstractPlaylist*   _playlist;
    QHeaderView*        _header;
};

#endif // TABLEMODEL_H
