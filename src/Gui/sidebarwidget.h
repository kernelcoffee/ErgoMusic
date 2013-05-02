#ifndef SIDEBARIDGET_H
#define SIDEBARWIDGET_H

#include <QWidget>
#include <QTreeView>

class SidebarWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SidebarWidget(QWidget *parent = 0);
    
signals:
    void    selected(int, int);
public slots:
    void    selected(QModelIndex);
    void    update();

private:
    QTreeView*  m_view;
};

#endif // SidebarWIDGET_H
