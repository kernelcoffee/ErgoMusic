#ifndef PLAYLISTWIDGET_H
#define PLAYLISTWIDGET_H

#include <QWidget>
#include <QTreeView>

class PlaylistWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PlaylistWidget(QWidget *parent = 0);
    
signals:
    
public slots:
    void    selected(QModelIndex);
    
private:
    QTreeView*  m_view;
};

#endif // PLAYLISTWIDGET_H
