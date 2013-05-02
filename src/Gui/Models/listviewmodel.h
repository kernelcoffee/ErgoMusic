#ifndef LISTVIEWMODEL_H
#define LISTVIEWMODEL_H

#include "treemodel.h"
#include "Utilities/Abstract/abstractplaylist.h"

class ListViewModel : public TreeModel
{
    Q_OBJECT
public:
    explicit ListViewModel(QObject *parent = 0);
    ~ListViewModel();
    
    void    setPlaylist(AbstractPlaylist*);
    void    setupModelData();
signals:
    
public slots:

private:
    AbstractPlaylist*   m_playlist;
};

#endif // LISTVIEWMODEL_H
