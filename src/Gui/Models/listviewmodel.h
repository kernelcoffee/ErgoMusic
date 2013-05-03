#ifndef LISTVIEWMODEL_H
#define LISTVIEWMODEL_H

#include "treemodel.h"
#include "Utilities/Abstract/abstractplaylist.h"

#include <QHeaderView>

class ListViewModel : public TreeModel
{
    Q_OBJECT
public:
    explicit ListViewModel(QObject *parent = 0);
    ~ListViewModel();
    
    void            setPlaylist(AbstractPlaylist*);
    void            setupModelData();

    QVariant        headerData(int section, Qt::Orientation orientation, int role) const;
    int             columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant        data(const QModelIndex &index, int role) const;

signals:
    
public slots:

private:
    void                _initHeader();
    AbstractPlaylist*   m_playlist;
    QStringList         m_header;
};

#endif // LISTVIEWMODEL_H
