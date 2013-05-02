#ifndef LISTVIEW_H
#define LISTVIEW_H

#include <QTreeView>

class ListView : public QTreeView
{
    Q_OBJECT
public:
    explicit ListView(QWidget *parent = 0);
    ~ListView();
    
    void    init(void);
signals:
    
public slots:
    
};

#endif // LISTVIEW_H
