#ifndef TREEMODEL_H
#define TREEMODEL_H

// For doc, TreeModel extracted from treeview example on qt-project
// Idea to use is as another Abstract model from project defuze.me

#include "Gui/Items/treeitem.h"

#include <QAbstractItemModel>

class TreeItem;

class TreeModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    ~TreeModel();

    QVariant data(const QModelIndex &index, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const;
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const;
    QModelIndex parent(const QModelIndex &index) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;

protected:
    TreeModel(QObject* parent = 0);
    virtual void setupModelData() = 0;

    TreeItem *rootItem;
};

#endif // TREEMODEL_H
